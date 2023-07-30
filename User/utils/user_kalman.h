#ifndef __KALMAN_H_
#define __KALMAN_H_


float Kalman_Filter_z(float Angle,float Gyro,float dt);		
float Kalman_Filter_x(float Angle,float AngVelocity);		
float Kalman_Filter_y(float Angle,float AngVelocity);

#endif
