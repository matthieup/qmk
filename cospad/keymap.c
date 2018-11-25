#include QMK_KEYBOARD_H
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-------------------.
   * |Left| 1  |  4 | 7  |
   * |----|----|----|----|
   * | 0  | 2  | 5  | 8  |
   * |----|----|----|----|
   * |Rigt| 3  | 6  | 9  |
   * |----|----|----|----|
   * | _FL|PGUP|CtrC|BTOG|
   * |----|----|----|----|
   * |RTRN|PGDW|CtrV|RTOG|
   * |----|----|----|----|
   * |MUTE|VDWN| VUP|RST |
   * `-------------------'
   */

[_BL] = LAYOUT_ortho_6x4(
  KC_LEFT,  KC_P1,  KC_P4,   KC_P7, \
  KC_P0,    KC_P2,  KC_P5,   KC_P8, \
  KC_RIGHT, KC_P3,  KC_P6,   KC_P9,\
  MO(_FL),  KC_PGUP, LGUI(KC_C), BL_TOGG, \
  KC_ENTER, KC_PGDOWN,LGUI(KC_V), RGB_TOG, \
  KC_MUTE,  KC_VOLD, KC_VOLU, RESET),

  /* Keymap _FL: Function Layer
   * ,-------------------.
   * |Left|PGUP|MLFT| MB1|
   * |----|----|----|----|
   * |DOWN|UP  |MDWN|MUP |
   * |----|----|----|----|
   * |RIGT|PGDW|MRGT|MB2 |
   * |----|----|----|----|
   * |SAD |SAI |BOFF|    |
   * |----|----|----|----|
   * |VAD |VAS | 3  |    |
   * |----|----|----|----|
   * |   0|    |RST |    |
   * `-------------------'
   */
[_FL] = LAYOUT_ortho_6x4(
  KC_LEFT,  KC_PGUP,   KC_MS_L,  KC_BTN1,\
  KC_DOWN,  KC_UP,  KC_MS_D,  KC_MS_U, \
  KC_RIGHT, KC_PGDOWN,  KC_MS_R,  KC_BTN2, \
  RGB_SAD,  RGB_SAI,  BL_OFF,   KC_PPLS, \
  RGB_VAD,  RGB_VAI,  KC_P3,    RESET,  \
  KC_P0,  RESET   , RESET ,   RESET),
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = MO(_FL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
         if (record->event.pressed) {
            cospad_bl_led_togg();
         }
         return false;
      case BL_ON:
         if (record->event.pressed) {
            cospad_bl_led_on();
         }
         return false;
      case BL_OFF:
         if(record->event.pressed) {
            cospad_bl_led_off();
         }
         return false;
      default:
         return true;
   }
}
