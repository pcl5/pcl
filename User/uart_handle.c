/**
 * @file uart_handle.c
 * @author cbr (ran13245@outlook.com)
 * @brief UART输入的处理程序
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//#include "bsp.h"
void UartCallBack_USB(void){
#ifdef USB_UART
    Uart_DMA_Trans(USB_UART,uart_usb.receive,uart_usb.len);
    // Uart_DMA_Trans(BLE_UART,&uart_usb.receive[1],uart_usb.len-2);//设置蓝牙用
#endif
}


void UartCallBack_BLE(void){
#ifdef BLE_UART
    Uart_DMA_Trans(CONSOLE_UART,uart_ble.receive,uart_ble.len);
#endif
}


void UartCallBack_JET(void){
#ifdef Jetson_UART
    jts_to_mcu.target_v_z_H=uart_jetson.receive[5];
    jts_to_mcu.target_v_z_L=uart_jetson.receive[6];
    jts_to_mcu.target_v_x_H=uart_jetson.receive[3];
    jts_to_mcu.target_v_x_L=uart_jetson.receive[4];
    Uart_DMA_Trans(CONSOLE_UART,uart_jetson.receive,uart_jetson.len);
    Download_From_JTS();
#endif
}


void UartCallBack_K210(void){
#ifdef K210_UART	

#endif
}


void UartCallBack_OPENMV(void){
#ifdef OPENMV_UART

#endif
}
