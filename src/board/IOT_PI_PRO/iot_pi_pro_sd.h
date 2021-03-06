/**
  ******************************************************************************
  * @file    iot_pi_pro_sd.h
  * @author  MCD Application Team
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm32h7b3i_discovery_sd.c driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IOT_PI_PRO_SD_H
#define IOT_PI_PRO_SD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "iot_pi_pro_bsp_conf.h"
#include "iot_pi_pro_bsp_errno.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32H7B3I_DK
  * @{
  */

/** @defgroup STM32H7B3I_DK_SD SD
  * @{
  */

/** @defgroup STM32H7B3I_DK_SD_Exported_Types Exported Types
  * @{
  */

/**
  * @brief SD Card information structure
  */
#define BSP_SD_CardInfo HAL_SD_CardInfoTypeDef

#if (USE_HAL_SD_REGISTER_CALLBACKS == 1)
typedef struct
{
  pSD_CallbackTypeDef  pMspInitCb;
  pSD_CallbackTypeDef  pMspDeInitCb;
}BSP_SD_Cb_t;
#endif /* (USE_HAL_SD_REGISTER_CALLBACKS == 1) */
/**
  * @}
  */

/** @defgroup STM32H7B3I_DK_SD_Exported_Constants Exported Constants
  * @{
  */
#define SD_INSTANCES_NBR         1UL

#ifndef SD_WRITE_TIMEOUT
#define SD_WRITE_TIMEOUT         100U
#endif

#ifndef SD_READ_TIMEOUT
#define SD_READ_TIMEOUT          100U
#endif

/**
  * @brief  SD transfer state definition
  */
#define SD_TRANSFER_OK         0U
#define SD_TRANSFER_BUSY       1U

#define MSD_OK                 SD_TRANSFER_OK

/**
  * @brief SD-detect signal
  */
#define SD_PRESENT               1UL
#define SD_NOT_PRESENT           0UL

#define SD_DETECT_PIN                        GPIO_PIN_14
#define SD_DETECT_GPIO_PORT                  GPIOD
#define SD_DETECT_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOD_CLK_ENABLE()
#define SD_DETECT_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOD_CLK_DISABLE()
#define SD_DETECT_EXTI_IRQn                  EXTI15_10_IRQn
#define SD_DETECT_EXTI_LINE                  EXTI_LINE_14

/* DMA definitions for SD DMA transfer */
#define SD2_DMAx_TxRx_CLK_ENABLE           __HAL_RCC_DMA2_CLK_ENABLE
#define SD2_SDMMC2_DMAx_Tx_CHANNEL         DMA_CHANNEL_4
#define SD2_SDMMC2_DMAx_Rx_CHANNEL         DMA_CHANNEL_4
#define SD2_SDMMC2_DMAx_Tx_STREAM          DMA2_Stream6
#define SD2_SDMMC2_DMAx_Rx_STREAM          DMA2_Stream3
#define SD2_SDMMC2_DMAx_Tx_IRQn            DMA2_Stream6_IRQn
#define SD2_SDMMC2_DMAx_Rx_IRQn            DMA2_Stream3_IRQn
#define SD2_SDMMC2_DMA_Tx_IRQHandler       DMA2_Stream6_IRQHandler
#define SD2_SDMMC2_DMA_Rx_IRQHandler       DMA2_Stream3_IRQHandler
#define SD2_SDMMC2_IRQHandler              SDMMC2_IRQHandler

/**
  * @}
  */

/** @addtogroup STM32H7B3I_DK_SD_Exported_Variables
  * @{
  */
extern SD_HandleTypeDef   hsd_sdmmc[SD_INSTANCES_NBR];
extern EXTI_HandleTypeDef hsd_exti[SD_INSTANCES_NBR];

/**
  * @}
  */

/** @defgroup STM32H7B3I_DK_SD_Exported_FunctionsPrototypes Exported Functions Prototypes
  * @{
  */
int32_t BSP_SD_Init();
int32_t BSP_SD_DeInit();
#if (USE_HAL_SD_REGISTER_CALLBACKS == 1)
int32_t BSP_SD_RegisterMspCallbacks(BSP_SD_Cb_t *CallBacks);
int32_t BSP_SD_RegisterDefaultMspCallbacks();
#endif /* (USE_HAL_SD_REGISTER_CALLBACKS == 1) */
int32_t BSP_SD_DetectITConfig();
int32_t BSP_SD_ReadBlocks(uint32_t *pData, uint32_t BlockIdx, uint32_t BlocksNbr);
int32_t BSP_SD_WriteBlocks(uint32_t *pData, uint32_t BlockIdx, uint32_t NbrOfBlocks);
int32_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t BlockIdx, uint32_t NbrOfBlocks);
int32_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t BlockIdx, uint32_t NbrOfBlocks);
int32_t BSP_SD_ReadBlocks_IT(uint32_t *pData, uint32_t BlockIdx, uint32_t NbrOfBlocks);
int32_t BSP_SD_WriteBlocks_IT(uint32_t *pData, uint32_t BlockIdx, uint32_t NbrOfBlocks);
int32_t BSP_SD_Erase(uint32_t BlockIdx, uint32_t BlocksNbr);
int32_t BSP_SD_GetCardState();
int32_t BSP_SD_GetCardInfo(BSP_SD_CardInfo *CardInfo);
int32_t BSP_SD_IsDetected();

/* These functions can be modified in case the current settings (e.g. DMA stream ot IT)
   need to be changed for specific application needs */
void BSP_SD_AbortCallback();
void BSP_SD_WriteCpltCallback();
void BSP_SD_ReadCpltCallback();

HAL_StatusTypeDef MX_SDMMC2_SD_Init(SD_HandleTypeDef *hsd);
void BSP_SD_DetectCallback(uint32_t Status);

void BSP_SD_DETECT_IRQHandler();
void BSP_SD_IRQHandler();

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* IOT_PI_PRO_SD_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
