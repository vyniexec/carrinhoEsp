#ifndef __DIRECTIONCAR__H__
#define __DIRECTIONCAR__H__
#include "includes.h"

/* == Manipulador HTTP GET front == */
esp_err_t front_get_handler(httpd_req_t *req)
{
    gpio_set_level(FRONT, 1);
    ESP_LOGI(TAG, "FRONT 1");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, ON_RESP, strlen(ON_RESP));
    return ESP_OK;
}
/* == Manipulador HTTP GET front == */
esp_err_t frontOff_get_handler(httpd_req_t *req)
{
    gpio_set_level(FRONT, 0);
    ESP_LOGI(TAG, "FRONT 0");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, ON_RESP, strlen(ON_RESP));
    return ESP_OK;
}

/* == Manipulador HTTP GET led2off == */
esp_err_t back_get_handler(httpd_req_t *req)
{
    gpio_set_level(BACK, 1);
    ESP_LOGI(TAG, "BACK 1");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}
/* == Manipulador HTTP GET led2off == */
esp_err_t backOff_get_handler(httpd_req_t *req)
{
    gpio_set_level(BACK, 0);
    ESP_LOGI(TAG, "BACK 0");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}

/* == Manipulador HTTP GET led2off == */
esp_err_t right_get_handler(httpd_req_t *req)
{
    gpio_set_level(RIGHT, 1);
    ESP_LOGI(TAG, "RIGHT 1");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}
/* == Manipulador HTTP GET led2off == */
esp_err_t rightOff_get_handler(httpd_req_t *req)
{
    gpio_set_level(RIGHT, 0);
    ESP_LOGI(TAG, "RIGHT 0");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}

/* == Manipulador HTTP GET led2off == */
esp_err_t left_get_handler(httpd_req_t *req)
{
    gpio_set_level(LEFT, 1);
    ESP_LOGI(TAG, "LEFT 1");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}
/* == Manipulador HTTP GET led2off == */
esp_err_t leftOff_get_handler(httpd_req_t *req)
{
    gpio_set_level(LEFT, 0);
    ESP_LOGI(TAG, "LEFT 0");
    vTaskDelay(10);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, OFF_RESP, strlen(OFF_RESP));
    return ESP_OK;
}

/* == Configuração do evento LED ON no HTTP GET == */
httpd_uri_t front = {
    .uri = "/front",
    .method = HTTP_GET,
    .handler = front_get_handler,
    .user_ctx = NULL};
/* == Configuração do evento LED ON no HTTP GET == */
httpd_uri_t frontOff = {
    .uri = "/frontOff",
    .method = HTTP_GET,
    .handler = frontOff_get_handler,
    .user_ctx = NULL};

/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t back = {
    .uri = "/back",
    .method = HTTP_GET,
    .handler = back_get_handler,
    .user_ctx = NULL};
/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t backOff = {
    .uri = "/backOff",
    .method = HTTP_GET,
    .handler = backOff_get_handler,
    .user_ctx = NULL};

/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t left = {
    .uri = "/left",
    .method = HTTP_GET,
    .handler = left_get_handler,
    .user_ctx = NULL};
/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t leftOff = {
    .uri = "/leftOff",
    .method = HTTP_GET,
    .handler = leftOff_get_handler,
    .user_ctx = NULL};

/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t right = {
    .uri = "/right",
    .method = HTTP_GET,
    .handler = right_get_handler,
    .user_ctx = NULL};
/* == Configuração do evento LED OFF no HTTP GET == */
httpd_uri_t rightOff = {
    .uri = "/rightOff",
    .method = HTTP_GET,
    .handler = rightOff_get_handler,
    .user_ctx = NULL};

/* == Função para inicar o WEB Server HTTP == */
httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    /* == Inicia o servidor HTTP == */
    if (httpd_start(&server, &config) == ESP_OK)
    {
        /* == Registra as URI responsaveis pelo estado da função front ou led2off == */
        httpd_register_uri_handler(server, &front);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &back);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &right);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &left);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &frontOff);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &backOff);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &rightOff);
        vTaskDelay(10);
        httpd_register_uri_handler(server, &leftOff);
        vTaskDelay(10);
    }

    return server;
}

#endif  //!__DIRECTIONCAR__H__