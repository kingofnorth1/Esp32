#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void app_main(void)
{
    int i = 0;
    gpio_reset_pin(GPIO_NUM_12);
    gpio_reset_pin(GPIO_NUM_13);
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_13, GPIO_MODE_OUTPUT);
    while (1)
    {
        i++;
        if (i%2 == 0){
            gpio_set_level(GPIO_NUM_12, 1);
            gpio_set_level(GPIO_NUM_13, 0);
        }
        else if (i%2 == 1){
            gpio_set_level(GPIO_NUM_12, 0);
            gpio_set_level(GPIO_NUM_13, 1);
        }
        vTaskDelay(30);
    }
}
