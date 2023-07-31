/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-28 16:51:50
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-31 11:05:04
 */ 

#ifndef _APP_I2C_H_
#define _APP_I2C_H_
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include <i2cm_drv.h>
extern tI2CMInstance I2C8Inst;
extern tI2CMInstance I2C2Inst;
extern volatile bool I2C8Done;
extern volatile bool I2C2Done;
extern tI2CMWrite8 I2C8WriteInst;
extern tI2CMWrite8 I2C2WriteInst;

void init_bsp_i2c(void);
uint8_t I2C8_ReadByte(uint8_t DevAddress, uint8_t DevReg);
void I2C8_WriteByte(uint8_t DevAddress, uint8_t DevReg, uint8_t Data);
void I2C8_Read(uint8_t DevAddress, uint8_t DevReg, uint8_t *pDataDst, uint8_t Length);
void I2C8_Write(uint8_t DevAddress, uint8_t DevReg, uint8_t *pData, uint8_t Length);

uint8_t I2C2_ReadByte(uint8_t DevAddress, uint8_t DevReg);
void I2C2_WriteByte(uint8_t DevAddress, uint8_t DevReg, uint8_t Data);
void I2C2_Read(uint8_t DevAddress, uint8_t DevReg, uint8_t *pDataDst, uint8_t Length);
void I2C2_Write(uint8_t DevAddress, uint8_t DevReg, uint8_t *pData, uint8_t Length);
#ifdef __cplusplus
}
#endif
#endif /* APP_I2C_H_ */
