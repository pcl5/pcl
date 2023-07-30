/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-25 13:57:20
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 12:42:43
 */
/**
 * @file drv_pwm.c
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\WhuCar-tiva129_v2.5_pcl\Drv
 * @version 1.0
 * @date 2023-07-26
 * @copyright Copyright (c) 2023-07-26
 * @code_reference cbr wgj 
 *
 */
/*************************************/
/*              Libs                 */
/*************************************/
#include "main.h"

/*************************************/
/*              Drivers              */
/*************************************/
#include "bsp_pwm.h"
#include "bsp.h"

//PWM初始化
void Drv_PWM_Init(void)
{
    //PWM时钟使能
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);

    //GPIO时钟使能(GPIO里面已经有了)
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //GPIO配置为PWM功能
    GPIOPinConfigure(GPIO_PF0_M0PWM0);
    GPIOPinConfigure(GPIO_PF1_M0PWM1);
    GPIOPinConfigure(GPIO_PF2_M0PWM2);
    GPIOPinConfigure(GPIO_PF3_M0PWM3);
    GPIOPinConfigure(GPIO_PG0_M0PWM4);//Servo?
    GPIOPinConfigure(GPIO_PG1_M0PWM5);//Servo?
    GPIOPinConfigure(GPIO_PK4_M0PWM6);//蜂鸣器Buzzer
    //GPIO配置为PWM输出
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);//电机Motor
	GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_0 | GPIO_PIN_1);//舵机Servo
    GPIOPinTypePWM(GPIO_PORTK_BASE, GPIO_PIN_4);//蜂鸣器Buzzer
    
    /*
	* system clock 120MHz. 64 division to 1.875MHz=1875000.
	* TB6612 need 10kHz to 20kHz, set peroid count to 200.
	* Servo need 50Hz, set peroid count to 37500.
	* Buzzer need 4kHz. set peroid count to 469.
    翻译：
    系统时钟120MHz。64分频为1.875MHz = 1875000。
    TB6612需要10kHz至20kHz，将周期计数设置为200。
    舵机需要50Hz，将周期计数设置为37500。
    蜂鸣器需要4kHz。将周期计数设置为469。
	*/
    
    //PWM时钟配置
    PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_64);
    //PWM模块0配置
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);// 2 channel of PWM for Left Motors
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);// 2 channel of PWM for Right Motors
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);// Servos
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); // 1 channel of PWM for Buzzer
 
    //PWM周期设置
    PWMGenPeriodSet(PWM0_BASE,PWM_GEN_0,200);//电机Motor
	PWMGenPeriodSet(PWM0_BASE,PWM_GEN_1,200);//电机Motor
    PWMGenPeriodSet(PWM0_BASE,PWM_GEN_2,37500);//舵机Servo
    PWMGenPeriodSet(PWM0_BASE,PWM_GEN_3,469);//蜂鸣器buzzer
    
    //PWM占空比设置
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_0,0);
	PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,0);
	PWMPulseWidthSet(PWM0_BASE,PWM_OUT_2,0);
	PWMPulseWidthSet(PWM0_BASE,PWM_OUT_3,0);
	PWMPulseWidthSet(PWM0_BASE,PWM_OUT_4,0);//Servo
	PWMPulseWidthSet(PWM0_BASE,PWM_OUT_5,0);//Servo
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_6,469);//蜂鸣器Buzzer

    //PWM时钟使能
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);//舵机Servo
    PWMGenEnable(PWM0_BASE, PWM_GEN_3);//蜂鸣器Buzzer

    //PWM输出使能
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT, true);
}

//PWM输出
//参数：Base：PWM模块，PWM_OUT：PWM输出通道，Duty：占空比,带%
void Set_Duty(uint32_t Base, uint32_t PWM_OUT, float Duty)
{
    if(Duty < 0.0F) Duty=0.0F;
	if(Duty > 1.0F) Duty=1.0F;
	uint32_t Gen;
	uint32_t OutBits;
	switch(PWM_OUT)
	{
		case PWM_OUT_0:	Gen=PWM_GEN_0,OutBits=PWM_OUT_0_BIT;	break;
		case PWM_OUT_1:	Gen=PWM_GEN_0,OutBits=PWM_OUT_1_BIT;	break;
		case PWM_OUT_2:	Gen=PWM_GEN_1,OutBits=PWM_OUT_2_BIT;	break;
		case PWM_OUT_3:	Gen=PWM_GEN_1,OutBits=PWM_OUT_3_BIT;	break;
		case PWM_OUT_4:	Gen=PWM_GEN_2,OutBits=PWM_OUT_4_BIT;	break;
		case PWM_OUT_5:	Gen=PWM_GEN_2,OutBits=PWM_OUT_5_BIT;	break;
		case PWM_OUT_6:	Gen=PWM_GEN_3,OutBits=PWM_OUT_6_BIT;	break;
		case PWM_OUT_7:	Gen=PWM_GEN_3,OutBits=PWM_OUT_7_BIT;	break;
	}
	if(Duty==0.0F){
		PWMOutputState(Base, OutBits, false);
	}
	else {
		//配置占空比
		PWMPulseWidthSet(Base, PWM_OUT, PWMGenPeriodGet(Base, Gen)*Duty);
		PWMOutputState(Base, OutBits, true);
	}
	//使能发生器模块
	PWMGenEnable(Base, Gen);
}
