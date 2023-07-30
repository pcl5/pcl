/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-25 13:57:26
 * @Code Reference: cbr wgj
 * @LastEditTime: 2023-07-30 23:21:28
 */

#pragma once
#include <math.h>
#include <stdbool.h>
#include <pwm.h>
#include <gpio.h>


void Drv_PWM_Init(void);
void Set_Duty(uint32_t Base, uint32_t PWM_OUT, float Duty);
