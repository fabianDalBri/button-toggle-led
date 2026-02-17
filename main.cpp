#include "pico/stdlib.h"

#define LED 15
#define BTN 14   // change if you moved to GP0 or another pin

int main() {
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);  // button wired to GND

    bool led_state = false;
    gpio_put(LED, led_state);

    while (true) {

        // detect press (active-LOW)
        if (gpio_get(BTN) == 0) {

            sleep_ms(30);  // debounce press

            if (gpio_get(BTN) == 0) {

                // toggle state
                led_state = !led_state;
                gpio_put(LED, led_state);

                // wait until button released
                while (gpio_get(BTN) == 0) {
                    sleep_ms(1);
                }

                sleep_ms(30); // debounce release
            }
        }
    }
}
