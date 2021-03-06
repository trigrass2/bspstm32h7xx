/*********************************************************************************************************
**
**                                北京翼辉信息技术有限公司
**
**                                  微型安全实时操作系统
**
**                                      MS-RTOS(TM)
**
**                               Copyright All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: stm32_drv_gpio.h
**
** 创   建   人: Jiao.jinxing
**
** 文件创建日期: 2020 年 04 月 07 日
**
** 描        述: STM32 芯片 GPIO 驱动头文件
*********************************************************************************************************/

#ifndef STM32_DRV_GPIO_H
#define STM32_DRV_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

ms_err_t stm32_gpio_drv_register(void);
ms_err_t stm32_gpio_dev_create(const char *path, ms_addr_t base, ms_uint16_t pin);

void stm32_gpio_isr_install(ms_uint16_t pin, void (*isr)(ms_ptr_t), ms_ptr_t arg);
void stm32_gpio_int_enable(ms_uint16_t pin, ms_bool_t enable);

#ifdef __cplusplus
}
#endif

#endif                                                                  /*  STM32_DRV_TOUCH_H           */
/*********************************************************************************************************
  END
*********************************************************************************************************/
