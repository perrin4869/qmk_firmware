#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define NAVL 1 // navigation layer
#define NUMP 2 // Numpad Layer
#define HEBL 3 // hebrew Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Hebrew |   1  |   2  |   3  |   4  |   5  |ALT+S |            |B.tick|  6   |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   '  |   ,  |   .  |   P  |   Y  | LCK2 |           | CTRL |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           | LEFT |------+------+------+------+------+--------|
 * | ESC    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| LCK1 |           | CTRL |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           | RIGHT|   B  |   M  |   W  |   V  |Z/Ctrl| RSHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |FN2   | COPY | CUT  | PASTE| FN1  |                                       |  [   |   ]  |   \  | UNDO | CTRL+A |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | WIN+D| ALT  |       | END  | HOME   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | SUPER|       | PgUp |        |      |
 *                                 | BACK | DEL  |------|       |------|  Enter |SPACE |
 *                                 | SPACE|      | CTRL |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        TG(HEBL),       KC_1,           KC_2,       KC_3,       KC_4,       KC_5,   LALT(KC_LSFT),
        KC_TAB,         KC_QUOT,        KC_COMM,    KC_DOT,     KC_P,       KC_Y,   TG(1),
        KC_ESC,         KC_A,           KC_O,       KC_E,       KC_U,       KC_I,
        KC_LSFT,        KC_SCLN,        KC_Q,       KC_J,       KC_K,       KC_X,   ALL_T(KC_NO),
        MO(NUMP),       LCTL(KC_C),     LCTL(KC_X), LCTL(KC_V), MO(NAVL),
                                             LGUI(KC_D),    KC_LALT,
                                                            KC_LGUI,
                                             KC_BSPC,KC_DEL,KC_LCTL,
        // right hand
             KC_GRV,        KC_6,   KC_7,       KC_8,       KC_9,       KC_0,           KC_EQL,
             LCTL(KC_LEFT), KC_F,   KC_G,       KC_C,       KC_R,       KC_L,           KC_SLSH,
                            KC_D,   KC_H,       KC_T,       KC_N,       KC_S,           KC_MINS,
             LCTL(KC_RIGHT),KC_B,   KC_M,       KC_W,       KC_V,       CTL_T(KC_Z),    KC_RSFT,
                                    KC_LBRC,    KC_RBRC,    KC_BSLS,    LCTL(KC_Z),     LCTL(KC_A),
             KC_END,        KC_HOME,
             KC_PGUP,
             KC_PGDN,KC_ENT,KC_SPC
    ),
/* Keymap 1: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | MUTE |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           | VOL  |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |   +  |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           | VOL  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |   -  |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Lclk | Rclk |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |PL/PS |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | NEXT |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | PREV |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAVL] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_MUTE,    KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
       KC_VOLU,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_MPLY,
       KC_VOLD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_MPLY, KC_TRNS,
       KC_MNXT,
       KC_MPRV, KC_TRNS, KC_TRNS
),
 /* Keymap 2: Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | NMLK |  P/  |  P*  |  P-  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |   8  |  9   |  P+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |   5  |  6   |  P+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |   2  |  3   | ENTER|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |      |  .   | ENTER|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMP] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS,
                 KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PENT,
                          KC_TRNS, KC_P0, KC_TRNS, KC_P, KC_PENT,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: HEBREW
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  w   |  '   |  /   |  r   |   t  |      |           |      |  y   |   u  |  e   |  o   |  p   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  a   |  s   |  d   |  f   |   g  |------|           |------|  h   |   j  |  k   |  l   |  ;   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  z   |  x   |  c   |  v   |   b  |      |           |      |  n   |   m  |  ,   |  .   |  i   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[HEBL] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_W, KC_QUOT, KC_SLSH, KC_R, KC_T, KC_TRNS,
       KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G,
       KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_Y, KC_U, KC_E, KC_O, KC_P, KC_TRNS,
                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_MPLY,
       KC_TRNS,  KC_N, KC_M, KC_COMM, KC_DOT, KC_I, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NAVL)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
