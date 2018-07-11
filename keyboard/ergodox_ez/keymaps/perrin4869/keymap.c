#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define NAVL 1 // navigation layer
#define NUMP 2 // numpad Layer
#define QWRT 3 // querty Layer
#define HEBL 4 // hebrew Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Qwerty |   1  |   2  |   3  |   4  |   5  | Nump |           | Navl |  6   |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   '  |   ,  |   .  |   P  |   Y  | [    |           | ]    |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ESC    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| =    |           | \    |------+------+------+------+------+--------|
 * | LSHIFT |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RSHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | LGUI   | Navl | COPY | CUT  | PASTE|                                       |  [   |   ]  | UNDO | Nump | RGUI   |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       | PgUp | PgDn   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LALT |       | RALT |        |      |
 *                                 | BACK | LCTL |------|       |------|  Enter |SPACE |
 *                                 |      |      | DEL  |       | RCTL |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        TG(QWRT),   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,   MO(NUMP),
        KC_TAB,     KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,   KC_LBRC,
        KC_ESC,     KC_A,       KC_O,       KC_E,       KC_U,       KC_I,
        KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,   KC_EQL,
        KC_LGUI,    MO(NAVL),   LCTL(KC_C), LCTL(KC_X), LCTL(KC_V),
                                             KC_HOME,           KC_END,
                                                                KC_LALT,
                                             KC_BSPC,KC_LCTL,   KC_DEL,
        // right hand
             MO(NAVL),  KC_6,   KC_7,       KC_8,       KC_9,       KC_0,           KC_GRV,
             KC_RBRC,   KC_F,   KC_G,       KC_C,       KC_R,       KC_L,           KC_SLSH,
                        KC_D,   KC_H,       KC_T,       KC_N,       KC_S,           KC_MINS,
             KC_BSLS,   KC_B,   KC_M,       KC_W,       KC_V,       KC_Z,           KC_RSFT,
                                KC_LBRC,    KC_RBRC,    LCTL(KC_Z), MO(NUMP),       KC_RGUI,
             KC_PGUP,            KC_PGDN,
             KC_RALT,
             KC_RCTL,KC_ENT,    KC_SPC
    ),
/* Keymap 1: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  MUTE  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  UP  |      |      | VOL+ |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LEFT | DOWN | RIGHT|      |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------| VOL- |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
       KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_VOLU,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
       KC_TRNS,  KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS,
                 KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
                          KC_P0,   KC_TRNS, KC_P,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  q   |  w   |  e   |  r   |   t  |      |           |      |  y   |   u  |  i   |  o   |  p   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  a   |  s   |  d   |  f   |   g  |------|           |------|  h   |   j  |  k   |  l   |  ;   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  z   |  x   |  c   |  v   |   b  |      |           |      |  n   |   m  |  ,   |  .   |  /   |        |
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
[QWRT] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,
       KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G,
       KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_MPLY,
       KC_TRNS,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[HEBL] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_QUOT, KC_SLSH, UC(1512), UC(1488), KC_TRNS,
       KC_TRNS, UC(1513), UC(1491), UC(1490), UC(1499), UC(1506),
       KC_TRNS, UC(1494), UC(1505), UC(1489), UC(1492), UC(1504), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  UC(1496), UC(1493), UC(1511), UC(1501), UC(1508), KC_TRNS,
                 UC(1497), UC(1495), UC(1500), UC(1498), UC(1507), KC_MPLY,
       KC_TRNS,  UC(1502), UC(1510), UC(1514), UC(1509), UC(1503), KC_TRNS,
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
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

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
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
