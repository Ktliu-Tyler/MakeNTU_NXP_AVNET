/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Start;
	bool Start_del;
	lv_obj_t *Start_img_1;
	lv_obj_t *Start_img_2;
	lv_obj_t *Normal;
	bool Normal_del;
	lv_obj_t *Normal_eyeR;
	lv_obj_t *Normal_eyeR_label;
	lv_obj_t *Normal_eyeL;
	lv_obj_t *Normal_eyeL_label;
	lv_obj_t *Normal_relieve;
	lv_obj_t *Normal_relieve_label;
	lv_obj_t *Normal_mouth;
	lv_obj_t *Normal_mouth_label;
	lv_obj_t *Normal_eyebowR;
	lv_obj_t *Normal_eyebowL;
	lv_obj_t *Thinking;
	bool Thinking_del;
	lv_obj_t *Thinking_eyeL;
	lv_obj_t *Thinking_eyeL_label;
	lv_obj_t *Thinking_relieve;
	lv_obj_t *Thinking_relieve_label;
	lv_obj_t *Thinking_mouth;
	lv_obj_t *Thinking_mouth_label;
	lv_obj_t *Thinking_eyeR;
	lv_obj_t *Thinking_eyeR_label;
	lv_obj_t *Thinking_spinner_1;
	lv_obj_t *Thinking_btn_1;
	lv_obj_t *Thinking_btn_1_label;
	lv_obj_t *Thinking_btn_2;
	lv_obj_t *Thinking_btn_2_label;
	lv_obj_t *Thinking_btn_3;
	lv_obj_t *Thinking_btn_3_label;
	lv_obj_t *Thinking_eyebowR;
	lv_obj_t *Thinking_eyebowL;
	lv_obj_t *Sleep;
	bool Sleep_del;
	lv_obj_t *Sleep_eyeR;
	lv_obj_t *Sleep_eyeR_label;
	lv_obj_t *Sleep_eyeL;
	lv_obj_t *Sleep_eyeL_label;
	lv_obj_t *Sleep_ZZZ2;
	lv_obj_t *Sleep_ZZZ1;
	lv_obj_t *Sleep_btn_1;
	lv_obj_t *Sleep_btn_1_label;
	lv_obj_t *Speaking;
	bool Speaking_del;
	lv_obj_t *Speaking_eyeR;
	lv_obj_t *Speaking_eyeR_label;
	lv_obj_t *Speaking_eyeL;
	lv_obj_t *Speaking_eyeL_label;
	lv_obj_t *Speaking_relieve;
	lv_obj_t *Speaking_relieve_label;
	lv_obj_t *Speaking_mouth;
	lv_obj_t *Speaking_mouth_label;
	lv_obj_t *Speaking_eyeL5;
	lv_obj_t *Speaking_eyeL5_label;
	lv_obj_t *Speaking_eyeR5;
	lv_obj_t *Speaking_eyeR5_label;
	lv_obj_t *Speaking_eyeR4;
	lv_obj_t *Speaking_eyeR4_label;
	lv_obj_t *Speaking_eyeL4;
	lv_obj_t *Speaking_eyeL4_label;
	lv_obj_t *Speaking_emo4L;
	lv_obj_t *Speaking_emo4R;
	lv_obj_t *Speaking_eyeL3;
	lv_obj_t *Speaking_eyeL3_label;
	lv_obj_t *Speaking_eyeR3;
	lv_obj_t *Speaking_eyeR3_label;
	lv_obj_t *Speaking_eyebowR3;
	lv_obj_t *Speaking_eyebowL3;
	lv_obj_t *Speaking_eyebowR4;
	lv_obj_t *Speaking_eyebowL4;
	lv_obj_t *Speaking_eyebowL5;
	lv_obj_t *Speaking_eyebowR5;
	lv_obj_t *Speaking_eyebowR;
	lv_obj_t *Speaking_eyebowL;
	lv_obj_t *Speaking_eyeR2;
	lv_obj_t *Speaking_eyeR2_label;
	lv_obj_t *Speaking_eyeL2;
	lv_obj_t *Speaking_eyeL2_label;
	lv_obj_t *Speaking_eyebowL2;
	lv_obj_t *Speaking_eyebowR2;
	lv_obj_t *Speaking_eyeR1;
	lv_obj_t *Speaking_eyeR1_label;
	lv_obj_t *Speaking_eyeL1;
	lv_obj_t *Speaking_eyeL1_label;
	lv_obj_t *Speaking_eyebowL1;
	lv_obj_t *Speaking_eyebowR1;
	lv_obj_t *Speaking_emoL3;
	lv_obj_t *Speaking_emoL3_label;
	lv_obj_t *Speaking_emoR3;
	lv_obj_t *Speaking_emoR3_label;
	lv_obj_t *Speakless;
	bool Speakless_del;
	lv_obj_t *Speakless_eyeL;
	lv_obj_t *Speakless_eyeL_label;
	lv_obj_t *Speakless_relieve;
	lv_obj_t *Speakless_relieve_label;
	lv_obj_t *Speakless_mouth;
	lv_obj_t *Speakless_mouth_label;
	lv_obj_t *Speakless_btn_1;
	lv_obj_t *Speakless_btn_1_label;
	lv_obj_t *Speakless_btn_3;
	lv_obj_t *Speakless_btn_3_label;
	lv_obj_t *Speakless_btn_2;
	lv_obj_t *Speakless_btn_2_label;
	lv_obj_t *Music;
	bool Music_del;
	lv_obj_t *Music_eyeR;
	lv_obj_t *Music_eyeR_label;
	lv_obj_t *Music_eyeL;
	lv_obj_t *Music_eyeL_label;
	lv_obj_t *Music_relieve;
	lv_obj_t *Music_relieve_label;
	lv_obj_t *Music_line_2;
	lv_obj_t *Music_line_1;
	lv_obj_t *Music_label_1;
	lv_obj_t *Focus;
	bool Focus_del;
	lv_obj_t *Focus_eyeR;
	lv_obj_t *Focus_eyeR_label;
	lv_obj_t *Focus_eyeL;
	lv_obj_t *Focus_eyeL_label;
	lv_obj_t *Focus_relieve;
	lv_obj_t *Focus_relieve_label;
	lv_obj_t *Focus_mouth;
	lv_obj_t *Focus_mouth_label;
	lv_obj_t *Focus_line_2;
	lv_obj_t *Focus_line_1;
	lv_obj_t *Focus_digital_clock_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_Start(lv_ui *ui);
void setup_scr_Normal(lv_ui *ui);
void setup_scr_Thinking(lv_ui *ui);
void setup_scr_Sleep(lv_ui *ui);
void setup_scr_Speaking(lv_ui *ui);
void setup_scr_Speakless(lv_ui *ui);
void setup_scr_Music(lv_ui *ui);
void setup_scr_Focus(lv_ui *ui);
LV_IMG_DECLARE(_NXP_alpha_135x65);
LV_IMG_DECLARE(_AVNET_alpha_258x74);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_30)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_22)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_21)
LV_FONT_DECLARE(lv_font_Amiko_Regular_30)
LV_FONT_DECLARE(lv_font_Antonio_Regular_25)


#ifdef __cplusplus
}
#endif
#endif
