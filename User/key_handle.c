#include "bsp.h"

void KEY0_CallBack(void){
    // OLED_Print_Clear();
    printf_user(CONSOLE_UART,"key 0 pressed\r\n");
}

void KEY1_CallBack(void){
    printf_user(CONSOLE_UART,"key 1 pressed\r\n");
}

void KEY2_CallBack(void){
    printf_user(CONSOLE_UART,"key 2 pressed\r\n");
}
