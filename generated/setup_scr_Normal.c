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



void setup_scr_Normal(lv_ui *ui)
{
    //Write codes Normal
    ui->Normal = lv_obj_create(NULL);
    lv_obj_set_size(ui->Normal, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Normal, LV_SCROLLBAR_MODE_OFF);

    //Write style for Normal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Normal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Normal, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Normal, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_eyeR
    ui->Normal_eyeR = lv_btn_create(ui->Normal);
    ui->Normal_eyeR_label = lv_label_create(ui->Normal_eyeR);
    lv_label_set_text(ui->Normal_eyeR_label, "");
    lv_label_set_long_mode(ui->Normal_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Normal_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Normal_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Normal_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Normal_eyeR, 275, 85);
    lv_obj_set_size(ui->Normal_eyeR, 80, 130);

    //Write style for Normal_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Normal_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Normal_eyeR, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Normal_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Normal_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Normal_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Normal_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Normal_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Normal_eyeR, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Normal_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Normal_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_eyeL
    ui->Normal_eyeL = lv_btn_create(ui->Normal);
    ui->Normal_eyeL_label = lv_label_create(ui->Normal_eyeL);
    lv_label_set_text(ui->Normal_eyeL_label, "");
    lv_label_set_long_mode(ui->Normal_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Normal_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Normal_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Normal_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Normal_eyeL, 125, 85);
    lv_obj_set_size(ui->Normal_eyeL, 80, 130);

    //Write style for Normal_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Normal_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Normal_eyeL, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Normal_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Normal_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Normal_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Normal_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Normal_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Normal_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Normal_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Normal_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_relieve
    ui->Normal_relieve = lv_btn_create(ui->Normal);
    ui->Normal_relieve_label = lv_label_create(ui->Normal_relieve);
    lv_label_set_text(ui->Normal_relieve_label, "");
    lv_label_set_long_mode(ui->Normal_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Normal_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Normal_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Normal_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Normal_relieve, 11, 222);
    lv_obj_set_size(ui->Normal_relieve, 458, 92);

    //Write style for Normal_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Normal_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Normal_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Normal_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Normal_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Normal_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Normal_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Normal_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Normal_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_mouth
    ui->Normal_mouth = lv_btn_create(ui->Normal);
    ui->Normal_mouth_label = lv_label_create(ui->Normal_mouth);
    lv_label_set_text(ui->Normal_mouth_label, "");
    lv_label_set_long_mode(ui->Normal_mouth_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Normal_mouth_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Normal_mouth, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Normal_mouth_label, LV_PCT(100));
    lv_obj_set_pos(ui->Normal_mouth, 220, 240);
    lv_obj_set_size(ui->Normal_mouth, 40, 12);

    //Write style for Normal_mouth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Normal_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Normal_mouth, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Normal_mouth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Normal_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Normal_mouth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Normal_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Normal_mouth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Normal_mouth, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Normal_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Normal_mouth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_eyebowR
    ui->Normal_eyebowR = lv_line_create(ui->Normal);
    static lv_point_t Normal_eyebowR[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Normal_eyebowR, Normal_eyebowR, 2);
    lv_obj_set_pos(ui->Normal_eyebowR, 286, 64);
    lv_obj_set_size(ui->Normal_eyebowR, 109, 62);

    //Write style for Normal_eyebowR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Normal_eyebowR, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Normal_eyebowR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Normal_eyebowR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Normal_eyebowR, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Normal_eyebowL
    ui->Normal_eyebowL = lv_line_create(ui->Normal);
    static lv_point_t Normal_eyebowL[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Normal_eyebowL, Normal_eyebowL, 2);
    lv_obj_set_pos(ui->Normal_eyebowL, 135, 66);
    lv_obj_set_size(ui->Normal_eyebowL, 127, 47);

    //Write style for Normal_eyebowL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Normal_eyebowL, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Normal_eyebowL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Normal_eyebowL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Normal_eyebowL, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Normal.


    //Update current screen layout.
    lv_obj_update_layout(ui->Normal);

    //Init events for screen.
    events_init_Normal(ui);
}
