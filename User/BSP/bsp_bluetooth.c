#include "bsp_bluetooth.h"
#include "bsp_uart.h"
#include "driverlib/sysctl.h"
#include "config.h"

extern void delay_ms(uint32_t n);
/*!
 * @brief ��������ģ��,��Ҫ����ʱ����һ�μ���
 * @param  
 */
void BLE_AT_Set(void){
#ifdef BLE_UART
    printf_user(BLE_UART,"AT+NAME=HC-09-PCLZY");
    delay_ms(200);
    printf_user(BLE_UART,"AT+CLEAR");
#endif
}
