/**
 * @file bsp_gpio.c
 * @author cbr (ran13245@outlook.com)
 * @brief 板级GPIO驱动
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "main.h"
#include "bsp_gpio.h"
#include "driverlib/gpio.h"
#include "tm4c1290ncpdt.h"
#include "hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "tm4c_it.h"
#include "hw_types.h"
#include "hw_gpio.h"
#include "config.h"

/*!
 * @brief 初始化GPIO
 * @param  none
 */
void init_Bsp_GPIO(void){
    /* GPIO port enable */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);

    /* GPIO mode configuration */
    GPIOPinTypeGPIOOutput(LEDR_GPIO_Port, LEDR_Pin);
    GPIOPinTypeGPIOOutput(LEDG_GPIO_Port, LEDG_Pin);
    GPIOPinTypeGPIOOutput(LEDB_GPIO_Port, LEDB_Pin);

    GPIOPinTypeGPIOOutput(OLED_SCLK_GPIO_Port, OLED_SCLK_Pin);
    GPIOPinTypeGPIOOutput(OLED_MOSI_GPIO_Port, OLED_MOSI_Pin);
    GPIOPinTypeGPIOOutput(OLED_RST_GPIO_Port, OLED_RST_Pin);
    GPIOPinTypeGPIOOutput(OLED_DC_GPIO_Port, OLED_DC_Pin);

    GPIOPinTypeGPIOOutput(LFMotor_RotateDirectionCtrl1_GPIO_Port, LFMotor_RotateDirectionCtrl1_Pin);
    GPIOPinTypeGPIOOutput(LFMotor_RotateDirectionCtrl2_GPIO_Port, LFMotor_RotateDirectionCtrl2_Pin);
    GPIOPinTypeGPIOOutput(LRMotor_RotateDirectionCtrl1_GPIO_Port, LRMotor_RotateDirectionCtrl1_Pin);
    GPIOPinTypeGPIOOutput(LRMotor_RotateDirectionCtrl2_GPIO_Port, LRMotor_RotateDirectionCtrl2_Pin);
    GPIOPinTypeGPIOOutput(RFMotor_RotateDirectionCtrl1_GPIO_Port, RFMotor_RotateDirectionCtrl1_Pin);
    GPIOPinTypeGPIOOutput(RFMotor_RotateDirectionCtrl2_GPIO_Port, RFMotor_RotateDirectionCtrl2_Pin);
    GPIOPinTypeGPIOOutput(RRMotor_RotateDirectionCtrl1_GPIO_Port, RRMotor_RotateDirectionCtrl1_Pin);
    GPIOPinTypeGPIOOutput(RRMotor_RotateDirectionCtrl2_GPIO_Port, RRMotor_RotateDirectionCtrl2_Pin);

    GPIOPinTypeGPIOInput(EncA_LeftFront_GPIO_Port, EncA_LeftFront_Pin);
    GPIOPinTypeGPIOInput(EncB_LeftFront_GPIO_Port, EncB_LeftFront_Pin);
    GPIOPinTypeGPIOInput(EncA_LeftRear_GPIO_Port, EncA_LeftRear_Pin);
    GPIOPinTypeGPIOInput(EncB_LeftRear_GPIO_Port, EncB_LeftRear_Pin);
    GPIOPinTypeGPIOInput(EncA_RightFront_GPIO_Port, EncA_RightFront_Pin);
    GPIOPinTypeGPIOInput(EncB_RightFront_GPIO_Port, EncB_RightFront_Pin);
    GPIOPinTypeGPIOInput(EncA_RightRear_GPIO_Port, EncA_RightRear_Pin);
    GPIOPinTypeGPIOInput(EncB_RightRear_GPIO_Port, EncB_RightRear_Pin);

    GPIOPinTypeGPIOInput(KEY0_GPIO_Port, KEY0_Pin);
    GPIOPinTypeGPIOInput(KEY1_GPIO_Port, KEY1_Pin);
    GPIOPinTypeGPIOInput(KEY2_GPIO_Port, KEY2_Pin);

    GPIOIntRegister(GPIO_PORTG_BASE, EXTI_PORTG_IRQHandler);
    GPIOIntRegister(GPIO_PORTE_BASE, EXTI_PORTE_IRQHandler);

    IntPrioritySet(INT_GPIOG, PRIORITY_PORTG);
    IntPrioritySet(INT_GPIOE, PRIORITY_PORTE);

    // /* GPIO interrupt configuration */
    GPIOIntEnable(KEY0_GPIO_Port, KEY0_IntPin);
    GPIOIntTypeSet(KEY0_GPIO_Port, KEY0_Pin, GPIO_FALLING_EDGE);

    GPIOIntEnable(KEY1_GPIO_Port, KEY1_IntPin);
    GPIOIntTypeSet(KEY1_GPIO_Port, KEY1_Pin, GPIO_FALLING_EDGE);

    GPIOIntEnable(KEY2_GPIO_Port, KEY2_IntPin);
    GPIOIntTypeSet(KEY2_GPIO_Port, KEY2_Pin, GPIO_FALLING_EDGE);

//四倍频:
#if USE_4_TIMES_ENCODER
    GPIOIntEnable(EncA_LeftFront_GPIO_Port, EncA_LeftFront_IntPin);
    GPIOIntTypeSet(EncA_LeftFront_GPIO_Port, EncA_LeftFront_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncB_LeftFront_GPIO_Port, EncB_LeftFront_IntPin);
    GPIOIntTypeSet(EncB_LeftFront_GPIO_Port, EncB_LeftFront_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncA_LeftRear_GPIO_Port, EncA_LeftRear_IntPin);
    GPIOIntTypeSet(EncA_LeftRear_GPIO_Port, EncA_LeftRear_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncB_LeftRear_GPIO_Port, EncB_LeftRear_IntPin);
    GPIOIntTypeSet(EncB_LeftRear_GPIO_Port, EncB_LeftRear_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncA_RightFront_GPIO_Port, EncA_RightFront_IntPin);
    GPIOIntTypeSet(EncA_RightFront_GPIO_Port, EncA_RightFront_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncB_RightFront_GPIO_Port, EncB_RightFront_IntPin);
    GPIOIntTypeSet(EncB_RightFront_GPIO_Port, EncB_RightFront_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncA_RightRear_GPIO_Port, EncA_RightRear_IntPin);
    GPIOIntTypeSet(EncA_RightRear_GPIO_Port, EncA_RightRear_Pin, GPIO_BOTH_EDGES);

    GPIOIntEnable(EncB_RightRear_GPIO_Port, EncB_RightRear_IntPin);
    GPIOIntTypeSet(EncB_RightRear_GPIO_Port, EncB_RightRear_Pin, GPIO_BOTH_EDGES);

#else
//非四倍频:
    GPIOIntEnable(EncB_LeftFront_GPIO_Port, EncB_LeftFront_IntPin);
    GPIOIntTypeSet(EncB_LeftFront_GPIO_Port, EncB_LeftFront_Pin, GPIO_RISING_EDGE);

    GPIOIntEnable(EncB_LeftRear_GPIO_Port, EncB_LeftRear_IntPin);
    GPIOIntTypeSet(EncB_LeftRear_GPIO_Port, EncB_LeftRear_Pin, GPIO_RISING_EDGE);

    GPIOIntEnable(EncB_RightFront_GPIO_Port, EncB_RightFront_IntPin);
    GPIOIntTypeSet(EncB_RightFront_GPIO_Port, EncB_RightFront_Pin, GPIO_RISING_EDGE);

    GPIOIntEnable(EncB_RightRear_GPIO_Port, EncB_RightRear_IntPin);
    GPIOIntTypeSet(EncB_RightRear_GPIO_Port, EncB_RightRear_Pin, GPIO_RISING_EDGE);
#endif
}
