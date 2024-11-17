// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LA_NUM LT(_NUM, KC_LALT)

const uint16_t PROGMEM cmb_ent[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_map[] = {KC_Q, KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_map, KC_M),
};

enum layers {
    _DEF,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │
     * ├───┼───┼───┼───┼───┼───┤
     * │Bsp│ A │ S │ D │ F │ G │
     * ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │
     * ├───┼───┼───┼───┼───┼───┤
     * │Ctl│App│Spc│   │Spc│Spc│
     * └───┴───┴───┴───┴───┴───┘
     */
    [_DEF] = LAYOUT(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
        KC_BSPC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
        KC_LCTL,    LA_NUM,     KC_SPC,     KC_NO,      KC_SPC,     KC_SPC
    ),

    [_NUM] = LAYOUT(
        KC_ESC,     KC_7,       KC_8,       KC_9,       KC_ENT,     _______,
        _______,    KC_4,       KC_5,       KC_6,       KC_0,       _______,
        _______,    KC_1,       KC_2,       KC_3,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______
    )
};
