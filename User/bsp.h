/**
 * @file bsp.h
 * @author cbr (ran13245@outlook.com)
 * @brief 集成板级驱动程序
 * @attention 只允许在应用层包含,不允许在驱动层包含,否则可能出现头文件递归引用
 * @version 0.1
 * @date 2023-07-9
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BSP_H_
#define __BSP_H_

#include <stdint.h>
#include <stdbool.h>

#include "tm4c1290ncpdt.h"
#include "hw_types.h"					
#include "hw_memmap.h"	
#include "hw_gpio.h"			
#include "driverlib/sysctl.h"			
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "driverlib/fpu.h"
#include "driverlib/pwm.h"
#include "driverlib/udma.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"

#include "main.h"
#include "bsp_uart.h"
#include "bsp_gpio.h"
#include "bsp_pwm.h"
#include "bsp_keypad.h"
//#include "bsp_i2c.h"
//#include "bsp_uDMA.h"
//#include "bsp_adc.h"
//#include "bsp_tim.h"
//#include "motor.h"
#include "bsp_led.h"
//#include "oled.h"
//#include "servo.h"
//#include "irs.h"
//#include "ist8310.h"
//#include "icm20602.h"
#include "uart_handle.h"
//#include "tim_handle.h"
#include "key_handle.h"
//#include "bluetooth.h"
//#include "protocol.h"
//#include "car_attitude.h"
//#include "car_control.h"
#include "filter.h"
//#include "software_pwm.h"

#include "config.h"
//#include "const.h"

#endif
