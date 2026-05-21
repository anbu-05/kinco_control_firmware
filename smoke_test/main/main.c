#include <stdio.h>

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

static const gpio_num_t led_pin = GPIO_NUM_2;
static const __uint32_t sleep_time_ms = 200;

__uint8_t led_state = 0;


void app_main(void)
{
    gpio_reset_pin(led_pin);
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

    while(1) {
        led_state = !led_state;
        gpio_set_level(led_pin, led_state);

        printf("LED state: %d\n", led_state);

        vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
    }

    
}
