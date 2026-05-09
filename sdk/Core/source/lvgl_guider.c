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

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

extern int Focus_digital_clock_Focus_hour_value;
extern int Focus_digital_clock_Focus_min_value;
extern int Focus_digital_clock_Focus_sec_value;

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

typedef struct weather_status {
    bool current_valid;
    bool daily_valid;
    bool rain_valid;
    bool code_valid;
    int current_temp;
    int daily_low;
    int daily_high;
    int rain_percent;
    int weather_code;
} weather_status_t;

static weather_status_t s_weather_status = {0};
static bool s_weather_dirty = true;
static lv_obj_t *s_weather_applied_screen = NULL;

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

static bool IsValidLvObj(lv_obj_t *obj)
{
    return obj != NULL && lv_obj_is_valid(obj);
}

static int ClampInt(int value, int min_value, int max_value)
{
    if (value < min_value) {
        return min_value;
    }
    if (value > max_value) {
        return max_value;
    }
    return value;
}

static char *AppendText(char *p, char *end, const char *text)
{
    while (p < end && text != NULL && *text != '\0') {
        *p++ = *text++;
    }
    return p;
}

static char *AppendSignedInt(char *p, char *end, int value)
{
    char digits[12];
    int count = 0;
    unsigned int magnitude;

    if (p >= end) {
        return p;
    }

    if (value < 0) {
        *p++ = '-';
        magnitude = (unsigned int)(-(value + 1)) + 1U;
    } else {
        magnitude = (unsigned int)value;
    }

    do {
        digits[count++] = (char)('0' + (magnitude % 10U));
        magnitude /= 10U;
    } while (magnitude != 0U && count < (int)sizeof(digits));

    while (count > 0 && p < end) {
        *p++ = digits[--count];
    }

    return p;
}

static void SetLabelTempCurrent(lv_obj_t *label, int temp)
{
    char text[24];
    char *p = text;
    char *end = text + sizeof(text) - 1U;

    p = AppendText(p, end, "Temp: ");
    p = AppendSignedInt(p, end, temp);
    p = AppendText(p, end, " C");
    *p = '\0';
    lv_label_set_text(label, text);
}

static void SetLabelTempMaxMin(lv_obj_t *label, int low, int high)
{
    char text[40];
    char *p = text;
    char *end = text + sizeof(text) - 1U;

    p = AppendText(p, end, "Max: ");
    p = AppendSignedInt(p, end, high);
    p = AppendText(p, end, " C Min: ");
    p = AppendSignedInt(p, end, low);
    p = AppendText(p, end, " C");
    *p = '\0';
    lv_label_set_text(label, text);
}

static void SetLabelRainPercent(lv_obj_t *label, int rain_percent)
{
    char text[32];
    char *p = text;
    char *end = text + sizeof(text) - 1U;

    p = AppendText(p, end, "Rain Percent: ");
    p = AppendSignedInt(p, end, rain_percent);
    p = AppendText(p, end, " %");
    *p = '\0';
    lv_label_set_text(label, text);
}

static void HideWeatherImages(void)
{
    if (IsValidLvObj(guider_ui.Weather_img_0)) {
        lv_obj_add_flag(guider_ui.Weather_img_0, LV_OBJ_FLAG_HIDDEN);
    }
    if (IsValidLvObj(guider_ui.Weather_img_1)) {
        lv_obj_add_flag(guider_ui.Weather_img_1, LV_OBJ_FLAG_HIDDEN);
    }
    if (IsValidLvObj(guider_ui.Weather_img_3)) {
        lv_obj_add_flag(guider_ui.Weather_img_3, LV_OBJ_FLAG_HIDDEN);
    }
    if (IsValidLvObj(guider_ui.Weather_img_45)) {
        lv_obj_add_flag(guider_ui.Weather_img_45, LV_OBJ_FLAG_HIDDEN);
    }
    if (IsValidLvObj(guider_ui.Weather_img_55)) {
        lv_obj_add_flag(guider_ui.Weather_img_55, LV_OBJ_FLAG_HIDDEN);
    }
    if (IsValidLvObj(guider_ui.Weather_img_95)) {
        lv_obj_add_flag(guider_ui.Weather_img_95, LV_OBJ_FLAG_HIDDEN);
    }
}

static lv_obj_t *SelectWeatherImageObj(int weather_code, const void **image_src)
{
    *image_src = &_1_alpha_163x130;

    switch (weather_code) {
    case 0:
        *image_src = &_0_alpha_136x124;
        return guider_ui.Weather_img_0;
    case 1:
        *image_src = &_1_alpha_163x130;
        return guider_ui.Weather_img_1;
    case 2:
        *image_src = &_1_alpha_163x130;
        return guider_ui.Weather_img_1;
    case 3:
        *image_src = &_3_alpha_180x125;
        return guider_ui.Weather_img_3;
    case 45:
    case 48:
        *image_src = &_45_alpha_180x125;
        return guider_ui.Weather_img_45;
    case 51:
    case 53:
    case 55:
    case 56:
    case 57:
        *image_src = &_55_alpha_171x132;
        return guider_ui.Weather_img_55;
    case 61:
    case 63:
    case 65:
    case 66:
    case 67:
    case 71:
    case 73:
    case 75:
    case 77:
    case 80:
    case 81:
    case 82:
    case 85:
    case 86:
        *image_src = &_55_alpha_171x132;
        return guider_ui.Weather_img_55;
    case 95:
    case 96:
    case 99:
        *image_src = &_95_alpha_171x143;
        return guider_ui.Weather_img_95;
    default:
        *image_src = &_1_alpha_163x130;
        return guider_ui.Weather_img_1;
    }
}

static void ApplyWeatherImage(int weather_code)
{
    const void *image_src = NULL;
    lv_obj_t *image_obj = NULL;

    HideWeatherImages();
    image_obj = SelectWeatherImageObj(weather_code, &image_src);

    if (IsValidLvObj(image_obj)) {
        lv_img_set_src(image_obj, image_src);
        lv_obj_clear_flag(image_obj, LV_OBJ_FLAG_HIDDEN);
    }
}

static void WeatherApplyStateToUi(void)
{
    int temp_bar_value = 0;
    int rain_value = 0;

    if (!IsValidLvObj(guider_ui.Weather)) {
        s_weather_applied_screen = NULL;
        return;
    }

    if (!s_weather_dirty && s_weather_applied_screen == guider_ui.Weather) {
        return;
    }

    if (IsValidLvObj(guider_ui.Weather_TempCurrentLabel)) {
        if (s_weather_status.current_valid) {
            SetLabelTempCurrent(guider_ui.Weather_TempCurrentLabel, s_weather_status.current_temp);
        } else {
            lv_label_set_text(guider_ui.Weather_TempCurrentLabel, "Temp: -- C");
        }
    }

    if (IsValidLvObj(guider_ui.Weather_TempMaxMinLabel)) {
        if (s_weather_status.daily_valid) {
            SetLabelTempMaxMin(guider_ui.Weather_TempMaxMinLabel,
                               s_weather_status.daily_low,
                               s_weather_status.daily_high);
        } else {
            lv_label_set_text(guider_ui.Weather_TempMaxMinLabel, "Max: -- C Min: -- C");
        }
    }

    if (IsValidLvObj(guider_ui.Weather_RainPercentLabel)) {
        if (s_weather_status.rain_valid) {
            SetLabelRainPercent(guider_ui.Weather_RainPercentLabel, s_weather_status.rain_percent);
        } else {
            lv_label_set_text(guider_ui.Weather_RainPercentLabel, "Rain Percent: -- %");
        }
    }

    if (IsValidLvObj(guider_ui.Weather_TempBar)) {
        lv_bar_set_range(guider_ui.Weather_TempBar, 0, 70);
        if (s_weather_status.current_valid) {
            temp_bar_value = s_weather_status.current_temp;
        } else if (s_weather_status.daily_valid) {
            temp_bar_value = s_weather_status.daily_high;
        }
        lv_bar_set_value(guider_ui.Weather_TempBar, ClampInt(temp_bar_value, 0, 70), LV_ANIM_ON);
    }

    if (IsValidLvObj(guider_ui.Weather_RainBar)) {
        lv_bar_set_range(guider_ui.Weather_RainBar, 0, 100);
        if (s_weather_status.rain_valid) {
            rain_value = s_weather_status.rain_percent;
        }
        lv_bar_set_value(guider_ui.Weather_RainBar, ClampInt(rain_value, 0, 100), LV_ANIM_ON);
    }

    if (s_weather_status.code_valid) {
        ApplyWeatherImage(s_weather_status.weather_code);
    }

    s_weather_applied_screen = guider_ui.Weather;
    s_weather_dirty = false;
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
#if !LV_USE_GUIDER_SIMULATOR
        MonitorProcess();
#endif
        WeatherApplyStateToUi();
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

static bool ParseSpeakingEmotion(const char *pValue, unsigned int *out_value)
{
    const char *p = pValue;
    char *end = NULL;
    unsigned long parsed = 0;

    if (pValue == NULL || out_value == NULL) {
        return false;
    }

    while (*p != '\0' && !isdigit((unsigned char)*p)) {
        p++;
    }

    if (*p == '\0') {
        return false;
    }

    parsed = strtoul(p, &end, 10);
    if (end == p) {
        return false;
    }

    if (parsed > 5UL) {
        parsed = 5UL;
    }

    *out_value = (unsigned int)parsed;
    return true;
}

static unsigned int ReadSpeakingEmotionOrNeutral(char *pValue)
{
    unsigned int value = 0;

    PRINTF("Speaking raw pValue = [%s]\r\n", pValue ? pValue : "(null)");

    if (!ParseSpeakingEmotion(pValue, &value)) {
        PRINTF("Speaking emotion parse failed, using neutral\r\n");
        value = 0;
    }

    PRINTF("Speaking emotion code = %u\r\n", value);
    return value;
}

static void HideSpeakingEmotionDecorations(void)
{
    lv_obj_add_flag(guider_ui.Speaking_emoL3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_emoR3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_emo4L, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_emo4R, LV_OBJ_FLAG_HIDDEN);
}

static void ResetFocusClock(void)
{
    Focus_digital_clock_Focus_hour_value = 0;
    Focus_digital_clock_Focus_min_value = 0;
    Focus_digital_clock_Focus_sec_value = 0;

    if (lv_obj_is_valid(guider_ui.Focus_digital_clock_Focus)) {
        lv_dclock_set_text_fmt(guider_ui.Focus_digital_clock_Focus, "%d:%02d:%02d",
                               Focus_digital_clock_Focus_hour_value,
                               Focus_digital_clock_Focus_min_value,
                               Focus_digital_clock_Focus_sec_value);
    }
}

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
    unsigned int value = ReadSpeakingEmotionOrNeutral(pValue);
    robot.emotionstatus = value;

    HideSpeakingEmotionDecorations();

    typedef struct
    {
        int32_t eyeL_x;
        int32_t eyeL_y;
        int32_t eyeL_w;
        int32_t eyeL_h;
        uint32_t eyeL_color_hex;
        int32_t eyeR_x;
        int32_t eyeR_y;
        int32_t eyeR_w;
        int32_t eyeR_h;
        uint32_t eyeR_color_hex;
        int32_t browL_x;
        int32_t browL_y;
        int32_t browL_w;
        int32_t browL_h;
        int32_t browR_x;
        int32_t browR_y;
        int32_t browR_w;
        int32_t browR_h;
    } speaking_pose_t;

    const speaking_pose_t *pose = NULL;
    lv_obj_t *eyebowL_obj = guider_ui.Speaking_eyebowL;
    lv_obj_t *eyebowR_obj = guider_ui.Speaking_eyebowR;
    static const speaking_pose_t neutral_pose = {125, 85, 80, 130, 0x2195f6, 275, 85, 80, 130, 0x2195f6, 135, 66, 127, 47, 286, 64, 109, 62};
    static const speaking_pose_t concerned_pose = {91, 64, 124, 124, 0x4ba5ef, 266, 64, 126, 124, 0x5aa7ef, 135, 26, 89, 46, 303, 30, 115, 51};
    static const speaking_pose_t angry_pose = {109, 123, 100, 80, 0xdb3750, 275, 123, 100, 80, 0xdb3750, 112, 113, 127, 47, 275, 113, 109, 62};
    static const speaking_pose_t sad_pose = {125, 85, 80, 130, 0x2195f6, 275, 85, 80, 129, 0x2195f6, 115, 76, 109, 62, 266, 76, 115, 51};
    static const speaking_pose_t happy_pose = {125, 103, 80, 82, 0xe79faa, 275, 103, 80, 80, 0xe79faa, 91, 56, 115, 51, 283, 56, 109, 62};
    static const speaking_pose_t confused_pose = {125, 150, 80, 19, 0x2195f6, 266, 150, 80, 19, 0x2195f6, 112, 118, 115, 51, 266, 94, 109, 62};

    switch (value)
    {
    case 1:
        PRINTF("emotion: concerned");
        pose = &concerned_pose;
        eyebowL_obj = guider_ui.Speaking_eyebowL1;
        eyebowR_obj = guider_ui.Speaking_eyebowR1;
        break;
    case 2:
        PRINTF("emotion: angry");
        pose = &angry_pose;
        eyebowL_obj = guider_ui.Speaking_eyebowL2;
        eyebowR_obj = guider_ui.Speaking_eyebowR2;
        break;
    case 3:
        PRINTF("emotion: sad");
        pose = &sad_pose;
        lv_obj_clear_flag(guider_ui.Speaking_emoL3, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.Speaking_emoR3, LV_OBJ_FLAG_HIDDEN);
        eyebowL_obj = guider_ui.Speaking_eyebowL3;
        eyebowR_obj = guider_ui.Speaking_eyebowR3;
        break;
    case 4:
        PRINTF("emotion: happy");
        pose = &happy_pose;
        lv_obj_clear_flag(guider_ui.Speaking_emo4L, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.Speaking_emo4R, LV_OBJ_FLAG_HIDDEN);
        eyebowL_obj = guider_ui.Speaking_eyebowL4;
        eyebowR_obj = guider_ui.Speaking_eyebowR4;
        break;
    case 5:
        PRINTF("emotion: confused");
        pose = &confused_pose;
        eyebowL_obj = guider_ui.Speaking_eyebowL5;
        eyebowR_obj = guider_ui.Speaking_eyebowR5;
        break;
    case 0:
    default:
        PRINTF("emotion: neutral");
        pose = &neutral_pose;
        break;
    }

    lv_obj_add_flag(guider_ui.Speaking_eyebowL, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowL1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowL2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowL3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowL4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowL5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.Speaking_eyebowR5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(eyebowL_obj, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(eyebowR_obj, LV_OBJ_FLAG_HIDDEN);

    ui_animation(guider_ui.Speaking_eyeL, 220, 0, lv_obj_get_x(guider_ui.Speaking_eyeL), pose->eyeL_x, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeL, 220, 0, lv_obj_get_y(guider_ui.Speaking_eyeL), pose->eyeL_y, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeL, 220, 0, lv_obj_get_width(guider_ui.Speaking_eyeL), pose->eyeL_w, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeL, 220, 0, lv_obj_get_height(guider_ui.Speaking_eyeL), pose->eyeL_h, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
    lv_obj_set_style_bg_color(guider_ui.Speaking_eyeL, lv_color_hex(pose->eyeL_color_hex), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_animation(guider_ui.Speaking_eyeR, 220, 0, lv_obj_get_x(guider_ui.Speaking_eyeR), pose->eyeR_x, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeR, 220, 0, lv_obj_get_y(guider_ui.Speaking_eyeR), pose->eyeR_y, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeR, 220, 0, lv_obj_get_width(guider_ui.Speaking_eyeR), pose->eyeR_w, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
    ui_animation(guider_ui.Speaking_eyeR, 220, 0, lv_obj_get_height(guider_ui.Speaking_eyeR), pose->eyeR_h, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
    lv_obj_set_style_bg_color(guider_ui.Speaking_eyeR, lv_color_hex(pose->eyeR_color_hex), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_animation(eyebowL_obj, 220, 0, lv_obj_get_x(eyebowL_obj), pose->browL_x, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
    ui_animation(eyebowL_obj, 220, 0, lv_obj_get_y(eyebowL_obj), pose->browL_y, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
    ui_animation(eyebowL_obj, 220, 0, lv_obj_get_width(eyebowL_obj), pose->browL_w, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
    ui_animation(eyebowL_obj, 220, 0, lv_obj_get_height(eyebowL_obj), pose->browL_h, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
    lv_obj_set_style_line_color(eyebowL_obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_animation(eyebowR_obj, 220, 0, lv_obj_get_x(eyebowR_obj), pose->browR_x, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
    ui_animation(eyebowR_obj, 220, 0, lv_obj_get_y(eyebowR_obj), pose->browR_y, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
    ui_animation(eyebowR_obj, 220, 0, lv_obj_get_width(eyebowR_obj), pose->browR_w, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
    ui_animation(eyebowR_obj, 220, 0, lv_obj_get_height(eyebowR_obj), pose->browR_h, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
    lv_obj_set_style_line_color(eyebowR_obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    ResetFocusClock();
    PRINTF("switch to FOCUS");
    robot.Facestatus = 4;
    robot.speakstatus = 3;
}

static const char *SkipSpaces(const char *p)
{
    while (p != NULL && (*p == ' ' || *p == '\t')) {
        p++;
    }
    return p;
}

static bool ParseWeatherIntField(const char **cursor, int *out_value, bool require_comma)
{
    char *end = NULL;
    long value = 0;
    const char *p = SkipSpaces(*cursor);

    if (p == NULL || out_value == NULL || *p == '\0') {
        return false;
    }

    value = strtol(p, &end, 10);
    if (end == p) {
        return false;
    }

    p = SkipSpaces(end);
    if (require_comma) {
        if (*p != ',') {
            return false;
        }
        p++;
    }

    *out_value = (int)value;
    *cursor = p;
    return true;
}

static bool ParseWeatherCommand(const char *pValue,
                                char *kind,
                                size_t kind_size,
                                int *value_1,
                                int *value_2,
                                int *rain_percent,
                                int *weather_code)
{
    const char *p = SkipSpaces(pValue);
    size_t kind_len = 0;

    if (p == NULL || kind == NULL || kind_size == 0U ||
        value_1 == NULL || value_2 == NULL || rain_percent == NULL || weather_code == NULL) {
        return false;
    }

    while (*p != '\0' && *p != ',' && *p != ' ' && *p != '\t') {
        if (kind_len + 1U < kind_size) {
            kind[kind_len++] = *p;
        }
        p++;
    }
    kind[kind_len] = '\0';

    p = SkipSpaces(p);
    if (kind_len == 0U || *p != ',') {
        return false;
    }
    p++;

    if (!ParseWeatherIntField(&p, value_1, true)) {
        return false;
    }
    if (!ParseWeatherIntField(&p, value_2, true)) {
        return false;
    }
    if (!ParseWeatherIntField(&p, rain_percent, true)) {
        return false;
    }
    if (!ParseWeatherIntField(&p, weather_code, false)) {
        return false;
    }

    return true;
}

void WeatherControl(char* pValue)
{
    char kind[10];
    int value_1 = 0;
    int value_2 = 0;
    int rain_percent = 0;
    int weather_code = 0;

    PRINTF("Weather raw pValue = [%s]\r\n", pValue ? pValue : "(null)");

    if (!ParseWeatherCommand(pValue, kind, sizeof(kind), &value_1, &value_2, &rain_percent, &weather_code)) {
        PRINTF("Weather parse failed, use: Weather daily,<low>,<high>,<rain>,<code>\r\n");
        PRINTF("                       or: Weather current,<temp>,<temp>,<rain>,<code>\r\n");
        return;
    }

    rain_percent = ClampInt(rain_percent, 0, 100);

    if (strcmp(kind, "daily") == 0) {
        s_weather_status.daily_low = value_1;
        s_weather_status.daily_high = value_2;
        s_weather_status.daily_valid = true;
    } else if (strcmp(kind, "current") == 0) {
        s_weather_status.current_temp = value_1;
        s_weather_status.current_valid = true;
    } else {
        PRINTF("Weather kind unknown: %s\r\n", kind);
        return;
    }

    s_weather_status.rain_percent = rain_percent;
    s_weather_status.weather_code = weather_code;
    s_weather_status.rain_valid = true;
    s_weather_status.code_valid = true;
    s_weather_dirty = true;

    PRINTF("Weather %s value1=%d value2=%d rain=%d code=%d\r\n",
           kind, value_1, value_2, rain_percent, weather_code);
    WeatherApplyStateToUi();
}

static bool ParseMotorAngle(const char *pValue, int *out_angle)
{
    int angle = 0;

    if (pValue == NULL || out_angle == NULL) {
        return false;
    }

    // 支援 pValue = "90" 或 pValue = "MotorYaw 90"
    if (sscanf(pValue, " %d", &angle) == 1 ||
        sscanf(pValue, " %*s %d", &angle) == 1) {
        *out_angle = angle;
        return true;
    }

    return false;
}

static bool ParseMotorYawPitchAngles(const char *pValue, int *out_yaw, int *out_pitch)
{
    const char *p = pValue;
    char *end = NULL;
    long values[2] = {0};
    int count = 0;

    if (pValue == NULL || out_yaw == NULL || out_pitch == NULL) {
        return false;
    }

    while (*p != '\0' && count < 2) {
        while (*p != '\0' && !isdigit((unsigned char)*p) && *p != '-' && *p != '+') {
            p++;
        }

        if (*p == '\0') {
            break;
        }

        values[count] = strtol(p, &end, 10);
        if (end == p) {
            return false;
        }

        count++;
        p = end;
    }

    if (count < 2) {
        return false;
    }

    *out_yaw = (int)values[0];
    *out_pitch = (int)values[1];
    return true;
}

void MotorControlPitch(char* pValue)
{
    int value = 90;

    PRINTF("Motor Pitch raw pValue = [%s]\r\n", pValue ? pValue : "(null)");

    if (!ParseMotorAngle(pValue, &value)) {
        PRINTF("Motor Pitch parse failed\r\n");
        return;
    }

    if (value < 65) value = 65;
    if (value > 115) value = 115;

    robot.motorP = value;
    PRINTF("Motor Pitch = %d\r\n", value);
    Servo_SetPitch(value);
}

void MotorControlYaw(char* pValue)
{
    int value = 90;

    PRINTF("Motor Yaw raw pValue = [%s]\r\n", pValue ? pValue : "(null)");

    if (!ParseMotorAngle(pValue, &value)) {
        PRINTF("Motor Yaw parse failed\r\n");
        return;
    }

    if (value < 0) value = 0;
    if (value > 180) value = 180;

    robot.motorY = value;
    PRINTF("Motor Yaw = %d\r\n", value);
    Servo_SetYaw(value);
}

void MotorControlYawPitch(char* pValue)
{
    int yaw = 90;
    int pitch = 90;

    PRINTF("Motor YawPitch raw pValue = [%s]\r\n", pValue ? pValue : "(null)");

    if (!ParseMotorYawPitchAngles(pValue, &yaw, &pitch)) {
        PRINTF("Motor YawPitch parse failed, use: MotorYawPitch <yaw> <pitch>\r\n");
        return;
    }

    if (yaw < 0) yaw = 0;
    if (yaw > 180) yaw = 180;
    if (pitch < 65) pitch = 65;
    if (pitch > 115) pitch = 115;

    robot.motorY = yaw;
    robot.motorP = pitch;
    PRINTF("Motor Yaw = %d, Pitch = %d\r\n", yaw, pitch);
    Servo_SetYaw(yaw);
    Servo_SetPitch(pitch);
}

void ShowNumber(char* pValue)
{
	unsigned int value=0;
    if (pValue != NULL)
    {
        sscanf(pValue, "%u", &value);
    }
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
    {  "Weather",    "<kind>,<temp>,<temp>,<rain>,<code>",     "update weather data",     WeatherControl },
	{  "MotorPitch",    "<var 1> <var 2>",     "control motor P",      MotorControlPitch},
	{  "MotorYaw",    "<var 1> <var 2>",     "control motor Y",      MotorControlYaw},
	{  "MotorYawPitch",    "<yaw> <pitch>",     "control motor Y and P",      MotorControlYawPitch},
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
