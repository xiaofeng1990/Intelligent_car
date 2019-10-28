/***************************************************************
 LED驱动程序接口文件
***************************************************************/

#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

#define LED1			GPIOC , GPIO_Pin_13

void led_init(void);
void set_led_on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void set_led_off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void set_led_toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);	
#endif

