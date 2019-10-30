
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "stm32f10x.h"

#define	SPEED_MAX	899

/********* left motor *********/
//control pin PB12/13
#define MOTOR_LEFT_1  GPIOB , GPIO_Pin_12
#define MOTOR_LEFT_2  GPIOB , GPIO_Pin_13
//pwm pin PA6

/********* right motor *********/
//control pin PB14/15
#define MOTOR_RIGHT_1 GPIOB , GPIO_Pin_14
#define MOTOR_RIGHT_2 GPIOB , GPIO_Pin_15
//pwm pin PA7

void motor_init(void);
void motor_set_speed_left(uint16_t speed);
void motor_set_speed_right(uint16_t speed);
void motor_set_speeds(uint16_t speed);
void motor_forward(void);
void motor_back(void);
void gpio_init(void);

#endif
