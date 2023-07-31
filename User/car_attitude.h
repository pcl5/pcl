/**
 * @file car_attitude.h
 * @brief 小车控制代码
 * 
 */
#ifndef __CAR_ATTITUDE_H_
#define __CAR_ATTITUDE_H_

typedef struct __car_attitude
{
    float current_v_line;//当前线速度,mm/s
    float current_v_angle;//当前角速度,degree/s
    // float current_v_z;//旋转补偿线速度,左右差速值的一半mm/s
    float target_v_line;//目标线速度,mm/s
    float target_v_angle;//目标角速度,degree/s
    // float target_v_z;//旋转补偿线速度,mm/s
    float yaw;//偏航角,[0,360) degree
    bool flag_stop;//小车是否停止
    bool updated;//小车姿态是否更新
    pid pid_v_angle;
}_car_attitude;


#endif