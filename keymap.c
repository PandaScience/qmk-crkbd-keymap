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

#define ___x___ KC_NO
#define ___O___ KC_NO
#ifndef _______
#define _______ KC_TRNS
#endif

#define UC_EUR  ALGR(KC_5)

#define CTRL   KC_LCTL
#define SFT    KC_LSFT
#define ALT    KC_LALT
#define GUI    KC_LGUI
#define S_CTRL S(KC_LCTL)
#define S_ALT  S(KC_LALT)
#define S_GUI  S(KC_LGUI)

#define S_H LSFT_T(KC_H)
#define S_S RSFT_T(KC_S)
#define C_X LCTL_T(KC_X)
#define C_J RCTL_T(KC_J)
#define A_A LALT_T(KC_A)
#define A_N ALGR_T(KC_N)
#define G_E LGUI_T(KC_E)
#define G_R RGUI_T(KC_R)

#define sC_EQL  RCS_T(KC_EQL)
#define sC_SLSH RCS_T(KC_SLSH)
#define sA_Q    LSA_T(KC_Q)
#define sA_M    LSA_T(KC_M)
#define sG_LBRC LSG_T(KC_LBRC)
#define sG_W    LSG_T(KC_W)

#define SYM_MINS LT(SYM, KC_MINS)
#define SYM_F    LT(SYM, KC_F)

#define NAV_I LT(NAV, KC_I)
#define MSE_T LT(MSE, KC_T)

// swap hands; this unfortunatley breaks tap-repeat on space -> use SYM/NAV layer
#define SW_SPC SH_T(KC_SPC)
#define SW_ENT SH_T(KC_ENT)

#define SYS_ESC LT(SYS, KC_ESC)
#define NUM_TAB LT(NUM, KC_TAB)



enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    LX_HOME,
    SCOPE,
};

// TODO: add greek layer GRK

// ---------- LAYERS ----------------------------------------------------------
enum layers {BSE, SYM, NUM, FUN, NAV, MSE, SYS};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SYS_ESC,    KC_K,  KC_DOT,    KC_O, KC_COMM,    KC_Y,                         KC_V,    KC_G,    KC_C,    KC_L,    KC_Z, SYS_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SYM_MINS,     S_H,     A_A,     G_E,   NAV_I,    KC_U,                         KC_D,   MSE_T,     G_R,     A_N,     S_S,   SYM_F,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       sC_EQL,     C_X,    sA_Q, sG_LBRC, KC_RBRC, KC_QUOT,                         KC_B,    KC_P,    sG_W,    sA_M,     C_J, sC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, NUM_TAB,  SW_ENT,     SW_SPC, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TILDE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, ___x___,                      ___x___, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___O___, ___x___, ___x___, KC_LPRN, KC_RPRN, ___x___,                      KC_PIPE, KC_COLN, KC_SCLN, ___x___, ___x___, ___O___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, ___x___, ___x___, KC_LABK, KC_RABK, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, LX_HOME,  KC_ENT,     KC_SPC,   UPDIR, ___x___
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ___x___, ___x___, ___x___, ___x___, ___x___,                      KC_ASTR,    KC_7,    KC_8,    KC_9, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(FUN),     SFT,     ALT,     GUI,  KC_DOT, ___x___,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_MINS,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_CTRL,    CTRL,   S_ALT,   S_GUI, KC_COMM, ___x___,                      ___x___,    KC_1,    KC_2,    KC_3, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, ___O___, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_F12,   KC_F7,   KC_F8,   KC_F9, ___x___, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___O___,     SFT,     ALT,     GUI, ___x___, ___x___,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_CTRL,    CTRL,   S_ALT,   S_GUI, ___x___, ___x___,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, ___O___, ___x___,    ___x___, ___x___, ___x___
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, ___x___, ___x___,___x___,  ___x___, ___x___,                      ___x___, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___,     SFT,     ALT,     GUI, ___x___, ___x___,                      ___x___, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_CTRL,    CTRL,   S_ALT,   S_GUI, ___x___, ___x___,                      ___x___, KC_PSTE, KC_COPY,  KC_CUT,  KC_INS, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___,  KC_TAB,  KC_ENT,     KC_SPC, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [MSE] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, ___x___, KC_WH_D, KC_MS_U, KC_WH_U, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_R, ___x___,                      ___x___, ___O___, KC_ACL0, KC_ACL1, KC_ACL2, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___x___, KC_BTN4, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN2, KC_BTN3, KC_BTN1,    KC_BTN1, KC_BTN3, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___x___, RGB_M_P, RGB_M_B, RGB_M_R, ___x___, ___x___,                      ___x___, KC_BRID, ___x___, KC_BRIU, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RESET, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      ___x___, KC_VOLD, KC_MUTE, KC_VOLU, ___x___,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___x___, ___x___, ___x___,    KC_MPLY, KC_MPRV, KC_MNXT
                                      //`--------------------------'  `--------------------------'
  )
};


// ---------- KEY COMBOS ------------------------------------------------------
// taken from https://github.com/getreuer/qmk-keymap/blob/main/keymap.c
enum combo_events {
    // , and . => types a period, space, and sets one-shot mod for shift.
    END_SENTENCE_COMBO,
    EI_ESC,
    RT_ESC,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM end_sentence_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ei_esc_combo[] = {G_E, NAV_I, COMBO_END};
const uint16_t PROGMEM rt_esc_combo[] = {G_R, MSE_T, COMBO_END};

combo_t key_combos[] = {
    [END_SENTENCE_COMBO] = COMBO_ACTION(end_sentence_combo),
    [EI_ESC] = COMBO_ACTION(ei_esc_combo),
    [RT_ESC] = COMBO_ACTION(rt_esc_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch(combo_index) {
            case END_SENTENCE_COMBO:
                SEND_STRING(". ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
                break;
            case EI_ESC:
            case RT_ESC:
                tap_code16(KC_ESC);
                break;
        }
    }
}

//make all combos tap-only
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}

// ---------- KEY OVERRIDES ---------------------------------------------------
// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
// https://docs.qmk.fm/#/feature_key_overrides?id=key-overrides
const key_override_t dot_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, KC_DOT, KC_COLN, (1 << BSE)
);

const key_override_t comma_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (1 << BSE)
);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &dot_key_override,
    &comma_key_override,
    NULL // Null terminate the array of overrides!
};

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
            case LX_HOME:
                SEND_STRING("~/");
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
        case MSE:
            /* oled_write_ln_P(PSTR("MSE"), true); */
            oled_write_ln_P(PSTR("    __ __"), false);
            oled_write_ln_P(PSTR("|V|(_ |_ "), false);
            oled_write_ln_P(PSTR("| |__)|__"), false);
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
