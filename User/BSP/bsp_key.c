/**
 * @file drv_key.c
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
#include "bsp_key.h"
#include "bsp.h"
//长按标识
int tran = 0;
static uint16_t Press_count;

/**************************************************************************
函数功能：按键切换功能
入口参数：无
返回  值：无
加入硬件去抖不可使用长按双击检测
**************************************************************************/
void Key(void)
{	
	uint16_t tmp,tmp2;
	#if( Is_Detrembling != 0 )
		tmp = click();
		//按键按下
		if(tmp==1)
		{
			GPIO_ResetBits(GPIOE,GPIO_Pin_0);
			return;
		}
		else{}
	#else
	tmp=click_N_Double(20);
	//单击
	if(tmp==1)
	{
		
		return;
	}
	//双击
	else if(tmp==2)
	{
		
		return;
	} 
	tmp2=Long_Press();
	//长按键发送
	if(tmp2==3)
	{
		tran = 1;
	}
	#endif
	
}

/**************************************************************************
函数功能：按键扫描
入口参数：双击等待时间
返回  值：按键状态 0：无动作 1：单击 2：双击 
**************************************************************************/
uint8_t click_N_Double (uint16_t time)
{
	static	uint16_t flag_key=0,count_key=0,double_key=0;	
	static	uint16_t count_single=0,Forever_count=0;
	if(KEY==0)  							//KEY为PC0管脚状态，此时按键按下
		Forever_count++;   					//长按标志位未置1
    else       
		Forever_count=0;
	if(KEY == 0 && flag_key == 0)			//按键按下，且按键按下标志为0	
		flag_key=1;	
	if(count_key == 0)						//第一次为0
	{
		if(flag_key==1) 
		{
			double_key++;					//按键按下一次，double_key加一次
			count_key=1;					//按键按下，count=1
		}
		if(double_key==2) 
		{
			double_key=0;
			count_single=0;
			return 2;//双击执行的指令
		}
	}
	if(KEY == 1)			
		flag_key=0,count_key=0;				//按键未按下
	if(double_key == 1)						//按键已经按下一次
	{
		count_single++;						//超过等待时间
		if(count_single>time&&Forever_count<time)
		{
			double_key=0;
			count_single=0;	
			return 1;//单击执行的指令
		}
		if(Forever_count>time)
		{
			double_key=0;
			count_single=0;	
		}
	}	
	return 0;
}
/**************************************************************************
函数功能：按键扫描
入口参数：无
返回  值：按键状态 0：无动作 1：单击 
**************************************************************************/
uint8_t click(void)
{
	static uint8_t flag_key=1;//按键按松开标志
	if(flag_key&&KEY==0)
	{
		flag_key=0;
		return 1;	// 按键按下
	}
	else if(1==KEY)			flag_key=1;
		return 0;//无按键按下
}
/**************************************************************************
函数功能：长按检测
入口参数：无
返回  值：按键状态 0：无动作 1：长按2s
**************************************************************************/
uint8_t Long_Press(void)
{
	static uint16_t Long_Press_count,Long_Press;
	if(Long_Press==0&&KEY==0) 
	{		
		Press_count++;
		Long_Press_count++;   //长按标志位未置1
	}
	else                       
		Long_Press_count=0; 
	if(Long_Press_count>200)		
	{
		Long_Press=1;
		Long_Press_count=0;
		return 3;
	}	
	else if(Long_Press_count==1)
	{
		Press_count=0;
		return 1;
	}		
	if(Long_Press==1)     //长按标志位置1
	{
		Long_Press=0;
	}
	return 0;
}

//Key执行函数,用作freertos任务
// static void Key_Task(void* pvParameters)
// {
// 	while(1)
// 	{
// 		Key();
// 		//delay_ms(15);
// 	}
// }
