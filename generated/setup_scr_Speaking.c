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



void setup_scr_Speaking(lv_ui *ui)
{
    //Write codes Speaking
    ui->Speaking = lv_obj_create(NULL);
    lv_obj_set_size(ui->Speaking, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Speaking, LV_SCROLLBAR_MODE_OFF);

    //Write style for Speaking, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR
    ui->Speaking_eyeR = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR_label = lv_label_create(ui->Speaking_eyeR);
    lv_label_set_text(ui->Speaking_eyeR_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR, 275, 85);
    lv_obj_set_size(ui->Speaking_eyeR, 80, 130);

    //Write style for Speaking_eyeR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL
    ui->Speaking_eyeL = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL_label = lv_label_create(ui->Speaking_eyeL);
    lv_label_set_text(ui->Speaking_eyeL_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL, 125, 85);
    lv_obj_set_size(ui->Speaking_eyeL, 80, 130);

    //Write style for Speaking_eyeL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_relieve
    ui->Speaking_relieve = lv_btn_create(ui->Speaking);
    ui->Speaking_relieve_label = lv_label_create(ui->Speaking_relieve);
    lv_label_set_text(ui->Speaking_relieve_label, "");
    lv_label_set_long_mode(ui->Speaking_relieve_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_relieve_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_relieve, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_relieve_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_relieve, 18, 219);
    lv_obj_set_size(ui->Speaking_relieve, 458, 92);

    //Write style for Speaking_relieve, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_relieve, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_relieve, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_relieve, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_relieve, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_relieve, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_mouth
    ui->Speaking_mouth = lv_btn_create(ui->Speaking);
    ui->Speaking_mouth_label = lv_label_create(ui->Speaking_mouth);
    lv_label_set_text(ui->Speaking_mouth_label, "");
    lv_label_set_long_mode(ui->Speaking_mouth_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_mouth_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_mouth, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_mouth_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_mouth, 220, 240);
    lv_obj_set_size(ui->Speaking_mouth, 40, 15);

    //Write style for Speaking_mouth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_mouth, lv_color_hex(0xc6e1f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_mouth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_mouth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_mouth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_mouth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_mouth, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_mouth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_mouth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL5
    ui->Speaking_eyeL5 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL5_label = lv_label_create(ui->Speaking_eyeL5);
    lv_label_set_text(ui->Speaking_eyeL5_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL5_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL5, 125, 150);
    lv_obj_set_size(ui->Speaking_eyeL5, 80, 19);
    lv_obj_add_flag(ui->Speaking_eyeL5, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeL5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR5
    ui->Speaking_eyeR5 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR5_label = lv_label_create(ui->Speaking_eyeR5);
    lv_label_set_text(ui->Speaking_eyeR5_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR5_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR5, 268, 150);
    lv_obj_set_size(ui->Speaking_eyeR5, 80, 19);
    lv_obj_add_flag(ui->Speaking_eyeR5, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeR5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR4
    ui->Speaking_eyeR4 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR4_label = lv_label_create(ui->Speaking_eyeR4);
    lv_label_set_text(ui->Speaking_eyeR4_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR4_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR4, 275, 103);
    lv_obj_set_size(ui->Speaking_eyeR4, 80, 80);
    lv_obj_add_flag(ui->Speaking_eyeR4, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeR4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR4, lv_color_hex(0xe79faa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL4
    ui->Speaking_eyeL4 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL4_label = lv_label_create(ui->Speaking_eyeL4);
    lv_label_set_text(ui->Speaking_eyeL4_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL4_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL4, 125, 103);
    lv_obj_set_size(ui->Speaking_eyeL4, 80, 82);
    lv_obj_add_flag(ui->Speaking_eyeL4, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeL4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL4, lv_color_hex(0xe79faa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_emo4L
    ui->Speaking_emo4L = lv_label_create(ui->Speaking);
    lv_label_set_text(ui->Speaking_emo4L, "l  l  l  l  l  l  l");
    lv_label_set_long_mode(ui->Speaking_emo4L, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Speaking_emo4L, 43, 198);
    lv_obj_set_size(ui->Speaking_emo4L, 187, 32);
    lv_obj_add_flag(ui->Speaking_emo4L, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_emo4L, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_emo4L, lv_color_hex(0xf3bec6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_emo4L, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_emo4L, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Speaking_emo4L, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_emo4L, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_emo4L, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_emo4R
    ui->Speaking_emo4R = lv_label_create(ui->Speaking);
    lv_label_set_text(ui->Speaking_emo4R, "l  l  l  l  l  l  l ");
    lv_label_set_long_mode(ui->Speaking_emo4R, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Speaking_emo4R, 260, 198);
    lv_obj_set_size(ui->Speaking_emo4R, 179, 32);
    lv_obj_add_flag(ui->Speaking_emo4R, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_emo4R, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_emo4R, lv_color_hex(0xf3bec6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_emo4R, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_emo4R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Speaking_emo4R, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_emo4R, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_emo4R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL3
    ui->Speaking_eyeL3 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL3_label = lv_label_create(ui->Speaking_eyeL3);
    lv_label_set_text(ui->Speaking_eyeL3_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL3, 120, 118);
    lv_obj_set_size(ui->Speaking_eyeL3, 75, 95);
    lv_obj_add_flag(ui->Speaking_eyeL3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeL3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR3
    ui->Speaking_eyeR3 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR3_label = lv_label_create(ui->Speaking_eyeR3);
    lv_label_set_text(ui->Speaking_eyeR3_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR3, 289, 123);
    lv_obj_set_size(ui->Speaking_eyeR3, 75, 95);
    lv_obj_add_flag(ui->Speaking_eyeR3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeR3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR3
    ui->Speaking_eyebowR3 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR3[] = {{100, 20},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowR3, Speaking_eyebowR3, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR3, 298, 85);
    lv_obj_set_size(ui->Speaking_eyebowR3, 115, 51);
    lv_obj_add_flag(ui->Speaking_eyebowR3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowR3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL3
    ui->Speaking_eyebowL3 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL3[] = {{100, 0},{0, 20},};
    lv_line_set_points(ui->Speaking_eyebowL3, Speaking_eyebowL3, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL3, 91, 88);
    lv_obj_set_size(ui->Speaking_eyebowL3, 109, 62);
    lv_obj_add_flag(ui->Speaking_eyebowL3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowL3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR4
    ui->Speaking_eyebowR4 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR4[] = {{100, 20},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowR4, Speaking_eyebowR4, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR4, 283, 56);
    lv_obj_set_size(ui->Speaking_eyebowR4, 109, 62);
    lv_obj_add_flag(ui->Speaking_eyebowR4, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowR4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL4
    ui->Speaking_eyebowL4 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL4[] = {{100, 0},{0, 20},};
    lv_line_set_points(ui->Speaking_eyebowL4, Speaking_eyebowL4, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL4, 91, 56);
    lv_obj_set_size(ui->Speaking_eyebowL4, 115, 51);
    lv_obj_add_flag(ui->Speaking_eyebowL4, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowL4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL5
    ui->Speaking_eyebowL5 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL5[] = {{100, 0},{0, 10},};
    lv_line_set_points(ui->Speaking_eyebowL5, Speaking_eyebowL5, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL5, 112, 118);
    lv_obj_set_size(ui->Speaking_eyebowL5, 115, 51);
    lv_obj_add_flag(ui->Speaking_eyebowL5, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowL5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL5, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR5
    ui->Speaking_eyebowR5 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR5[] = {{100, 20},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowR5, Speaking_eyebowR5, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR5, 266, 94);
    lv_obj_set_size(ui->Speaking_eyebowR5, 109, 62);
    lv_obj_add_flag(ui->Speaking_eyebowR5, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowR5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR5, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR
    ui->Speaking_eyebowR = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowR, Speaking_eyebowR, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR, 286, 64);
    lv_obj_set_size(ui->Speaking_eyebowR, 109, 62);

    //Write style for Speaking_eyebowR, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL
    ui->Speaking_eyebowL = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL[] = {{60, 0},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowL, Speaking_eyebowL, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL, 135, 66);
    lv_obj_set_size(ui->Speaking_eyebowL, 127, 47);

    //Write style for Speaking_eyebowL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR2
    ui->Speaking_eyeR2 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR2_label = lv_label_create(ui->Speaking_eyeR2);
    lv_label_set_text(ui->Speaking_eyeR2_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR2, 275, 123);
    lv_obj_set_size(ui->Speaking_eyeR2, 100, 80);
    lv_obj_add_flag(ui->Speaking_eyeR2, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeR2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR2, lv_color_hex(0xdb3750), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL2
    ui->Speaking_eyeL2 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL2_label = lv_label_create(ui->Speaking_eyeL2);
    lv_label_set_text(ui->Speaking_eyeL2_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL2, 109, 123);
    lv_obj_set_size(ui->Speaking_eyeL2, 100, 80);
    lv_obj_add_flag(ui->Speaking_eyeL2, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeL2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL2, lv_color_hex(0xdb3750), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL2
    ui->Speaking_eyebowL2 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL2[] = {{100, 20},{0, 2},};
    lv_line_set_points(ui->Speaking_eyebowL2, Speaking_eyebowL2, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL2, 112, 113);
    lv_obj_set_size(ui->Speaking_eyebowL2, 127, 47);
    lv_obj_add_flag(ui->Speaking_eyebowL2, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowL2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR2
    ui->Speaking_eyebowR2 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR2[] = {{100, 0},{0, 20},};
    lv_line_set_points(ui->Speaking_eyebowR2, Speaking_eyebowR2, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR2, 275, 113);
    lv_obj_set_size(ui->Speaking_eyebowR2, 109, 62);
    lv_obj_add_flag(ui->Speaking_eyebowR2, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowR2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeR1
    ui->Speaking_eyeR1 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeR1_label = lv_label_create(ui->Speaking_eyeR1);
    lv_label_set_text(ui->Speaking_eyeR1_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeR1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeR1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeR1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeR1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeR1, 266, 64);
    lv_obj_set_size(ui->Speaking_eyeR1, 126, 124);
    lv_obj_add_flag(ui->Speaking_eyeR1, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeR1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeR1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeR1, lv_color_hex(0x5aa7ef), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeR1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeR1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeR1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeR1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeR1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeR1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeR1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeR1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyeL1
    ui->Speaking_eyeL1 = lv_btn_create(ui->Speaking);
    ui->Speaking_eyeL1_label = lv_label_create(ui->Speaking_eyeL1);
    lv_label_set_text(ui->Speaking_eyeL1_label, "");
    lv_label_set_long_mode(ui->Speaking_eyeL1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_eyeL1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_eyeL1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_eyeL1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_eyeL1, 91, 64);
    lv_obj_set_size(ui->Speaking_eyeL1, 124, 124);
    lv_obj_add_flag(ui->Speaking_eyeL1, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyeL1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_eyeL1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_eyeL1, lv_color_hex(0x4ba5ef), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_eyeL1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_eyeL1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_eyeL1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_eyeL1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_eyeL1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_eyeL1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_eyeL1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_eyeL1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowL1
    ui->Speaking_eyebowL1 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowL1[] = {{50, 0},{0, 5},};
    lv_line_set_points(ui->Speaking_eyebowL1, Speaking_eyebowL1, 2);
    lv_obj_set_pos(ui->Speaking_eyebowL1, 135, 26);
    lv_obj_set_size(ui->Speaking_eyebowL1, 89, 46);
    lv_obj_add_flag(ui->Speaking_eyebowL1, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowL1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowL1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowL1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowL1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowL1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_eyebowR1
    ui->Speaking_eyebowR1 = lv_line_create(ui->Speaking);
    static lv_point_t Speaking_eyebowR1[] = {{50, 5},{0, 0},};
    lv_line_set_points(ui->Speaking_eyebowR1, Speaking_eyebowR1, 2);
    lv_obj_set_pos(ui->Speaking_eyebowR1, 303, 30);
    lv_obj_set_size(ui->Speaking_eyebowR1, 115, 51);
    lv_obj_add_flag(ui->Speaking_eyebowR1, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_eyebowR1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Speaking_eyebowR1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Speaking_eyebowR1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Speaking_eyebowR1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Speaking_eyebowR1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_emoL3
    ui->Speaking_emoL3 = lv_btn_create(ui->Speaking);
    ui->Speaking_emoL3_label = lv_label_create(ui->Speaking_emoL3);
    lv_label_set_text(ui->Speaking_emoL3_label, "");
    lv_label_set_long_mode(ui->Speaking_emoL3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_emoL3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_emoL3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_emoL3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_emoL3, 104, 208);
    lv_obj_set_size(ui->Speaking_emoL3, 95, 28);
    lv_obj_add_flag(ui->Speaking_emoL3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_emoL3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_emoL3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_emoL3, lv_color_hex(0x8bc6f8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_emoL3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_emoL3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_emoL3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_emoL3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_emoL3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_emoL3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_emoL3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_emoL3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Speaking_emoR3
    ui->Speaking_emoR3 = lv_btn_create(ui->Speaking);
    ui->Speaking_emoR3_label = lv_label_create(ui->Speaking_emoR3);
    lv_label_set_text(ui->Speaking_emoR3_label, "");
    lv_label_set_long_mode(ui->Speaking_emoR3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Speaking_emoR3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Speaking_emoR3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Speaking_emoR3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Speaking_emoR3, 283, 208);
    lv_obj_set_size(ui->Speaking_emoR3, 89, 26);
    lv_obj_add_flag(ui->Speaking_emoR3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Speaking_emoR3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Speaking_emoR3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Speaking_emoR3, lv_color_hex(0x75bdf7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Speaking_emoR3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Speaking_emoR3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Speaking_emoR3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Speaking_emoR3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Speaking_emoR3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Speaking_emoR3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Speaking_emoR3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Speaking_emoR3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Speaking.


    //Update current screen layout.
    lv_obj_update_layout(ui->Speaking);

    //Init events for screen.
    events_init_Speaking(ui);
}
