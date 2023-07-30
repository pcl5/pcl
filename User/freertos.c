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
#include "semphr.h"
#include "queue.h"
#include "main.h"

#include "bsp.h"

SemaphoreHandle_t semphr_uart_receive = NULL;
QueueHandle_t queue_key = NULL;

static TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t TaskHandle_LEDBlink = NULL;
static TaskHandle_t TaskHandle_UartHandle = NULL;
//static TaskHandle_t TaskHandle_Key = NULL;


static void AppTaskCreate(void* pvParameters);
static void Task_LEDBlink(void* pvParameters);
static void Task_UartHandle(void* pvParameters);
//static void Task_Key(void* pvParameters);
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
  BaseType_t xReturn = pdPASS;

	taskENTER_CRITICAL();//进入临界区

/*任务创建*/
  printf_user(CONSOLE_UART,"-Task-\r\n");

	xReturn = xTaskCreate(Task_UartHandle,"UartHandle",512,NULL,7,&TaskHandle_UartHandle);
	if(pdPASS == xReturn)
	printf_user(CONSOLE_UART,"UartHandle\r\n");
	
//	xReturn = xTaskCreate(Task_LEDBlink,"LEDBlink",128,NULL,1,&TaskHandle_LEDBlink);
//	if(pdPASS == xReturn)
//	printf_user(CONSOLE_UART,"LEDBlink\r\n");

//	xReturn = xTaskCreate(Task_Key,"Key",128,NULL,6,&TaskHandle_Key);
//	if(pdPASS == xReturn)
//	printf_user(CONSOLE_UART,"Key\r\n");
	
	printf_user(CONSOLE_UART,"-Task-\r\n");
	/*信号量创建*/
	printf_user(CONSOLE_UART,"-Semaphore List-\r\n");

	semphr_uart_receive = xSemaphoreCreateCounting(RX_QUEUE_SIZE,0);
	if(semphr_uart_receive != NULL)
	printf_user(CONSOLE_UART,"uart_receive\r\n");

	printf_user(CONSOLE_UART,"-Semaphore List End-\r\n");
	
	/*队列创建*/
	printf_user(CONSOLE_UART,"-Queue-\r\n");

//	queue_key = xQueueCreate(1,1);
//	if(queue_key != NULL)
//	printf_user(CONSOLE_UART,"key\r\n");

	printf_user(CONSOLE_UART,"-Queue-\r\n");

	
	vTaskDelete(AppTaskCreate_Handle);
	taskEXIT_CRITICAL();//退出临界区
}
/*!
 * @brief 串口处理程序,处理上位机传回的数据
 * @param pvParameters 
 */
void Task_LEDBlink(void* pvParameters)
{
	for(;;){
		Set_LED(0,0,1);
		vTaskDelay(5000);
		Set_LED(0,1,0);
		vTaskDelay(5000);
		Set_LED(0,1,1);
		vTaskDelay(5000);
		Set_LED(1,0,0);
		vTaskDelay(5000);
		Set_LED(1,0,1);
		vTaskDelay(5000);
		Set_LED(1,1,0);
		vTaskDelay(5000);
		Set_LED(1,1,1);
		vTaskDelay(5000);
	}
}
/*!
 * @brief 串口处理程序,处理上位机传回的数据
 * @param pvParameters 
 */
void Task_UartHandle(void* pvParameters){
	BaseType_t xReturn = pdPASS;
	for(;;){
		xReturn = xSemaphoreTake(semphr_uart_receive,portMAX_DELAY);
		if(pdTRUE == xReturn){
			UartRxSolve();
		}
	}
}

///*!
// * @brief 按键服务
// * @param pvParameters 
// */
//void Task_Key(void* pvParameters){
//	BaseType_t xReturn = pdPASS;
//	uint8_t key;
//	for(;;){
//		xReturn = xQueueReceive(queue_key,&key,portMAX_DELAY);
//		if(pdTRUE == xReturn){
//			if(key==0)KEY0_CallBack();
//			if(key==1)KEY1_CallBack();
//			if(key==2)KEY2_CallBack();
//		}
//		vTaskDelay(50);
//	}
//}
