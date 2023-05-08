#ifndef __INCLUDES__H__
#define __INCLUDES__H__

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include <stdlib.h>
#include <string.h> 
#include "esp_system.h"
#include "spi_flash_mmap.h"
#include <esp_http_server.h>
#include <lwip/sockets.h>
#include <lwip/sys.h>
#include <lwip/api.h>
#include <lwip/netdb.h>

static const char *TAG = "vynizinho!";

/* == Criando a API JSON == */
static const char *ON_RESP = "{\"status\": \"on\"}";
static const char *OFF_RESP = "{\"status\": \"off\"}";

// -- Nomeando as saídas e entradas do ESP32 --;
#define FRONT      GPIO_NUM_2                 // -- Pino do registrador de deslocamento (74HC595) saída - CLOCK --;
#define BACK       GPIO_NUM_18                 // -- Pino do registrador de deslocamento (74HC595) saída - SERIAL IN --;
#define LEFT       GPIO_NUM_21                 // -- Pino do registrador de deslocamento (74HC595) saída - LATCH --;
#define RIGHT      GPIO_NUM_19                 // -- Pino do registrador de deslocamento (74HC595) saída - LATCH --;

#endif  //!__INCLUDES__H__