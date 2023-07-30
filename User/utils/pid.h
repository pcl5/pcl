
/**
 * @file pid.h
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\TIVA_RTOS_CAR_tm4c129_group\User\utils
 * @version 1.0
 * @date 2023-07-30
 * @copyright Copyright (c) 2023-07-30
 * @code_reference cbr wgj 
 *
 */
#ifndef __PID_H__
#define __PID_H__
/********************************/
/*          Libs                */
/********************************/
#include <math.h>
#include "config.h"
#include "filter.h"
#include "main.h"

/********************************/
/*              BSP             */
/********************************/
#include "bsp.h"
#include "pid.h"

/********************************/
/*            Defines           */
/********************************/





/********************************/
/*            Struct            */
/********************************/

typedef struct PIDTypeDef
{
	float p;
	float i;
	float d;

	float iError;       //当前
	float LastError;    //上一次
	float PrevError;    //上上次
    float IntegralError; //误差积分,用于位置式PID

	float InputVal;//设置的
	float FeedBack;//实际的
    float OutputVal;//经过pid反馈的

    float output_limit_inc;         //增量式PID输出上限
    float output_limit_pos;         //位置式PID输出上限
    float integral_error_limit;     //积分上限
}PID;

/********************************/
/*            函数              */
/********************************/
void Set_PID(PID* obj, float p, float i, float d);
void Set_PID_Limit(PID*obj, float output_limit_inc, float output_limit_pos, float integral_error_limit);
float PID_Cal_Inc(PID *pid_t, float current, float target);
float PID_Cal_Inc_Perfect(PID *pid_t, float current, float target);
float PID_Cal_Pos(PID *obj, float current, float target);
void PID_Clear(PID* obj);



#endif
