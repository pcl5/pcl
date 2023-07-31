/**
 * @file car_attitude.h
 * @brief С�����ƴ���
 * 
 */
#ifndef __CAR_ATTITUDE_H_
#define __CAR_ATTITUDE_H_

typedef struct __car_attitude
{
    float current_v_line;//��ǰ���ٶ�,mm/s
    float current_v_angle;//��ǰ���ٶ�,degree/s
    // float current_v_z;//��ת�������ٶ�,���Ҳ���ֵ��һ��mm/s
    float target_v_line;//Ŀ�����ٶ�,mm/s
    float target_v_angle;//Ŀ����ٶ�,degree/s
    // float target_v_z;//��ת�������ٶ�,mm/s
    float yaw;//ƫ����,[0,360) degree
    bool flag_stop;//С���Ƿ�ֹͣ
    bool updated;//С����̬�Ƿ����
    pid pid_v_angle;
}_car_attitude;


#endif