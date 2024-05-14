#include QMK_KEYBOARD_H

#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE
#ifdef LAYER_LOCK_ENABLE
#include "features/layer_lock.h"
#endif  // LAYER_LOCK_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
#include "features/orbital_mouse.h"
#endif  // ORBITAL_MOUSE_ENABLE

#define SPACE_NAV LT(NAV, KC_SPC)
#define BSPACE_SYM LT(SYM, KC_BSPC)
#define UNDS_SYM LT(SYM, KC_UNDS)
#define ESC_MOUSE LT(MOUSE, KC_ESC)
#define LGUI_WIN LT(WIN, KC_LGUI)
#define TAB_NUM LT(WIN, KC_TAB)

/* Layers
                    BASE
                      |
     .------+------+------+------+------.
     |      |      |      |      |      |
    NAV    NUM    FUN    SYM   MOUSE   WIN
*/
enum sofle_layers {
    BASE,
    NAV,
    NUM,
    SYM,
    MOUSE,
    WIN,
};

enum custom_keycodes {
    SELLINE = SAFE_RANGE,  // Selects the current line
    LLOCK,                 // Locks the layer
    LMBDA,                 // Lambda (=>)
    UPDIR,                 // Up directory (../)
};

/* EMPTY
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
// [_EMPTY] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//                     _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
// ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Snip |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   W  |   L  |   Y  |   P  |   B  |                    |   Z  |   F  |   O  |   U  |   '  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   -  |   C  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   A  |   _  |
 * |      |      |  Alt | Ctrl | Shift|      |                    |      |Shift | Ctrl |  Alt |      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |   :  |   Q  |   J  |   V  |   D  |   K  |  mute |    | zoom  |   X  |   H  |   ,  |   .  |   ;  |   /  |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |  Os  |  Esc |   _  | Space|  Tab  |    | Enter | Space|Backsp|  Del |  Os  |
 *               |  WIN | MOUSE|  SYM | NAV  |  NUM  |    |       |      |  SYM |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[BASE] = LAYOUT(
  _______, KC_1, KC_2,         KC_3,         KC_4,         KC_5,                            KC_6,    KC_7,         KC_8,         KC_9,         KC_0,    SGUI(KC_S),
  _______, KC_W, KC_L,         KC_Y,         KC_P,         KC_B,                            KC_Z,    KC_F,         KC_O,         KC_U,         KC_QUOT, KC_BSLS,
  KC_MINS, KC_C, LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                            KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), KC_A,    KC_UNDS,
  KC_COLN, KC_Q, KC_J,         KC_V,         KC_D,         KC_K,      KC_MUTE,     _______, KC_X,    KC_H,         KC_COMM,      KC_DOT,       KC_SCLN, KC_SLSH,
                 LGUI_WIN,     ESC_MOUSE,    UNDS_SYM,     SPACE_NAV, TAB_NUM,     KC_ENT,  KC_SPC,  BSPACE_SYM,   KC_DEL,       KC_RGUI
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PgUp | Home |  Up  |  End |C-PgUp|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    | PgDn | Left | Down | Right|C-PgDn|  C-A |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |Select| Copy | Paste|  Cut | Undo | Redo |
 * |      |      |      |      |      |      |       |    |       | line |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       | LOCK |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______,  _______,    _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGUP, KC_HOME, KC_UP,   KC_END,   C(KC_PGUP), _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, C(KC_PGDN), C(KC_A),
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, SELLINE, C(KC_C), C(KC_V),  C(KC_X), C(KC_Z),    C(KC_Y),
                    _______, _______, _______, _______, _______,     _______, LLOCK,   _______, _______, _______
),

/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | Calc |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   :  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    |   +  |   4  |   5  |   6  |   /  |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |   -  |   1  |   2  |   3  |   *  |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |   ,  |   0  |   .  |
 *               |      |      |      | BASE |       |    |       | LOCK |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       KC_CALC, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_COLN, KC_7,    KC_8,    KC_9,    _______, _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_PPLS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_PMNS, KC_1,    KC_2,    KC_3,    KC_PAST, _______,
                    _______, _______, _______, _______, _______,     _______, LLOCK,   KC_PCMM, KC_0,    KC_PDOT
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   <  |   >  |   "  |   `  |                    |   &  |  =>  |   [  |   ]  |   %  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   -  |   +  |   =  |   #  |                    |   |  |   :  |   (  |   )  |   ?  |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |   ^  |   /  |   *  |   \  |  ../ |       |    |       |   ~  |   $  |   {  |   }  |   @  |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[SYM] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, KC_LABK, KC_RABK, KC_DQUO, KC_GRV,                        KC_AMPR, LMBDA,   KC_LBRC, KC_RBRC, KC_PERC, KC_F12,
  _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                       KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR,   _______,     _______, KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT,   _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* MOUSE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |DblClc| Click| Fwrd | Btn 2|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BASE |      |      |      |      |      |                    | Hold | rot -| Bkwd | rot +|      | BASE |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |Releas|Wh-Up |Wh-Dwn|      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       | LOCK |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[MOUSE] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       OM_DBLS, OM_BTNS, OM_U,    OM_BTN2, _______, _______,
  TO(BASE), XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       OM_HLDS, OM_L,    OM_D,    OM_R,    _______, TO(BASE),
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, OM_RELS, OM_W_D , OM_W_U , _______, _______, _______,
                     _______, _______, _______, _______, _______,     _______, LLOCK, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
  #endif  // ACHORDION_ENABLE
  #ifdef ORBITAL_MOUSE_ENABLE
  if (!process_orbital_mouse(keycode, record)) { return false; }
  #endif  // ORBITAL_MOUSE_ENABLE
  #ifdef LAYER_LOCK_ENABLE
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  #endif  // LAYER_LOCK_ENABLE

  if (record->event.pressed) {
    switch (keycode) {
      case SELLINE:  // Selects the current line.
        SEND_STRING_DELAY(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)), TAP_CODE_DELAY);
        return false;
      case LMBDA:  // Lambda (=>).
        SEND_STRING_DELAY("=>", TAP_CODE_DELAY);
        return false;
      case UPDIR:  // Up directory (../).
        SEND_STRING_DELAY("../", TAP_CODE_DELAY);
        return false;
    }
  }
  return true;
}

void matrix_scan_user(void) {
  #ifdef ACHORDION_ENABLE
  achordion_task();
  #endif  // ACHORDION_ENABLE
  #ifdef ORBITAL_MOUSE_ENABLE
  orbital_mouse_task();
  #endif  // ORBITAL_MOUSE_ENABLE
}
