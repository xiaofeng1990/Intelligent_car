#ifndef __SYS_H
#define __SYS_H	
#include "stm32f10x.h"

//以下为汇编函数
void WFI_SET(void);		//执行WFI指令
void INTX_DISABLE(void);//关闭所有中断
void INTX_ENABLE(void);	//开启所有中断

#endif
