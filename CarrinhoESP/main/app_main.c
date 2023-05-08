#include <stdio.h>
#include "includes.h"
#include "geral.h"

void init(void)
{
    // -- Resetando os pinos dos registradores --;
    // -- Teclado --;
    gpio_reset_pin(FRONT);                 // -- Resetando todos os pinos a serem usados --;
    gpio_reset_pin(BACK);                // -- Resetando todos os pinos a serem usados --;
    gpio_reset_pin(LEFT);                 // -- Resetando todos os pinos a serem usados --;
    gpio_reset_pin(RIGHT);                 // -- Resetando todos os pinos a serem usados --;

    // -- Configurandos as portas --;
    gpio_set_direction(FRONT, GPIO_MODE_OUTPUT);
    gpio_set_direction(BACK, GPIO_MODE_OUTPUT);
    gpio_set_direction(LEFT, GPIO_MODE_OUTPUT);
    gpio_set_direction(RIGHT, GPIO_MODE_OUTPUT);
}

// -- Função do código principal --;
void app_main(void)
{
    init();
    vTaskDelay(10);
    /* == Inicializando o NVS que armazena configurações do ESP32 == */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    connect_wifi();
    start_webserver();
    vTaskDelay(100);
    while (1)
    {
    }
}