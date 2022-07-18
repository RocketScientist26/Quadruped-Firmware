/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_STATUS_Pin GPIO_PIN_1
#define LED_STATUS_GPIO_Port GPIOA
#define BUTTON_RESET_Pin GPIO_PIN_3
#define BUTTON_RESET_GPIO_Port GPIOA
#define BUTTON_RESET_EXTI_IRQn EXTI3_IRQn
#define SERVO_3_Pin GPIO_PIN_0
#define SERVO_3_GPIO_Port GPIOB
#define SERVO_4_Pin GPIO_PIN_1
#define SERVO_4_GPIO_Port GPIOB
#define BT_STAT_Pin GPIO_PIN_8
#define BT_STAT_GPIO_Port GPIOA
#define BT_STAT_EXTI_IRQn EXTI9_5_IRQn
#define BT_TX_Pin GPIO_PIN_9
#define BT_TX_GPIO_Port GPIOA
#define BT_RX_Pin GPIO_PIN_10
#define BT_RX_GPIO_Port GPIOA
#define BT_RESET_Pin GPIO_PIN_11
#define BT_RESET_GPIO_Port GPIOA
#define SERVO_1_Pin GPIO_PIN_4
#define SERVO_1_GPIO_Port GPIOB
#define SERVO_2_Pin GPIO_PIN_5
#define SERVO_2_GPIO_Port GPIOB
#define SERVO_5_Pin GPIO_PIN_6
#define SERVO_5_GPIO_Port GPIOB
#define SERVO_6_Pin GPIO_PIN_7
#define SERVO_6_GPIO_Port GPIOB
#define SERVO_7_Pin GPIO_PIN_8
#define SERVO_7_GPIO_Port GPIOB
#define SERVO_8_Pin GPIO_PIN_9
#define SERVO_8_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
