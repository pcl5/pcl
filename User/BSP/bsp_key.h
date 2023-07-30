/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-29 23:29:53
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 12:39:41
 */
/**
 * @file bsp_key.h
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\WhuCar-tiva129_v2.5_pcl\Drv
 * @version 1.0
 * @date 2023-07-26
 * @copyright Copyright (c) 2023-07-26
 * @code_reference cbr wgj 
 *
 */

#pragma once

#include <stdint.h>
#include <main.h>


#define KEY  !GPIOPinRead(KEY0_GPIO_Port,KEY0_Pin)//PCin(0)  
#define KEY1 !GPIOPinRead(KEY1_GPIO_Port,KEY1_Pin)
#define KEY2 !GPIOPinRead(KEY2_GPIO_Port,KEY2_Pin)


//是否使用硬件去抖
#define Is_Detrembling 0

void Key(void);
uint8_t click(void);
uint8_t click_N_Double(uint16_t time);
uint8_t Long_Press(void);
static void Key_Task(void* pvParameters);
//Compare this snippet from Drv\drv_main.c:

