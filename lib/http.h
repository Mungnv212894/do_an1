#ifndef __HTTP__H_
#define __HTTP__H_


#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "sdkconfig.h"

#include "adc.h"

#define TAG "HTTP_CLIENT"
#define SERVER_IP "192.168.1.83"
#define SERVER_PORT 8080

// Task handler function
void http_client_task(void *pvParameters);

#endif /* __HTTP__H_ */