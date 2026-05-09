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



void setup_scr_Weather(lv_ui *ui)
{
    //Write codes Weather
    ui->Weather = lv_obj_create(NULL);
    lv_obj_set_size(ui->Weather, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Weather, LV_SCROLLBAR_MODE_OFF);

    //Write style for Weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Weather, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Weather, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_label_1
    ui->Weather_label_1 = lv_label_create(ui->Weather);
    lv_label_set_text(ui->Weather_label_1, "Today's Weather");
    lv_label_set_long_mode(ui->Weather_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Weather_label_1, 97, 46);
    lv_obj_set_size(ui->Weather_label_1, 298, 52);

    //Write style for Weather_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Weather_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Weather_label_1, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Weather_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Weather_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Weather_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_0
    ui->Weather_img_0 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_0, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_0, &_0_alpha_136x124);
    lv_img_set_pivot(ui->Weather_img_0, 50,50);
    lv_img_set_angle(ui->Weather_img_0, 0);
    lv_obj_set_pos(ui->Weather_img_0, 56, 114);
    lv_obj_set_size(ui->Weather_img_0, 136, 124);
    lv_obj_add_flag(ui->Weather_img_0, LV_OBJ_FLAG_HIDDEN);

    //Write style for Weather_img_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_0, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_1
    ui->Weather_img_1 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_1, &_1_alpha_163x130);
    lv_img_set_pivot(ui->Weather_img_1, 50,50);
    lv_img_set_angle(ui->Weather_img_1, 0);
    lv_obj_set_pos(ui->Weather_img_1, 64, 110);
    lv_obj_set_size(ui->Weather_img_1, 163, 130);

    //Write style for Weather_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_3
    ui->Weather_img_3 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_3, &_3_alpha_180x125);
    lv_img_set_pivot(ui->Weather_img_3, 50,50);
    lv_img_set_angle(ui->Weather_img_3, 0);
    lv_obj_set_pos(ui->Weather_img_3, 36, 124);
    lv_obj_set_size(ui->Weather_img_3, 180, 125);
    lv_obj_add_flag(ui->Weather_img_3, LV_OBJ_FLAG_HIDDEN);

    //Write style for Weather_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_45
    ui->Weather_img_45 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_45, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_45, &_45_alpha_180x125);
    lv_img_set_pivot(ui->Weather_img_45, 50,50);
    lv_img_set_angle(ui->Weather_img_45, 0);
    lv_obj_set_pos(ui->Weather_img_45, 36, 124);
    lv_obj_set_size(ui->Weather_img_45, 180, 125);
    lv_obj_add_flag(ui->Weather_img_45, LV_OBJ_FLAG_HIDDEN);

    //Write style for Weather_img_45, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_45, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_55
    ui->Weather_img_55 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_55, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_55, &_55_alpha_171x132);
    lv_img_set_pivot(ui->Weather_img_55, 50,50);
    lv_img_set_angle(ui->Weather_img_55, 0);
    lv_obj_set_pos(ui->Weather_img_55, 41, 118);
    lv_obj_set_size(ui->Weather_img_55, 171, 132);
    lv_obj_add_flag(ui->Weather_img_55, LV_OBJ_FLAG_HIDDEN);

    //Write style for Weather_img_55, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_55, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_55, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_img_95
    ui->Weather_img_95 = lv_img_create(ui->Weather);
    lv_obj_add_flag(ui->Weather_img_95, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Weather_img_95, &_95_alpha_171x143);
    lv_img_set_pivot(ui->Weather_img_95, 50,50);
    lv_img_set_angle(ui->Weather_img_95, 0);
    lv_obj_set_pos(ui->Weather_img_95, 56, 114);
    lv_obj_set_size(ui->Weather_img_95, 171, 143);
    lv_obj_add_flag(ui->Weather_img_95, LV_OBJ_FLAG_HIDDEN);

    //Write style for Weather_img_95, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Weather_img_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Weather_img_95, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_img_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Weather_img_95, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_TempBar
    ui->Weather_TempBar = lv_bar_create(ui->Weather);
    lv_obj_set_style_anim_time(ui->Weather_TempBar, 300, 0);
    lv_bar_set_mode(ui->Weather_TempBar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Weather_TempBar, 0, 70);
    lv_bar_set_value(ui->Weather_TempBar, 30, LV_ANIM_ON);
    lv_obj_set_pos(ui->Weather_TempBar, 253, 151);
    lv_obj_set_size(ui->Weather_TempBar, 189, 20);

    //Write style for Weather_TempBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Weather_TempBar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Weather_TempBar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Weather_TempBar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_TempBar, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_TempBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Weather_TempBar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Weather_TempBar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Weather_TempBar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Weather_TempBar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_TempBar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Weather_RainBar
    ui->Weather_RainBar = lv_bar_create(ui->Weather);
    lv_obj_set_style_anim_time(ui->Weather_RainBar, 300, 0);
    lv_bar_set_mode(ui->Weather_RainBar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Weather_RainBar, 0, 70);
    lv_bar_set_value(ui->Weather_RainBar, 30, LV_ANIM_ON);
    lv_obj_set_pos(ui->Weather_RainBar, 253, 222);
    lv_obj_set_size(ui->Weather_RainBar, 189, 20);

    //Write style for Weather_RainBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Weather_RainBar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Weather_RainBar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Weather_RainBar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_RainBar, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_RainBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Weather_RainBar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Weather_RainBar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Weather_RainBar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Weather_RainBar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_RainBar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Weather_TempCurrentLabel
    ui->Weather_TempCurrentLabel = lv_label_create(ui->Weather);
    lv_label_set_text(ui->Weather_TempCurrentLabel, "Temp: -- C");
    lv_label_set_long_mode(ui->Weather_TempCurrentLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Weather_TempCurrentLabel, 227, 100);
    lv_obj_set_size(ui->Weather_TempCurrentLabel, 235, 46);

    //Write style for Weather_TempCurrentLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Weather_TempCurrentLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Weather_TempCurrentLabel, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Weather_TempCurrentLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Weather_TempCurrentLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Weather_TempCurrentLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_TempCurrentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_TempMaxMinLabel
    ui->Weather_TempMaxMinLabel = lv_label_create(ui->Weather);
    lv_label_set_text(ui->Weather_TempMaxMinLabel, "Max: -- C Min: -- C");
    lv_label_set_long_mode(ui->Weather_TempMaxMinLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Weather_TempMaxMinLabel, 227, 124);
    lv_obj_set_size(ui->Weather_TempMaxMinLabel, 237, 31);

    //Write style for Weather_TempMaxMinLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Weather_TempMaxMinLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Weather_TempMaxMinLabel, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Weather_TempMaxMinLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Weather_TempMaxMinLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Weather_TempMaxMinLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_TempMaxMinLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_RainPercentLabel
    ui->Weather_RainPercentLabel = lv_label_create(ui->Weather);
    lv_label_set_text(ui->Weather_RainPercentLabel, "Rain Percent: -- %");
    lv_label_set_long_mode(ui->Weather_RainPercentLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Weather_RainPercentLabel, 227, 194);
    lv_obj_set_size(ui->Weather_RainPercentLabel, 237, 31);

    //Write style for Weather_RainPercentLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Weather_RainPercentLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Weather_RainPercentLabel, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Weather_RainPercentLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Weather_RainPercentLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Weather_RainPercentLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_RainPercentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Weather_RoomTH_Label
    ui->Weather_RoomTH_Label = lv_label_create(ui->Weather);
    lv_label_set_text(ui->Weather_RoomTH_Label, "Room Temp: -- C");
    lv_label_set_long_mode(ui->Weather_RoomTH_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Weather_RoomTH_Label, 23, 261);
    lv_obj_set_size(ui->Weather_RoomTH_Label, 460, 29);

    //Write style for Weather_RoomTH_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Weather_RoomTH_Label, lv_color_hex(0xfbe69d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Weather_RoomTH_Label, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Weather_RoomTH_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Weather_RoomTH_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Weather_RoomTH_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Weather_RoomTH_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Weather.


    //Update current screen layout.
    lv_obj_update_layout(ui->Weather);

    //Init events for screen.
    events_init_Weather(ui);
}
