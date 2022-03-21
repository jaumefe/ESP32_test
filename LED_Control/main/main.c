#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/ledc.h"

int app_main(){
    ledc_timer_config_t configLEDR = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LED_AUTO_CLK,
    };
    ledc_channel_config(&configLEDR);

    ledc_timer_config_t configLEDG = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LED_AUTO_CLK,
    };
    ledc_channel_config(&configLEDG);

    ledc_timer_config_t configLEDB = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LED_AUTO_CLK,
    };
    ledc_channel_config(&configLEDB);
    
}