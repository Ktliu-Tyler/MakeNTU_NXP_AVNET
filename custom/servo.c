/*
 * servo.c - Dual servo driver (GPIO software PWM)
 *
 * Active outputs:
 *   - Pitch: P1_12 (GPIO1_12)
 *   - Yaw:   P1_13 (GPIO1_13)
 */

#include "servo.h"

#include "FreeRTOS.h"
#include "task.h"

#include <stdbool.h>

#include "fsl_clock.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

/*******************************************************************************
 * Configuration — edit here
 ******************************************************************************/

/* ── Pitch channel (P1_12 -> GPIO1_12) ── */
#define SERVO_PITCH_PORT        PORT1
#define SERVO_PITCH_GPIO        GPIO1
#define SERVO_PITCH_PIN         12U
#define SERVO_PITCH_ALT         kPORT_MuxAlt0

/* ── Yaw channel (P1_13 -> GPIO1_13) ── */
#define SERVO_YAW_PORT          PORT1
#define SERVO_YAW_GPIO          GPIO1
#define SERVO_YAW_PIN           13U
#define SERVO_YAW_ALT           kPORT_MuxAlt0

/* ── PWM parameters ── */
#define SERVO_PWM_PERIOD_US     20000U
#define SERVO_PULSE_MIN_US      1000U
#define SERVO_PULSE_MAX_US      2000U

#define SERVO_TASK_STACK_SIZE   (configMINIMAL_STACK_SIZE + 128U)
#define SERVO_TASK_PRIORITY     (tskIDLE_PRIORITY + 3U)  /* Higher priority to avoid touch interrupt preemption */

/*******************************************************************************
 * Private state  (file-scope, not exposed to callers)
 ******************************************************************************/

static volatile uint32_t s_pitch_angle = 90U;
static volatile uint32_t s_yaw_angle = 90U;
static volatile bool s_servo_initialized = false;
static TaskHandle_t s_servo_task_handle = NULL;

/*******************************************************************************
 * Private helpers
 ******************************************************************************/

static void servo_delay_us(uint32_t us)
{
    SDK_DelayAtLeastUs(us, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

static uint32_t servo_angle_to_pulse_us(uint32_t angle)
{
    if (angle > 180U)
    {
        angle = 180U;
    }

    return SERVO_PULSE_MIN_US
         + (angle * (SERVO_PULSE_MAX_US - SERVO_PULSE_MIN_US)) / 180U;
}

static void servo_gpio_init(void)
{
    gpio_pin_config_t cfg = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };

    CLOCK_EnableClock(kCLOCK_Port1);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    PORT_SetPinMux(SERVO_PITCH_PORT, SERVO_PITCH_PIN, SERVO_PITCH_ALT);
    PORT_SetPinMux(SERVO_YAW_PORT, SERVO_YAW_PIN, SERVO_YAW_ALT);

    GPIO_PinInit(SERVO_PITCH_GPIO, SERVO_PITCH_PIN, &cfg);
    GPIO_PinInit(SERVO_YAW_GPIO, SERVO_YAW_PIN, &cfg);
}

static void servo_task(void *param)
{
    TickType_t last_wake_time = xTaskGetTickCount();
    (void)param;

    for (;;)
    {
        uint32_t pitch_pulse_us = servo_angle_to_pulse_us(s_pitch_angle);
        uint32_t yaw_pulse_us = servo_angle_to_pulse_us(s_yaw_angle);

        /* Pitch pulse */
        GPIO_PinWrite(SERVO_PITCH_GPIO, SERVO_PITCH_PIN, 1U);
        servo_delay_us(pitch_pulse_us);
        GPIO_PinWrite(SERVO_PITCH_GPIO, SERVO_PITCH_PIN, 0U);

        /* Yaw pulse */
        GPIO_PinWrite(SERVO_YAW_GPIO, SERVO_YAW_PIN, 1U);
        servo_delay_us(yaw_pulse_us);
        GPIO_PinWrite(SERVO_YAW_GPIO, SERVO_YAW_PIN, 0U);

        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(SERVO_PWM_PERIOD_US / 1000U));
    }
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

void Servo_Init(void)
{
    if (s_servo_initialized)
    {
        return;
    }

    servo_gpio_init();
    s_servo_initialized = true;

    (void)xTaskCreate(servo_task,
                      "servo",
                      SERVO_TASK_STACK_SIZE,
                      NULL,
                      SERVO_TASK_PRIORITY,
                      &s_servo_task_handle);
}

void Servo_SetPitch(uint32_t angle)
{
    if (!s_servo_initialized)
    {
        return;
    }

    if (angle > 180U)
    {
        angle = 180U;
    }

    s_pitch_angle = angle;
}

void Servo_SetYaw(uint32_t angle)
{
    if (!s_servo_initialized)
    {
        return;
    }

    if (angle > 180U)
    {
        angle = 180U;
    }

    s_yaw_angle = angle;
}