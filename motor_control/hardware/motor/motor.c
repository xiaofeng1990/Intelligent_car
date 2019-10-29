#include "motor.h"
#include "pwm.h"

// motor init
void motor_init(void)
{
	//gpio init
	gpio_init();
	//pwm init
	pwm_init((uint16_t)SPEED_MAX, 0);
}

//set left speed
void motor_set_speed_left(uint16_t speed)
{
	if(speed < 0)
		speed = 0;
	if(speed > SPEED_MAX)
		speed = SPEED_MAX;
	
	pwm_set_duty_c1(speed);
}
//set right speed
void motor_set_speed_right(uint16_t speed)
{
	if(speed < 0)
		speed = 0;
	if(speed > SPEED_MAX)
		speed = SPEED_MAX;
	
	pwm_set_duty_c2(speed);
}

void motor_set_speeds(uint16_t speed)
{
	if(speed < 0)
		speed = 0;
	if(speed > SPEED_MAX)
		speed = SPEED_MAX;
	pwm_set_duty_c1(speed);
	pwm_set_duty_c2(speed);
}

//go forward
void motor_forward(void)
{
	GPIO_SetBits(MOTOR_LEFT_1);
	GPIO_ResetBits(MOTOR_LEFT_2);
	
	GPIO_SetBits(MOTOR_RIGHT_1);
	GPIO_ResetBits(MOTOR_RIGHT_2);
	
}

//go back
void motor_back(void)
{
	GPIO_SetBits(MOTOR_LEFT_2);
	GPIO_ResetBits(MOTOR_LEFT_1);
	
	GPIO_SetBits(MOTOR_RIGHT_2);
	GPIO_ResetBits(MOTOR_RIGHT_1);
}

void gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(MOTOR_LEFT_1);
	GPIO_SetBits(MOTOR_LEFT_2);
	GPIO_SetBits(MOTOR_RIGHT_1);
	GPIO_SetBits(MOTOR_RIGHT_2);
}


//≤‚ÀŸ