#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "motor.h"

int main(void)
{
	delay_init();
	uart1_init(115200);
	led_init();
	motor_init();
	motor_set_speeds(600);
	motor_forward();
	while(1)
	{
		set_led_on(LED1);
		delay_ms(500);
		set_led_off(LED1);
		delay_ms(500);
	}
}
