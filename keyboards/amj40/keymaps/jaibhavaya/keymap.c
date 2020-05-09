


#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3



enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Default Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * |LCtl/Tab| A | S | D |  F |  G |  H |  J |  K |  L | Ent    |
     * |-----------------------------------------------------------|
     * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  ;  | /? |RSft|
     * |-----------------------------------------------------------|
     * | LAlt | LCtl| LGui|    fn0  |    spc        | [  |  ] | \  |
     * `-----------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,\
        MT(MOD_LCTL, KC_TAB),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT,\
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_SCLN, KC_SLSH,  KC_RSFT,\
        KC_LALT, KC_LCTL, KC_LGUI, _LOWER,KC_SPC,KC_LBRC, KC_RBRC, KC_BSLS \
		),

    /* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |   `  |   1   |  2  | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | Bkspc|
     * |-----------------------------------------------------------|
     * |     |  |  |  |  |   | Left  | Down  | Up | Right |        |
     * |-----------------------------------------------------------|
     * |        |    |    |    |    | -  |=   | ,   |.  | '   |    |
     * |-----------------------------------------------------------|
     * |RESET |    |    |           |             |      |   |     |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
        KC_GRV, KC_1, KC_2,   KC_3, KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
		_______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, \
		_______,   _______,   _______,   _______,  _______,  KC_MINUS,KC_EQL, KC_COMM, KC_DOT,KC_QUOT, _______, \
		RESET, _______, _______, _______, _______, _______, _______, _______ \
		),
	
	/* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * | `/~ | 1  | 2  | 3  |  4 |  5 |  6 |  7 |  8 | 9 | 0 | Del |
     * |-----------------------------------------------------------|
     * |      |    |    |    |    |   |   |   | ;  | '   |         |
     * |-----------------------------------------------------------|
     * |        | |  |    |  + |  - | | - | =  |   ,    |     |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             | Stop| App|     |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
		_______,   _______,   _______,   _______,   _______,   _______,   _______, _______,  KC_SCLN, KC_QUOT, _______, \
		_______,   _______,   _______,   _______,  _______,  _______,  KC_MINS, KC_EQL, KC_COMM, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______ \
		),
	
	/* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |Caps|    |MSel| ⏮ | ⏯ | ⏭ |PSCR|SkLk|Paus|  ↑ | Ins| Del|
     * |-----------------------------------------------------------|
     * |      | 🔇 | ⏏ |    |  * |  / |Hone|PgUp|  ← |  → |       |
     * |-----------------------------------------------------------|
     * |        | 🔉 | 🔊 |    |  + |  - | End|PgDn| ↓ |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             | Stop| App|RESET|
     * `-----------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT( \
        _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
		_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______,  _______,  \
		_______, _______, _______, RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD, \
		KC_SYSTEM_SLEEP, _______, _______, _______, _______, _______, _______, RESET \
		),

    

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
  switch (keycode) {
    
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
