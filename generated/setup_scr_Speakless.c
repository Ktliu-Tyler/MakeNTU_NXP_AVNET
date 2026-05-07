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



void setup_scr_Speakless(lv_ui *ui)
{
    //Write codes Speakless
    ui->Speakless = lv_obj_create(NULL);
    lv_obj_set_size(ui->Speakless, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Speakless, LV_SCROLLBAR_MODE_OFF);

    //Write style for Speakless, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_eyeL
    ui->Speakless_eyeL = lv_btn_create(ui->Speakless);
    ui->Speakless_eyeL_label = lv_label_create(ui->Speakless_eyeL);
    lv_label_set_text(ui->Speakless_eyeL_label, "");
    lv_label_set_long_mode(ui->Speakless_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_eyeL, 125, 151);
    lv_obj_set_size(ui->Speakless_eyeL, 80, 15);

    //Write style for Speakless_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless_eyeL, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_relieve
    ui->Speakless_relieve = lv_btn_create(ui->Speakless);
    ui->Speakless_relieve_label = lv_label_create(ui->Speakless_relieve);
    lv_label_set_text(ui->Speakless_relieve_label, "");
    lv_label_set_long_mode(ui->Speakless_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_relieve, 13, 223);
    lv_obj_set_size(ui->Speakless_relieve, 458, 92);

    //Write style for Speakless_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_mouth
    ui->Speakless_mouth = lv_btn_create(ui->Speakless);
    ui->Speakless_mouth_label = lv_label_create(ui->Speakless_mouth);
    lv_label_set_text(ui->Speakless_mouth_label, "");
    lv_label_set_long_mode(ui->Speakless_mouth_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_mouth_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_mouth, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_mouth_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_mouth, 220, 206);
    lv_obj_set_size(ui->Speakless_mouth, 40, 43);

    //Write style for Speakless_mouth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless_mouth, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless_mouth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_mouth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_mouth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_mouth, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_mouth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_btn_1
    ui->Speakless_btn_1 = lv_btn_create(ui->Speakless);
    ui->Speakless_btn_1_label = lv_label_create(ui->Speakless_btn_1);
    lv_label_set_text(ui->Speakless_btn_1_label, "");
    lv_label_set_long_mode(ui->Speakless_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_btn_1, 125, 171);
    lv_obj_set_size(ui->Speakless_btn_1, 80, 15);

    //Write style for Speakless_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_btn_3
    ui->Speakless_btn_3 = lv_btn_create(ui->Speakless);
    ui->Speakless_btn_3_label = lv_label_create(ui->Speakless_btn_3);
    lv_label_set_text(ui->Speakless_btn_3_label, "");
    lv_label_set_long_mode(ui->Speakless_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_btn_3, 275, 150);
    lv_obj_set_size(ui->Speakless_btn_3, 80, 15);

    //Write style for Speakless_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speakless_btn_2
    ui->Speakless_btn_2 = lv_btn_create(ui->Speakless);
    ui->Speakless_btn_2_label = lv_label_create(ui->Speakless_btn_2);
    lv_label_set_text(ui->Speakless_btn_2_label, "");
    lv_label_set_long_mode(ui->Speakless_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speakless_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speakless_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speakless_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speakless_btn_2, 275, 171);
    lv_obj_set_size(ui->Speakless_btn_2, 80, 15);

    //Write style for Speakless_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speakless_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speakless_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speakless_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speakless_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speakless_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speakless_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speakless_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speakless_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speakless_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speakless_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Speakless.


    //Update current screen layout.
    lv_obj_update_layout(ui->Speakless);

}
