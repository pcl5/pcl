#include "user_kalman.h"
#include <math.h>
#include "config.h"

/**
 * @brief 简易单轴卡尔曼滤波 
 * @param Accel 外部得到的角度
 * @param Gyro imu获取的角速度
 * @param dt 数据更新时间隔（秒）,每5ms进行一次滤波 
 * @returns 
 */	 
float Kalman_Filter_z(float Angle,float Gyro,float dt)		
{
	static float angle;
	// 过程噪声的协方差
	float Q_angle=0.001; 		
	// 过程噪声的协方差 过程噪声的协方差为一个一行两列矩阵
	float Q_gyro=0.003;			
	// 测量噪声的协方差 既测量偏差
	float R_angle=0.5;			
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	// 首次协方差矩阵
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	
	// 角度先验估计积分
	angle+=(Gyro - Q_bias) * dt;
	
	// Pk-先验估计误差协方差的微分
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; 
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	// Pk-先验估计误差协方差微分的积分
	PP[0][0] += Pdot[0] * dt;   
	// 先验估计误差协方差
	PP[0][1] += Pdot[1] * dt;   
	PP[1][0] += Pdot[2] * dt;
	PP[1][1] += Pdot[3] * dt;
	// zk-先验估计，角度偏差
	Angle_err = Angle - angle;
	
	// 求卡尔曼增益
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	// 求卡尔曼增益分母
	E = R_angle + C_0 * PCt_0;	
	// 计算卡尔曼增益
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;	
	
	// 更新协方差矩阵
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];
	// 后验估计误差协方差
	PP[0][0] -= K_0 * t_0;		 
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
	
	// 利用卡尔曼进行最优估计
	// 后验估计
	angle	+= K_0 * Angle_err;	 
	// 后验估计
	Q_bias	+= K_1 * Angle_err;	 
	return angle;
}
float Kalman_Filter_x(float Angle,float AngVelocity)		
{
	//static float angle_dot;
	static float angle;
	float Q_angle=0.001; 		// 过程噪声的协方差
	float Q_gyro=0.003;			// 0.003 过程噪声的协方差 过程噪声的协方差为一个一行两列矩阵
	float R_angle=0.5;			// 测量噪声的协方差 既测量偏差
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	angle+=(AngVelocity - Q_bias) *  TASK_ITV_IMU /1000; //先验估计
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-先验估计误差协方差的微分
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	PP[0][0] += Pdot[0] *  TASK_ITV_IMU /1000;   // Pk-先验估计误差协方差微分的积分
	PP[0][1] += Pdot[1] *  TASK_ITV_IMU /1000;   // 先验估计误差协方差
	PP[1][0] += Pdot[2] *  TASK_ITV_IMU /1000;
	PP[1][1] += Pdot[3] *  TASK_ITV_IMU /1000;
	Angle_err = Angle - angle;	//zk-先验估计
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //后验估计误差协方差
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
		
	angle	+= K_0 * Angle_err;	   //后验估计
	Q_bias	+= K_1 * Angle_err;	 //后验估计
	//angle_dot   = Gyro - Q_bias;	//输出值(后验估计)的微分=角速度
	return angle;
}
float Kalman_Filter_y(float Angle,float AngVelocity)		
{
	//static float angle_dot;
	static float angle;
	float Q_angle=0.001; 		// 过程噪声的协方差
	float Q_gyro=0.003;			// 0.003 过程噪声的协方差 过程噪声的协方差为一个一行两列矩阵
	float R_angle=0.5;			// 测量噪声的协方差 既测量偏差
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	angle+=(AngVelocity - Q_bias) *  TASK_ITV_IMU /1000; //先验估计
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-先验估计误差协方差的微分
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	PP[0][0] += Pdot[0] *  TASK_ITV_IMU /1000;   // Pk-先验估计误差协方差微分的积分
	PP[0][1] += Pdot[1] *  TASK_ITV_IMU /1000;   // 先验估计误差协方差
	PP[1][0] += Pdot[2] *  TASK_ITV_IMU /1000;
	PP[1][1] += Pdot[3] *  TASK_ITV_IMU /1000;
	Angle_err = Angle - angle;	//zk-先验估计
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //后验估计误差协方差
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;

	angle	+= K_0 * Angle_err;	   //后验估计
	Q_bias	+= K_1 * Angle_err;	 //后验估计
	//angle_dot   = Gyro - Q_bias;	//输出值(后验估计)的微分=角速度
	return angle;
}
