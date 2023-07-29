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

#include "tm4c1290ncpdt.h"
#include "driverlib/sysctl.h"		
#include "driverlib/interrupt.h"

#include "FreeRTOS.h"
#include "task.h"
extern BaseType_t RTOS_Init(void);//创建任务,在freertos.c中实现

/*!
 * @brief 初始化硬件驱动包
 * @param  void
 */
static void BSP_Init(void){
	SysCtlClockFreqSet(SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN|SYSCTL_USE_PLL|SYSCTL_CFG_VCO_240,120000000);
	
}

int main(void){
	BaseType_t xReturn = pdPASS;//

	BSP_Init();

	xReturn = RTOS_Init();
	
	if(pdPASS == xReturn){
		IntMasterEnable();
		portENABLE_INTERRUPTS();
		vTaskStartScheduler();
	}
	else {
		/*FreeRTOS failed*/
	}

	while(1){

	}
}
