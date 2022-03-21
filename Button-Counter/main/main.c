#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define button 4
#define LEDA 2
#define LEDB 5
#define LEDC 12
#define LEDD 27
#define LEDE 14
#define LEDF 15
#define LEDG 16
#define LEDP 17

void displayLED (int num);
void configGPIOs ();

int app_main(){
    //Configuration of GPIOs
    configGPIOs();
    //Initial number of times the button has been pressed and implementation at LED matrix
    uint8_t number = 0;
    displayLED(number);
    
    while(true){
        if(gpio_get_level(button) && number < 10){
            number++;
        }
        else if (gpio_get_level(button) && number >= 10){
            number = 0;
        }
        displayLED(number);
        vTaskDelay(500 / portTICK_RATE_MS);
    }
    return 0;
}

void configGPIOs(){
    gpio_config_t configButton = {
        .pin_bit_mask = (1ULL << button),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&configButton);

    gpio_config_t configLEDA = {
        .pin_bit_mask = (1ULL << LEDA),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDA);

    gpio_config_t configLEDB = {
        .pin_bit_mask = (1ULL << LEDB),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDB);

    gpio_config_t configLEDC = {
        .pin_bit_mask = (1ULL << LEDC),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDC);

    gpio_config_t configLEDD = {
        .pin_bit_mask = (1ULL << LEDD),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDD);

    gpio_config_t configLEDE = {
        .pin_bit_mask = (1ULL << LEDE),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDE);

    gpio_config_t configLEDF = {
        .pin_bit_mask = (1ULL << LEDF),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDF);

    gpio_config_t configLEDG = {
        .pin_bit_mask = (1ULL << LEDG),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDG);

    gpio_config_t configLEDP = {
        .pin_bit_mask = (1ULL << LEDP),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE, 
    };
    gpio_config(&configLEDP);
}

void displayLED (int num){
    switch (num)
    {
    case 0:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 1);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 0);
        gpio_set_level(LEDP, 0);
        break;

    case 1:
        gpio_set_level(LEDA, 0);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 0);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 0);
        gpio_set_level(LEDG, 0);
        gpio_set_level(LEDP, 0);
        break;

    case 2:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 0);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 1);
        gpio_set_level(LEDF, 0);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;
    
    case 3:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 0);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;

    case 4:
        gpio_set_level(LEDA, 0);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 0);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;
    
    case 5:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 0);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;

    case 6:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 0);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 1);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;

    case 7:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 0);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 0);
        gpio_set_level(LEDG, 0);
        gpio_set_level(LEDP, 0);
        break;

    case 8:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 1);
        gpio_set_level(LEDE, 1);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;

    case 9:
        gpio_set_level(LEDA, 1);
        gpio_set_level(LEDB, 1);
        gpio_set_level(LEDC, 1);
        gpio_set_level(LEDD, 0);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 1);
        gpio_set_level(LEDG, 1);
        gpio_set_level(LEDP, 0);
        break;

    case 10:
        gpio_set_level(LEDA, 0);
        gpio_set_level(LEDB, 0);
        gpio_set_level(LEDC, 0);
        gpio_set_level(LEDD, 0);
        gpio_set_level(LEDE, 0);
        gpio_set_level(LEDF, 0);
        gpio_set_level(LEDG, 0);
        gpio_set_level(LEDP, 1);
        break;
    }

}