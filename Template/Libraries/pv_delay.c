/**
 * @file pv_delay.c
 * @author Phát Vũ
 * @brief Tệp source của thư viện DELAY.
 */

#include "pv_delay.h"
#include <stdlib.h>

/**
 * @brief Cấu trúc gói dữ liệu.
 */
typedef struct
{
  uint32_t MsTick;        /*!< Giá trị Tick. */
}
PV_DELAY_DataTypeDef;

/**
 * @name Gói dữ liệu dùng chung
 * @{
 */
volatile PV_DELAY_DataTypeDef __PV_DELAY_DataStruct;
/**
 * @}
 */

/* Hàm khởi tạo delay */
void PV_DELAY_Init(void)
{
  /* Lam gì đó ở đây */
}

/* Hàm lấy giá trị hiện hành của SysTick */
uint32_t PV_DELAY_GetTick(void)
{
  /* Trả về giá trị Tick */
  return __PV_DELAY_DataStruct.MsTick;
}

/* Hàm delay ms sử dụng SysTick */
void PV_DELAY_Ms(uint32_t Ms)
{
  /* Tạo trễ Blocking */
  uint32_t startTick = __PV_DELAY_DataStruct.MsTick;
  while (__PV_DELAY_DataStruct.MsTick - startTick < Ms);
}

/* Hàm tăng giá trị Tick */
void PV_DELAY_IncTick(void)
{
  /* Tăng biến tick */
  __PV_DELAY_DataStruct.MsTick++;
}
