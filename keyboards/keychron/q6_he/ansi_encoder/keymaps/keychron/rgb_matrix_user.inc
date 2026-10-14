// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)


#include "rgb_matrix_types.h"
RGB_MATRIX_EFFECT(pride_trans)
RGB_MATRIX_EFFECT(pride_lesbian)
RGB_MATRIX_EFFECT(pride_bi)
RGB_MATRIX_EFFECT(pride_demi)
RGB_MATRIX_EFFECT(pride_rainbow)
RGB_MATRIX_EFFECT(ukraine_flag)

// hack to make VS Code copletion work
// Remove TRUE to compile
#ifdef true2
#define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include "rgb_matrix.h"
#include "color.h"
#endif
// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


#define RGB_TRANS_BLUE 0x57, 0xCF, 0xFF
#define RGB_TRANS_PINK 0xFF, 0x8A, 0xA1


#define RGB_LESB_DORNG 0xD6, 0x29, 0x00
#define RGB_LESB_LORNG 0xFF, 0x9B, 0x55
#define RGB_LESB_LPURP 0xD4, 0x61, 0xA6
#define RGB_LESB_DPURP 0xA5, 0x00, 0x62


#define RGB_BI_CENTER  0x89, 0x50, 0x92
#define RGB_BI_TOP     0xB7, 0x04, 0x6D
#define RGB_BI_BOTTOM  0x21, 0x3B, 0xA3

#define RGB_DEMI_CNT   0x5E, 0x00, 0x6D
#define RGB_DEMI_TOP   RGB_WHITE
#define RGB_DEMI_BOT   0x51, 0x51, 0x51
#define RGB_DEMI_TRI   RGB_BLACK

#define RGB_UKRAINE_TOP 0x00, 0x57, 0x5B
#define RGB_UKRAINE_BOT 0xFF, 0xDD, 0x00


// Flag that has only horizontal stripes
static bool pride_horizontal_flag6(effect_params_t* params,
                                    uint8_t row0_r, uint8_t row0_g, uint8_t row0_b,
                                    uint8_t row1_r, uint8_t row1_g, uint8_t row1_b,
                                    uint8_t row2_r, uint8_t row2_g, uint8_t row2_b,
                                    uint8_t row3_r, uint8_t row3_g, uint8_t row3_b,
                                    uint8_t row4_r, uint8_t row4_g, uint8_t row4_b,
                                    uint8_t row5_r, uint8_t row5_g, uint8_t row5_b
                                 ) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            switch (g_led_config.matrix_co[r][c]) {
                case 255:
                    break;
                default:
                    switch (r) {
                        case 0:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row0_r, row0_g, row0_b);
                            break;
                        case 1:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row1_r, row1_g, row1_b);
                            break;
                        case 2:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row2_r, row2_g, row2_b);
                            break;
                        case 3:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row3_r, row3_g, row3_b);
                            break;
                        case 4:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row4_r, row4_g, row4_b);
                            break;
                        case 5:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row5_r, row5_g, row5_b);
                            break;
                        default:
                            break;
                    }
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// Flag that is mirrored with a set center color
static bool pride_mirrored_flag5(effect_params_t* params,
                                uint8_t row_center_r, uint8_t row_center_g, uint8_t row_center_b,
                                uint8_t row_pm1_r, uint8_t row_pm1_g, uint8_t row_pm1_b,
                                uint8_t row_pm2_r, uint8_t row_pm2_g, uint8_t row_pm2_b
                                ) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            switch (g_led_config.matrix_co[r][c]) {
                case 255:
                    break;
                default:
                    switch (r) {
                        case 0:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], RGB_BLACK);
                            break;
                        case 3:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row_center_r, row_center_g, row_center_b);
                            break;
                        case 2:
                        case 4:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row_pm1_r, row_pm1_g, row_pm1_b);
                            break;
                        case 1:
                        case 5:
                            rgb_matrix_set_color(g_led_config.matrix_co[r][c], row_pm2_r, row_pm2_g, row_pm2_b);
                            break;
                        default:
                            break;
                    }
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
                                };

static bool pride_trans(effect_params_t* params) {
    return pride_mirrored_flag5(params, RGB_WHITE, RGB_TRANS_PINK, RGB_TRANS_BLUE);
}

static bool pride_lesbian(effect_params_t* params) {
    return pride_horizontal_flag6(params,
                                  RGB_BLACK, RGB_LESB_DORNG, RGB_LESB_LORNG, RGB_WHITE, RGB_LESB_LPURP, RGB_LESB_DPURP);
}

static bool pride_bi(effect_params_t* params) {
    return pride_horizontal_flag6(params, RGB_BLACK, RGB_BI_TOP, RGB_BI_TOP, RGB_BI_CENTER, RGB_BI_BOTTOM, RGB_BI_BOTTOM);
}


static bool pride_demi(effect_params_t* params) {
    pride_horizontal_flag6(params, RGB_BLACK, RGB_DEMI_TOP, RGB_DEMI_TOP, RGB_DEMI_CNT, RGB_DEMI_BOT, RGB_DEMI_BOT);
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t r = 1; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < 3; c++) {
            switch (g_led_config.matrix_co[r][c]) {
                case 255:
                    break;
                default:
                    switch (r) {
                        case 1:
                        case 5:
                            if (c < 2) {
                                rgb_matrix_set_color(g_led_config.matrix_co[r][c], RGB_DEMI_TRI);
                                break;
                            } else {
                                break;
                            }

                        case 2:
                        case 4:
                            if (c < 3) {
                                rgb_matrix_set_color(g_led_config.matrix_co[r][c], RGB_DEMI_TRI);
                                break;
                            } else {
                                break;
                            }
                        case 3:
                            if (c < 4) {
                                rgb_matrix_set_color(g_led_config.matrix_co[r][c], RGB_DEMI_TRI);
                                break;
                            } else {
                                break;
                            }
                        default:
                            break;
                    }
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool pride_rainbow(effect_params_t* params) {
    return pride_horizontal_flag6(params, RGB_RED, RGB_ORANGE, RGB_YELLOW, RGB_GREEN, RGB_BLUE, RGB_PURPLE);
}

static bool ukraine_flag(effect_params_t* params) {
    return pride_horizontal_flag6(params, RGB_UKRAINE_TOP, RGB_UKRAINE_TOP, RGB_UKRAINE_TOP, RGB_UKRAINE_BOT, RGB_UKRAINE_BOT, RGB_UKRAINE_BOT);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
