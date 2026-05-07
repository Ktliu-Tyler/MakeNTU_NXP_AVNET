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



void setup_scr_Start(lv_ui *ui)
{
    //Write codes Start
    ui->Start = lv_obj_create(NULL);
    lv_obj_set_size(ui->Start, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Start, LV_SCROLLBAR_MODE_OFF);

    //Write style for Start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Start, lv_color_hex(0xcbf6ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Start_img_1
    ui->Start_img_1 = lv_img_create(ui->Start);
    lv_obj_add_flag(ui->Start_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Start_img_1, &_NXP_alpha_135x65);
    lv_img_set_pivot(ui->Start_img_1, 50,50);
    lv_img_set_angle(ui->Start_img_1, 0);
    lv_obj_set_pos(ui->Start_img_1, 41, 131);
    lv_obj_set_size(ui->Start_img_1, 135, 65);

    //Write style for Start_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Start_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Start_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Start_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Start_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Start_img_2
    ui->Start_img_2 = lv_img_create(ui->Start);
    lv_obj_add_flag(ui->Start_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Start_img_2, &_AVNET_alpha_258x74);
    lv_img_set_pivot(ui->Start_img_2, 50,50);
    lv_img_set_angle(ui->Start_img_2, 0);
    lv_obj_set_pos(ui->Start_img_2, 195, 127);
    lv_obj_set_size(ui->Start_img_2, 258, 74);

    //Write style for Start_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Start_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Start_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Start_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Start_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Start.


    //Update current screen layout.
    lv_obj_update_layout(ui->Start);

    //Init events for screen.
    events_init_Start(ui);
}
