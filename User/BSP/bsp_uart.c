/**
 * @file bsp_uart.c
 * @author cbr (ran13245@outlook.com)
 * @brief 板级UART驱动
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "bsp.h"
#include "freertos.h"
#include "task.h"
#include "semphr.h"

#include "tm4c_it.h"
#include <stdio.h>
#include <stdarg.h>

extern SemaphoreHandle_t semphr_uart_receive;

#ifdef USB_UART
uart_device uart_usb={0};
#endif
#ifdef BLE_UART
uart_device uart_ble={0};
#endif
#ifdef Jetson_UART
uart_device uart_jetson={0};
#endif
#ifdef K210_UART
uart_device uart_k210={0};
#endif
#ifdef OPENMV_UART
uart_device uart_openmv={0};
#endif


/*
 * 重定义printf
 */
uint32_t uiBase_stdio=CONSOLE_UART;
int fputc(int ch, FILE* stream)
{
#if USE_NON_BLOKING_PUT
    UARTCharPutNonBlocking(uiBase_stdio, (uint8_t)ch);
#else
    UARTCharPut(uiBase_stdio, (uint8_t)ch);
#endif
    return ch;
}

static void _DeviceRxIntHandler(uint32_t ui32Base, uart_device* device);

/*!
 * @brief 用户print函数
 * @attention 注意当前是否为非阻塞输出设置,建议输出16字符以内
 * @param uiBase 输出端口BASE
 * @param pcString 待输出string,接受args
 */
void printf_user(uint32_t uiBase, const char *pcString, ...)
{
    uiBase_stdio=uiBase;
    va_list vaArgP;

    //
    // Start the varargs processing.
    //
    va_start(vaArgP, pcString);

    vprintf(pcString, vaArgP);

    //
    // We're finished with the varargs now.
    //
    va_end(vaArgP);
}       

//函数功能：串口发送数据,类似printf
void user_printf(uint32_t ui32Base, const char *pui8Format, ...) 
{
    char buffer[256];
    va_list va;

    va_start(va, pui8Format);
    vsnprintf(buffer, sizeof(buffer), pui8Format, va);
    va_end(va);

    // Assuming you have a UARTCharPut function that writes a char to the UART
    for(int i = 0; buffer[i] != '\0'; i++) {
        UARTCharPut(ui32Base, buffer[i]);
    }
}

void USB_Printf(const char *pui8Format, ...)
{
    user_printf(USB_UART,pui8Format);
}

/*!
 * @brief 初始化UART
 */
void init_Bsp_UART(void){
	/* UART0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    UARTConfigSetExpClk(UART0_BASE, USER_SYS_FREQ, BAUD_RATE_UART0, UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);
    UARTIntRegister(UART0_BASE, UART0_IRQHandler);
    UARTFIFOLevelSet(UART0_BASE, UART_FIFO_RX1_8, UART_FIFO_TX1_8);
    IntPrioritySet(INT_UART0,PRIORITY_UART0);
    IntEnable(INT_UART0);

	/* UART1 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PB1_U1TX);
    GPIOPinConfigure(GPIO_PB0_U1RX);
    UARTConfigSetExpClk(UART1_BASE, USER_SYS_FREQ, BAUD_RATE_UART1,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTIntRegister(UART1_BASE,UART1_IRQHandler);
    UARTFIFOLevelSet(UART1_BASE, UART_FIFO_RX1_8, UART_FIFO_TX1_8);
    IntPrioritySet(INT_UART1,PRIORITY_UART1);
    IntEnable(INT_UART1);
	
	/* UART2 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7);
    GPIOPinConfigure(GPIO_PA7_U2TX);
    GPIOPinConfigure(GPIO_PA6_U2RX);
    UARTConfigSetExpClk(UART2_BASE, USER_SYS_FREQ, BAUD_RATE_UART2,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	UARTFIFOLevelSet(UART2_BASE, UART_FIFO_RX1_8, UART_FIFO_TX1_8);
    UARTIntRegister(UART2_BASE,UART2_IRQHandler);
    IntPrioritySet(INT_UART2,PRIORITY_UART2);
    IntEnable(INT_UART2);
	
	/* UART3 */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PA5_U3TX);
    GPIOPinConfigure(GPIO_PA4_U3RX);
    UARTConfigSetExpClk(UART3_BASE, USER_SYS_FREQ, BAUD_RATE_UART3,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	UARTFIFOLevelSet(UART3_BASE, UART_FIFO_RX1_8, UART_FIFO_TX1_8);
    UARTIntRegister(UART3_BASE,UART3_IRQHandler);
    IntPrioritySet(INT_UART3,PRIORITY_UART3);
    IntEnable(INT_UART3);
	
	/* UART4 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART4);
	GPIOPinTypeUART(GPIO_PORTK_BASE, GPIO_PIN_1 | GPIO_PIN_0);
    GPIOPinConfigure(GPIO_PK1_U4TX);
    GPIOPinConfigure(GPIO_PK0_U4RX);
    UARTConfigSetExpClk(UART4_BASE, USER_SYS_FREQ, BAUD_RATE_UART4,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	UARTFIFOLevelSet(UART4_BASE, UART_FIFO_RX1_8, UART_FIFO_TX1_8);
    UARTIntRegister(UART4_BASE,UART4_IRQHandler);
    IntPrioritySet(INT_UART4,PRIORITY_UART4);
	IntEnable(INT_UART4);


    #ifdef USB_UART
        UARTIntEnable(USB_UART,UART_INT_RX|UART_INT_RT);
        RingBuf_uint8_t_init( &uart_usb.ringbuf , uart_usb.buffer , BUFFER_SIZE );
        Queue_uint8_t_init(&uart_usb.rx_len_queue,uart_usb._queue,RX_QUEUE_SIZE);
    #endif
    #ifdef BLE_UART
        UARTIntEnable(BLE_UART,UART_INT_RX|UART_INT_RT);
        RingBuf_uint8_t_init( &uart_ble.ringbuf , uart_ble.buffer , BUFFER_SIZE );
        Queue_uint8_t_init(&uart_ble.rx_len_queue,uart_ble._queue,RX_QUEUE_SIZE);
    #endif
    #ifdef Jetson_UART
        UARTIntEnable(Jetson_UART,UART_INT_RX|UART_INT_RT);
        RingBuf_uint8_t_init( &uart_jetson.ringbuf , uart_jetson.buffer , BUFFER_SIZE );
        Queue_uint8_t_init(&uart_jetson.rx_len_queue,uart_jetson._queue,RX_QUEUE_SIZE);
    #endif
    #ifdef K210_UART
        UARTIntEnable(K210_UART,UART_INT_RX|UART_INT_RT);
        RingBuf_uint8_t_init( &uart_k210.ringbuf , uart_k210.buffer , BUFFER_SIZE );
        Queue_uint8_t_init(&uart_k210.rx_len_queue,uart_k210._queue,RX_QUEUE_SIZE);
    #endif
    #ifdef OPENMV_UART
        UARTIntEnable(OPENMV_UART,UART_INT_RX|UART_INT_RT);
        RingBuf_uint8_t_init( &uart_openmv.ringbuf , uart_openmv.buffer , BUFFER_SIZE );
        Queue_uint8_t_init(&uart_openmv.rx_len_queue,uart_openmv._queue,RX_QUEUE_SIZE);
    #endif

}
void _DeviceRxIntHandler(uint32_t ui32Base, uart_device* device){
    while (UARTCharsAvail(ui32Base))
    {
        uint8_t rdata;
        uint16_t len;
        rdata=UARTCharGetNonBlocking(ui32Base);
        // UARTCharPutNonBlocking(CONSOLE_UART,rdata);
        device->rx_p++;
        if(device->received_head)RingBuf_uint8_t_push( &device->ringbuf , rdata );
        if((!device->received_head)&&(rdata==UART_HEAD)){
            RingBuf_uint8_t_push( &device->ringbuf , rdata );
            device->received_head=true;
            device->tx_p=device->rx_p-1;
        }
        if((device->received_head)&&(rdata==UART_TAIL)){
            len=device->rx_p-device->tx_p;
            Queue_uint8_t_enqueue(&device->rx_len_queue,len);
#if  (!TEST_BENCH)
            BaseType_t pxHigherPriorityTaskWoken;
            if(xSemaphoreGiveFromISR(semphr_uart_receive,&pxHigherPriorityTaskWoken) == errQUEUE_FULL){//给信号量,拉起RX处理任务
                error_uart();//丢包了
            }
            // portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
#endif
            device->rx_p=0;
            device->tx_p=0;
            device->received_head=false;
        }
    }

}

/*!
 * @brief 中断处理
 * @param ui32Base 中断BASE 
 @*/
void UartRxIntHandler(uint32_t ui32Base){
    UARTIntClear(ui32Base, UART_INT_RX|UART_INT_RT);//清除中断标志
    UARTRxErrorClear(ui32Base);
    #ifdef USB_UART
        if(ui32Base==USB_UART){
            _DeviceRxIntHandler(USB_UART,&uart_usb);
        }
    #endif

    #ifdef BLE_UART
        if(ui32Base==BLE_UART){
            _DeviceRxIntHandler(BLE_UART,&uart_ble);
        }
    #endif

    #ifdef Jetson_UART
        if(ui32Base==Jetson_UART){
            _DeviceRxIntHandler(Jetson_UART,&uart_jetson);
        }
    #endif

    #ifdef K210_UART
        if(ui32Base==K210_UART){
            _DeviceRxIntHandler(K210_UART,&uart_k210);
        }
    #endif

    #ifdef OPENMV_UART
        if(ui32Base==OPENMV_UART){
            _DeviceRxIntHandler(OPENMV_UART,&uart_openmv);
        }
    #endif

}

/*!
 * @brief uart数据处理程序
 */
void UartRxSolve(void){

    #ifdef USB_UART
        if(Queue_uint8_t_count_remain(&uart_usb.rx_len_queue)){
            uart_usb.len=Queue_uint8_t_dequeue(&uart_usb.rx_len_queue);
            RingBuf_uint8_t_pop_length(&uart_usb.ringbuf,uart_usb.receive,uart_usb.len);
            UartCallBack_USB();
        }
    #endif

    #ifdef BLE_UART
        if(Queue_uint8_t_count_remain(&uart_ble.rx_len_queue)){
            uart_ble.len=Queue_uint8_t_dequeue(&uart_ble.rx_len_queue);
            RingBuf_uint8_t_pop_length(&uart_ble.ringbuf,uart_ble.receive,uart_ble.len);
            UartCallBack_BLE();
        }
    #endif

    #ifdef Jetson_UART
        if(Queue_uint8_t_count_remain(&uart_jetson.rx_len_queue)){
            uart_jetson.len=Queue_uint8_t_dequeue(&uart_jetson.rx_len_queue);
            RingBuf_uint8_t_pop_length(&uart_jetson.ringbuf,uart_jetson.receive,uart_jetson.len);
            UartCallBack_JET();
        }
    #endif

    #ifdef K210_UART
        if(Queue_uint8_t_count_remain(&uart_k210.rx_len_queue)){
            uart_k210.len=Queue_uint8_t_dequeue(&uart_k210.rx_len_queue);
            RingBuf_uint8_t_pop_length(&uart_k210.ringbuf,uart_k210.receive,uart_k210.len);
            UartCallBack_K210();
        }
    #endif

    #ifdef OPENMV_UART
        if(Queue_uint8_t_count_remain(&uart_openmv.rx_len_queue)){
            uart_openmv.len=Queue_uint8_t_dequeue(&uart_openmv.rx_len_queue);
            RingBuf_uint8_t_pop_length(&uart_openmv.ringbuf,uart_openmv.receive,uart_openmv.len);
            UartCallBack_OPENMV();
        }
    #endif

}

/*!
 * @brief 通过DMA发送数据
 * @param uiBase 发送UART端口
 * @param pcString 待发送数据首地址
 * @param length 发送长度
 */
void Uart_DMA_Trans(uint32_t uiBase, uint8_t *pcString, uint16_t length){
    uint32_t dma_channel;
    volatile uint32_t* uart_dr;
    switch (uiBase)
    {
    case UART0_BASE:
        dma_channel=9;
        uart_dr=&UART0_DR_R;
        break;
    case UART1_BASE:
        dma_channel=23;
        uart_dr=&UART1_DR_R;
        break;
    case UART2_BASE:
        dma_channel=13;
        uart_dr=&UART2_DR_R;
        break;
    case UART3_BASE:
        dma_channel=17;
        uart_dr=&UART3_DR_R;
        break;
    case UART4_BASE:
        dma_channel=19;
        uart_dr=&UART4_DR_R;
        break;
    default:
        dma_channel=9;
        uart_dr=&UART0_DR_R;
        break;
    }

    if(uDMAChannelIsEnabled(dma_channel) == false){//判断DMA是否发送完成
        uDMAChannelTransferSet(UDMA_PRI_SELECT | dma_channel, UDMA_MODE_BASIC, pcString,(void*)uart_dr,length);
        uDMAChannelEnable(dma_channel);
    }

}

//DMA发送错误提示
void error_uDMA(void){
    printf_user(CONSOLE_UART,"uDMA busy\r\n");
    while(1);
}

//串口接收错误提示
void error_uart(void){
    printf_user(CONSOLE_UART,"UART Data SKIPPED\r\n");
    while(1);
}

