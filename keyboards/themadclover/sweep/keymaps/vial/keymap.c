// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

/*  Default values - replace with personal
#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
*/

#define HOME KC_HOME
#define END KC_END
#define FWD A(KC_RGHT)
#define BACK A(KC_LEFT)
#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)
#define SEL_L C(S(KC_LEFT))
#define SEL_R C(S(KC_RGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define LA_COL DF(COL)
#define LA_DEF DF(DEF)

enum layers {
  DEF,
  COL,
  SYM,
  NAV,
  NUM,
  GAME,
};

enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = QK_KB_0,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
  SW_WIN,  // Switch to next window         (cmd-tab)
  SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  Default value - replace with personal
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_CTLA, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN,
    KC_LSHZ, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_RLSH,
                                    KC_CLGV, KC_BSM1, KC_SPM2, KC_GUTA
  ),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    QK_GESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [4] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [5] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */

  [DEF] = LAYOUT_split_3x5_2(
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT,
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
                                LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM
  ),

  [COL] = LAYOUT_split_3x5_2(
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
                                LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM
  ),

  [SYM] = LAYOUT_split_3x5_2(
      KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
      KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
      KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, LA_COL, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,
                                _______, _______, _______, _______
  ),

  [NAV] = LAYOUT_split_3x5_2(
      KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU, KC_PSCR, HOME,    KC_UP,   END,     KC_DEL,
      OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
      SEL_L,   SEL_R,   BACK,    FWD,     KC_MPLY, LA_DEF,  KC_PGDN, KC_PGUP, SW_LANG, KC_ENT,
                                _______, _______, _______, _______
  ),

  [NUM] = LAYOUT_split_3x5_2(
      KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
      OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  KC_F10,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
      KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,
                                _______, _______, _______, _______
  ),

  [GAME] = LAYOUT_split_3x5_2(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,
                                 KC_LCTL, KC_SPC,  KC_BSPC, KC_0
  ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case LA_SYM:
  case LA_NAV:
      return true;
  default:
      return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case LA_SYM:
  case LA_NAV:
  case KC_LSFT:
  case OS_SHFT:
  case OS_CTRL:
  case OS_ALT:
  case OS_CMD:
      return true;
  default:
      return false;
  }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(
      &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
      keycode, record
  );
  update_swapper(
      &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
      keycode, record
  );

  update_oneshot(
      &os_shft_state, KC_LSFT, OS_SHFT,
      keycode, record
  );
  update_oneshot(
      &os_ctrl_state, KC_LCTL, OS_CTRL,
      keycode, record
  );
  update_oneshot(
      &os_alt_state, KC_LALT, OS_ALT,
      keycode, record
  );
  update_oneshot(
      &os_cmd_state, KC_LCMD, OS_CMD,
      keycode, record
  );

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, SYM, NAV, NUM);
}
