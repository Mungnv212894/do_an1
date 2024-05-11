#include "http.h"

// Task handler function
void http_client_task(void *pvParameters) {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sock < 0) {
        ESP_LOGE(TAG, "Failed to create socket");
        vTaskDelete(NULL);
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) != 0) {
        ESP_LOGE(TAG, "Socket unable to connect");
        close(sock);
        vTaskDelete(NULL);
    }

    // Your JSON string
    //const char *myjson = "{\"name\": \"John\", \"age\": 30, \"married\": true}";

    // Send JSON string
    if (send(sock,json_string, strlen(json_string), 0) < 0) {
        ESP_LOGE(TAG, "Error occurred during sending");
        close(sock);
        vTaskDelete(NULL);
    }

    ESP_LOGI(TAG, "JSON sent successfully: %s", myjson);

    close(sock);
    vTaskDelete(NULL);
}

