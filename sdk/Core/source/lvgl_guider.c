/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "lvgl_demo_utils.h"
#include "lvgl_freertos.h"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smartdma.h"
#include "fsl_inputmux_connections.h"
#include "fsl_inputmux.h"
#include "fsl_lpuart.h"
#include "AvnetTypedef.h"
#include "Monitor.h"
#include "servo.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define I2C_RELEASE_SDA_PORT  PORT4
#define I2C_RELEASE_SCL_PORT  PORT4
#define I2C_RELEASE_SDA_GPIO  GPIO4
#define I2C_RELEASE_SDA_PIN   0U
#define I2C_RELEASE_SCL_GPIO  GPIO4
#define I2C_RELEASE_SCL_PIN   1U
#define I2C_RELEASE_BUS_COUNT 100U

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;
/*KT add*/
struct robotStatus {
    int motorP;
    int motorY;
    unsigned int Facestatus;
    unsigned int speakstatus;
    unsigned int emotionstatus;
};

struct robotStatus robot = {
    .motorP = 90,
    .motorY = 90,
    .Facestatus = 1,
    .speakstatus = 0,
    .emotionstatus = 0
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if LV_USE_LOG
static void print_cb(const char *buf)
{
    PRINTF("\r%s\n", buf);
}
#endif

static uint32_t get_idle_time_cb(void)
{
	 return 0;
}

static void reset_idle_time_cb(void)
{
    resetIdleTaskTime();
}

static void AppTask(void *param)
{
#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    lv_timer_register_get_idle_cb(get_idle_time_cb);
    lv_timer_register_reset_idle_cb(reset_idle_time_cb);
    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    for (;;)
    {
        lv_task_handler();
        vTaskDelay(5);
    }
}

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_I2C_ReleaseBus(void);

static void BOARD_InitSmartDMA(void)
{
    RESET_ClearPeripheralReset(kMUX_RST_SHIFT_RSTn);

    INPUTMUX_Init(INPUTMUX0);
    INPUTMUX_AttachSignal(INPUTMUX0, 0, kINPUTMUX_FlexioToSmartDma);

    /* Turnoff clock to inputmux to save power. Clock is only needed to make changes */
    INPUTMUX_Deinit(INPUTMUX0);

    SMARTDMA_InitWithoutFirmware();

    NVIC_EnableIRQ(SMARTDMA_IRQn);
    NVIC_SetPriority(SMARTDMA_IRQn, 3);
}


static void i2c_release_bus_delay(void)
{
    SDK_DelayAtLeastUs(100U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

void BOARD_I2C_ReleaseBus(void)
{
    uint8_t i = 0;
    gpio_pin_config_t pin_config;
    port_pin_config_t i2c_pin_config = {0};

    /* Config pin mux as gpio */
    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.mux        = kPORT_MuxAsGpio;

    pin_config.pinDirection = kGPIO_DigitalOutput;
    pin_config.outputLogic  = 1U;
    CLOCK_EnableClock(kCLOCK_Port4);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SCL_PIN, &i2c_pin_config);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SDA_PIN, &i2c_pin_config);

    GPIO_PinInit(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, &pin_config);
    GPIO_PinInit(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, &pin_config);

    /* Drive SDA low first to simulate a start */
    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    /* Send 9 pulses on SCL and keep SDA high */
    for (i = 0; i < 9; i++)
    {
        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
        i2c_release_bus_delay();
        i2c_release_bus_delay();
    }

    /* Send stop */
    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
    i2c_release_bus_delay();
}


void InitUartConnect()
{
    lpuart_config_t config;

    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;
    LPUART_Init(DEMO_LPUART, &config, DEMO_LPUART_CLK_FREQ);
#if !LV_USE_GUIDER_SIMULATOR
    MonitorInit();
#endif
    /* Enable RX interrupt. */
    LPUART_EnableInterrupts(DEMO_LPUART, kLPUART_RxDataRegFullInterruptEnable);
    EnableIRQ(DEMO_LPUART_IRQn);
}
//my custom code
void SLEEPGui(char* pValue)
{
    ui_load_scr_animation(&guider_ui, &guider_ui.Sleep, guider_ui.Sleep_del, &guider_ui.Sleep_del, setup_scr_Sleep, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
    PRINTF("switch to SLEEP");
    robot.Facestatus = 2;
}

void NORMALGui(char* pValue)
{
	ui_load_scr_animation(&guider_ui, &guider_ui.Normal, guider_ui.Normal_del, &guider_ui.Normal_del, setup_scr_Normal, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
	PRINTF("switch to NORMAL");
	robot.Facestatus = 1;
    robot.speakstatus = 0;
}
void THINKGui(char* pValue)
{
	ui_load_scr_animation(&guider_ui, &guider_ui.Thinking, guider_ui.Thinking_del, &guider_ui.Thinking_del, setup_scr_Thinking, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
	PRINTF("switch to THINKING");
	robot.Facestatus = 3;
    robot.speakstatus = 0;
}
void SpeakingGui(char* pValue)
{
    ui_load_scr_animation(&guider_ui, &guider_ui.Speaking, guider_ui.Speaking_del, &guider_ui.Speaking_del, setup_scr_Speaking, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    PRINTF("switch to SPEAKING");
    robot.speakstatus = 1;
    unsigned int value;
    sscanf(pValue, "%d", &value);
    robot.emotionstatus = value;
    switch (value)
    {
    case 0:
        PRINTF("emotion: neutral");
        break;
    case 1:
        PRINTF("emotion: concerned");
        break;
    case 2:
        PRINTF("emotion: angry");
        break;
    case 3:
        PRINTF("emotion: sad");
        break;
    case 4:
        PRINTF("emotion: happy");
        break;
    case 5:
        PRINTF("emotion: confused");
        break;
    }
}

void MusicGui(char* pValue)
{
    ui_load_scr_animation(&guider_ui, &guider_ui.Music, guider_ui.Music_del, &guider_ui.Music_del, setup_scr_Music, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    PRINTF("switch to MUSIC");
    robot.speakstatus = 2;
}

void FocusGui(char* pValue)
{
    ui_load_scr_animation(&guider_ui, &guider_ui.Focus, guider_ui.Focus_del, &guider_ui.Focus_del, setup_scr_Focus, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    PRINTF("switch to FOCUS");
    robot.Facestatus = 4;
    robot.speakstatus = 0;
}

void MotorControlPitch(char* pValue)
{
    unsigned int value;
    sscanf(pValue, "%d", &value);
    robot.motorP = value;
    Servo_SetPitch(value);
}

void MotorControlYaw(char* pValue)
{
    unsigned int value;
    sscanf(pValue, "%d", &value);
    robot.motorY = value;
    Servo_SetYaw(value);
}

void ShowNumber(char* pValue)
{
	unsigned int value=0;
	sscanf(pValue,"%d",&value);
	PRINTF("Number = %d\r\n" , value);
}

SMONITORCOMMAND sMonitorFuncList[]=
{
	{  "Sleep",    "<var 1> <var 2>",     "switch to SLEEP",      SLEEPGui },
	{  "Normal",    "<var 1> <var 2>",     "switch to NORMAL",      NORMALGui },
    {  "Thinking",    "<var 1> <var 2>",     "switch to THINKING",      THINKGui },
    {  "Speaking",    "<var 1> <var 2>",     "switch to SPEAKING",      SpeakingGui },
    {  "Music",    "<var 1> <var 2>",     "switch to MUSIC",      MusicGui },
    {  "Focus",    "<var 1> <var 2>",     "switch to FOCUS",      FocusGui },
	{  "ShowNum",    "<var 1> <var 2>",     "Print the input numbers",     ShowNumber },
	{  "MotorPitch",    "<var 1> <var 2>",     "control motor P",      MotorControlPitch},
	{  "MotorYaw",    "<var 1> <var 2>",     "control motor Y",      MotorControlYaw},
	{0,0,0,0}
};

/*!
 * @brief Main function
 */
int main(void)
{
    BaseType_t stat;

    /* Init board hardware. */
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach FRO 12M to FLEXCOMM2 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

    CLOCK_SetClkDiv(kCLOCK_DivFlexioClk, 1u);
    CLOCK_AttachClk(kPLL0_to_FLEXIO);
    BOARD_InitBootClocks();
    BOARD_I2C_ReleaseBus();
    BOARD_InitBootPins();
    BOARD_InitDebugConsole();
    DEMO_InitUsTimer();
    
    /* Init smartdma. */
    BOARD_InitSmartDMA();
    InitUartConnect();
    #if !LV_USE_GUIDER_SIMULATOR
    Servo_Init();
    #endif
    stat = xTaskCreate(AppTask, "lvgl", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc failed. Increase the heap size.");

    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
