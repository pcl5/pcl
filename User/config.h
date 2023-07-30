/**
 * @file config.h
 * @brief ��������
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*ϵͳƵ��,����Ϊ�������,������������*/
#define         USER_SYS_FREQ          12000000


/*----testbench�Ƿ�����----*/
#define         TEST_BENCH          0
/*----IMU�˲��Ƿ�����----*/
#define         USE_IMU_FILTER      0 

/*�˲�������Ƶ�ʲ���*/
#define         FILTER_FREQ_IMU_AX     50.0F
#define         FILTER_FREQ_IMU_AY     50.0F
#define         FILTER_FREQ_IMU_AZ     50.0F
#define         FILTER_FREQ_IMU_GX     25.0F
#define         FILTER_FREQ_IMU_GY     25.0F
#define         FILTER_FREQ_IMU_GZ     25.0F

/**
 * @brief ����
 * ****************************************************************************************************************************
 */
/*�豸����,����ʱע�͵�*/
#if (!TEST_BENCH)
    #define         USB_UART         UART4_BASE
    #define         BLE_UART         UART1_BASE
    #define         Jetson_UART      UART3_BASE
    #define         K210_UART        UART2_BASE
    #define         TFLuna_UART      UART0_BASE
    /*������ʾ����*/
    #define         WAVE_UART        USB_UART
#else 
    #define         USB_UART         UART4_BASE
    #define         BLE_UART         UART1_BASE
    // #define         Jetson_UART      UART3_BASE
    // #define         K210_UART        UART2_BASE
    // #define         OPENMV_UART      UART0_BASE

    /*������ʾ����*/
    #define         WAVE_UART        USB_UART
#endif
 
/*�ն˴���*/
#define             CONSOLE_UART       USB_UART 

/*���ڲ�����*/
#define         BAUD_RATE_UART0     115200
#define         BAUD_RATE_UART1     9600
#define         BAUD_RATE_UART2     115200
#define         BAUD_RATE_UART3     115200
#define         BAUD_RATE_UART4     115200

/*֡ͷ֡β*/
#define         UART_HEAD        '['
#define         UART_TAIL        ']'

/**
 * @brief �ж����ȼ�,(0~7)<<5,����FreeRTOS�����ж�������ȼ�=2
 * ****************************************************************************************************************************
 */

#if   TEST_BENCH
/*����*/
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
/*����*/
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
 * @brief FreeRTOS������ִ�м��ʱ��,ms
 * 
 */
#define         TASK_ITV_CAR        50
#define         TASK_ITV_IMU        5
#define         TASK_ITV_UPLOAD     10
/**
 * @brief С������
 * ****************************************************************************************************************************
 */
//�������,4����2��,2��ʱʹ��ǰ��
#define         USE_4_MOTOR             1

//�Ƿ�ʹ���ı�Ƶ
#define         USE_4_TIMES_ENCODER     1

//�Ƿ��IMU���õ�ǰ���ٶ�
#define         V_DEGREE_FROM_IMU       0

//�Ƿ�ʹ�ý��ٶ�PID
#define         V_ANGLE_PID             1

//ÿȦ��������
#define         ENC_EVERY_CIRCLE        1560
//��ֱ�� mm
#define         WHEEL_DIR               67
//���ܳ� mm
#define         WHEEL_PERIMETER         210.4867096F

//Ȧ��=ʵ���ٶ�/�ܳ�=�������ٶ�/ÿȦ��������
//�������ٶ�/ʵ���ٶ�=ÿȦ��������/�ܳ�         !!����mm!!
#define         V_REAL_TO_ENC           7.36388588F

/*�������*/
#define         LF_DIR                  1
#define         LR_DIR                  1
#define         RF_DIR                  0
#define         RR_DIR                  0

//�����־��һ��        !!��λmm!!
#define         FRAME_W_HALF            80.0F

//ǰ��������һ��
#define         FRAME_L_HALF            100.0F

/**
 * @brief PID����
 * ****************************************************************************************************************************
 */
#define         P_LF            0.05F
#define         P_LR            0.05F
#define         P_RF            0.05F
#define         P_RR            0.05F
//#define         P_POS           1.0F    //λ��
//#define         P_SPIN          2.0F    //ԭ����ת
//#define         P_V_ANGLE       0.5F    //���ٶ�

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
