#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_system.h"
#include <string.h>
#include "adc.h"
#include "Timestamp.h"
#include "WifiConnect.h"


void app_main() {
    connect_to_wifi();
    initialize_sntp();
    // Create ADC task
    wait_for_time();
    xTaskCreate(adc_task, "adc_task", 8196, NULL, 5, NULL); 
}
