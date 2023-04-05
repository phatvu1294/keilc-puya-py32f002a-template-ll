/**
 * @file pv_startup.c
 * @author Phát Vũ
 * @brief Tệp source của thư viện STARTUP.
 */

#include "main.h"
#include "pv_startup.h"

/* Hàm khởi tạo Clock */
void PV_STARTUP_Init(void)
{
  /* ___ INIT___ */

  /* Bật Clock PWR */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* Bật Clock AFIO để remap chân */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);

  /* ___CLOCK___ */

  /* Bật HSI */
  LL_RCC_HSI_Enable();

  /* Chờ cho đến khi HSI Ready */
  while (!LL_RCC_HSI_IsReady());
	
	/* Đặt HSI tần số cao */
	LL_RCC_HSI_SetCalibFreq(LL_RCC_HSICALIBRATION_24MHz);

  /* Đặt hệ số chia trước AHB */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  /* Đặt System Clock Switch */
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);

  /* Chờ cho đến khi System Clock Switch sẵn sàng */
  while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_HSISYS);
	
	/* Đặt hệ số chia trước APB1 */
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	
  /* Đặt System Clock Core */
  LL_SetSystemCoreClock(24000000);

  /* ___SYSTICK___ */

  /* Cấu hình Clock SysTick cho delay ms */
  SysTick_Config(SystemCoreClock / 1000);

  /* Cấu hình mức độ ưu tiên ngắt SysTick */
  NVIC_SetPriority(SysTick_IRQn, 0);
}
