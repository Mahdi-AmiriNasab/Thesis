/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
#define DCDC_RST_Pin GPIO_PIN_2
#define DCDC_RST_GPIO_Port GPIOE
#define DAC_Voltage_Pin GPIO_PIN_4
#define DAC_Voltage_GPIO_Port GPIOA
#define DAC_Current_Pin GPIO_PIN_5
#define DAC_Current_GPIO_Port GPIOA
#define CurrentSensor_pack_Pin GPIO_PIN_0
#define CurrentSensor_pack_GPIO_Port GPIOB
#define en_pack2ax_Pin GPIO_PIN_1
#define en_pack2ax_GPIO_Port GPIOB
#define trig_neg_8_Pin GPIO_PIN_2
#define trig_neg_8_GPIO_Port GPIOB
#define trig_neg_9_Pin GPIO_PIN_7
#define trig_neg_9_GPIO_Port GPIOE
#define trig_neg_10_Pin GPIO_PIN_8
#define trig_neg_10_GPIO_Port GPIOE
#define trig_pos_8_Pin GPIO_PIN_9
#define trig_pos_8_GPIO_Port GPIOE
#define trig_pos_9_Pin GPIO_PIN_10
#define trig_pos_9_GPIO_Port GPIOE
#define trig_neg_2_Pin GPIO_PIN_11
#define trig_neg_2_GPIO_Port GPIOE
#define trig_neg_3_Pin GPIO_PIN_12
#define trig_neg_3_GPIO_Port GPIOE
#define trig_neg_4_Pin GPIO_PIN_13
#define trig_neg_4_GPIO_Port GPIOE
#define trig_neg_5_Pin GPIO_PIN_14
#define trig_neg_5_GPIO_Port GPIOE
#define trig_neg_6_Pin GPIO_PIN_15
#define trig_neg_6_GPIO_Port GPIOE
#define trig_neg_7_Pin GPIO_PIN_10
#define trig_neg_7_GPIO_Port GPIOB
#define en_ax2pack_Pin GPIO_PIN_11
#define en_ax2pack_GPIO_Port GPIOB
#define trig_pos_1_Pin GPIO_PIN_14
#define trig_pos_1_GPIO_Port GPIOB
#define trig_pos_2_Pin GPIO_PIN_15
#define trig_pos_2_GPIO_Port GPIOB
#define trig_pos_3_Pin GPIO_PIN_8
#define trig_pos_3_GPIO_Port GPIOD
#define trig_pos_4_Pin GPIO_PIN_9
#define trig_pos_4_GPIO_Port GPIOD
#define trig_pos_5_Pin GPIO_PIN_10
#define trig_pos_5_GPIO_Port GPIOD
#define trig_pos_7_Pin GPIO_PIN_11
#define trig_pos_7_GPIO_Port GPIOD
#define trig_pos_6_Pin GPIO_PIN_12
#define trig_pos_6_GPIO_Port GPIOD
#define CAN_STB_Pin GPIO_PIN_2
#define CAN_STB_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOD
#define LED4_Pin GPIO_PIN_6
#define LED4_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
