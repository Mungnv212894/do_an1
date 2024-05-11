#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_system.h"

void app_main() {
    // Initialize ADC
    adc1_config_width(ADC_WIDTH_BIT_12); // Set ADC resolution to 12 bits
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); // Configure channel and attenuation for full range
    adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11);

    while(1) {
        // Read ADC value from channel 4
        int raw_data1 = adc1_get_raw(ADC1_CHANNEL_4);
        int raw_data2 = adc1_get_raw(ADC1_CHANNEL_5);
        printf("%d %d\n", raw_data1,raw_data2);  // Corrected print statement
        //printf("%d\n", raw_data2);  // Corrected print statement
        //printf();

        // Delay for 100 ms
        vTaskDelay(pdMS_TO_TICKS(10)); // Correct usage of vTaskDelay for FreeRTOS
    }
}
