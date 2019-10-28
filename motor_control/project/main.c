#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

int main(void)
{
	delay_init();
	uart1_init(115200);
	led_init();
	pwm_init(899,0);
	TIM_SetCompare1(TIM3,450);
	TIM_SetCompare2(TIM3,450);
	TIM_SetCompare3(TIM3,450);
	TIM_SetCompare4(TIM3,450);
	while(1)
	{
		set_led_on(LED1);
		delay_ms(100);
		set_led_off(LED1);
		delay_ms(100);
	}
}
