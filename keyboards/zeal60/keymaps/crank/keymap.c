// Default layout for Zeal60
#include QMK_KEYBOARD_H

enum custom_keycodes {
    LM_TMUX = SAFE_RANGE,
};

uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LM_TMUX:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(1);
            } else {
                layer_off(1);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING(SS_LCTRL("b"));
                }
            }
            break;
    }
    return true;
};

// KEY MAPPING

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  DEFAULT - QWERTY
 *
 *  ,----------------------------------------------------------------------------------------.
 *  | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bksp   |
 *  |----------------------------------------------------------------------------------------|
 *  | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \   |
 *  |----------------------------------------------------------------------------------------|
 *  | Layer1  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter  |
 *  |----------------------------------------------------------------------------------------|
 *  | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |        Shift  |
 *  |----------------------------------------------------------------------------------------|
 *  | Ctl  | Cmd  |  Alt  |           Space / Mouse            |  Alt  |  FN2 | FN3  | Ctl   |
 *  `----------------------------------------------------------------------------------------'
 *
 *  Layer1 - Access Layer 1 when held
 */

[0] = LAYOUT_60_ansi(
	KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
	LM_TMUX,    KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	KC_LCTL,  KC_LGUI, KC_LALT,                           LT(2, KC_SPC),                             KC_RALT, FN_MO13, FN_MO23, KC_RCTL),

/*  LAYER 1 - FUNCTION
 *
 *  ,----------------------------------------------------------------------------------------.
 *  |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  |Mute |Vol- |Vol+ |   Del    |
 *  |----------------------------------------------------------------------------------------|
 *  | ~      |     |     |     |     |     |     |     |     | Ins |     |Prev |Next | Play  |
 *  |----------------------------------------------------------------------------------------|
 *  | <HELD>  |     |Scrn |     |     |     | Lft | Dwn | Up  | Rt  |Home |End  | Desktop    |
 *  |----------------------------------------------------------------------------------------|
 *  |            |     |     |Caps |     |     |     |     | PgDn| PgUp|     |               |
 *  |----------------------------------------------------------------------------------------|
 *  |      |      | Chrm  |          Quick Command             |       |      |      | Sleep |
 *  `----------------------------------------------------------------------------------------'
 */

[1] = LAYOUT_60_ansi(
	KC_GRV,  KC_F1,   KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_MUTE, KC_VOLD, KC_VOLU,  KC_DEL ,
	KC_TILD, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_TRNS, KC_PSCR, KC_MRWD, KC_MFFD,  KC_MPLY,
	KC_TRNS, KC_LGUI, JC_SCREEN_CLIP, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END, KC_F11,
	KC_TRNS, KC_TRNS, KC_TRNS,        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, JC_CHROME_MENU,                   JC_ALBERT,                         KC_TRNS, KC_TRNS, KC_TRNS, JC_SLEEP),

/*  LAYER 2 - Mouse
 *
 *  ,----------------------------------------------------------------------------------------.
 *  |     |     |     |     |     |     |     |     | MMC |     |     |     |     |          |
 *  |----------------------------------------------------------------------------------------|
 *  |        |     |     |     |     |     |     | MLC | MRC |     |     |     |     |       |
 *  |----------------------------------------------------------------------------------------|
 *  |         |     |     |     |     |     |MLft |MDwn |MUp  |MRt  |     |     |            |
 *  |----------------------------------------------------------------------------------------|
 *  |            |     |     |     |     |     |MScL |MScD |MScU |MScR |     |               |
 *  |----------------------------------------------------------------------------------------|
 *  |      |      |       |              <HELD>                |       |      |      |       |
 *  `----------------------------------------------------------------------------------------'
 */

[2] = LAYOUT_60_ansi(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

/*  LAYER 3 - LIGHTING
 *
 *  ,----------------------------------------------------------------------------------------.
 *  |     | M-  | M+  | H1- | H1+ | H2- | H2+ |     |     |     |     |Br-  |Br+  |          |
 *  |----------------------------------------------------------------------------------------|
 *  |        |     |     | S1- | S1+ | S2- | S2+ |     |     |     |     | Sp- | Sp+ |       |
 *  |----------------------------------------------------------------------------------------|
 *  |         |     |     |     |     |     |     |     |     |     |     |     |            |
 *  |----------------------------------------------------------------------------------------|
 *  |            |     |     |     |     |     |     |     |     |     |     |               |
 *  |----------------------------------------------------------------------------------------|
 *  |      |      |       |                                    |       |      |      |       |
 *  `----------------------------------------------------------------------------------------'
 */

[3] = LAYOUT_60_ansi(
	KC_TRNS, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BR_DEC,  BR_INC,  KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ES_DEC,  ES_INC,  KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};
:
