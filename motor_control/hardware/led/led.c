/***************************************************************
 LED��������
***************************************************************/

#include "led.h"

/******************************************************************************
 * @fn      LED_Init
 *
 * @brief   ��ʼ��LEDӲ����LED��Ӧ�������±���ʾ
 *
 * @param   NULL
 *			
 * @return  NULL
 *****************************************************************************/
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
}

/******************************************************************************
 * @fn      SetOneLED_ON
 *
 * @brief   ����һ��LED����Ӧ�ܽ�����

 *
 * @param   �������ú궨��ķ���

 *			
 * @return  NULL
 *****************************************************************************/
void set_led_on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	/* �������õ�LED */
	GPIO_ResetBits(GPIOx , GPIO_Pin);
}

/******************************************************************************
 * @fn      SetOneLED_OFF
 *
 * @brief   ����һ��LED����Ӧ�ܽ�����
 
 *
 * @param   �������ú궨��ķ���

 *
 *			
 * @return  NULL
 *****************************************************************************/
void set_led_off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_SetBits(GPIOx , GPIO_Pin);
}

/******************************************************************************
 * @fn      SetOneLED_TOGGLE
 *
 * @brief   ����һ��LED����Ӧ�ܽ�����
 *
 * @param   �������ú궨��ķ���
 *		
 * @return  NULL
 *****************************************************************************/
void set_led_toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	u8 bitstatus = 0;
	
	bitstatus = GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin);
	if(bitstatus == 1)
		GPIO_ResetBits(GPIOx , GPIO_Pin);
	else if(bitstatus == 0)
		GPIO_SetBits(GPIOx , GPIO_Pin);
}
