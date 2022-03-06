#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED 4

int app_main(){
    gpio_config_t configLED;
    configLED.mode = GPIO_MODE_OUTPUT;
    configLED.pull_up_en = GPIO_PULLUP_DISABLE;
    configLED.pull_down_en = GPIO_PULLDOWN_DISABLE;
    configLED.intr_type = GPIO_INTR_DISABLE;
    configLED.pin_bit_mask = (1ULL << LED);
    gpio_config(&configLED);

    while(true) {
        gpio_set_level(LED, 0);
        vTaskDelay(500 / portTICK_RATE_MS);
        gpio_set_level(LED, 1);
        vTaskDelay(500 / portTICK_RATE_MS);
    }

}