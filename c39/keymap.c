#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define _FN3 3 

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

// Tap dances
enum {
	TD_Q_ESC = 0,
	TD_A_TAB
};

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
	[TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------.  ,-------------.
 * |   Q  |   W  |   E  |   R  |   T  | Bksp |   Y  |   U  |   I  |   O  |   P  |  |  FN1 |  FN2 |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   A  |   S  |   D  |   F  |   G  | Enter|   H  |   J  |   K  |   L  |   ;  |  |  FN3  |  M4  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  SPC |   N  |   M  |   ,  |   .  |   /  |  |  M5  |  M6  |
 * `----------------------------------------------------------------------------'  `-------------'
 */
[_QWERTY] = LAYOUT(
    TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T, KC_BSPC, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(_FN1, KC_BSPC), MO(_FN2) ,
    TD(TD_A_TAB), KC_S, KC_D, KC_F, KC_G, MT(MOD_LSFT, KC_ENT), KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(_FN3, KC_ENTER), KC_LGUI,
    MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LCTL, KC_LALT
),
/* FN1
 * ,----------------------------------------------------------------------------.  ,-------------.
 * |   1  |   2  |   3  |   4  |   5  | Bksp |   6  |   7  |   8  |  9  |   0   |  |  M1  |  M2  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   ESC|  LFT | RGT  |   UP |      | Enter|   =  |   -  |      |  [   |  ]   |  |  M3  |  M4  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   7  |   8  |   9  |   DWN|      |  SPC |      |  END |      |  {   |  }   |  |  M5  |  M6  |
 * `----------------------------------------------------------------------------'  `-------------'
 */
[_FN1] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______,
    KC_GESC, KC_LEFT, KC_RGHT, KC_UP, _______, KC_ENT,  KC_EQUAL, KC_MINUS, _______, KC_LBRC,KC_RBRC,   _______, KC_4,
    KC_7, KC_8, KC_9, KC_DOWN, _______, KC_SPC, _______, KC_END, _______, KC_LCBR, KC_RCBR,   KC_5, KC_6
), 
/* FN2
 * ,----------------------------------------------------------------------------.  ,-------------.
 * |   !  |   @  |   #  |   $  |   %  | Bksp |   ^  |   &  |   *  |  (  |   )   |  |  M1  |  M2  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   ~  |   5  |   6  |   +  |      | Enter|  +   |   _  |      |  [   |  '   |  |  M3  |  M4  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   7  |   8  |   9  |   0  |      | SPC  |      |   <  |  >   | PGUP | PGDWN|  |  M5  |  M6  |
 * `----------------------------------------------------------------------------'  `-------------'
 */
[_FN2] = LAYOUT(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_BSPC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,
    KC_GRV, KC_5, KC_6, KC_PLUS, _______, KC_ENT,  KC_PLUS, KC_UNDS, _______, KC_LBRC,KC_QUOT, _______, KC_4,
    KC_7, KC_8, KC_9, KC_0, _______, KC_SPC, _______, KC_LT, KC_GT, KC_PGUP, KC_PGDN, KC_5, KC_6
), 
/* FN3
 * ,----------------------------------------------------------------------------.  ,-------------.
 * |   F1 |  F2  |  F3  |   F4 |  F5  | F6   |  F7  |  F8  |   F9 |  F10 |  F11 |  |  M1  |  M2  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * | TAB  |   5  |   6  |   +  | VOLU | Enter|  LCLK| MSUP | RCLK |  [   |  F12 |  |  M3  |  M4  |
 * |------+------+------+------+------+------+------+------+------+------+------+  |------+------|
 * |   7  |   8  |   9  |   0  | VOLD | SPC  | MSLT | MSDWN| MSRT | PGUP | PGDWN|  |  M5  |  M6  |
 * `----------------------------------------------------------------------------'  `-------------'
 */
[_FN3] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,  _______, _______,
    KC_TAB, KC_5, KC_6, KC_PLUS, KC_VOLU, KC_ENT,KC_BTN1, KC_MS_U, KC_BTN2, KC_LBRC,KC_F12, _______, KC_4,
    KC_7, KC_8, KC_9, KC_0, KC_VOLD, KC_SPC, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP, KC_PGDN,   KC_5, KC_6
), };
