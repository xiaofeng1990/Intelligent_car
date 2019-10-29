#include "servo.h"
#include "pwm.h"


void servo_init(void)
{
	//pwm≥ı ºªØ
	pwm_tim2_init(19999,71);
}

void servo_set_angle(uint16_t angle)
{
	if(angle < ANGLE_MIN)
		angle = ANGLE_MIN;
	if(angle > ANGLE_MAX)
		angle = ANGLE_MAX;
	
	TIM_SetCompare2(TIM2,angle);
}