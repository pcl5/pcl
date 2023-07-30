#include "user_kalman.h"
#include <math.h>
#include "config.h"

/**
 * @brief ���׵��Ῠ�����˲� 
 * @param Accel �ⲿ�õ��ĽǶ�
 * @param Gyro imu��ȡ�Ľ��ٶ�
 * @param dt ���ݸ���ʱ������룩,ÿ5ms����һ���˲� 
 * @returns 
 */	 
float Kalman_Filter_z(float Angle,float Gyro,float dt)		
{
	static float angle;
	// ����������Э����
	float Q_angle=0.001; 		
	// ����������Э���� ����������Э����Ϊһ��һ�����о���
	float Q_gyro=0.003;			
	// ����������Э���� �Ȳ���ƫ��
	float R_angle=0.5;			
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	// �״�Э�������
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	
	// �Ƕ�������ƻ���
	angle+=(Gyro - Q_bias) * dt;
	
	// Pk-����������Э�����΢��
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; 
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	// Pk-����������Э����΢�ֵĻ���
	PP[0][0] += Pdot[0] * dt;   
	// ����������Э����
	PP[0][1] += Pdot[1] * dt;   
	PP[1][0] += Pdot[2] * dt;
	PP[1][1] += Pdot[3] * dt;
	// zk-������ƣ��Ƕ�ƫ��
	Angle_err = Angle - angle;
	
	// �󿨶�������
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	// �󿨶��������ĸ
	E = R_angle + C_0 * PCt_0;	
	// ���㿨��������
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;	
	
	// ����Э�������
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];
	// ����������Э����
	PP[0][0] -= K_0 * t_0;		 
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
	
	// ���ÿ������������Ź���
	// �������
	angle	+= K_0 * Angle_err;	 
	// �������
	Q_bias	+= K_1 * Angle_err;	 
	return angle;
}
float Kalman_Filter_x(float Angle,float AngVelocity)		
{
	//static float angle_dot;
	static float angle;
	float Q_angle=0.001; 		// ����������Э����
	float Q_gyro=0.003;			// 0.003 ����������Э���� ����������Э����Ϊһ��һ�����о���
	float R_angle=0.5;			// ����������Э���� �Ȳ���ƫ��
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	angle+=(AngVelocity - Q_bias) *  TASK_ITV_IMU /1000; //�������
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-����������Э�����΢��
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	PP[0][0] += Pdot[0] *  TASK_ITV_IMU /1000;   // Pk-����������Э����΢�ֵĻ���
	PP[0][1] += Pdot[1] *  TASK_ITV_IMU /1000;   // ����������Э����
	PP[1][0] += Pdot[2] *  TASK_ITV_IMU /1000;
	PP[1][1] += Pdot[3] *  TASK_ITV_IMU /1000;
	Angle_err = Angle - angle;	//zk-�������
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //����������Э����
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
		
	angle	+= K_0 * Angle_err;	   //�������
	Q_bias	+= K_1 * Angle_err;	 //�������
	//angle_dot   = Gyro - Q_bias;	//���ֵ(�������)��΢��=���ٶ�
	return angle;
}
float Kalman_Filter_y(float Angle,float AngVelocity)		
{
	//static float angle_dot;
	static float angle;
	float Q_angle=0.001; 		// ����������Э����
	float Q_gyro=0.003;			// 0.003 ����������Э���� ����������Э����Ϊһ��һ�����о���
	float R_angle=0.5;			// ����������Э���� �Ȳ���ƫ��
	char  C_0 = 1;
	static float Q_bias, Angle_err;
	static float PCt_0, PCt_1, E;
	static float K_0, K_1, t_0, t_1;
	static float Pdot[4] ={0,0,0,0};
	static float PP[2][2] = { { 1, 0 },{ 0, 1 } };
	angle+=(AngVelocity - Q_bias) *  TASK_ITV_IMU /1000; //�������
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-����������Э�����΢��
	Pdot[1]=-PP[1][1];
	Pdot[2]=-PP[1][1];
	Pdot[3]=Q_gyro;
	PP[0][0] += Pdot[0] *  TASK_ITV_IMU /1000;   // Pk-����������Э����΢�ֵĻ���
	PP[0][1] += Pdot[1] *  TASK_ITV_IMU /1000;   // ����������Э����
	PP[1][0] += Pdot[2] *  TASK_ITV_IMU /1000;
	PP[1][1] += Pdot[3] *  TASK_ITV_IMU /1000;
	Angle_err = Angle - angle;	//zk-�������
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //����������Э����
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;

	angle	+= K_0 * Angle_err;	   //�������
	Q_bias	+= K_1 * Angle_err;	 //�������
	//angle_dot   = Gyro - Q_bias;	//���ֵ(�������)��΢��=���ٶ�
	return angle;
}
