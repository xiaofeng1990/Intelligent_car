#ifndef __PWM_H
#define __PWM_H
#include "stm32f10x.h"

void pwm_init(uint16_t arr,uint16_t psc);
void pwm_set_duty_c1(uint16_t duty);
void pwm_set_duty_c2(uint16_t duty);
void pwm_set_duty_c3(uint16_t duty);
void pwm_set_duty_c4(uint16_t duty);
void pwm_set_duty_all(uint16_t duty);

#endif

