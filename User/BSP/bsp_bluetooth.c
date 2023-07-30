#include "bsp_bluetooth.h"
#include "bsp_uart.h"
#include "driverlib/sysctl.h"
#include "config.h"

extern void delay_ms(uint32_t n);
/*!
 * @brief 设置蓝牙模块,需要设置时调用一次即可
 * @param  
 */
void BLE_AT_Set(void){
#ifdef BLE_UART
    printf_user(BLE_UART,"AT+NAME=HC-09-PCLZY");
    delay_ms(200);
    printf_user(BLE_UART,"AT+CLEAR");
#endif
}
