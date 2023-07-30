/**
 * @file communication.c
 * @brief 上位机通信
 * 
 */

#include "communication.h"

#ifdef Jetson_UART

uint8_t mcu_to_jts_trans[MCU_TO_JTS_SIZE];
_mcu_to_jts mcu_to_jts;
_jts_to_mcu jts_to_mcu;

/*!
 * @brief 数据同步到Jetson
 * @param  
 */
void Upload_To_JTS(void){
//	mcu_to_jts.acc_x=(int32_t)(imu_data.a_x*1000);
//	mcu_to_jts.acc_y=(int32_t)(imu_data.a_y*1000);
//	mcu_to_jts.acc_z=(int32_t)(imu_data.a_z*1000);
	
//	mcu_to_jts.flag=car_attitude.updated;
//	mcu_to_jts.timestamp = imu_timestamp;
//	
//	mcu_to_jts.gyr_x=(int32_t)(imu_data.g_x*1000);
//	mcu_to_jts.gyr_y=(int32_t)(imu_data.g_y*1000);
//	mcu_to_jts.gyr_z=(int32_t)(imu_data.g_z*1000);
//	mcu_to_jts.voltage=(short)(main_voltage*1000);
//	mcu_to_jts.x_speed=car_attitude.current_v_line;
//	mcu_to_jts.y_speed=0;
//	mcu_to_jts.z_speed=car_attitude.current_v_angle*1000;

//	mcu_to_jts_trans[0]=UART_HEAD;
//	mcu_to_jts_trans[1]=mcu_to_jts.flag;
//	mcu_to_jts_trans[2]=mcu_to_jts.timestamp>>24;
//	mcu_to_jts_trans[3]=mcu_to_jts.timestamp>>16;
//	mcu_to_jts_trans[4]=mcu_to_jts.timestamp>>8;
//	mcu_to_jts_trans[5]=mcu_to_jts.timestamp;
//	mcu_to_jts_trans[6]=mcu_to_jts.x_speed>>8;
//	mcu_to_jts_trans[7]=mcu_to_jts.x_speed;
//	mcu_to_jts_trans[8]=mcu_to_jts.y_speed>>8;
//	mcu_to_jts_trans[9]=mcu_to_jts.y_speed;
//	mcu_to_jts_trans[10]=mcu_to_jts.z_speed>>8;
//	mcu_to_jts_trans[11]=mcu_to_jts.z_speed;
//	mcu_to_jts_trans[12]=mcu_to_jts.acc_x>>24;
//	mcu_to_jts_trans[13]=mcu_to_jts.acc_x>>16;
//	mcu_to_jts_trans[14]=mcu_to_jts.acc_x>>8;
//	mcu_to_jts_trans[15]=mcu_to_jts.acc_x;
//	mcu_to_jts_trans[16]=mcu_to_jts.acc_y>>24;
//	mcu_to_jts_trans[17]=mcu_to_jts.acc_y>>16;
//	mcu_to_jts_trans[18]=mcu_to_jts.acc_y>>8;
//	mcu_to_jts_trans[19]=mcu_to_jts.acc_y;
//	mcu_to_jts_trans[20]=mcu_to_jts.acc_z>>24;
//	mcu_to_jts_trans[21]=mcu_to_jts.acc_z>>16;
//	mcu_to_jts_trans[22]=mcu_to_jts.acc_z>>8;
//	mcu_to_jts_trans[23]=mcu_to_jts.acc_z;
//	mcu_to_jts_trans[24]=mcu_to_jts.gyr_x>>24;
//	mcu_to_jts_trans[25]=mcu_to_jts.gyr_x>>16;
//	mcu_to_jts_trans[26]=mcu_to_jts.gyr_x>>8;
//	mcu_to_jts_trans[27]=mcu_to_jts.gyr_x;
//	mcu_to_jts_trans[28]=mcu_to_jts.gyr_y>>24;
//	mcu_to_jts_trans[29]=mcu_to_jts.gyr_y>>16;
//	mcu_to_jts_trans[30]=mcu_to_jts.gyr_y>>8;
//	mcu_to_jts_trans[31]=mcu_to_jts.gyr_y;
//	mcu_to_jts_trans[32]=mcu_to_jts.gyr_z>>24;
//	mcu_to_jts_trans[33]=mcu_to_jts.gyr_z>>16;
//	mcu_to_jts_trans[34]=mcu_to_jts.gyr_z>>8;
//	mcu_to_jts_trans[35]=mcu_to_jts.gyr_z;
//	mcu_to_jts_trans[36]=mcu_to_jts.voltage>>8;
//	mcu_to_jts_trans[37]=mcu_to_jts.voltage;
//	mcu_to_jts_trans[38]=UART_TAIL;

	Uart_DMA_Trans(Jetson_UART, mcu_to_jts_trans, MCU_TO_JTS_SIZE);
}


/*!
 * @brief 将数据下放到小车 v_x:mm/s; v_z:degree/s
 * @param  
 */
void Download_From_JTS(void){
//	float target_v_line;//mm/s
//	float target_v_z;//degree/s
//	target_v_z=(float)((short)((jts_to_mcu.target_v_z_H<<8)+(jts_to_mcu.target_v_z_L)));
//	target_v_line=(float)((short)(jts_to_mcu.target_v_x_H<<8)+(jts_to_mcu.target_v_x_L));
//	Set_Car_Attitude(target_v_line,target_v_z); 
}

#endif

