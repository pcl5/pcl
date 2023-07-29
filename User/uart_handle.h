/**
 * @file uart_handle.h
 * @author cbr (ran13245@outlook.com)
 * @brief UART输入的处理程序
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __UART_HANDLE_H_
#define __UART_HANDLE_H_

void UartCallBack_USB(void);

void UartCallBack_BLE(void);

void UartCallBack_JET(void);

void UartCallBack_K210(void);

void UartCallBack_OPENMV(void);

#endif