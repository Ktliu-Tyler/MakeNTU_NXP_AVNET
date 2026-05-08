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



void setup_scr_Panel(lv_ui *ui)
{
    //Write codes Panel
    ui->Panel = lv_obj_create(NULL);
    lv_obj_set_size(ui->Panel, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Panel, LV_SCROLLBAR_MODE_OFF);

    //Write style for Panel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Panel_Fan_slide
    ui->Panel_Fan_slide = lv_slider_create(ui->Panel);
    lv_slider_set_range(ui->Panel_Fan_slide, 0, 100);
    lv_slider_set_mode(ui->Panel_Fan_slide, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Panel_Fan_slide, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Panel_Fan_slide, 103, 68);
    lv_obj_set_size(ui->Panel_Fan_slide, 291, 40);

    //Write style for Panel_Fan_slide, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel_Fan_slide, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel_Fan_slide, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel_Fan_slide, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Panel_Fan_slide, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Panel_Fan_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Panel_Fan_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Panel_Fan_slide, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel_Fan_slide, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel_Fan_slide, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel_Fan_slide, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Panel_Fan_slide, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Panel_Fan_slide, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel_Fan_slide, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel_Fan_slide, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel_Fan_slide, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Panel_Fan_slide, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Panel_btn_1
    ui->Panel_btn_1 = lv_btn_create(ui->Panel);
    ui->Panel_btn_1_label = lv_label_create(ui->Panel_btn_1);
    lv_label_set_text(ui->Panel_btn_1_label, "ON");
    lv_label_set_long_mode(ui->Panel_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Panel_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Panel_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Panel_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Panel_btn_1, 106, 146);
    lv_obj_set_size(ui->Panel_btn_1, 135, 119);

    //Write style for Panel_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel_btn_1, lv_color_hex(0x3cb962), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Panel_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Panel_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Panel_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Panel_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Panel_btn_1, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Panel_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Panel_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Panel_btn_2
    ui->Panel_btn_2 = lv_btn_create(ui->Panel);
    ui->Panel_btn_2_label = lv_label_create(ui->Panel_btn_2);
    lv_label_set_text(ui->Panel_btn_2_label, "OFF");
    lv_label_set_long_mode(ui->Panel_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Panel_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Panel_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Panel_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Panel_btn_2, 252, 146);
    lv_obj_set_size(ui->Panel_btn_2, 135, 119);

    //Write style for Panel_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Panel_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Panel_btn_2, lv_color_hex(0xe20023), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Panel_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Panel_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Panel_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Panel_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Panel_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Panel_btn_2, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Panel_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Panel_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Panel.


    //Update current screen layout.
    lv_obj_update_layout(ui->Panel);

    //Init events for screen.
    events_init_Panel(ui);
}
