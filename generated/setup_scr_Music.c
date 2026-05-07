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



void setup_scr_Music(lv_ui *ui)
{
    //Write codes Music
    ui->Music = lv_obj_create(NULL);
    lv_obj_set_size(ui->Music, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Music, LV_SCROLLBAR_MODE_OFF);

    //Write style for Music, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Music, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Music, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Music, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_eyeR
    ui->Music_eyeR = lv_btn_create(ui->Music);
    ui->Music_eyeR_label = lv_label_create(ui->Music_eyeR);
    lv_label_set_text(ui->Music_eyeR_label, "");
    lv_label_set_long_mode(ui->Music_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Music_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Music_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Music_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Music_eyeR, 277, 105);
    lv_obj_set_size(ui->Music_eyeR, 71, 89);

    //Write style for Music_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Music_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Music_eyeR, lv_color_hex(0xf2ea06), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Music_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Music_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Music_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Music_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Music_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Music_eyeR, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Music_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Music_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_eyeL
    ui->Music_eyeL = lv_btn_create(ui->Music);
    ui->Music_eyeL_label = lv_label_create(ui->Music_eyeL);
    lv_label_set_text(ui->Music_eyeL_label, "");
    lv_label_set_long_mode(ui->Music_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Music_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Music_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Music_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Music_eyeL, 139, 105);
    lv_obj_set_size(ui->Music_eyeL, 70, 90);

    //Write style for Music_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Music_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Music_eyeL, lv_color_hex(0xf2ea06), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Music_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Music_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Music_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Music_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Music_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Music_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Music_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Music_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_relieve
    ui->Music_relieve = lv_btn_create(ui->Music);
    ui->Music_relieve_label = lv_label_create(ui->Music_relieve);
    lv_label_set_text(ui->Music_relieve_label, "");
    lv_label_set_long_mode(ui->Music_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Music_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Music_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Music_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Music_relieve, 11, 221);
    lv_obj_set_size(ui->Music_relieve, 458, 92);

    //Write style for Music_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Music_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Music_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Music_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Music_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Music_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Music_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Music_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Music_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_line_2
    ui->Music_line_2 = lv_line_create(ui->Music);
    static lv_point_t Music_line_2[] = {{60, 0},{0, 4},};
    lv_line_set_points(ui->Music_line_2, Music_line_2, 2);
    lv_obj_set_pos(ui->Music_line_2, 283, 79);
    lv_obj_set_size(ui->Music_line_2, 115, 51);

    //Write style for Music_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Music_line_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Music_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Music_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Music_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_line_1
    ui->Music_line_1 = lv_line_create(ui->Music);
    static lv_point_t Music_line_1[] = {{60, 4},{0, 0},};
    lv_line_set_points(ui->Music_line_1, Music_line_1, 2);
    lv_obj_set_pos(ui->Music_line_1, 147, 79);
    lv_obj_set_size(ui->Music_line_1, 109, 62);

    //Write style for Music_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Music_line_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Music_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Music_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Music_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Music_label_1
    ui->Music_label_1 = lv_label_create(ui->Music);
    lv_label_set_text(ui->Music_label_1, "3");
    lv_label_set_long_mode(ui->Music_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Music_label_1, 194, 211);
    lv_obj_set_size(ui->Music_label_1, 100, 32);

    //Write style for Music_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Music_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Music_label_1, &lv_font_Amiko_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Music_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Music_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Music_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Music_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Music.


    //Update current screen layout.
    lv_obj_update_layout(ui->Music);

}
