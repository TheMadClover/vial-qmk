// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "oled.h"
#include "layers.h"

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case DEF:
            oled_write_raw_P(layer0_img, sizeof(layer0_img));
            break;
        case SYM:
            oled_write_raw_P(layer1_img, sizeof(layer1_img));
            break;
        case NAV:
            oled_write_raw_P(layer2_img, sizeof(layer2_img));
            break;
        case NUM:
            oled_write_raw_P(layer3_img, sizeof(layer3_img));
            break;
    }
}
