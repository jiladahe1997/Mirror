/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define STACK_SIZE 4096
StaticTask_t xTaskBuffer;
StackType_t xStack[ STACK_SIZE ];
static void blink(void *);

void app_main(void)
{
    printf("Hello world!\n");

    xTaskCreateStatic(blink, "blink", STACK_SIZE, NULL, tskIDLE_PRIORITY, xStack, &xTaskBuffer);
    return;


}


static void blink(void *){
    printf("blink start\n");
    esp_err_t ret;

    //zero-initialize the config structure.
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = ((1ULL<<3) | (1ULL<<4) | (1ULL<<5));
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    gpio_set_level(3, 1);  //红
    gpio_set_level(4, 1);  //绿
    gpio_set_level(5, 1);  //蓝

    uint32_t count=0;
    while(1) {
        count++;
        printf("blink count:%ld portTICK_PERIOD_MS:%ld\n", count, portTICK_PERIOD_MS);
        //ret = gpio_set_level(3, 1);
        ret = gpio_set_level(5, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        //ret = gpio_set_level(3, 0);
        ret = gpio_set_level(5, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}