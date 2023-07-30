/**
 * @file tm4c123_it.c
 * @author pansamic (wanggengjie@ieee.org)
 * @brief interrupt handler file
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "tm4c_it.h"
#include <stdint.h>
#include "bsp.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/**
 * 关于硬件中断优先级的设置:
 * 前三位是抢占优先级，数字越小优先级越高
 * 后五位不建议使用
 */


//四倍频:
#if	USE_4_TIMES_ENCODER
/*
 * @brief:GPIO external interrupt handler for left front motor encoder phase A.
 * */
void EXTI_LFEA_IRQHandler(void)
{
//	GPIOIntClear(EncA_LeftFront_GPIO_Port, EncA_LeftFront_IntPin);
//	uint8_t LeftFrontEncAState = ((EncA_LeftFront_Pin & GPIOPinRead(EncA_LeftFront_GPIO_Port, EncA_LeftFront_Pin))!=0);
//	uint8_t LeftFrontEncBState = ((EncB_LeftFront_Pin & GPIOPinRead(EncB_LeftFront_GPIO_Port, EncB_LeftFront_Pin))!=0);
//	
//	if(LeftFrontEncAState ^ LeftFrontEncBState) // phase A and phase B are not in the same state
//	{
//		motor_LeftFront.EncSource--;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_LeftFront.EncSource++;
//	}
}

/*
 * @brief:GPIO external interrupt handler for left front motor encoder phase B.
 * */
void EXTI_LFEB_IRQHandler(void)
{
//	GPIOIntClear(EncB_LeftFront_GPIO_Port, EncB_LeftFront_IntPin);
//	uint8_t LeftFrontEncAState = ((EncA_LeftFront_Pin & GPIOPinRead(EncA_LeftFront_GPIO_Port, EncA_LeftFront_Pin))!=0);
//	uint8_t LeftFrontEncBState = ((EncB_LeftFront_Pin & GPIOPinRead(EncB_LeftFront_GPIO_Port, EncB_LeftFront_Pin))!=0);
//	
//	if(LeftFrontEncAState ^ LeftFrontEncBState) // phase A and phase B are not in the same state
//	{
//		motor_LeftFront.EncSource++;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_LeftFront.EncSource--;
//	}
}

/*
 * @brief:GPIO external interrupt handler for left rear motor encoder phase A.
 * */
void EXTI_LREA_IRQHandler(void)
{
//	GPIOIntClear(EncA_LeftRear_GPIO_Port, EncA_LeftRear_IntPin);
//	uint8_t LeftRearEncAState = ((EncA_LeftRear_Pin & GPIOPinRead(EncA_LeftRear_GPIO_Port, EncA_LeftRear_Pin))!=0);
//	uint8_t LeftRearEncBState = ((EncB_LeftRear_Pin & GPIOPinRead(EncB_LeftRear_GPIO_Port, EncB_LeftRear_Pin))!=0);
//	
//	if(LeftRearEncAState ^ LeftRearEncBState) // phase A and phase B are not in the same state
//	{
//		motor_LeftRear.EncSource--;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_LeftRear.EncSource++;
//	}
}

/*
 * @brief:GPIO external interrupt handler for left rear motor encoder phase B.
 * */
void EXTI_LREB_IRQHandler(void)
{
//	GPIOIntClear(EncB_LeftRear_GPIO_Port, EncB_LeftRear_IntPin);
//	uint8_t LeftRearEncAState = ((EncA_LeftRear_Pin & GPIOPinRead(EncA_LeftRear_GPIO_Port, EncA_LeftRear_Pin))!=0);
//	uint8_t LeftRearEncBState = ((EncB_LeftRear_Pin & GPIOPinRead(EncB_LeftRear_GPIO_Port, EncB_LeftRear_Pin))!=0);

//	if(LeftRearEncAState ^ LeftRearEncBState) // phase A and phase B are not in the same state
//	{
//		motor_LeftRear.EncSource++;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_LeftRear.EncSource--;
//	}
}

/*
 * @brief:GPIO external interrupt handler for right front motor encoder phase A.
 * */
void EXTI_RFEA_IRQHandler(void)
{
//	GPIOIntClear(EncA_RightFront_GPIO_Port, EncA_RightFront_IntPin);
//	uint8_t RightFrontEncAState = ((EncA_RightFront_Pin & GPIOPinRead(EncA_RightFront_GPIO_Port, EncA_RightFront_Pin))!=0);
//	uint8_t RightFrontEncBState = ((EncB_RightFront_Pin & GPIOPinRead(EncB_RightFront_GPIO_Port, EncB_RightFront_Pin))!=0);

//	if(RightFrontEncAState ^ RightFrontEncBState) // phase A and phase B are not in the same state
//	{
//		motor_RightFront.EncSource--;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_RightFront.EncSource++;
//	}
}

/*
 * @brief:GPIO external interrupt handler for right front motor encoder phase B.
 * */
void EXTI_RFEB_IRQHandler(void)
{
//	GPIOIntClear(EncB_RightFront_GPIO_Port, EncB_RightFront_IntPin);
//	uint8_t RightFrontEncAState = ((EncA_RightFront_Pin & GPIOPinRead(EncA_RightFront_GPIO_Port, EncA_RightFront_Pin))!=0);
//	uint8_t RightFrontEncBState = ((EncB_RightFront_Pin & GPIOPinRead(EncB_RightFront_GPIO_Port, EncB_RightFront_Pin))!=0);
//	
//	if(RightFrontEncAState ^ RightFrontEncBState) // phase A and phase B are not in the same state
//	{
//		motor_RightFront.EncSource++;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_RightFront.EncSource--;
//	}
}

/*
 * @brief:GPIO external interrupt handler for right rear motor encoder phase A.
 * */
void EXTI_RREA_IRQHandler(void)
{
//	GPIOIntClear(EncA_RightRear_GPIO_Port, EncA_RightRear_IntPin);
//	uint8_t RightRearEncAState = ((EncA_RightRear_Pin & GPIOPinRead(EncA_RightRear_GPIO_Port, EncA_RightRear_Pin))!=0);
//	uint8_t RightRearEncBState = ((EncB_RightRear_Pin & GPIOPinRead(EncB_RightRear_GPIO_Port, EncB_RightRear_Pin))!=0);

//	if(RightRearEncAState ^ RightRearEncBState) // phase A and phase B are not in the same state
//	{
//		motor_RightRear.EncSource--;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_RightRear.EncSource++;
//	}
}

/*
 * @brief:GPIO external interrupt handler for right rear motor encoder phase B.
 * */
void EXTI_RREB_IRQHandler(void)
{
//	GPIOIntClear(EncB_RightRear_GPIO_Port, EncB_RightRear_IntPin);
//	uint8_t RightRearEncAState = ((EncA_RightRear_Pin & GPIOPinRead(EncA_RightRear_GPIO_Port, EncA_RightRear_Pin))!=0);
//	uint8_t RightRearEncBState = ((EncB_RightRear_Pin & GPIOPinRead(EncB_RightRear_GPIO_Port, EncB_RightRear_Pin))!=0);
//	
//	if(RightRearEncAState ^ RightRearEncBState) // phase A and phase B are not in the same state
//	{
//		motor_RightRear.EncSource++;
//	}
//	else // phase A and phase B are in the same state
//	{
//		motor_RightRear.EncSource--;
//	}
}

#else

//非四倍频:
void EXTI_LFEB_IRQHandler(void)
{
	GPIOIntClear(EncB_LeftFront_GPIO_Port, EncB_LeftFront_IntPin);
	uint8_t LeftFrontEncAState = ((EncA_LeftFront_Pin & GPIOPinRead(EncA_LeftFront_GPIO_Port, EncA_LeftFront_Pin))!=0);
	
	if(LeftFrontEncAState) 
	{
		motor_LeftFront.EncSource++;
	}
	else 
	{
		motor_LeftFront.EncSource--;
	}
}

void EXTI_LREB_IRQHandler(void)
{
	GPIOIntClear(EncB_LeftRear_GPIO_Port, EncB_LeftRear_IntPin);
	uint8_t LeftRearEncAState = ((EncA_LeftRear_Pin & GPIOPinRead(EncA_LeftRear_GPIO_Port, EncA_LeftRear_Pin))!=0);

	if(LeftRearEncAState) 
	{
		motor_LeftRear.EncSource++;
	}
	else 
	{
		motor_LeftRear.EncSource--;
	}
}

void EXTI_RFEB_IRQHandler(void)
{
	GPIOIntClear(EncB_RightFront_GPIO_Port, EncB_RightFront_IntPin);
	uint8_t RightFrontEncAState = ((EncA_RightFront_Pin & GPIOPinRead(EncA_RightFront_GPIO_Port, EncA_RightFront_Pin))!=0);
	
	if(RightFrontEncAState) 
	{
		motor_RightFront.EncSource++;
	}
	else 
	{
		motor_RightFront.EncSource--;
	}
}

void EXTI_RREB_IRQHandler(void)
{
	GPIOIntClear(EncB_RightRear_GPIO_Port, EncB_RightRear_IntPin);
	uint8_t RightRearEncAState = ((EncA_RightRear_Pin & GPIOPinRead(EncA_RightRear_GPIO_Port, EncA_RightRear_Pin))!=0);
	
	if(RightRearEncAState) 
	{
		motor_RightRear.EncSource++;
	}
	else 
	{
		motor_RightRear.EncSource--;
	}
}
#endif

/*
 * @brief:UART0 receive interrupt handler.
 * */
void UART0_IRQHandler(void)
{

	UartRxIntHandler(UART0_BASE);

}

/*
 * @brief:UART1 receive interrupt handler.
 * */
void UART1_IRQHandler(void)
{

	UartRxIntHandler(UART1_BASE);

}

/*
 * @brief:UART2 receive interrupt handler.
 * */
void UART2_IRQHandler(void)
{

	UartRxIntHandler(UART2_BASE);

}

/*
 * @brief:UART3 receive interrupt handler.
 * */
void UART3_IRQHandler(void)
{

	UartRxIntHandler(UART3_BASE);

}

/*
 * @brief:UART4 receive interrupt handler.
 * */
void UART4_IRQHandler(void)
{

	UartRxIntHandler(UART4_BASE);

}
void EXTI_PORTE_IRQHandler(void){
//	uint32_t IntPins=GPIOIntStatus(GPIO_PORTE_BASE,true);
//	static uint8_t key=0;
//	extern QueueHandle_t queue_key;
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE; 
//	if(IntPins&KEY0_IntPin){
//		key=0;
//		xQueueSendFromISR(queue_key,&key,&xHigherPriorityTaskWoken);
//	}
//	if(IntPins&KEY1_IntPin){
//		key=1;
//		xQueueSendFromISR(queue_key,&key,&xHigherPriorityTaskWoken);
//	}
//	if(IntPins&KEY2_IntPin){
//		key=2;
//		xQueueSendFromISR(queue_key,&key,&xHigherPriorityTaskWoken);
//	}

//	GPIOIntClear(GPIO_PORTE_BASE, IntPins);
//	// portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

#if USE_4_TIMES_ENCODER
void EXTI_PORTG_IRQHandler(void){
//	uint32_t IntPins=GPIOIntStatus(GPIO_PORTG_BASE,true);
//	if(IntPins&EncA_RightFront_IntPin) EXTI_RFEA_IRQHandler();
//	if(IntPins&EncB_RightFront_IntPin) EXTI_RFEB_IRQHandler();
//	if(IntPins&EncA_RightRear_IntPin) EXTI_RREA_IRQHandler();
//	if(IntPins&EncB_RightRear_IntPin) EXTI_RREB_IRQHandler();
//	if(IntPins&EncA_LeftRear_IntPin) EXTI_LREA_IRQHandler();
//  if(IntPins&EncB_LeftRear_IntPin) EXTI_LREB_IRQHandler();
}

void EXTI_PORTQ_IRQHandler(void){
//	uint32_t IntPins=GPIOIntStatus(GPIO_PORTQ_BASE,true);
//  if(IntPins&EncA_LeftFront_IntPin) EXTI_LFEA_IRQHandler();
//	if(IntPins&EncB_LeftFront_IntPin) EXTI_LFEB_IRQHandler();
}
#else
void EXTI_PORTG_IRQHandler(void){
	uint32_t IntPins=GPIOIntStatus(GPIO_PORTG_BASE,true);
	if(IntPins&EncB_RightRear_IntPin) EXTI_RREB_IRQHandler();
	if(IntPins&EncB_RightFront_IntPin) EXTI_RFEB_IRQHandler();
  if(IntPins&EncB_LeftRear_IntPin) EXTI_LREB_IRQHandler();
}
void EXTI_PORTQ_IRQHandler(void){
	uint32_t IntPins=GPIOIntStatus(GPIO_PORTQ_BASE,true);
	if(IntPins&EncB_LeftFront_IntPin) EXTI_LFEB_IRQHandler();
}
#endif

void TIM1_IRQHandler(void){
//	Tim_CallBack();
}
