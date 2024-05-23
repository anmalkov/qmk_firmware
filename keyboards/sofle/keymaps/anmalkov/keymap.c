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

#define BSPACE_NAV LT(NAV, KC_BSPC)
#define ESC_SYM LT(SYM, KC_ESC)
#define DEL_SYM LT(SYM, KC_DEL)
#define LGUI_WIN LT(WIN, KC_LGUI)
#define TAB_NUM LT(NUM, KC_TAB)

/* Layers
                    BASE
                      |
     .------+------+------+------.
     |      |      |      |      |
    NAV    NUM    SYM   MOUSE   WIN
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
    BTN1_DBL,              // Double left mouse click
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
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Snip |   W  |   L  |   Y  |   P  |   B  |                    |   Z  |   F  |   O  |   U  |   '  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   -  |   C  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   A  |   _  |
 * |      |      |  Alt | Ctrl | Shift|      |                    |      |Shift | Ctrl |  Alt |      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |   :  |   Q  |   J  |   V  |   D  |   K  |  mute |    | zoom  |   X  |   H  |   ,  |   .  |   ;  |   /  |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |  Os  |      |  Esc |Backsp|  Tab  |    | Enter | Space|  Del |      |  Os  |
 *               |  WIN | MOUSE|  SYM | NAV  |  NUM  |    |       |      |  SYM |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[BASE] = LAYOUT(
  KC_F1,      KC_F2, KC_F3,        KC_F4,        KC_F5,        KC_F6,                            KC_F7,   KC_F8,        KC_F9,        KC_F10,       KC_F11,  KC_F12,
  SGUI(KC_S), KC_W,  KC_L,         KC_Y,         KC_P,         KC_B,                             KC_Z,    KC_F,         KC_O,         KC_U,         KC_QUOT, KC_BSLS,
  KC_MINS,    KC_C,  LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                             KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), KC_A,    KC_UNDS,
  KC_COLN,    KC_Q,  KC_J,         KC_V,         KC_D,         KC_K,       KC_MUTE,     _______, KC_X,    KC_H,         KC_COMM,      KC_DOT,       KC_SCLN, KC_SLSH,
                     LGUI_WIN,     MO(MOUSE),    ESC_SYM,      BSPACE_NAV, TAB_NUM,     KC_ENT,  KC_SPC,  DEL_SYM,      XXXXXXX,      KC_RGUI
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | LLOCK|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PgUp | Home |  Up  |  End |C-PgUp|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    | PgDn | Left | Down | Right|C-PgDn|Ctrl+A|
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |Select| Copy | Paste|  Cut | Undo | Redo |
 * |      |      |      |      |      |      |       |    |       | line |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______,  _______,    LLOCK,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGUP, KC_HOME, KC_UP,   KC_END,   C(KC_PGUP), _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, C(KC_PGDN), C(KC_A),
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, SELLINE, C(KC_C), C(KC_V),  C(KC_X), C(KC_Z),    C(KC_Y),
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* NUM 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | Calc |      |      |      |      | LLOCK|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   +  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    |   -  |   4  |   5  |   6  |   /  |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |   :  |   1  |   2  |   3  |   =  |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |   ,  |   0  |   .  |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       KC_CALC, _______, _______, _______, _______, LLOCK,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_COLN, KC_1,    KC_2,    KC_3,    KC_PEQL, _______,
                    _______, _______, _______, _______, _______,     _______, _______, KC_COMM, KC_0,    KC_DOT
),

/* SYM 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | LLOCK|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   _  |   <  |   >  |   "  |   `  |                    |   &  |  =>  |   [  |   ]  |   %  |      |
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
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, LLOCK,
  _______, KC_UNDS, KC_LABK, KC_RABK, KC_DQUO, KC_GRV,                        KC_AMPR, LMBDA,   KC_LBRC, KC_RBRC, KC_PERC, _______,
  _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                       KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR,   _______,     _______, KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT,   _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* MOUSE orbital
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |DblClc|LClick| Fwrd |RClick|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    | Hold | rot -| Bkwd | rot +|      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |Releas|Wh-Up |Wh-Dwn|      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
// orbital
// [MOUSE] = LAYOUT(
//   _______,  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, LLOCK,
//   _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       OM_DBLS, OM_BTNS, OM_U,    OM_BTN2, _______, _______,
//   TO(BASE), XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       OM_HLDS, OM_L,    OM_D,    OM_R,    _______, TO(BASE),
//   _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, OM_RELS, OM_W_D , OM_W_U , _______, _______, _______,
//                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
// ),

/* MOUSE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | LLOCK|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |DClick|LClick|  Up  |RClick|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      | WH-L | WH-D | WH-U | WH-R |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______,  _______, _______, _______, _______, LLOCK,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       BTN1_DBL, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       _______,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, _______,  KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,
                     _______, _______, _______, _______, _______,     _______, LLOCK,   _______, _______, _______
),

/* WIN
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | Sleep|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl | Shift|      |                    |      |GUI+<-|      |GUI+->|      |      |
 * |------+------+------+------+------+------|-------.    .-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * '-------------+------+------+------+------+-------|    |-------|------+------+------+------+-------------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               '------'------'------'------'-------'    '-------'------'------'------'------'
 */
[WIN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______, _______,    _______, _______,     _______, KC_SLEP,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       _______, _______,    _______, _______,     _______, _______,
  _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       _______, G(KC_LEFT), _______, G(KC_RIGHT), _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, _______, _______,    _______, _______,     _______, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______,    _______, _______
),
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
      case BTN1_DBL:  // Double left mouse click.
        SEND_STRING_DELAY(SS_TAP(X_BTN1) SS_TAP(X_BTN1), MOUSE_DBL_CLICK_DELAY);
        return false;
    }
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    // Left encoder
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {
    // Right encoder
    if (clockwise) {
      SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_WH_U)), TAP_CODE_DELAY);
    } else {
      SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_WH_D)), TAP_CODE_DELAY);
    }
  }
  return true;
}

void print_layer_status(void) {
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("LAYER"), false);
  oled_write_P(PSTR("\n\n"), false);
  switch (get_highest_layer(layer_state)) {
      case BASE:
        oled_write_ln_P(PSTR("BASE"), false);
        break;
      case NAV:
        oled_write_ln_P(PSTR("NAV"), false);
        break;
      case NUM:
        oled_write_ln_P(PSTR("NUM"), false);
        break;
      case SYM:
        oled_write_ln_P(PSTR("SYM"), false);
        break;
      case MOUSE:
        oled_write_ln_P(PSTR("MOUSE"), false);
        break;
      case WIN:
        oled_write_ln_P(PSTR("WIN"), false);
        break;
      default:
        oled_write_ln_P(PSTR("Undef"), false);
  }  
}

// void print_time(void) {
//   char time_str[21];  // Buffer to hold the formatted time string

//   uint8_t hour = hour();
//   uint8_t minute = minute();

//   int cet_hour = (hour + 1) % 24;  // CET: UTC +1
//   int pdt_hour = (hour - 7 + 24) % 24;  // PDT: UTC -7
//   int edt_hour = (hour - 4 + 24) % 24;  // EDT: UTC -4
//   int mel_hour = (hour + 10) % 24;  // MEL: UTC +10

//   oled_clear();

//   // CET
//   oled_write_ln("CET", false);
//   snprintf(time_str, sizeof(time_str), "%02d:%02d", cet_hour, minute);
//   oled_write_ln(time_str, false);
//   oled_write_P(PSTR("\n\n"), false);

//   // EDT
//   oled_write_ln("EDT", false);
//   snprintf(time_str, sizeof(time_str), "%02d:%02d", edt_hour, minute);
//   oled_write_ln(time_str, false);
//   oled_write_P(PSTR("\n\n"), false);

//   // PDT
//   oled_write_ln("PDT", false);
//   snprintf(time_str, sizeof(time_str), "%02d:%02d", pdt_hour, minute);
//   oled_write_ln(time_str, false);
//   oled_write_P(PSTR("\n\n"), false);

//   // MEL
//   oled_write_ln("MEL", false);
//   snprintf(time_str, sizeof(time_str), "%02d:%02d", mel_hour, minute);
//   oled_write_ln(time_str, false);
// }

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_layer_status();
  } else {
    //print_time();
  }
  return false;
}

void matrix_scan_user(void) {
  #ifdef ACHORDION_ENABLE
  achordion_task();
  #endif  // ACHORDION_ENABLE
  #ifdef ORBITAL_MOUSE_ENABLE
  orbital_mouse_task();
  #endif  // ORBITAL_MOUSE_ENABLE
}
