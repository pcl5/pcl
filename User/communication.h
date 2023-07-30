#ifndef __COMMUNICATION_H_
#define __COMMUNICATION_H_

#include "bsp.h"

#ifdef Jetson_UART
//MCU to Jetson 数据个数
#define  MCU_TO_JTS_SIZE 39

typedef struct __mcu_to_jts
{
   uint8_t flag;
	 
	 uint32_t timestamp;
}_mcu_to_jts;

typedef struct __jts_to_mcu
{
    uint8_t target_v_x_H;
    uint8_t target_v_x_L;
    uint8_t target_v_z_H;
    uint8_t target_v_z_L;

}_jts_to_mcu;

extern _jts_to_mcu jts_to_mcu;
extern _mcu_to_jts mcu_to_jts;

void Upload_To_JTS(void);
void Download_From_JTS(void);

#endif


#endif

