/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

#ifndef LV_USE_GUIDER_SIMULATOR
#define LV_USE_GUIDER_SIMULATOR 0
#endif

#if !LV_USE_GUIDER_SIMULATOR
#include "Monitor.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_obj_t *s_bound_panel_btn_1 = NULL;
static lv_obj_t *s_bound_panel_btn_2 = NULL;
static lv_timer_t *s_custom_timer = NULL;

/**
 * Create a demo application
 */

static int custom_append_u32(char *buffer, int index, int buffer_size, uint32_t value)
{
    char digits[10];
    int digit_count = 0;

    do {
        digits[digit_count++] = (char)('0' + (value % 10U));
        value /= 10U;
    } while (value != 0U && digit_count < (int)sizeof(digits));

    while (digit_count > 0 && index < buffer_size) {
        buffer[index++] = digits[--digit_count];
    }

    return index;
}

static void custom_uart_send(const char *data, int len)
{
    if (data == NULL || len <= 0) {
        return;
    }

#if LV_USE_GUIDER_SIMULATOR
    fwrite(data, 1, (size_t)len, stdout);
    fflush(stdout);
#else
    UartSend(data, len);
#endif
}

static void custom_send_fan_speed(int32_t speed)
{
    static const char prefix[] = "Fanspeed ";
    char command[24];
    int len = 0;
    int i = 0;

    if (speed < 0) {
        speed = 0;
    } else if (speed > 100) {
        speed = 100;
    }

    for (i = 0; prefix[i] != '\0' && len < (int)sizeof(command); i++) {
        command[len++] = prefix[i];
    }

    len = custom_append_u32(command, len, (int)sizeof(command), (uint32_t)speed);

    if (len + 2 <= (int)sizeof(command)) {
        command[len++] = '\r';
        command[len++] = '\n';
        custom_uart_send(command, len);
    }
}

static void custom_process_timer_cb(lv_timer_t *timer)
{
    custom_process((lv_ui *)timer->user_data);
}

static void custom_panel_btn_1_event_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if (ui == NULL) {
        ui = &guider_ui;
    }

    if (ui->Panel_Fan_slide != NULL && lv_obj_is_valid(ui->Panel_Fan_slide)) {
        custom_send_fan_speed(lv_slider_get_value(ui->Panel_Fan_slide));
    }
}

static void custom_panel_btn_2_event_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if (ui == NULL) {
        ui = &guider_ui;
    }

    custom_send_fan_speed(0);

    if (ui->Panel_Fan_slide != NULL && lv_obj_is_valid(ui->Panel_Fan_slide)) {
        lv_slider_set_value(ui->Panel_Fan_slide, 0, LV_ANIM_OFF);
    }
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    (void)ui;
    s_bound_panel_btn_1 = NULL;
    s_bound_panel_btn_2 = NULL;

    if (s_custom_timer == NULL) {
        s_custom_timer = lv_timer_create(custom_process_timer_cb, 50, ui);
    }
}

void custom_process(lv_ui *ui)
{
    if (ui == NULL) {
        return;
    }

    if (ui->Panel == NULL || !lv_obj_is_valid(ui->Panel) || lv_scr_act() != ui->Panel) {
        s_bound_panel_btn_1 = NULL;
        s_bound_panel_btn_2 = NULL;
        return;
    }

    if (ui->Panel_Fan_slide == NULL || !lv_obj_is_valid(ui->Panel_Fan_slide)) {
        return;
    }

    if (ui->Panel_btn_1 != NULL && lv_obj_is_valid(ui->Panel_btn_1) &&
        s_bound_panel_btn_1 != ui->Panel_btn_1) {
        lv_obj_add_event_cb(ui->Panel_btn_1, custom_panel_btn_1_event_handler, LV_EVENT_CLICKED, ui);
        s_bound_panel_btn_1 = ui->Panel_btn_1;
    }

    if (ui->Panel_btn_2 != NULL && lv_obj_is_valid(ui->Panel_btn_2) &&
        s_bound_panel_btn_2 != ui->Panel_btn_2) {
        lv_obj_add_event_cb(ui->Panel_btn_2, custom_panel_btn_2_event_handler, LV_EVENT_CLICKED, ui);
        s_bound_panel_btn_2 = ui->Panel_btn_2;
    }
}
