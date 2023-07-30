/**
 * @file config.h
 * @brief 参数设置
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*系统频率,仅作为计算参数,不能用来设置*/
#define         USER_SYS_FREQ          12000000


/*----testbench是否启用----*/
#define         TEST_BENCH          0
/*----IMU滤波是否启用----*/
#define         USE_IMU_FILTER      0 

/*滤波器中心频率参数*/
#define         FILTER_FREQ_IMU_AX     50.0F
#define         FILTER_FREQ_IMU_AY     50.0F
#define         FILTER_FREQ_IMU_AZ     50.0F
#define         FILTER_FREQ_IMU_GX     25.0F
#define         FILTER_FREQ_IMU_GY     25.0F
#define         FILTER_FREQ_IMU_GZ     25.0F

/**
 * @brief 串口
 * ****************************************************************************************************************************
 */
/*设备串口,不用时注释掉*/
#if (!TEST_BENCH)
    #define         USB_UART         UART4_BASE
    #define         BLE_UART         UART1_BASE
    #define         Jetson_UART      UART3_BASE
    #define         K210_UART        UART2_BASE
    #define         TFLuna_UART      UART0_BASE
    /*波形显示串口*/
    #define         WAVE_UART        USB_UART
#else 
    #define         USB_UART         UART4_BASE
    #define         BLE_UART         UART1_BASE
    // #define         Jetson_UART      UART3_BASE
    // #define         K210_UART        UART2_BASE
    // #define         OPENMV_UART      UART0_BASE

    /*波形显示串口*/
    #define         WAVE_UART        USB_UART
#endif
 
/*终端串口*/
#define             CONSOLE_UART       USB_UART 

/*串口波特率*/
#define         BAUD_RATE_UART0     115200
#define         BAUD_RATE_UART1     9600
#define         BAUD_RATE_UART2     115200
#define         BAUD_RATE_UART3     115200
#define         BAUD_RATE_UART4     115200

/*帧头帧尾*/
#define         UART_HEAD        '['
#define         UART_TAIL        ']'

/**
 * @brief 中断优先级,(0~7)<<5,留意FreeRTOS管理中断最低优先级=2
 * ****************************************************************************************************************************
 */

#if   TEST_BENCH
/*串口*/
#define         PRIORITY_UART0      (0<<5)
#define         PRIORITY_UART1      (0<<5)
#define         PRIORITY_UART2      (0<<5)
#define         PRIORITY_UART3      (0<<5)
#define         PRIORITY_UART4      (0<<5)


/*EXTI*/
#define         PRIORITY_PORTQ      (0<<5)
#define         PRIORITY_PORTG      (0<<5)
#define         PRIORITY_PORTE      (0<<5)

/*TIM*/
#define         PRIORITY_TIM        (0<<5)

#else
/*串口*/
#define         PRIORITY_UART0      (3<<5)
#define         PRIORITY_UART1      (3<<5)
#define         PRIORITY_UART2      (3<<5)
#define         PRIORITY_UART3      (3<<5)
#define         PRIORITY_UART4      (3<<5)


/*EXTI*/
#define         PRIORITY_PORTG      (1<<5)
#define         PRIORITY_PORTE      (4<<5)
#define         PRIORITY_PORTQ      (1<<5)
/*TIM*/
#define         PRIORITY_TIM        (2<<5)
#endif

/**
 * @brief FreeRTOS各任务执行间隔时间,ms
 * 
 */
#define         TASK_ITV_CAR        50
#define         TASK_ITV_IMU        5
#define         TASK_ITV_UPLOAD     10
/**
 * @brief 小车参数
 * ****************************************************************************************************************************
 */
//电机个数,4个或2个,2个时使用前轮
#define         USE_4_MOTOR             1

//是否使用四倍频
#define         USE_4_TIMES_ENCODER     1

//是否从IMU读得当前角速度
#define         V_DEGREE_FROM_IMU       0

//是否使用角速度PID
#define         V_ANGLE_PID             1

//每圈编码器数
#define         ENC_EVERY_CIRCLE        1560
//轮直径 mm
#define         WHEEL_DIR               67
//轮周长 mm
#define         WHEEL_PERIMETER         210.4867096F

//圈速=实际速度/周长=编码器速度/每圈编码器数
//编码器速度/实际速度=每圈编码器数/周长         !!长度mm!!
#define         V_REAL_TO_ENC           7.36388588F

/*电机方向*/
#define         LF_DIR                  1
#define         LR_DIR                  1
#define         RF_DIR                  0
#define         RR_DIR                  0

//左右轮距的一半        !!单位mm!!
#define         FRAME_W_HALF            80.0F

//前后轮轴距的一半
#define         FRAME_L_HALF            100.0F

/**
 * @brief PID参数
 * ****************************************************************************************************************************
 */
#define         P_LF            0.05F
#define         P_LR            0.05F
#define         P_RF            0.05F
#define         P_RR            0.05F
//#define         P_POS           1.0F    //位置
//#define         P_SPIN          2.0F    //原地旋转
//#define         P_V_ANGLE       0.5F    //角速度

#define         I_LF            0.01F
#define         I_LR            0.01F
#define         I_RF            0.01F
#define         I_RR            0.01F
//#define         I_POS           0.0F
//#define         I_SPIN          0.0F
//#define         I_V_ANGLE       0.0F

#define         D_LF            0.0F
#define         D_LR            0.0F
#define         D_RF            0.0F
#define         D_RR            0.0F
//#define         D_POS           0.0F
//#define         D_SPIN          0.0F
//#define         D_V_ANGLE       0.0F
