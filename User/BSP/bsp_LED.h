/**
 * @file bsp_LED.h
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\WhuCar-tiva129_v2.5_pcl\Drv
 * @version 1.0
 * @date 2023-07-25
 * @copyright Copyright (c) 2023-07-25
 * @code_reference cbr wgj 
 *
 */

#pragma once

#include <stdint.h>
#include <main.h>


void Set_LED(uint8_t R,uint8_t G,uint8_t B);
void Set_LED_R(uint8_t R);
void Set_LED_G(uint8_t G);
void Set_LED_B(uint8_t B);
