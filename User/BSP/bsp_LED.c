/*************************************/
/*              Libs                 */
/*************************************/
#include "main.h"
#include "bsp.h"
/*************************************/
/*              Drivers              */
/*************************************/
#include "bsp_LED.h"

void Set_LED(uint8_t R,uint8_t G,uint8_t B)
{   //解决warning问题，和0xFF进行与运算
    if(R>0) GPIOPinWrite(LEDR_GPIO_Port, LEDR_Pin, ~LEDR_Pin & 0xFF);
    else GPIOPinWrite(LEDR_GPIO_Port, LEDR_Pin, LEDR_Pin);
    if(G>0) GPIOPinWrite(LEDG_GPIO_Port, LEDG_Pin, ~LEDG_Pin);
    else GPIOPinWrite(LEDG_GPIO_Port, LEDG_Pin, LEDG_Pin);
    if(B>0) GPIOPinWrite(LEDB_GPIO_Port, LEDB_Pin, ~LEDB_Pin);
    else GPIOPinWrite(LEDB_GPIO_Port, LEDB_Pin, LEDB_Pin);
}

void Set_LED_R(uint8_t R)
{
    if(R>0) GPIOPinWrite(LEDR_GPIO_Port, LEDR_Pin, ~LEDR_Pin & 0xFF);
    else GPIOPinWrite(LEDR_GPIO_Port, LEDR_Pin, LEDR_Pin);
}

void Set_LED_G(uint8_t G)
{
    if(G>0) GPIOPinWrite(LEDG_GPIO_Port, LEDG_Pin, ~LEDG_Pin);
    else GPIOPinWrite(LEDG_GPIO_Port, LEDG_Pin, LEDG_Pin);
}

void Set_LED_B(uint8_t B)
{
    if(B>0) GPIOPinWrite(LEDB_GPIO_Port, LEDB_Pin, ~LEDB_Pin);
    else GPIOPinWrite(LEDB_GPIO_Port, LEDB_Pin, LEDB_Pin);
}

