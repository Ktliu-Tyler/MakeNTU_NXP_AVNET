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



void setup_scr_Sleep(lv_ui *ui)
{
    //Write codes Sleep
    ui->Sleep = lv_obj_create(NULL);
    lv_obj_set_size(ui->Sleep, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Sleep, LV_SCROLLBAR_MODE_OFF);

    //Write style for Sleep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Sleep, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Sleep, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Sleep, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Sleep_eyeR
    ui->Sleep_eyeR = lv_btn_create(ui->Sleep);
    ui->Sleep_eyeR_label = lv_label_create(ui->Sleep_eyeR);
    lv_label_set_text(ui->Sleep_eyeR_label, "");
    lv_label_set_long_mode(ui->Sleep_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Sleep_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Sleep_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Sleep_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Sleep_eyeR, 275, 150);
    lv_obj_set_size(ui->Sleep_eyeR, 80, 12);

    //Write style for Sleep_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Sleep_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Sleep_eyeR, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Sleep_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Sleep_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Sleep_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Sleep_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Sleep_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Sleep_eyeR, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Sleep_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Sleep_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Sleep_eyeL
    ui->Sleep_eyeL = lv_btn_create(ui->Sleep);
    ui->Sleep_eyeL_label = lv_label_create(ui->Sleep_eyeL);
    lv_label_set_text(ui->Sleep_eyeL_label, "");
    lv_label_set_long_mode(ui->Sleep_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Sleep_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Sleep_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Sleep_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Sleep_eyeL, 120, 150);
    lv_obj_set_size(ui->Sleep_eyeL, 80, 12);

    //Write style for Sleep_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Sleep_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Sleep_eyeL, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Sleep_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Sleep_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Sleep_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Sleep_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Sleep_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Sleep_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Sleep_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Sleep_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Sleep_ZZZ2
    ui->Sleep_ZZZ2 = lv_label_create(ui->Sleep);
    lv_label_set_text(ui->Sleep_ZZZ2, "Z Z ");
    lv_label_set_long_mode(ui->Sleep_ZZZ2, LV_LABEL_LONG_CLIP);
    lv_obj_set_pos(ui->Sleep_ZZZ2, 372, 67);
    lv_obj_set_size(ui->Sleep_ZZZ2, 91, 29);

    //Write style for Sleep_ZZZ2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Sleep_ZZZ2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Sleep_ZZZ2, &lv_font_Alatsi_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Sleep_ZZZ2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Sleep_ZZZ2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Sleep_ZZZ2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Sleep_ZZZ2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Sleep_ZZZ1
    ui->Sleep_ZZZ1 = lv_label_create(ui->Sleep);
    lv_label_set_text(ui->Sleep_ZZZ1, "Z ");
    lv_label_set_long_mode(ui->Sleep_ZZZ1, LV_LABEL_LONG_CLIP);
    lv_obj_set_pos(ui->Sleep_ZZZ1, 345, 93);
    lv_obj_set_size(ui->Sleep_ZZZ1, 73, 36);

    //Write style for Sleep_ZZZ1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Sleep_ZZZ1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Sleep_ZZZ1, &lv_font_Alatsi_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Sleep_ZZZ1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Sleep_ZZZ1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Sleep_ZZZ1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Sleep_ZZZ1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Sleep_btn_1
    ui->Sleep_btn_1 = lv_btn_create(ui->Sleep);
    ui->Sleep_btn_1_label = lv_label_create(ui->Sleep_btn_1);
    lv_label_set_text(ui->Sleep_btn_1_label, "");
    lv_label_set_long_mode(ui->Sleep_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Sleep_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Sleep_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Sleep_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Sleep_btn_1, 187, 205);
    lv_obj_set_size(ui->Sleep_btn_1, 40, 20);

    //Write style for Sleep_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Sleep_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Sleep_btn_1, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Sleep_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Sleep_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Sleep_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Sleep_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Sleep_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Sleep_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Sleep_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Sleep_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Sleep.


    //Update current screen layout.
    lv_obj_update_layout(ui->Sleep);

    //Init events for screen.
    events_init_Sleep(ui);
}
