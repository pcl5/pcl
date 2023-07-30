/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-30 12:32:40
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 12:35:23
 */
/**
 * @file main.h
 * @author pansamic (wanggengjie@ieee.org)
 * @brief 板级外设端口定义
 * @version 0.1
 * @date 2023-07-9
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdint.h>
#include <stdbool.h>
/*****************************************************/
/*                        LED                        */
/*****************************************************/
#define LEDR_Pin GPIO_PIN_7
#define LEDR_GPIO_Port GPIO_PORTC_BASE
#define LEDG_Pin GPIO_PIN_3
#define LEDG_GPIO_Port GPIO_PORTK_BASE
#define LEDB_Pin GPIO_PIN_2
#define LEDB_GPIO_Port GPIO_PORTK_BASE
/*****************************************************/
/*                       Motor                       */
/*****************************************************/
#define LFMotor_RotateDirectionCtrl1_Pin GPIO_PIN_5
#define LFMotor_RotateDirectionCtrl1_GPIO_Port GPIO_PORTC_BASE
#define LFMotor_RotateDirectionCtrl2_Pin GPIO_PIN_6
#define LFMotor_RotateDirectionCtrl2_GPIO_Port GPIO_PORTC_BASE

#define LRMotor_RotateDirectionCtrl1_Pin GPIO_PIN_4
#define LRMotor_RotateDirectionCtrl1_GPIO_Port GPIO_PORTC_BASE
#define LRMotor_RotateDirectionCtrl2_Pin GPIO_PIN_3
#define LRMotor_RotateDirectionCtrl2_GPIO_Port GPIO_PORTH_BASE

#define RFMotor_RotateDirectionCtrl1_Pin GPIO_PIN_1
#define RFMotor_RotateDirectionCtrl1_GPIO_Port GPIO_PORTH_BASE
#define RFMotor_RotateDirectionCtrl2_Pin GPIO_PIN_2
#define RFMotor_RotateDirectionCtrl2_GPIO_Port GPIO_PORTH_BASE

#define RRMotor_RotateDirectionCtrl1_Pin GPIO_PIN_0
#define RRMotor_RotateDirectionCtrl1_GPIO_Port GPIO_PORTH_BASE
#define RRMotor_RotateDirectionCtrl2_Pin GPIO_PIN_3
#define RRMotor_RotateDirectionCtrl2_GPIO_Port GPIO_PORTQ_BASE
/*****************************************************/
/*                    Encoder                        */
/*****************************************************/
#define EncA_LeftFront_Pin GPIO_PIN_5
#define EncA_LeftFront_GPIO_Port GPIO_PORTQ_BASE
#define EncA_LeftFront_IntPin GPIO_INT_PIN_5
#define EncA_LeftFront_GPIO_IntSource INT_GPIOQ

#define EncB_LeftFront_Pin GPIO_PIN_6
#define EncB_LeftFront_GPIO_Port GPIO_PORTQ_BASE
#define EncB_LeftFront_IntPin GPIO_INT_PIN_6
#define EncB_LeftFront_GPIO_IntSource INT_GPIOQ

#define EncA_LeftRear_Pin GPIO_PIN_7
#define EncA_LeftRear_GPIO_Port GPIO_PORTG_BASE
#define EncA_LeftRear_IntPin GPIO_INT_PIN_7
#define EncA_LeftRear_GPIO_IntSource INT_GPIOG

#define EncB_LeftRear_Pin GPIO_PIN_6
#define EncB_LeftRear_GPIO_Port GPIO_PORTG_BASE
#define EncB_LeftRear_IntPin GPIO_INT_PIN_6
#define EncB_LeftRear_GPIO_IntSource INT_GPIOG

#define EncA_RightFront_Pin GPIO_PIN_4
#define EncA_RightFront_GPIO_Port GPIO_PORTG_BASE
#define EncA_RightFront_IntPin GPIO_INT_PIN_4
#define EncA_RightFront_GPIO_IntSource INT_GPIOG

#define EncB_RightFront_Pin GPIO_PIN_5
#define EncB_RightFront_GPIO_Port GPIO_PORTG_BASE
#define EncB_RightFront_IntPin GPIO_INT_PIN_5
#define EncB_RightFront_GPIO_IntSource INT_GPIOG

#define EncA_RightRear_Pin GPIO_PIN_3
#define EncA_RightRear_GPIO_Port GPIO_PORTG_BASE
#define EncA_RightRear_IntPin GPIO_INT_PIN_3
#define EncA_RightRear_GPIO_IntSource INT_GPIOG

#define EncB_RightRear_Pin GPIO_PIN_2
#define EncB_RightRear_GPIO_Port GPIO_PORTG_BASE
#define EncB_RightRear_IntPin GPIO_INT_PIN_2
#define EncB_RightRear_GPIO_IntSource INT_GPIOG
/*****************************************************/
/*                       Key                         */
/*****************************************************/
#define KEY0_Pin GPIO_PIN_2
#define KEY0_IntPin GPIO_INT_PIN_2
#define KEY0_GPIO_Port GPIO_PORTE_BASE
#define KEY1_Pin GPIO_PIN_1
#define KEY1_IntPin GPIO_INT_PIN_1
#define KEY1_GPIO_Port GPIO_PORTE_BASE
#define KEY2_Pin GPIO_PIN_0
#define KEY2_IntPin GPIO_INT_PIN_0
#define KEY2_GPIO_Port GPIO_PORTE_BASE

#define LF_BASE         GPIO_PORTF_BASE
#define LF_PIN          GPIO_PIN_3
#define LR_BASE         GPIO_PORTF_BASE
#define LR_PIN          GPIO_PIN_2
#define RF_BASE         GPIO_PORTF_BASE
#define RF_PIN          GPIO_PIN_1
#define RR_BASE         GPIO_PORTF_BASE
#define RR_PIN          GPIO_PIN_0
/*****************************************************/
/*                       BUZZER                      */
/*****************************************************/
#define BUZZER_BASE     GPIO_PORTK_BASE
#define BUZZER_PIN      GPIO_PIN_4

/*****************************************************/
/*                      OLED                         */
/*****************************************************/
#define OLED_DC_GPIO_Port GPIO_PORTD_BASE
#define OLED_DC_Pin GPIO_PIN_0
#define OLED_MOSI_GPIO_Port GPIO_PORTD_BASE
#define OLED_MOSI_Pin GPIO_PIN_1
#define OLED_RST_GPIO_Port GPIO_PORTD_BASE
#define OLED_RST_Pin GPIO_PIN_2
#define OLED_SCLK_GPIO_Port GPIO_PORTD_BASE
#define OLED_SCLK_Pin GPIO_PIN_3


#define PWM_LF_BASE     PWM0_BASE
#define PWM_LF_OUT      PWM_OUT_3
#define PWM_LR_BASE     PWM0_BASE
#define PWM_LR_OUT      PWM_OUT_2
#define PWM_RF_BASE     PWM0_BASE
#define PWM_RF_OUT      PWM_OUT_1
#define PWM_RR_BASE     PWM0_BASE
#define PWM_RR_OUT      PWM_OUT_0
#define PWM_BUZZER_BASE PWM0_BASE
#define PWM_BUZZER_OUT  PWM_OUT_6

// sensor irs
#define IR_SENSOR_GPIO_Port GPIO_PORTQ_BASE
#define IR_SENSOR_CLK_Pin GPIO_PIN_0
#define IR_SENSOR_DAT_Pin GPIO_PIN_2

#define     IST8310_I2C_BASE   I2C8_BASE 
#define	   	IST8310_DEV_ADD 	0x0e

#define     ICM20602_I2C_BASE   I2C8_BASE
#define     ICM20602_DEV_ADD    0x69
/*****************************************************/
/*                       ADC                         */
/*****************************************************/
#define     POWER_BASE      GPIO_PORTE_BASE
#define     POWER_PIN       GPIO_PIN_3
#define     POWER_ADC_BASE  ADC0_BASE
/*****************************************************/
/*                       servo                       */
/*****************************************************/
#define PWM_SERVO1_BASE     PWM0_BASE
#define PWM_SERVO1_OUT      PWM_OUT_4
#define PWM_SERVO2_BASE     PWM0_BASE
#define PWM_SERVO2_OUT      PWM_OUT_5
#endif
