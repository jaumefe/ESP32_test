#include <driver/gpio.h>
#include <driver/uart.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <string.h>
#include <esp_log.h>

static const char* TAG = "UART0";

int app_main(){
    // Configuration of UART2
    const uart_port_t uart_num = UART_NUM_0;
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    ESP_ERROR_CHECK(uart_driver_install(uart_num, (1024*2),0,0,NULL,0));
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(uart_num, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, 
                                                                    UART_PIN_NO_CHANGE));

    
    

    while(1){
        uint8_t data[128];
        char * test = "Hello World\n";
        int length = uart_read_bytes(uart_num, data, (1024 - 1), 5000 / portTICK_PERIOD_MS);
        uart_write_bytes(uart_num, (const char*)test, strlen(test));
        if(length){
            ESP_LOGI(TAG,"Recv str: %s", (char*) data);
        }
    }
    return 0;
}