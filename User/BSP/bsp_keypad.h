/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-30 20:44:36
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 21:01:01
 */
/**
 * @file bsp_keypad.h
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\TIVA_RTOS_CAR_tm4c129_group\User\BSP
 * @version 1.0
 * @date 2023-07-30
 * @copyright Copyright (c) 2023-07-30
 * @code_reference cbr wgj 
 *
 */

#pragma once
/********************************************/
/*               Libs                       */
/********************************************/
#include <stdint.h>
#include <stdbool.h>
#include "main.h"

/********************************************/
/*                bsp                       */
/********************************************/
#include "bsp.h"

/********************************************/
/*               Defines                    */
/********************************************/
// 键盘矩阵配置
#define ROW_NUM     4  //四行
#define COLUMN_NUM  4  //四列

// 端口和引脚配置
#define ROW_BASE    GPIO_PORTA_BASE
#define COLUMN_BASE GPIO_PORTB_BASE

#define ROW_SYSCTL  SYSCTL_PERIPH_GPIOA
#define COLUMN_SYSCTL SYSCTL_PERIPH_GPIOB

#define ROW_PIN     (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)
#define COLUMN_PIN  (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)

void keypad_init(void);
int keypad_getkey(void);
