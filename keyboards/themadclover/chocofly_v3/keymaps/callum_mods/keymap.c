#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define LOCK G(KC_L)
#define HOME KC_HOME
#define END KC_END
#define FWD A(KC_RGHT)
#define BACK A(KC_LEFT)
#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)
#define SPACE_L S(C(KC_LEFT))
#define SPACE_R S(C(KC_RGHT))
#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_COL DF(_COL)
#define LA_QTY DF(_QTY)
#define EPIC C(KC_SPC)
#define SW_WIN2 C(A(KC_TAB))

const uint16_t PROGMEM cmb_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_win[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_bsp[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_chtsrch[] = {KC_Q, KC_R, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_win, KC_LGUI),
    COMBO(cmb_del, KC_DEL),
    COMBO(cmb_bsp, KC_BSPC),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_chtsrch, C(KC_LSFT)),
};
enum layers {
    _QTY,
    _COL,
    _SYM,
    _NAV,
    _NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};
/*
#define RS_SPC LT(_RAISE, KC_SPC)
#define LW_LGUI LT(_LOWER, KC_LGUI)
#define RS_LGUI LT(_RAISE, KC_LGUI)
#define MT_LALT LALT_T(KC_ESC)
#define MT_RALT RALT_T(KC_ENT)
#define MT_LSFT LSFT_T(KC_EQL)
#define MT_RSFT RSFT_T(KC_MINS)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QTY] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT, KC_LBRC,
                 KC_BSLS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MUTE,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOCK,      _______,  _______,  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_RCTL,
                                                     _______, _______, LA_NAV,    KC_SPC,   KC_LSFT,  LA_SYM,   _______, _______
    ),
     [_COL] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                 _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, XXXXXXX,
                 _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______,                                 KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
                 _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,    _______,  _______,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, _______,
                                                     _______, _______, _______, _______,    _______,  _______,  _______, _______
    ),
    [_SYM] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                 _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,                                          KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV, XXXXXXX,
                 _______, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  _______,                                 KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX,
                 _______, KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, _______, _______,    _______,   _______, LA_COL,  KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM, _______,
                                                     _______, _______, _______, _______,    _______,   _______, _______, _______
    ),
    [_NAV] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                 _______, KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU,                                          KC_PSCR, HOME,    KC_UP,   END,     KC_DEL,  XXXXXXX,
                 _______, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_VOLD, _______,                                 KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
                 _______, SPACE_L, SPACE_R, BACK,    FWD,     KC_MPLY, _______, _______,    _______,   _______, LA_QTY,  KC_PGDN, KC_PGUP, SW_LANG, KC_ENT, _______,
                                                     _______, _______, _______, _______,    _______,   _______, _______, _______
    ),
     [_NUM] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                 _______, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                                             KC_8,    KC_0,    KC_2,    KC_4,    KC_6,    XXXXXXX,
                 _______, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  _______,                                 KC_F10,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX,
                 _______, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   _______, _______,    _______, _______,   KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,   _______,
                                                     _______, _______, _______, _______,    _______, _______,   _______, _______
    ),
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_COL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

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
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
/*
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder //
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    }
    return true;
}
*/
