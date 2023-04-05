/**
 * @file pv_delay.h
 * @author Phát Vũ
 * @brief Tệp header của thư viện DELAY.
 */

#ifndef __PV_DELAY_H
#define __PV_DELAY_H

#include "py32f002ax5.h"

/**
 * @brief         Hàm khởi tạo tạo trễ.
 */
void PV_DELAY_Init(void);

/**
 * @brief         Hàm lấy tick hiện tại.
 *
 * @return        Giá trị tick hiện tại.
 */
uint32_t PV_DELAY_GetTick(void);

/**
 * @brief         Hàm tạo trễ ms.
 *
 * @param[in]     Ms: Thời gian trễ ms.
 */
void PV_DELAY_Ms(uint32_t Ms);

/**
 * @brief         Hàm tăng giá trị Tick.
 */
void PV_DELAY_IncTick(void);

#endif
