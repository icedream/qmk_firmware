/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
#include "mousekey.h"

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 16

enum custom_keycodes {
    CUSTOM_WHEEL_TAB = SAFE_RANGE,
};

#define CUSTOM_MUTE_OR_WHEEL_TAB CUSTOM_WHEEL_TAB
#else
#define CUSTOM_MUTE_OR_WHEEL_TAB KC_MUTE
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           CUSTOM_MUTE_OR_WHEEL_TAB,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CUSTOM_WHEEL_TAB:
        if (record->event.pressed) {
            register_code16(KC_LALT);
        } else {
            unregister_code16(KC_LALT);
        }
        break;
    }
    return true;
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = {
//         {CUSTOM_WHEEL_TAB, KC_ESC},
//         // ...
//     },
// };

bool encoder_update_vol(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool encoder_update_prog_tab(uint8_t index, bool clockwise) {
    // use alt+tab/shift+alt+tab to tab between programs
    register_code16(KC_LALT);
    if (clockwise) {
        tap_code16(KC_TAB);
    } else {
        tap_code16(LSFT(KC_TAB));
    }
    return true;
}

enum encoder_wheel_mode {
    ENCODER_WHEEL_MODE_IDLE,
    ENCODER_WHEEL_MODE_DOWN,
    ENCODER_WHEEL_MODE_UP,
};

uint8_t encoder_wheel_current_mode = ENCODER_WHEEL_MODE_IDLE;
uint16_t encoder_wheel_timer = 0;

void matrix_scan_user(void) {
    if (encoder_wheel_current_mode != ENCODER_WHEEL_MODE_IDLE) { // we scrolling right now
        if (timer_elapsed(encoder_wheel_timer) > MOUSEKEY_WHEEL_INTERVAL) { // we stopped wheelin' though
            // stop the scrolling
            if (encoder_wheel_current_mode == ENCODER_WHEEL_MODE_UP) {
                unregister_code16(KC_WH_U);
            } else {
                unregister_code16(KC_WH_D);
            }
            encoder_wheel_current_mode = ENCODER_WHEEL_MODE_IDLE;
        }
    }
}

bool encoder_update_wheel(uint8_t index, bool clockwise) {
    // act as a mouse wheel
    if (clockwise) { // down
        if (encoder_wheel_current_mode == ENCODER_WHEEL_MODE_UP) {
            unregister_code16(KC_WH_U);
        }
        encoder_wheel_current_mode = ENCODER_WHEEL_MODE_DOWN;
        register_code16(KC_WH_D);
    } else { // up
        if (encoder_wheel_current_mode == ENCODER_WHEEL_MODE_DOWN) {
            unregister_code16(KC_WH_D);
        }
        encoder_wheel_current_mode = ENCODER_WHEEL_MODE_UP;
        register_code16(KC_WH_U);
    }
    encoder_wheel_timer = timer_read();
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case 0: // layer 0
            if (index == 0) {
                return encoder_update_prog_tab(index, clockwise);
            }
            break;
        case 1: // layer 1
            return encoder_update_wheel(index, clockwise);
        default: // all other layers
            return encoder_update_vol(index, clockwise);
    }
    return true;
}
#endif // ENCODER_ENABLE

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB LED layout

    // led number, function of the key
    //  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
    //  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
    //  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
    //  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
    //  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
    //  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
    //  87, Side led 07                                                                                                                                                                                                        88, Side led 18
    //  91, Side led 08                                                                                                                                                                                                        92, Side led 19

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(3, 255, 255, 255); //capslock key
    }
    // if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(67, 0, 255, 0); //side led 01
    //     RGB_MATRIX_INDICATOR_SET_COLOR(70, 0, 255, 0); //side led 02
    //     RGB_MATRIX_INDICATOR_SET_COLOR(73, 0, 255, 0); //side led 03
    // }
    // if (!IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
    //     RGB_MATRIX_INDICATOR_SET_COLOR(83, 255, 0, 255); //side led 06
    //     RGB_MATRIX_INDICATOR_SET_COLOR(87, 255, 0, 255); //side led 07
    //     RGB_MATRIX_INDICATOR_SET_COLOR(91, 255, 0, 255); //side led 08
    // }
    switch (get_highest_layer(layer_state)){  // special handling per layer
        case 1:  // FN layer/layer 0
            if (rgb_matrix_is_enabled()) {
                uint8_t speedIndicatorRed = 255 - rgb_matrix_get_speed();
                uint8_t speedIndicatorGreen = rgb_matrix_get_speed();
                uint8_t speedIndicatorBlue = 0;
                RGB_MATRIX_INDICATOR_SET_COLOR(7, 0, 255, 0); // 1, RGB Toggle
                RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 255, 255); // W, RGB Brightness +
                RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 255, 255); // S, RGB Brightness -
                RGB_MATRIX_INDICATOR_SET_COLOR(16, 255, 255, 255); // X, RGB Hue +
                RGB_MATRIX_INDICATOR_SET_COLOR(16, 255, 255, 255); // X, RGB Hue +
                RGB_MATRIX_INDICATOR_SET_COLOR(94, 255, 255, 255); // Up, MOD
                RGB_MATRIX_INDICATOR_SET_COLOR(97, 255, 255, 255); // Down, RMOD
                RGB_MATRIX_INDICATOR_SET_COLOR(95, speedIndicatorRed, speedIndicatorGreen, speedIndicatorBlue); // Left, SPD
                RGB_MATRIX_INDICATOR_SET_COLOR(79, speedIndicatorRed, speedIndicatorGreen, speedIndicatorBlue); // Right, SPI
            } else {
                RGB_MATRIX_INDICATOR_SET_COLOR(7, 255, 0, 0); // 1, RGB Toggle
            }

            // light up special function keys
            RGB_MATRIX_INDICATOR_SET_COLOR(38, keymap_config.nkro ? 0 : 255, keymap_config.nkro ? 255 : 0, 0); // N, N-key rollover
            RGB_MATRIX_INDICATOR_SET_COLOR(6, 255, 255, 255); // F1
            RGB_MATRIX_INDICATOR_SET_COLOR(12, 255, 255, 255); // F2
            RGB_MATRIX_INDICATOR_SET_COLOR(18, 255, 255, 255); // F3
            RGB_MATRIX_INDICATOR_SET_COLOR(23, 255, 255, 255); // F4
            RGB_MATRIX_INDICATOR_SET_COLOR(28, 255, 255, 255); // F5
            RGB_MATRIX_INDICATOR_SET_COLOR(34, 255, 255, 255); // F6
            RGB_MATRIX_INDICATOR_SET_COLOR(39, 255, 255, 255); // F7
            RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 255, 255); // F8
            RGB_MATRIX_INDICATOR_SET_COLOR(50, 255, 255, 255); // F9
            RGB_MATRIX_INDICATOR_SET_COLOR(56, 255, 255, 255); // F10
            RGB_MATRIX_INDICATOR_SET_COLOR(61, 255, 255, 255); // F11
            RGB_MATRIX_INDICATOR_SET_COLOR(93, 255, 0, 0); // \, reset

            break;
        case 2:
            // RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 0, 255); //esc
            break;
        case 3:
            // rgb_matrix_set_color_all(255, 255, 0);
            break;
        default:
            break;
    }
}
