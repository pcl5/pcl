/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-29 21:42:51
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 23:26:02
 */
/**
 * @file main.c
 * @author cbr (ran13245@outlook.com)
 * @brief TIVA_RTOS Project
 * @version 0.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "bsp.h"
#include "FreeRTOS.h"
#include "task.h"

extern BaseType_t RTOS_Init(void);//创建任务,在freertos.c中实现

void delay_ms(uint32_t n)
{
	uint32_t count;
	count=USER_SYS_FREQ/1000;		
	SysCtlDelay(n*count/3);				
}

/*!
 * @brief 初始化硬件驱动包
 * @param  void
 */
static void BSP_Init(void){
	SysCtlClockFreqSet(SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN|SYSCTL_USE_PLL|SYSCTL_CFG_VCO_240,120000000);
	FPUEnable();
	FPULazyStackingEnable();
	IntPriorityGroupingSet(3);
	init_Bsp_GPIO();
	init_Bsp_UART();
	init_Bsp_uDMA();
	//printf_user(CONSOLE_UART,"Pass\r\n");
	init_filter();
	// BLE_AT_Set();
	delay_ms(200);
	//BLE_AT_Set();
}

int main(void){
	BaseType_t xReturn = pdPASS;//

	BSP_Init();
  printf_user(CONSOLE_UART,"BSP Pass.\r\n");
	xReturn = RTOS_Init();
	
	if(pdPASS == xReturn){
		printf_user(CONSOLE_UART,"Launch RTOS\r\n");
		IntMasterEnable();
		portENABLE_INTERRUPTS();
		printf_user(CONSOLE_UART,"Enable Interrupt\r\n");
		vTaskStartScheduler();
	}
	else {
		/*FreeRTOS failed*/
		printf_user(CONSOLE_UART,"RTOS Failed!\r\n");
	}

	while(1){

	}
}
