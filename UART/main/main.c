#include <driver/gpio.h>
#include <driver/uart.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

int app_main(){
    // Configuration of UART2
    const uart_port_t uart_num_2 = UART_NUM_2;
    uart_config_t uart2_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    ESP_ERROR_CHECK(uart_param_config(uart_num_2, &uart2_config));
    uart_set_pin(uart_num_2, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, 
                                                                    UART_PIN_NO_CHANGE);

    uart_driver_install(uart_num_2, (1024*2),0,0,NULL,0);
    // Configuration of UART 1
    const uart_port_t uart_num_1 = UART_NUM_1;
    uart_config_t uart1_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    ESP_ERROR_CHECK(uart_param_config(uart_num_1, &uart1_config));
    uart_set_pin(uart_num_1, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, 
                                                                    UART_PIN_NO_CHANGE);
    uart_driver_install(uart_num_2, (1024*2),0,0,NULL,0);
    return 0;
}