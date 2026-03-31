#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "layers.h"

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
#define LA_DEF DF(DEF)
#define EPIC C(KC_SPC)

/*
enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │Bsp├───┐   ┌───┤Ent│
      *               └───┤Tab│   │Spc├───┘
      *                   └───┘   └───┘
      */
    [DEF] = LAYOUT_unicorny(
        _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT,    _______,
        _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,       _______,
        _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,    _______,
                                      _______, LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM,  _______
    ),

    [SYM] = LAYOUT_unicorny(
        _______,    KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,     _______,
        _______,    KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,    _______,
        _______,    KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, XXXXXXX, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,    _______,
                                      _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_unicorny(
        _______,    KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU, KC_PSCR, HOME,    KC_UP,   END,     KC_DEL,     _______,
        _______,    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,    _______,
        _______,    SEL_L,   SEL_R,   BACK,    FWD,     KC_MPLY, TG(4),   KC_PGDN, KC_PGUP, EPIC,    KC_ENT,     _______,
                                      _______, _______, _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_unicorny(
        _______,    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,       _______,
        _______,    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  KC_F10,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,    _______,
        _______,    KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,      _______,
                                      _______, _______, _______, _______, _______, _______
    )
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
/*bool sw_lang_active = false;*/

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );
    /*
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );
    */
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
