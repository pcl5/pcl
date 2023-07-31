/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-30 23:46:12
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 23:46:57
 */
#include <stdint.h>
#include <stdbool.h>
#include "bsp_uDMA.h"
#include "driverlib/udma.h"
#include "driverlib/uart.h"
#include "hw_memmap.h"
#include "driverlib/sysctl.h"



// uDMA Control Table内存
// 注意：如需用alternate DMA功能需将空间扩大一倍
#if defined(ewarm)
	#pragma data_alignment=1024
	uint8_t uDMA_buf[1024];
#elif defined(ccs)
	#pragma DATA_ALIGN(ui8ControlTable, 1024)
	uint8_t uDMA_buf[1024];
#else
	uint8_t uDMA_buf[1024] __attribute__ ((aligned(1024)));
#endif

/*!
 * @brief 初始化uDMA
 * @param  
 */
void init_Bsp_uDMA(void){
	// 开启uDMA时钟 masterenable
	SysCtlPeripheralEnable( SYSCTL_PERIPH_UDMA );
	// uDMA使能
	uDMAEnable();
	//设定uDMA Control Table
	uDMAControlBaseSet( uDMA_buf );

    //uart0
	uDMAChannelControlSet( UDMA_PRI_SELECT | UDMA_CH9_UART0TX , UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1 );
	UARTDMAEnable( UART0_BASE , UART_DMA_TX );
	uDMAChannelAssign(UDMA_CH9_UART0TX);	

    //uart1
	uDMAChannelControlSet( UDMA_PRI_SELECT | UDMA_CH23_UART1TX , UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1 );
	UARTDMAEnable( UART1_BASE , UART_DMA_TX );
	uDMAChannelAssign(UDMA_CH23_UART1TX);	

    //uart2
    uDMAChannelControlSet( UDMA_PRI_SELECT | UDMA_CH13_UART2TX , UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1 );
	UARTDMAEnable( UART2_BASE , UART_DMA_TX );	
	uDMAChannelAssign(UDMA_CH13_UART2TX);	

    //uart3
    uDMAChannelControlSet( UDMA_PRI_SELECT | UDMA_CH17_UART3TX , UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1 );
	UARTDMAEnable( UART3_BASE , UART_DMA_TX );	
	uDMAChannelAssign(UDMA_CH17_UART3TX);	

    //uart4
    uDMAChannelControlSet( UDMA_PRI_SELECT | UDMA_CH19_UART4TX , UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1 );
	UARTDMAEnable( UART4_BASE , UART_DMA_TX );	
	uDMAChannelAssign(UDMA_CH19_UART4TX);	
}

