#include "main.h"
#include "pv_startup.h"
#include "pv_delay.h"

int main(void)
{
  /* Khởi tạo clock */
  PV_STARTUP_Init();

  /* Khởi tạo delay */
  PV_DELAY_Init();

  /* Khởi tạo PB3 */
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);

  /* Cấu hình PB3 */
  LL_GPIO_InitTypeDef LL_GPIO_InitStruture;
  LL_GPIO_InitStruture.Mode = LL_GPIO_MODE_OUTPUT;
  LL_GPIO_InitStruture.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_InitStruture.Pin = LL_GPIO_PIN_3;
  LL_GPIO_InitStruture.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_InitStruture.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  LL_GPIO_Init(GPIOB, &LL_GPIO_InitStruture);

  while (1)
  {
    LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_3);
    PV_DELAY_Ms(1000);
  }
}

void APP_ErrorHandler(void)
{
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  while (1)
  {
  }
}
#endif
