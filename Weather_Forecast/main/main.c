#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"

static const char *TAG = "i2c-simple-example";

#define I2C_MASTER_SCL_IO           22      
#define I2C_MASTER_SDA_IO           21      
#define I2C_MASTER_NUM              0                          
#define I2C_MASTER_FREQ_HZ          400000                    
#define I2C_MASTER_TX_BUF_DISABLE   0                          
#define I2C_MASTER_RX_BUF_DISABLE   0                          
#define I2C_MASTER_TIMEOUT_MS       1000

#define DPS310_SENSOR_ADDR                 0x77        
#define DPS310_ID_ADDR                     0x0D
#define DPS310_COEFF_ADDR                  0x10

#define SHT4xA_SENSOR_ADDR                 0x44
#define SHT4xA_ID_ADDR                     0x89

#define BME680_ADDR                        0x74
#define BME680_ID                          0xD0

static esp_err_t register_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(I2C_MASTER_NUM, slave_addr, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

static esp_err_t register_write_byte(uint8_t slave_addr, uint8_t reg_addr, uint8_t data)
{
    int ret;
    uint8_t write_buf[2] = {reg_addr, data};

    ret = i2c_master_write_to_device(I2C_MASTER_NUM, slave_addr, write_buf, sizeof(write_buf), I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);

    return ret;
}

static esp_err_t i2c_master_init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };

    i2c_param_config(i2c_master_port, &conf);

    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}


void app_main(void)
{
    uint8_t data[2];
    uint8_t coeff[51] = {0};
    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    ESP_ERROR_CHECK(register_read(BME680_ADDR, BME680_ID, data, 1));
    ESP_LOGI(TAG, "ID = %X", data[0]);
    ESP_LOGI(TAG, "ID = %X", data[1]);

    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    ESP_LOGI(TAG, "I2C de-initialized successfully");
/*

    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");
  
    ESP_ERROR_CHECK(register_read(DPS310_SENSOR_ADDR, DPS310_COEFF_ADDR, coeff, 51));
    ESP_LOGI(TAG, "ID = %X", coeff[0]);
    ESP_LOGI(TAG, "ID = %X", coeff[1]);
    ESP_LOGI(TAG, "ID = %X", coeff[2]);
    ESP_LOGI(TAG, "ID = %X", coeff[3]);
    ESP_LOGI(TAG, "ID = %X", coeff[4]);
    ESP_LOGI(TAG, "ID = %X", coeff[5]);
    ESP_LOGI(TAG, "ID = %X", coeff[6]);
    ESP_LOGI(TAG, "ID = %X", coeff[7]);
    ESP_LOGI(TAG, "ID = %X", coeff[8]);
    ESP_LOGI(TAG, "ID = %X", coeff[9]);
    ESP_LOGI(TAG, "ID = %X", coeff[10]);
    ESP_LOGI(TAG, "ID = %X", coeff[11]);
    ESP_LOGI(TAG, "ID = %X", coeff[12]);
    ESP_LOGI(TAG, "ID = %X", coeff[13]);
    ESP_LOGI(TAG, "ID = %X", coeff[14]);
    ESP_LOGI(TAG, "ID = %X", coeff[15]);
    ESP_LOGI(TAG, "ID = %X", coeff[16]);
    ESP_LOGI(TAG, "ID = %X", coeff[17]);
    ESP_LOGI(TAG, "ID = %X", coeff[18]);
    ESP_LOGI(TAG, "ID = %X", coeff[19]);
    ESP_LOGI(TAG, "ID = %X", coeff[20]);
    ESP_LOGI(TAG, "ID = %X", coeff[21]);
    ESP_LOGI(TAG, "ID = %X", coeff[22]);
    ESP_LOGI(TAG, "ID = %X", coeff[23]);
    ESP_LOGI(TAG, "ID = %X", coeff[24]);
    ESP_LOGI(TAG, "ID = %X", coeff[25]);
    ESP_LOGI(TAG, "ID = %X", coeff[26]);
    ESP_LOGI(TAG, "ID = %X", coeff[27]);
    ESP_LOGI(TAG, "ID = %X", coeff[28]);
    ESP_LOGI(TAG, "ID = %X", coeff[29]);
    ESP_LOGI(TAG, "ID = %X", coeff[30]);
    ESP_LOGI(TAG, "ID = %X", coeff[31]);
    ESP_LOGI(TAG, "ID = %X", coeff[32]);
    ESP_LOGI(TAG, "ID = %X", coeff[33]);
    ESP_LOGI(TAG, "ID = %X", coeff[34]);
    ESP_LOGI(TAG, "ID = %X", coeff[35]);
    ESP_LOGI(TAG, "ID = %X", coeff[36]);
    ESP_LOGI(TAG, "ID = %X", coeff[37]);
    ESP_LOGI(TAG, "ID = %X", coeff[38]);
    ESP_LOGI(TAG, "ID = %X", coeff[39]);
    ESP_LOGI(TAG, "ID = %X", coeff[40]);
    ESP_LOGI(TAG, "ID = %X", coeff[41]);
    ESP_LOGI(TAG, "ID = %X", coeff[42]);
    ESP_LOGI(TAG, "ID = %X", coeff[42]);
    ESP_LOGI(TAG, "ID = %X", coeff[44]);
    ESP_LOGI(TAG, "ID = %X", coeff[45]);
    ESP_LOGI(TAG, "ID = %X", coeff[46]);
    ESP_LOGI(TAG, "ID = %X", coeff[47]);
    ESP_LOGI(TAG, "ID = %X", coeff[48]);
    ESP_LOGI(TAG, "ID = %X", coeff[49]);
    ESP_LOGI(TAG, "ID = %X", coeff[50]);


    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    ESP_LOGI(TAG, "I2C de-initialized successfully");*/
}