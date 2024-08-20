// Copyright 2024 TheMadClover (@TheMadClover)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define EE_HANDS
#define COMBO_ONLY_FROM_LAYER 0

#define MATRIX_ROWS 8
#define MATRIX_COLS 5
/*
#define DIRECT_PINS { \
    { GP29, GP28, GP27, GP26, GP15 }, \
    { GP4, GP3, GP2, GP1,  GP0}, \
    { GP5, GP6, GP7, GP8, GP9 }, \
    { GP14, GP13, NO_PIN, NO_PIN, NO_PIN } \
}

#define DIRECT_PINS_RIGHT {  \
    { GP29, GP28, GP27, GP26, GP15 }, \
    { GP4, GP3, GP2, GP1,  GP0}, \
    { GP5, GP6, GP7, GP8, GP9 }, \
    { GP13, GP14, NO_PIN, NO_PIN, NO_PIN } \
}
*/

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Serial Config
#define USE_SERIAL
#define SERIAL_USART_TX_PIN GP11
*/

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
