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



void setup_scr_Thinking(lv_ui *ui)
{
    //Write codes Thinking
    ui->Thinking = lv_obj_create(NULL);
    lv_obj_set_size(ui->Thinking, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Thinking, LV_SCROLLBAR_MODE_OFF);

    //Write style for Thinking, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_eyeL
    ui->Thinking_eyeL = lv_btn_create(ui->Thinking);
    ui->Thinking_eyeL_label = lv_label_create(ui->Thinking_eyeL);
    lv_label_set_text(ui->Thinking_eyeL_label, "");
    lv_label_set_long_mode(ui->Thinking_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_eyeL, 125, 135);
    lv_obj_set_size(ui->Thinking_eyeL, 80, 50);

    //Write style for Thinking_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_eyeL, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_relieve
    ui->Thinking_relieve = lv_btn_create(ui->Thinking);
    ui->Thinking_relieve_label = lv_label_create(ui->Thinking_relieve);
    lv_label_set_text(ui->Thinking_relieve_label, "");
    lv_label_set_long_mode(ui->Thinking_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_relieve, 13, 223);
    lv_obj_set_size(ui->Thinking_relieve, 458, 92);

    //Write style for Thinking_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_mouth
    ui->Thinking_mouth = lv_btn_create(ui->Thinking);
    ui->Thinking_mouth_label = lv_label_create(ui->Thinking_mouth);
    lv_label_set_text(ui->Thinking_mouth_label, "");
    lv_label_set_long_mode(ui->Thinking_mouth_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_mouth_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_mouth, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_mouth_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_mouth, 220, 210);
    lv_obj_set_size(ui->Thinking_mouth, 40, 20);

    //Write style for Thinking_mouth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_mouth, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_mouth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_mouth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_mouth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_mouth, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_mouth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_eyeR
    ui->Thinking_eyeR = lv_btn_create(ui->Thinking);
    ui->Thinking_eyeR_label = lv_label_create(ui->Thinking_eyeR);
    lv_label_set_text(ui->Thinking_eyeR_label, "");
    lv_label_set_long_mode(ui->Thinking_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_eyeR, 275, 150);
    lv_obj_set_size(ui->Thinking_eyeR, 80, 30);

    //Write style for Thinking_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_eyeR, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_eyeR, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_spinner_1
    ui->Thinking_spinner_1 = lv_spinner_create(ui->Thinking, 1000, 60);
    lv_obj_set_pos(ui->Thinking_spinner_1, 205, 31);
    lv_obj_set_size(ui->Thinking_spinner_1, 77, 81);
    lv_obj_add_flag(ui->Thinking_spinner_1, LV_OBJ_FLAG_HIDDEN);

    //Write style for Thinking_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->Thinking_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Thinking_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Thinking_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Thinking_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Thinking_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_spinner_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_spinner_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Thinking_spinner_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Thinking_spinner_1, 254, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Thinking_spinner_1, lv_color_hex(0xd5d6de), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Thinking_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Thinking_spinner_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Thinking_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Thinking_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Thinking_btn_1
    ui->Thinking_btn_1 = lv_btn_create(ui->Thinking);
    ui->Thinking_btn_1_label = lv_label_create(ui->Thinking_btn_1);
    lv_label_set_text(ui->Thinking_btn_1_label, "");
    lv_label_set_long_mode(ui->Thinking_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_btn_1, 170, 60);
    lv_obj_set_size(ui->Thinking_btn_1, 20, 16);

    //Write style for Thinking_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_btn_1, lv_color_hex(0xc9f6fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_btn_2
    ui->Thinking_btn_2 = lv_btn_create(ui->Thinking);
    ui->Thinking_btn_2_label = lv_label_create(ui->Thinking_btn_2);
    lv_label_set_text(ui->Thinking_btn_2_label, "");
    lv_label_set_long_mode(ui->Thinking_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_btn_2, 230, 60);
    lv_obj_set_size(ui->Thinking_btn_2, 20, 16);

    //Write style for Thinking_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_btn_2, lv_color_hex(0xc9f6fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_btn_3
    ui->Thinking_btn_3 = lv_btn_create(ui->Thinking);
    ui->Thinking_btn_3_label = lv_label_create(ui->Thinking_btn_3);
    lv_label_set_text(ui->Thinking_btn_3_label, "");
    lv_label_set_long_mode(ui->Thinking_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Thinking_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Thinking_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Thinking_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Thinking_btn_3, 290, 60);
    lv_obj_set_size(ui->Thinking_btn_3, 20, 16);

    //Write style for Thinking_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Thinking_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Thinking_btn_3, lv_color_hex(0xc9f6fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Thinking_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Thinking_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Thinking_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Thinking_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Thinking_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Thinking_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Thinking_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Thinking_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_eyebowR
    ui->Thinking_eyebowR = lv_line_create(ui->Thinking);
    static lv_point_t Thinking_eyebowR[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Thinking_eyebowR, Thinking_eyebowR, 2);
    lv_obj_set_pos(ui->Thinking_eyebowR, 285, 130);
    lv_obj_set_size(ui->Thinking_eyebowR, 109, 62);

    //Write style for Thinking_eyebowR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Thinking_eyebowR, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Thinking_eyebowR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Thinking_eyebowR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Thinking_eyebowR, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Thinking_eyebowL
    ui->Thinking_eyebowL = lv_line_create(ui->Thinking);
    static lv_point_t Thinking_eyebowL[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Thinking_eyebowL, Thinking_eyebowL, 2);
    lv_obj_set_pos(ui->Thinking_eyebowL, 135, 110);
    lv_obj_set_size(ui->Thinking_eyebowL, 127, 47);

    //Write style for Thinking_eyebowL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Thinking_eyebowL, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Thinking_eyebowL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Thinking_eyebowL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Thinking_eyebowL, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Thinking.


    //Update current screen layout.
    lv_obj_update_layout(ui->Thinking);

    //Init events for screen.
    events_init_Thinking(ui);
}
