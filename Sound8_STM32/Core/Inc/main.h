/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WS_review_Pin GPIO_PIN_1
#define WS_review_GPIO_Port GPIOA
#define POWEREN_Pin GPIO_PIN_0
#define POWEREN_GPIO_Port GPIOB
#define MIC_WS_Pin GPIO_PIN_12
#define MIC_WS_GPIO_Port GPIOB
#define MIC_CK_Pin GPIO_PIN_13
#define MIC_CK_GPIO_Port GPIOB
#define I2SdummySD_Pin GPIO_PIN_15
#define I2SdummySD_GPIO_Port GPIOB
#define RGBB_Pin GPIO_PIN_6
#define RGBB_GPIO_Port GPIOC
#define RGBG_Pin GPIO_PIN_7
#define RGBG_GPIO_Port GPIOC
#define RGBR_Pin GPIO_PIN_8
#define RGBR_GPIO_Port GPIOC
#define BCLK_review_Pin GPIO_PIN_8
#define BCLK_review_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_8
#define SPI1_CS_GPIO_Port GPIOB
#define SPI1_CS_EXTI_IRQn EXTI9_5_IRQn
#define SPI1_IRQ_Pin GPIO_PIN_9
#define SPI1_IRQ_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
