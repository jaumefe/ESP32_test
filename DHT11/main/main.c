#include <driver/gpio.h>
#include <rom/ets_sys.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define DHT11 5

void startup(){
    gpio_set_level(DHT11, 0);
    vTaskDelay(20/portTICK_RATE_MS);
    gpio_set_level(DHT11, 1);
}

void configGPIO(){
    gpio_config_t DHT = {
        .mode = GPIO_MODE_INPUT_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
        .pin_bit_mask = (1ULL << DHT11),
    };
    gpio_config(&configGPIO);
}