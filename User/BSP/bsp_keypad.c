// Creator: PCL
/**
 * @file bsp_keypad.c
 * @author PCL
 * @brief C:\Users\pcl\Desktop\diansai\TM4C129\pcl\TIVA_RTOS_CAR_tm4c129_group\User\BSP
 * @version 1.0
 * @date 2023-07-30
 * @copyright Copyright (c) 2023-07-30
 * @code_reference cbr wgj 
 *
 */

#include "bsp_keypad.h"
#include "bsp.h"

void keypad_init(void)
{
    // 启用 GPIO 端口
    SysCtlPeripheralEnable(ROW_SYSCTL);
    SysCtlPeripheralEnable(COLUMN_SYSCTL);

    // 设置键盘行为输出
    GPIOPinTypeGPIOOutput(ROW_BASE, ROW_PIN);

    // 设置键盘列为输入
    GPIOPinTypeGPIOInput(COLUMN_BASE, COLUMN_PIN);

    // 开启内部上拉电阻
    GPIOPadConfigSet(COLUMN_BASE, COLUMN_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

int keypad_getkey(void)
{
    const unsigned char keymap[4][4] = {
        {1, 2, 3, 'A'},
        {4, 5, 6, 'B'},
        {7, 8, 9, 'C'},
        {'*', 0, '#', 'D'}
    };
    
    // 扫描所有行
    for(int row = 0; row < ROW_NUM; ++row)
    {
        // 激活当前行
        GPIOPinWrite(ROW_BASE, ROW_PIN, ~(1 << row));
        
        // 检查每一列是否被按下
        for(int column = 0; column < COLUMN_NUM; ++column)
        {
            if(GPIOPinRead(COLUMN_BASE, 1 << column) == 0)
            {
                // 等待按键释放
                while(GPIOPinRead(COLUMN_BASE, 1 << column) == 0);
                
                // 返回按键值
                return keymap[row][column];
            }
        }
    }

    // 如果没有按键被按下，返回 -1
    return -1;
}




