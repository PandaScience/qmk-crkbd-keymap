// https://docs.qmk.fm/#/keycodes

#undef A
#undef C
#undef G
#undef S
#undef X

#define A KC_A
#define B KC_B
#define C KC_C
#define D KC_D
#define E KC_E
#define F KC_F
#define G KC_G
#define H KC_H
#define I KC_I
#define J KC_J
#define K KC_K
#define L KC_L
#define M KC_M
#define N KC_N
#define O KC_O
#define P KC_P
#define Q KC_Q
#define R KC_R
#define S KC_S
#define T KC_T
#define U KC_U
#define V KC_V
#define W KC_W
#define X KC_X
#define Y KC_Y
#define Z KC_Z

#define WIN(kc) LGUI_T(kc)
#define ALT(kc) LALT_T(kc)
#define AGR(kc) ALGR_T(kc)
#define CTL(kc) LCTL_T(kc)
#define SFT(kc) LSFT_T(kc)

#define SYM(kc) LT(SYM, kc)
#define NUM(kc) LT(NUM, kc)
#define NAV(kc) LT(NAV, kc)
#define SYS(kc) LT(SYS, kc)

#define CTL_H CTL(KC_H)
#define CTL_S CTL(KC_S)
#define AGR_A AGR(KC_A)
#define AGR_N AGR(KC_N)
#define NAV_E NAV(KC_E)
#define NAV_R NAV(KC_R)
#define WIN_I WIN(KC_I)
#define SFT_X SFT(KC_X)
#define SFT_J SFT(KC_J)
#define NUM_TAB NUM(KC_TAB)

#define ESC KC_ESC
#define TAB KC_TAB

#define UC_EUR  ALGR(KC_5)

