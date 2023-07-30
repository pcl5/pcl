#ifndef _TM4C_IT_H_
#define _TM4C_IT_H_
#ifdef __cplusplus
extern "C"{
#endif
void EXTI_LFEA_IRQHandler(void);
void EXTI_LFEB_IRQHandler(void);
void EXTI_LREA_IRQHandler(void);
void EXTI_LREB_IRQHandler(void);
void EXTI_RFEA_IRQHandler(void);
void EXTI_RFEB_IRQHandler(void);
void EXTI_RREA_IRQHandler(void);
void EXTI_RREB_IRQHandler(void);
void UART0_IRQHandler(void);
void UART1_IRQHandler(void);
void UART2_IRQHandler(void);
void UART3_IRQHandler(void);
void UART4_IRQHandler(void);
void EXTI_PORTG_IRQHandler(void);
void EXTI_PORTE_IRQHandler(void);
void EXTI_PORTQ_IRQHandler(void);

void TIM1_IRQHandler(void);

#ifdef __cplusplus
}
#endif
#endif /* _TM4C123_IT_H_ */
