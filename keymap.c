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
#include "alphabet.h"

#define ___x___ KC_NO
#define ___O___ KC_NO
#ifndef _______
#define _______ KC_TRNS
#endif

// override default shifted versions of (,,<) and (.,>) to (,,;) and (.,:)
// const key_override_t delete_key_override = ko_make_basic(
// 	MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE
// );
// const key_override_t comma_key_override = ko_make_basic(
// 	MOD_MASK_SHIFT, KC_COMM, KC_SCLN
// );
// const key_override_t dot_key_override = ko_make_basic(
// 	MOD_MASK_SHIFT, KC_DOT, KC_COLN
// );
// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     /* &delete_key_override, */
//     NULL // Null terminate the array of overrides!
// };

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance declarations
td_state_t cur_dance(qk_tap_dance_state_t *state);

void generic_finished(qk_tap_dance_state_t *state, void *user_data, uint16_t kc, uint16_t kc_h);
void generic_reset(qk_tap_dance_state_t *state, void *user_data, uint16_t kc, uint16_t kc_h);
void win_finished(qk_tap_dance_state_t *state, void *user_data);
void win_reset(qk_tap_dance_state_t *state, void *user_data);
void ctl_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_reset(qk_tap_dance_state_t *state, void *user_data);

enum {
    C_H,
    W_E,
};



// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [C_H] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
    [W_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset)
};

enum layers {BASE, SYM, NUM, FUN, NAV, SYS};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SYS(ESC),    KC_K,  KC_DOT,    KC_O, KC_COMM,    KC_Y,                         KC_V,    KC_G,    KC_C,    KC_L,    KC_Z,SYS(ESC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(SYM), TD(C_H),  AGR(A), TD(W_E),  NAV(I),    KC_U,                         KC_D,   NAV(T), WIN(R),  AGR(N),  CTL(S), MO(SYM),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_SCLN,  SFT(X),    KC_Q, KC_LBRC, KC_RBRC,    KC_F,                         KC_B,    KC_P,    KC_W,    KC_M,  SFT(J), KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,NUM(TAB),  KC_SPC,     KC_ENT, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ___x___, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                      KC_EXLM,   KC_LT,   KC_GT,  KC_EQL, KC_AMPR, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___O___, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,                      KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN,   KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HASH,  KC_DLR, KC_PIPE, KC_TILD,  KC_GRV,                      KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN,  UC_EUR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       _______, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_ASTR,    KC_7,    KC_8,    KC_9, KC_SLSH, _______,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MO(FUN), KC_LCTL, KC_ALGR, KC_LGUI, ___x___, ___x___,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_MINS, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LSFT, ___x___, ___x___, ___x___, ___x___,                       KC_DOT,    KC_1,    KC_2,    KC_3, KC_COMM, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, ___O___, _______,    KC_MINS,    KC_0,  KC_DOT
                                       //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       _______, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_F12,   KC_F7,   KC_F8,   KC_F9, ___x___, _______,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___O___, KC_LCTL, KC_ALGR, ___x___, KC_LGUI, ___x___,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LSFT, ___x___, ___x___, ___x___, ___x___,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, ___x___, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, ___O___, ___x___,    ___x___, ___x___, ___x___
                                       //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       ___x___, ___x___, KC_WH_D, KC_MS_U, KC_WH_U, KC_AGIN,                      ___x___, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_UNDO,                      ___x___, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___x___,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ___x___, KC_LSFT, KC_CUT,  KC_COPY, KC_PSTE, ___x___,                      ___x___, KC_PSTE, KC_COPY,  KC_CUT,  KC_INS, ___x___,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           ___x___, KC_LGUI, KC_BTN1,    KC_BTN1, KC_BTN3, KC_BTN2
                                       //`--------------------------'  `--------------------------'
  ),

  [SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, RGB_M_P, RGB_M_B, RGB_M_R, ___x___, ___x___,                      ___x___, ___x___, KC_VOLU, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RESET, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      ___x___, KC_BRIU, KC_MUTE, ___x___, ___x___,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      ___x___, KC_BRID, KC_VOLD, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, ___x___, ___x___,    KC_MPLY, KC_MPRV, KC_MNXT
                                      //`--------------------------'  `--------------------------'
  )
};





// ---------- TAP DANCE CONFIG ------------------------------------------------
// see https://docs.qmk.fm/#/feature_tap_dance?id=example-4
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

static td_tap_t tap_state = {.is_press_action = true, .state = TD_NONE};

void win_finished(qk_tap_dance_state_t *state, void *user_data) {
	return generic_finished(state, user_data, KC_E, KC_LGUI);
}
void win_reset(qk_tap_dance_state_t *state, void *user_data) {
	return generic_reset(state, user_data, KC_E, KC_LGUI);
}
void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
	return generic_finished(state, user_data, KC_H, KC_LCTL);
}
void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
	return generic_reset(state, user_data, KC_H, KC_LCTL);
}

void generic_finished(
    qk_tap_dance_state_t *state,
    void *user_data,
    uint16_t kc,
    uint16_t kc_h
){
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(kc); break;
        case TD_SINGLE_HOLD: register_code(kc_h); break;
        case TD_DOUBLE_TAP: tap_code(kc); register_code(kc); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(kc_h)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(kc); register_code(kc); break;
        default: ;
    }
}

void generic_reset(
    qk_tap_dance_state_t *state,
    void *user_data,
    uint16_t kc,
    uint16_t kc_h
){
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(kc); break;
        case TD_SINGLE_HOLD: unregister_code(kc_h); break;
        case TD_DOUBLE_TAP: unregister_code(kc); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(kc_h)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(kc); break;
        default: ;
    }
    tap_state.state = TD_NONE;
}




// ---------- OLED CONFIG -----------------------------------------------------

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
        case FUN:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
        case NAV:
            oled_write_ln_P(PSTR("Nav"), false);
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
