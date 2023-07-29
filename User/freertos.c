/**
 * @file freertos.c
 * @author cbr (ran13245@outlook.com)
 * @brief FreeRTOS应用程序
 * @version 0.1
 * @date 2023-6-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "FreeRTOS.h"
#include "task.h"

static TaskHandle_t AppTaskCreate_Handle = NULL;

static void AppTaskCreate(void* pvParameters);

/*!
 * @brief RTOS初始化,启动引导程序
 * @param  void
 * @return 是否成功启动
 */
BaseType_t RTOS_Init(void){

	return xTaskCreate(AppTaskCreate,"AppTaskCreate",512,NULL,1,&AppTaskCreate_Handle);
	
}

/*!
 * @brief RTOS引导程序
 * @param pvParemeters 任务参数,NULL
 */
void AppTaskCreate(void* pvParameters){
//	BaseType_t xReturn = pdPASS;

	taskENTER_CRITICAL();//进入临界区

/*任务创建*/

//	xReturn = xTaskCreate(Task_LEDBlink,"LEDBlink",128,NULL,1,&TaskHandle_LEDBlink);
//	if(pdPASS == xReturn);
//		printf_user(CONSOLE_UART,"LEDBlink\r\n");
	
	vTaskDelete(AppTaskCreate_Handle);
	taskEXIT_CRITICAL();//退出临界区
}

