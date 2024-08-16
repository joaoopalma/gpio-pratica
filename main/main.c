/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 18;
const int BTN_PIN = 13;
const int LED_PIN2 = 3;
const int LED_PIN3 = 4;
const int LED_PIN4 = 5;
const int LED_PIN5 = 6;

    int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_init(LED_PIN2);
    gpio_init(LED_PIN3);
    gpio_init(LED_PIN4);
    gpio_init(LED_PIN5);
    gpio_init(BTN_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    gpio_set_dir(LED_PIN3, GPIO_OUT);
    gpio_set_dir(LED_PIN4, GPIO_OUT);
    gpio_set_dir(LED_PIN5, GPIO_OUT);
    gpio_set_dir(BTN_PIN, GPIO_IN);

    gpio_pull_up(BTN_PIN);

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            gpio_put(LED_PIN, 1);
            for (int i = 0; i < 515; i++) {
                gpio_put(LED_PIN2, 1);
                sleep_ms(10);
                gpio_put(LED_PIN2, 0);
                gpio_put(LED_PIN3, 1);
                sleep_ms(10);
                gpio_put(LED_PIN3, 0);
                gpio_put(LED_PIN4, 1);
                sleep_ms(10);
                gpio_put(LED_PIN4, 0);
                gpio_put(LED_PIN5, 1);
                sleep_ms(10);
                gpio_put(LED_PIN5, 0);
                sleep_ms(10);
                }
                gpio_put(LED_PIN, 0);
        }
        
    }
}
