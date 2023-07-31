/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-30 12:32:40
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-31 11:25:43
 */
/**
 * @file bsp.h
 * @author cbr (ran13245@outlook.com)
 * @brief ���ɰ弶��������
 * @attention ֻ������Ӧ�ò����?,�����������������?,������ܳ���ͷ�ļ��ݹ�����?
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
#include "bsp_i2c.h"
#include "bsp_uDMA.h"
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
#include "bsp_bluetooth.h"


#include "Datascope.h"
//#include "car_attitude.h"
//#include "car_control.h"
#include "filter.h"
//#include "software_pwm.h"
#include "user_kalman.h"

#include "config.h"
//#include "const.h"

#endif
