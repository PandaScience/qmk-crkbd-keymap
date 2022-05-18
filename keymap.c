/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers { BASE, SYM, NUM, FUN, NAV, MOUSE, MEDIA, SYS};


#define ___x___  KC_NO

#define WIN_H    LGUI_T(KC_H)
#define ALT_A    LALT_T(KC_A)
#define AGR_Q    ALGR_T(KC_Q)
#define CTL_E    LCTL_T(KC_E)
#define SHFT_I   LSFT_T(KC_I)

#define SHFT_T   LSFT_T(KC_T)
#define CTL_R    LCTL_T(KC_R)
#define ALT_N    LALT_T(KC_N)
#define WIN_S    LGUI_T(KC_S)

#define UC_EUR   ALGR(KC_5)

#define MSE_ESC  LT(MOUSE, KC_ESC)
#define NUM_SPC  LT(NUM, KC_SPC)
#define NAV_TAB  LT(NAV, KC_TAB)
#define SYS_ESC  LT(SYS, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SYS_ESC,    KC_K,  KC_DOT,    KC_O, KC_COMM,    KC_Y,                         KC_V,    KC_G,    KC_C,    KC_L,    KC_Z,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(SYM),   WIN_H,   ALT_A,   CTL_E,  SHFT_I,    KC_U,                         KC_D,  SHFT_T,   CTL_R,   ALT_N,   WIN_S, MO(SYM),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_SCLN,    KC_X,   AGR_Q, KC_LBRC, KC_RBRC,    KC_F,                         KC_B,    KC_P,    KC_W,    KC_M,    KC_J, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MSE_ESC, NAV_TAB, NUM_SPC,     KC_ENT, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, ___x___, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                      KC_EXLM,   KC_LT,   KC_GT,  KC_EQL, KC_AMPR, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,                      KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN,   KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_HASH,  KC_DLR, KC_PIPE, KC_TILD,  KC_GRV,                      KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN,  UC_EUR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MSE_ESC, NAV_TAB, NUM_SPC,     KC_ENT, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_ASTR,    KC_7,    KC_8,    KC_9, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MO(FUN), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___x___,                      KC_PLUS,    KC_4,    KC_5,    KC_6, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_SLSH,    KC_1,    KC_2,    KC_3, KC_COMM, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, ___x___, ___x___,    KC_MINS,    KC_0,  KC_DOT
                                       //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_F12,   KC_F7,   KC_F8,   KC_F9, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___x___,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, ___x___, ___x___,     KC_ENT,  KC_ESC, ___x___
                                       //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___x___,                      ___x___, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, ___x___, ___x___,    KC_BTN1, KC_BTN3, KC_BTN2
                                       //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___x___,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, ___x___, ___x___,    KC_BTN1, KC_BTN3, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___,   RESET, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, ___x___, ___x___,    ___x___, ___x___, ___x___
                                      //`--------------------------'  `--------------------------'
  )
};

// override default shifted versions of (,,<) and (.,>) to (,,;) and (.,:)
const key_override_t delete_key_override = ko_make_basic(
	MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE
);
const key_override_t comma_key_override = ko_make_basic(
	MOD_MASK_SHIFT, KC_COMM, KC_SCLN
);
const key_override_t dot_key_override = ko_make_basic(
	MOD_MASK_SHIFT, KC_DOT, KC_COLN
);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    /* &delete_key_override, */
    NULL // Null terminate the array of overrides!
};




#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case FUN:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
        case MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case SYS:
            oled_write_ln_P(PSTR("Sys"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
