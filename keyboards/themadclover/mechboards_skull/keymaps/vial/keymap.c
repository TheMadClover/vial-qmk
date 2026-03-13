#include QMK_KEYBOARD_H

#include "transactions.h"
#include "color.h"
#include "oneshot.h"
#include "swapper.h"

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

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    LED,
};

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
    [DEF] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
                                   LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM
    ),

    [SYM] = LAYOUT_split_3x5_2(
        KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
        KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, XXXXXXX, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,
                                   _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_split_3x5_2(
        KC_TAB,  SW_WIN,  TAB_L,   TAB_R,   KC_VOLU, KC_PSCR, HOME,    KC_UP,   END,     KC_DEL,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        SEL_L,   SEL_R,   BACK,    FWD,     KC_MPLY, TG(4),   KC_PGDN, KC_PGUP, EPIC, KC_ENT,
                                   _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_split_3x5_2(
        KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  KC_F10,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
        KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,
                                   _______, _______, _______, _______
    ),
    [LED] = LAYOUT_split_3x5_2(
        QK_BOOT,    _______,    _______,    EY_TOGG,    UG_TOGG,                               _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    EY_HUE,     UG_HUEU,                               _______,    _______,    _______,    _______,    _______,
        _______,    _______,    EY_SAT ,    EY_VAL,     UG_NEXT,                               _______,    _______,    _______, _______,  _______,
                                            _______,    _______,                               _______,  _______
    )
};

typedef union eyergb_config_t {
    uint32_t raw;
    struct {
        bool    enable : 1;
        uint8_t hue : 8;
        uint8_t sat : 8;
        uint8_t val : 8;
    };
} eyergb_config_t;

eyergb_config_t user_eyeconfig = {
    .enable = true,
    .hue = 8,
    .sat = 255,
    .val = 255
};

void set_eyehsv(bool enable, uint8_t hue, uint8_t sat, uint8_t val){

    if (user_eyeconfig.enable){
        hsv_t hsv = {hue,sat,val};
        rgb_t colour = hsv_to_rgb(hsv);
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, colour.r, colour.g, colour.b);
        }
    } else {
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, 0, 0, 0);
        }
    }

    rgblight_driver.flush();
}

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

    switch (keycode) {
    case EY_TOGG:
        if (record->event.pressed) {
            user_eyeconfig.enable = !user_eyeconfig.enable;
            set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
        }
        break;
    case EY_HUE:
        if (record->event.pressed) {
            user_eyeconfig.hue = user_eyeconfig.hue + RGBLIGHT_HUE_STEP;
            set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
        }
        break;
    case EY_SAT:
        if (record->event.pressed) {
            user_eyeconfig.sat = user_eyeconfig.sat + RGBLIGHT_SAT_STEP;
            set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
        }
        break;
    case EY_VAL:
        if (record->event.pressed) {
            user_eyeconfig.val = user_eyeconfig.val + RGBLIGHT_VAL_STEP;
            set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
        }
        break;
    }

    return true;
};

void user_sync_eyehsv_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const eyergb_config_t *m2s = (const eyergb_config_t*)in_data;

    if (user_eyeconfig.raw != m2s->raw){
        user_eyeconfig.raw = m2s->raw;
        set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
    }
}

void eeconfig_init_user(void) {
  user_eyeconfig.raw = 0;
  user_eyeconfig.enable = 1;
  user_eyeconfig.hue = 0;
  user_eyeconfig.sat = 255;
  user_eyeconfig.val = 255;

  eeconfig_update_user(user_eyeconfig.raw);

  set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
}

void keyboard_post_init_user(void){
    user_eyeconfig.raw = eeconfig_read_user();
    if (is_keyboard_left()){
        rgblight_set_effect_range(0, 10);
    } else {
        rgblight_set_effect_range(13, 10);
    }
    transaction_register_rpc(USER_SYNC_A, user_sync_eyehsv_handler);
    set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 100) {
            if(transaction_rpc_send(USER_SYNC_A, sizeof(user_eyeconfig), &user_eyeconfig)) {
                last_sync = timer_read32();
            }
        }
    }

    static uint32_t eeprom_sync = 0;
    if (timer_elapsed32(eeprom_sync) > 10000) { // check user eeprom every 10 seconds
        uint32_t raw = eeconfig_read_user();
        if(raw != user_eyeconfig.raw) {
                raw = user_eyeconfig.raw;
                eeconfig_update_user(raw);
        }
    }
}
