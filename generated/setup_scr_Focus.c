/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int Focus_digital_clock_Focus_min_value = 0;
int Focus_digital_clock_Focus_hour_value = 0;
int Focus_digital_clock_Focus_sec_value = 0;
void setup_scr_Focus(lv_ui *ui)
{
    //Write codes Focus
    ui->Focus = lv_obj_create(NULL);
    lv_obj_set_size(ui->Focus, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Focus, LV_SCROLLBAR_MODE_OFF);

    //Write style for Focus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Focus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Focus, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Focus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_eyeR
    ui->Focus_eyeR = lv_btn_create(ui->Focus);
    ui->Focus_eyeR_label = lv_label_create(ui->Focus_eyeR);
    lv_label_set_text(ui->Focus_eyeR_label, "");
    lv_label_set_long_mode(ui->Focus_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Focus_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Focus_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Focus_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Focus_eyeR, 275, 85);
    lv_obj_set_size(ui->Focus_eyeR, 80, 130);

    //Write style for Focus_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Focus_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Focus_eyeR, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Focus_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Focus_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Focus_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Focus_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Focus_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Focus_eyeR, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Focus_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Focus_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_eyeL
    ui->Focus_eyeL = lv_btn_create(ui->Focus);
    ui->Focus_eyeL_label = lv_label_create(ui->Focus_eyeL);
    lv_label_set_text(ui->Focus_eyeL_label, "");
    lv_label_set_long_mode(ui->Focus_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Focus_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Focus_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Focus_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Focus_eyeL, 125, 85);
    lv_obj_set_size(ui->Focus_eyeL, 80, 130);

    //Write style for Focus_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Focus_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Focus_eyeL, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Focus_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Focus_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Focus_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Focus_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Focus_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Focus_eyeL, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Focus_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Focus_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_relieve
    ui->Focus_relieve = lv_btn_create(ui->Focus);
    ui->Focus_relieve_label = lv_label_create(ui->Focus_relieve);
    lv_label_set_text(ui->Focus_relieve_label, "");
    lv_label_set_long_mode(ui->Focus_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Focus_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Focus_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Focus_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Focus_relieve, 11, 219);
    lv_obj_set_size(ui->Focus_relieve, 458, 92);

    //Write style for Focus_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Focus_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Focus_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Focus_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Focus_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Focus_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Focus_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Focus_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Focus_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_mouth
    ui->Focus_mouth = lv_btn_create(ui->Focus);
    ui->Focus_mouth_label = lv_label_create(ui->Focus_mouth);
    lv_label_set_text(ui->Focus_mouth_label, "");
    lv_label_set_long_mode(ui->Focus_mouth_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Focus_mouth_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Focus_mouth, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Focus_mouth_label, LV_PCT(100));
    lv_obj_set_pos(ui->Focus_mouth, 220, 240);
    lv_obj_set_size(ui->Focus_mouth, 40, 15);

    //Write style for Focus_mouth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Focus_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Focus_mouth, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Focus_mouth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Focus_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Focus_mouth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Focus_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Focus_mouth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Focus_mouth, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Focus_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Focus_mouth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_line_2
    ui->Focus_line_2 = lv_line_create(ui->Focus);
    static lv_point_t Focus_line_2[] = {{100, 20},{0, 0},};
    lv_line_set_points(ui->Focus_line_2, Focus_line_2, 2);
    lv_obj_set_pos(ui->Focus_line_2, 115, 76);
    lv_obj_set_size(ui->Focus_line_2, 109, 62);

    //Write style for Focus_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Focus_line_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Focus_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Focus_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Focus_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_line_1
    ui->Focus_line_1 = lv_line_create(ui->Focus);
    static lv_point_t Focus_line_1[] = {{100, 0},{0, 20},};
    lv_line_set_points(ui->Focus_line_1, Focus_line_1, 2);
    lv_obj_set_pos(ui->Focus_line_1, 266, 76);
    lv_obj_set_size(ui->Focus_line_1, 115, 51);

    //Write style for Focus_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Focus_line_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Focus_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Focus_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Focus_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Focus_digital_clock_Focus
    static bool Focus_digital_clock_Focus_timer_enabled = false;
    ui->Focus_digital_clock_Focus = lv_dclock_create(ui->Focus, "0:00:00");
    if (!Focus_digital_clock_Focus_timer_enabled) {
        lv_timer_create(Focus_digital_clock_Focus_timer, 1000, NULL);
        Focus_digital_clock_Focus_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Focus_digital_clock_Focus, 176, 24);
    lv_obj_set_size(ui->Focus_digital_clock_Focus, 134, 43);

    //Write style for Focus_digital_clock_Focus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Focus_digital_clock_Focus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Focus_digital_clock_Focus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Focus_digital_clock_Focus, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Focus_digital_clock_Focus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Focus_digital_clock_Focus, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Focus_digital_clock_Focus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Focus_digital_clock_Focus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Focus_digital_clock_Focus, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Focus_digital_clock_Focus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Focus_digital_clock_Focus, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Focus_digital_clock_Focus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Focus_digital_clock_Focus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Focus_digital_clock_Focus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Focus_digital_clock_Focus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Focus.


    //Update current screen layout.
    lv_obj_update_layout(ui->Focus);

    //Init events for screen.
    events_init_Focus(ui);
}
