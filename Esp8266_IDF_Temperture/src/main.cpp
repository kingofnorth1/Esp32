#include <stdio.h>
// #include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

uint32_t status = 0;

void app_main(void)
{
  gpio_reset_pin(2);                       // 初始化引脚
  gpio_set_direction(2, GPIO_MODE_OUTPUT); // 设置管脚输出模式
  while (1)
  {
    status != status;                      // 取反
    gpio_set_level(2, status);             // 设置管脚状态
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 延时1000/1秒运行周期=1
  }
}
