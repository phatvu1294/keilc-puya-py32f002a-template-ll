#ifndef __PY32F0XX_IT_H
#define __PY32F0XX_IT_H

/* Nguyên mẫu hàm */
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#endif
