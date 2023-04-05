#include "main.h"
#include "py32f0xx_it.h"
#include "pv_delay.h"

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}


void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
  /* Tăng giá trị tick */
	PV_DELAY_IncTick();
}
