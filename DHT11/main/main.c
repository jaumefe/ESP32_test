#include <driver/gpio.h>
#include <rom/ets_sys.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "esp_timer.h"
#include "rom/ets_sys.h"

#define DHT11 15
static const char* TAG = "DHT11";
static const char* TAG1 = "Debug";

void startup(){
    gpio_set_direction(DHT11, GPIO_MODE_OUTPUT);
    gpio_set_level(DHT11, 0);
    vTaskDelay(20/portTICK_RATE_MS);
    gpio_set_level(DHT11, 1);
    vTaskDelay(40/portTICK_RATE_MS);
    gpio_set_direction(DHT11, GPIO_MODE_INPUT);
}

void configGPIO(){
    gpio_config_t DHT = {
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
        .pin_bit_mask = (1ULL << DHT11),
    };
    gpio_config(&DHT);
}

int waitOrTimeout (uint16_t us, int level){
    uint16_t timer = 0;
    ESP_LOGW(TAG1, "Punt 3.1: Timer:%d, Level:%d", timer, level);
    while(gpio_get_level(DHT11)==level){
        ESP_LOGW(TAG1, "Punt 3.2: Timer:%d, Level:%d", timer, level);
        if (timer++ > us){
            timer = 99;
            ESP_LOGW(TAG1, "Punt 3.3: Timer:%d, Level:%d", timer, level);
            break;
        }
        ets_delay_us(1);
    }
    ESP_LOGW(TAG1, "Punt 3.4");
    return timer;
}

int app_main(){
    //preparation for data
    int data[5] = {0,0,0,0,0};
    configGPIO();
    ESP_LOGW(TAG1, "Punt 1");
    while(1){
        int timer = esp_timer_get_time();
        //ESP_LOGW(TAG1, "Punt 2");
        int i = 1;
        if(timer>=i*2000000){
            startup();
            ESP_LOGW(TAG1, "Punt 3");
            int timer1 = waitOrTimeout(80, 0);
            ESP_LOGW(TAG1, "Punt 4: Level:%d", gpio_get_level(DHT11));
            int timer2 = waitOrTimeout(80, 1);
            ESP_LOGW(TAG1, "Punt 5");
            //Start to transmit 1 bit
            for(int i = 0; i < 40; i++){
                int timer3 = waitOrTimeout(50, 0);
                if(waitOrTimeout(70, 1) > 28){
                    data[i/8] = (1 << (7 - i%8));
                    ESP_LOGW(TAG1, "Punt 6: Data:%d,%d,%d,%d,%d,%d,%d,%d",data[0],data[1], data[2],data[3],data[4],data[5],data[6], data[7]);
                }
            }
            ESP_LOGW(TAG, "Temperature:%d.%d, Humidity: %d.%d", data[0], data[1], data[2], data[3]);
        }
        i++;  
    }  
    return 0;
}