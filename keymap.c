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
// https://getreuer.info/posts/keyboards/caps-word/index.html
#include "extern/getreuer/features/caps_word.h"  // --> activate with L+R SHIFT key

#define ___x___ KC_NO
#define ___O___ KC_NO
#ifndef _______
#define _______ KC_TRNS
#endif

#define UC_EUR  ALGR(KC_5)

#define S_H LSFT_T(KC_H)
#define S_S RSFT_T(KC_S)
#define C_X LCTL_T(KC_X)
#define C_J RCTL_T(KC_J)
#define A_A LALT_T(KC_A)
#define A_N ALGR_T(KC_N)
#define W_E LGUI_T(KC_E)
#define W_R RGUI_T(KC_R)

#define sC_SCLN RCS_T(KC_SCLN)
#define sC_SLSH RCS_T(KC_SLSH)
#define sA_Q    LSA_T(KC_Q)
#define sA_M    LSA_T(KC_M)
#define sW_LBRC LSG_T(KC_LBRC)
#define sW_W    LSG_T(KC_W)

#define NAV_I LT(NAV, KC_I)
#define NAV_T LT(NAV, KC_T)

// swap hands; this unfortunatley breaks tap-repeat on space -> use SYM layer
#define SW_SPC SH_T(KC_SPC)
#define SW_ENT SH_T(KC_ENT)

#define SYS_ESC LT(SYS, KC_ESC)
#define NUM_TAB LT(NUM, KC_TAB)



enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    SCOPE,
};

// TODO: add greek layer GRK

// ---------- LAYERS ----------------------------------------------------------
enum layers {BSE, SYM, NUM, FUN, NAV, SYS};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SYS_ESC,    KC_K,  KC_DOT,    KC_O, KC_COMM,    KC_Y,                         KC_V,    KC_G,    KC_C,    KC_L,    KC_Z, SYS_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(SYM),     S_H,     A_A,     W_E,   NAV_I,    KC_U,                         KC_D,   NAV_T,     W_R,     A_N,     S_S, MO(SYM),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      sC_SCLN,     C_X,    sA_Q, sW_LBRC, KC_RBRC,    KC_F,                         KC_B,    KC_P,    sW_W,    sA_M,     C_J, sC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, NUM_TAB,  SW_SPC,     SW_ENT, KC_BSPC,  KC_DEL
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
                                          _______, _______,  KC_SPC,     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_ASTR,    KC_7,    KC_8,    KC_9, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(FUN), KC_LSFT, KC_LALT, KC_LGUI, ___x___, ___x___,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_MINS, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    S(KC_LCTL),KC_LCTL, ___x___, ___x___, ___x___, ___x___,                       KC_DOT,    KC_1,    KC_2,    KC_3, KC_COMM, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, ___O___, _______,    KC_MINS,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_F12,   KC_F7,   KC_F8,   KC_F9, ___x___, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___O___, KC_LSFT, KC_LALT, KC_LGUI, ___x___, ___x___,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    S(KC_LCTL),KC_LCTL, ___x___, ___x___, ___x___, ___x___,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, ___O___, ___x___,    ___x___, ___x___, ___x___
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, ___x___, KC_WH_D, KC_MS_U, KC_WH_U, KC_AGIN,                      ___x___, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_UNDO,                      ___x___, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_LCTL, KC_CUT,  KC_COPY, KC_PSTE, ___x___,                      ___x___, KC_PSTE, KC_COPY,  KC_CUT,  KC_INS, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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


// ---------- KEY COMBOS ------------------------------------------------------
// taken from https://github.com/getreuer/qmk-keymap/blob/main/keymap.c
enum combo_events {
    // . and C => activate Caps Word.
    CAPS_COMBO,
    // , and . => types a period, space, and sets one-shot mod for shift.
    // This combo is useful to flow between sentences.
    END_SENTENCE_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_combo[] = {KC_DOT, KC_C, COMBO_END};
const uint16_t PROGMEM end_sentence_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
    [END_SENTENCE_COMBO] = COMBO_ACTION(end_sentence_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch(combo_index) {
            case CAPS_COMBO:
                caps_word_set(true);  // Activate Caps Word.
                break;
            case END_SENTENCE_COMBO:
                SEND_STRING(". ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
                break;
        }
    }
}


// ---------- CUSTOM MACROS ---------------------------------------------------
// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#programming-the-behavior-of-any-keycode-idprogramming-the-behavior-of-any-keycode
// https://getreuer.info/posts/keyboards/caps-word/index.html
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }

    /* const uint8_t mods = get_mods(); */
    /* const uint8_t oneshot_mods = get_oneshot_mods(); */
    /* const bool shifted = (mods | oneshot_mods) & MOD_MASK_SHIFT; */

    // for more unicode, see https://github.com/getreuer/qmk-keymap/blob/main/keymap.c
    if (record->event.pressed) {
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;

            case SCOPE:
                SEND_STRING("::");
                return false;
        }

    }

    return true;
}


// ---------- OLED CONFIG -----------------------------------------------------
#ifdef OLED_ENABLE

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_layer_state(void) {
    // ascii art text: https://texteditor.com/multiline-text-art/
    switch (get_highest_layer(layer_state)) {
        case BSE:
            /* oled_write_ln_P(PSTR("BSE"), true); */
            oled_write_ln_P(PSTR(" _  __ __"), false);
            oled_write_ln_P(PSTR("|_)(_ |_ "), false);
            oled_write_ln_P(PSTR("|_)__)|__"), false);
            break;
        case SYM:
            /* oled_write_ln_P(PSTR("SYM"), true); */
            oled_write_ln_P(PSTR(" __      "), false);
            oled_write_ln_P(PSTR("(_ \\ /|V|"), false);
            oled_write_ln_P(PSTR("__) | | |"), false);
            break;
        case NUM:
            /* oled_write_ln_P(PSTR("NUM"), true); */
            oled_write_ln_P(PSTR("         "), false);
            oled_write_ln_P(PSTR("|\\|| ||V|"), false);
            oled_write_ln_P(PSTR("| ||_|| |"), false);
            break;
        case FUN:
            /* oled_write_ln_P(PSTR("FUN"), true); */
            oled_write_ln_P(PSTR(" __      "), false);
            oled_write_ln_P(PSTR("|_ | ||\\|"), false);
            oled_write_ln_P(PSTR("|  |_|| |"), false);
            break;
        case NAV:
            /* oled_write_ln_P(PSTR("NAV"), true); */
            oled_write_ln_P(PSTR("    _    "), false);
            oled_write_ln_P(PSTR("|\\||_|\\ /"), false);
            oled_write_ln_P(PSTR("| || | V "), false);
            break;
        case SYS:
            /* oled_write_ln_P(PSTR("SYS"), true); */
            oled_write_ln_P(PSTR(" __    __"), false);
            oled_write_ln_P(PSTR("(_ \\ /(_ "), false);
            oled_write_ln_P(PSTR("__) | __)"), false);
            break;
        default:
            /* oled_write_ln_P(PSTR("> ?"), false); */
            oled_write_ln_P(PSTR("      _  "), false);
            oled_write_ln_P(PSTR("|\\| /|_| "), false);
            oled_write_ln_P(PSTR("| |/ | | "), false);
    }

    oled_set_cursor(11, 0);
    oled_write_P(get_mods() & MOD_MASK_CTRL  ? PSTR("C") : PSTR(" "), false);
    oled_write_P(get_mods() & MOD_MASK_SHIFT ? PSTR("S") : PSTR(" "), false);
    oled_write_P(get_mods() & MOD_MASK_ALT   ? PSTR("A") : PSTR(" "), false);
    oled_write_P(get_mods() & MOD_MASK_GUI   ? PSTR("G") : PSTR(" "), false);

    oled_set_cursor(11, 2);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock    ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock   ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    // 1 line remaining.
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif
