/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "pso.h"
#include "pso_internal_types.h"
#include "pso_terminate.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "equalizer.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#ifndef typedef_emxArray_struct1_T_1x100
#define typedef_emxArray_struct1_T_1x100
typedef struct {
  struct1_T data[100];
  int size[2];
} emxArray_struct1_T_1x100;
#endif /* typedef_emxArray_struct1_T_1x100 */

float vol = 0.7, cur = 0.7;
uint8_t current_percent = 20;
float vout = 2.0;

double w_time = 0.4;
double w_inc = 0.4;
double w_ovp = 0.2;
double soc_init[9] = {39,   39,    20,    72,    81,    92,    51,    11,    60};
double soc[9];
uint16_t adc_current [1];

GPIO_PinState dcdc_rst1 = 0, dcdc_rst2 = 0;
GPIO_PinState main_relay = 0;
uint8_t flag_equalizer_step = 0;

typedef enum 
{
	DCDC_Off,
	DCDC_P2B,
	DCDC_B2P
}DCDCState;

  emxArray_struct1_T_1x100 eq_step;
  struct2_T stio;

GPIO_PinState pinstate_pos = GPIO_PIN_RESET;
GPIO_PinState pinstate_neg = GPIO_PIN_RESET;
uint8_t num_neg = 1, num_pos = 1;
DCDCState e_DCDC_status = DCDC_Off;
real_T I_cells [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

/* External inputs (root inport signals with default storage) */
extern ExtU_equalizer_T equalizer_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_equalizer_T equalizer_Y;

uint8_t step_cnt = 0;


typedef struct {
    uint32_t DMA_LISR;
    uint32_t DMA_HISR;
    uint32_t DMA_SxCR;
    uint32_t DMA_SxNDTR;
    uint32_t DMA_SxPAR;
    uint32_t DMA_SxM0AR;
    uint32_t DMA_SxM1AR;
    uint32_t DMA_SxFCR;
    uint32_t ADC_ISR;
    uint32_t ADC_IER;
    uint32_t ADC_CR;
    uint32_t ADC_CFGR;
    uint32_t ADC_CFGR2;
    uint32_t ADC_SMPR1;
    uint32_t ADC_SMPR2;
    uint32_t ADC_PCSEL;
    uint32_t ADC_LTR1;
    uint32_t ADC_HTR1;
    uint32_t ADC_SQR1;
    uint32_t ADC_SQR2;
    uint32_t ADC_SQR3;
    uint32_t ADC_SQR4;
    uint32_t ADC_DR;
    uint32_t ADC_JSQR;
    uint32_t ADC_OFR1;
    uint32_t ADC_OFR2;
    uint32_t ADC_OFR3;
    uint32_t ADC_OFR4;
    uint32_t ADC_JDR1;
    uint32_t ADC_JDR2;
    uint32_t ADC_JDR3;
    uint32_t ADC_JDR4;
    uint32_t ADC_AWD2CR;
    uint32_t ADC_AWD3CR;
    uint32_t ADC_LTR2;
    uint32_t ADC_HTR2;
    uint32_t ADC_LTR3;
    uint32_t ADC_HTR3;
    uint32_t ADC_DIFSEL;
    uint32_t ADC_CALFACT;
    uint32_t ADC_CALFACT2;
} DebugInfo;




void GetDebugInfo(DebugInfo *info)
{
    // Read DMA registers
    info->DMA_LISR = DMA2->LISR;
    info->DMA_HISR = DMA2->HISR;
    info->DMA_SxCR = DMA2_Stream0->CR;
    info->DMA_SxNDTR = DMA2_Stream0->NDTR;
    info->DMA_SxPAR = DMA2_Stream0->PAR;
    info->DMA_SxM0AR = DMA2_Stream0->M0AR;
    info->DMA_SxM1AR = DMA2_Stream0->M1AR;
    info->DMA_SxFCR = DMA2_Stream0->FCR;

    // Read ADC registers
    info->ADC_ISR = ADC1->ISR;
    info->ADC_IER = ADC1->IER;
    info->ADC_CR = ADC1->CR;
    info->ADC_CFGR = ADC1->CFGR;
    info->ADC_CFGR2 = ADC1->CFGR2;
    info->ADC_SMPR1 = ADC1->SMPR1;
    info->ADC_SMPR2 = ADC1->SMPR2;
    info->ADC_PCSEL = ADC1->PCSEL;
    info->ADC_LTR1 = ADC1->LTR1;
    info->ADC_HTR1 = ADC1->HTR1;
    info->ADC_SQR1 = ADC1->SQR1;
    info->ADC_SQR2 = ADC1->SQR2;
    info->ADC_SQR3 = ADC1->SQR3;
    info->ADC_SQR4 = ADC1->SQR4;
    info->ADC_DR = ADC1->DR;
    info->ADC_JSQR = ADC1->JSQR;
    info->ADC_OFR1 = ADC1->OFR1;
    info->ADC_OFR2 = ADC1->OFR2;
    info->ADC_OFR3 = ADC1->OFR3;
    info->ADC_OFR4 = ADC1->OFR4;
    info->ADC_JDR1 = ADC1->JDR1;
    info->ADC_JDR2 = ADC1->JDR2;
    info->ADC_JDR3 = ADC1->JDR3;
    info->ADC_JDR4 = ADC1->JDR4;
    info->ADC_AWD2CR = ADC1->AWD2CR;
    info->ADC_AWD3CR = ADC1->AWD3CR;
    info->ADC_LTR2 = ADC1->LTR2;
    info->ADC_HTR2 = ADC1->HTR2;
    info->ADC_LTR3 = ADC1->LTR3;
    info->ADC_HTR3 = ADC1->HTR3;
    info->ADC_DIFSEL = ADC1->DIFSEL;
    info->ADC_CALFACT = ADC1->CALFACT;
    info->ADC_CALFACT2 = ADC1->CALFACT2;
}



DebugInfo debugInfo;


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

DAC_HandleTypeDef hdac1;

FDCAN_HandleTypeDef hfdcan1;

RNG_HandleTypeDef hrng;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart5;

/* USER CODE BEGIN PV */
  struct0_T global_best;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC1_Init(void);
static void MX_FDCAN1_Init(void);
static void MX_UART5_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM6_Init(void);
static void MX_RNG_Init(void);
/* USER CODE BEGIN PFP */
void Set_DAC_Voltage(float voltage, uint32_t dac_channel);
void set_reset_trig_neg(uint8_t trig_num, GPIO_PinState action);
void set_reset_trig_pos(uint8_t trig_num, GPIO_PinState action);
void set_reset_trig_DCDC(DCDCState state);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_DAC1_Init();
  MX_FDCAN1_Init();
  MX_UART5_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM6_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 
  
  	/* Call the entry-point 'pso'. */
 
    
    HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
    HAL_DAC_Start(&hdac1, DAC_CHANNEL_2);

    HAL_TIM_Base_Start(&htim6);
    HAL_ADC_Start_IT(&hadc1);


    memcpy(soc, soc_init, sizeof(soc));
    equalizer_initialize();


    





		// set_reset_trig_pos(1, GPIO_PIN_SET);
		// set_reset_trig_pos(2, GPIO_PIN_SET);
		// set_reset_trig_pos(3, GPIO_PIN_SET);
		// set_reset_trig_pos(4, GPIO_PIN_SET);
		// set_reset_trig_pos(5, GPIO_PIN_SET);
		// set_reset_trig_pos(6, GPIO_PIN_SET);
		// set_reset_trig_pos(7, GPIO_PIN_SET);
		// set_reset_trig_pos(8, GPIO_PIN_SET);
		// set_reset_trig_pos(9, GPIO_PIN_SET);
	
		// set_reset_trig_neg(2,   GPIO_PIN_SET);
		// set_reset_trig_neg(3,   GPIO_PIN_SET);
		// set_reset_trig_neg(4,   GPIO_PIN_SET);
		// set_reset_trig_neg(5,   GPIO_PIN_SET);
		// set_reset_trig_neg(6,   GPIO_PIN_SET);
		// set_reset_trig_neg(7,   GPIO_PIN_SET);
		// set_reset_trig_neg(8,   GPIO_PIN_SET);
		// set_reset_trig_neg(9,   GPIO_PIN_SET);
    	// set_reset_trig_neg(10,  GPIO_PIN_SET);

        
        // // test timers
        // HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); // pwm_ax2pack_AXBATT_i_n (1)
        // HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_n (2)
        // HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_n (3)
        // HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); // pwm_ax2pack_DCDC_o_n (4)
        // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // pwm_ax2pack_AXBATT_i_p (5)
        // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_p (6)
        // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_p (7)
        // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); // pwm_ax2pack_DCDC_o_p (8)

        HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		pso(soc, 2, w_time, w_inc, w_ovp, &global_best, eq_step.data, eq_step.size, &stio);
        HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
        
        // initialize soc
        memcpy(soc, soc_init, sizeof(soc));

        // step size determination
        volatile uint8_t step_cnt_max = 0;
        for(uint8_t i= 0; i < eq_step.size[1]; i++)
        {
            if(eq_step.data[i].source_queue_cells.data[0] > 0)
                step_cnt_max++;
            else
                break;
        }
  
	while(1)
	{

 
        set_reset_trig_DCDC(e_DCDC_status);
        set_reset_trig_neg(num_neg, pinstate_neg);
        set_reset_trig_pos(num_pos, pinstate_pos);
        // GetDebugInfo(&debugInfo);

        
		if(e_DCDC_status == DCDC_Off)
		{
			dcdc_rst2 = 1;
			dcdc_rst1 = 1;
		}
		else if (e_DCDC_status == DCDC_B2P)
		{
			dcdc_rst2 = 0;
			dcdc_rst1 = 1;
		}
		else if(e_DCDC_status == DCDC_P2B)
		{
			dcdc_rst2 = 1;
			dcdc_rst1 = 0;
		}

        if(current_percent > 100)
            current_percent = 100;	
		cur = current_percent * 0.012;

        if(vout > 37)
            vout = 37;
        if(vout < 0)
            vout = 0;
        vol = 0.94 - vout * 0.0256;

        if(vol > 1)
            vol = 1;
        if(vol < 0)
            vol = 0;
        
        Set_DAC_Voltage(vol, DAC_CHANNEL_1);
        Set_DAC_Voltage(cur, DAC_CHANNEL_2);
		

        
        if(step_cnt < step_cnt_max) // if have any step to go
        {
            if(flag_equalizer_step)
            {
                flag_equalizer_step = 0;
                equalizer_U.CAP_mAh = 2200;
                equalizer_U.src_q_cls[0] = eq_step.data[step_cnt].source_queue_cells.data[0];
                equalizer_U.src_q_cls[1] = eq_step.data[step_cnt].source_queue_cells.data[1];
                equalizer_U.dst_q_cls[0] = eq_step.data[step_cnt].destination_queue_cells.data[0];
                equalizer_U.dst_q_cls[1] = eq_step.data[step_cnt].destination_queue_cells.data[1];
                equalizer_U.src_trg_soc_av = eq_step.data[step_cnt].source_target_soc_av.data[0];
                equalizer_U.dst_trg_soc_av = eq_step.data[step_cnt].destination_target_soc_av.data[0] ? eq_step.data[step_cnt].destination_target_soc_av.data[0] : 255;
                memcpy(equalizer_U.SOC_init, soc_init, sizeof(equalizer_U.SOC_init));
                memcpy(equalizer_U.SOC, soc, sizeof(equalizer_U.SOC));
                memcpy(equalizer_U.I_meas, I_cells, sizeof(equalizer_U.I_meas));
                
                equalizer_step();
                
								if(equalizer_Y.dir == -1)
								{
										static uint32_t dir_float_cnt = 0;
										dir_float_cnt++;
								}

								if(equalizer_Y.stop_transfer)
								{
										static uint32_t stop_transfer_cnt = 0;
										stop_transfer_cnt++;
										step_cnt++;
								}   
            }     
        }
	}





		
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Macro to configure the PLL clock source
  */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  RCC_OscInitStruct.PLL.PLLR = 6;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_16B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T6_TRGO;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_14;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  sConfig.OffsetSignedSaturation = DISABLE;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief DAC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC1_Init(void)
{

  /* USER CODE BEGIN DAC1_Init 0 */

  /* USER CODE END DAC1_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC1_Init 1 */

  /* USER CODE END DAC1_Init 1 */
  /** DAC Initialization
  */
  hdac1.Instance = DAC1;
  if (HAL_DAC_Init(&hdac1) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT1 config
  */
  sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_DISABLE;
  sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT2 config
  */
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC1_Init 2 */

  /* USER CODE END DAC1_Init 2 */

}

/**
  * @brief FDCAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = DISABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 1;
  hfdcan1.Init.NominalSyncJumpWidth = 1;
  hfdcan1.Init.NominalTimeSeg1 = 2;
  hfdcan1.Init.NominalTimeSeg2 = 2;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 1;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 0;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.RxFifo0ElmtsNbr = 0;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 0;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */

  /* USER CODE END FDCAN1_Init 2 */

}

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
static void MX_RNG_Init(void)
{

  /* USER CODE BEGIN RNG_Init 0 */

  /* USER CODE END RNG_Init 0 */

  /* USER CODE BEGIN RNG_Init 1 */

  /* USER CODE END RNG_Init 1 */
  hrng.Instance = RNG;
  hrng.Init.ClockErrorDetection = RNG_CED_ENABLE;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RNG_Init 2 */

  /* USER CODE END RNG_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 12-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 500-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 10;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 12-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 500-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 10;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 12-1;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 500-1;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart5.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart5, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart5, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, trig_neg_2_Pin|trig_pos_1_Pin|reset_ax2pack_AXBATT_i_n_Pin|reset_ax2pack_DCDC_o_p_Pin
                          |reset_pack2ax_DCDC_i_p_Pin|trig_neg_10_Pin|trig_pos_9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, trig_neg_3_Pin|trig_pos_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, en_pack2ax_Pin|reset_pack2ax_AXBATT_o_n_Pin|trig_neg_7_Pin|trig_pos_6_Pin
                          |reset_pack2ax_AXBATT_o_p_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, trig_neg_4_Pin|trig_pos_3_Pin|reset_pack2ax_DCDC_i_n_Pin|trig_neg_5_Pin
                          |trig_pos_4_Pin|reset_ax2pack_DCDC_o_n_Pin|trig_neg_6_Pin|trig_pos_5_Pin
                          |reset_ax2pack_AXBATT_i_p_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, trig_neg_8_Pin|trig_pos_7_Pin|trig_pos_8_Pin|trig_neg_9_Pin
                          |CAN_STB_Pin|CAN_STBD2_Pin|LED1_Pin|LED2_Pin
                          |LED3_Pin|LED4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DCDC_RST1_GPIO_Port, DCDC_RST1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : trig_neg_2_Pin trig_pos_1_Pin reset_ax2pack_AXBATT_i_n_Pin reset_ax2pack_DCDC_o_p_Pin
                           reset_pack2ax_DCDC_i_p_Pin trig_neg_10_Pin trig_pos_9_Pin */
  GPIO_InitStruct.Pin = trig_neg_2_Pin|trig_pos_1_Pin|reset_ax2pack_AXBATT_i_n_Pin|reset_ax2pack_DCDC_o_p_Pin
                          |reset_pack2ax_DCDC_i_p_Pin|trig_neg_10_Pin|trig_pos_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : trig_neg_3_Pin trig_pos_2_Pin */
  GPIO_InitStruct.Pin = trig_neg_3_Pin|trig_pos_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : en_pack2ax_Pin reset_pack2ax_AXBATT_o_n_Pin trig_neg_7_Pin trig_pos_6_Pin
                           reset_pack2ax_AXBATT_o_p_Pin */
  GPIO_InitStruct.Pin = en_pack2ax_Pin|reset_pack2ax_AXBATT_o_n_Pin|trig_neg_7_Pin|trig_pos_6_Pin
                          |reset_pack2ax_AXBATT_o_p_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : trig_neg_4_Pin trig_pos_3_Pin reset_pack2ax_DCDC_i_n_Pin trig_neg_5_Pin
                           trig_pos_4_Pin reset_ax2pack_DCDC_o_n_Pin trig_neg_6_Pin trig_pos_5_Pin
                           reset_ax2pack_AXBATT_i_p_Pin */
  GPIO_InitStruct.Pin = trig_neg_4_Pin|trig_pos_3_Pin|reset_pack2ax_DCDC_i_n_Pin|trig_neg_5_Pin
                          |trig_pos_4_Pin|reset_ax2pack_DCDC_o_n_Pin|trig_neg_6_Pin|trig_pos_5_Pin
                          |reset_ax2pack_AXBATT_i_p_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : trig_neg_8_Pin trig_pos_7_Pin trig_pos_8_Pin trig_neg_9_Pin
                           CAN_STB_Pin CAN_STBD2_Pin LED1_Pin LED2_Pin
                           LED3_Pin LED4_Pin */
  GPIO_InitStruct.Pin = trig_neg_8_Pin|trig_pos_7_Pin|trig_pos_8_Pin|trig_neg_9_Pin
                          |CAN_STB_Pin|CAN_STBD2_Pin|LED1_Pin|LED2_Pin
                          |LED3_Pin|LED4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : DCDC_RST1_Pin */
  GPIO_InitStruct.Pin = DCDC_RST1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DCDC_RST1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void Set_DAC_Voltage(float voltage, uint32_t dac_channel)
{
    if (voltage < 0.0f)
        voltage = 0.0f;
    if (voltage > 3.0f)
        voltage = 3.0f; // Assuming a 3.3V power supply
    uint32_t value = (uint32_t)((voltage / 3.0f) * 4095);
    HAL_DAC_SetValue(&hdac1, dac_channel, DAC_ALIGN_12B_R, value);
}
void set_reset_trig_neg(uint8_t trig_num, GPIO_PinState action)
{
    switch(trig_num)
    {
        case 1:
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, action);
    break;
        
        case 2:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, action);
    break;

        case 3:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, action);
    break;

        case 4:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, action);
    break;

        case 5:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, action);
    break;

        case 6:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, action);
    break;

        case 7:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, action);
        break;

        case 8:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, action);
        break;

        case 9:
            HAL_GPIO_WritePin(trig_neg_2_GPIO_Port, trig_neg_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_3_GPIO_Port, trig_neg_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_4_GPIO_Port, trig_neg_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_5_GPIO_Port, trig_neg_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_6_GPIO_Port, trig_neg_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_7_GPIO_Port, trig_neg_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_8_GPIO_Port, trig_neg_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_9_GPIO_Port, trig_neg_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_neg_10_GPIO_Port, trig_neg_10_Pin, action);
        break;
        
        default:
            // Error_Handler();
        break;
    }
}

void set_reset_trig_pos(uint8_t trig_num, GPIO_PinState action) 
{
    switch(trig_num)
    {
        case 1:
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, action);
        break;
        
        case 2:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, action);
        break;

        case 3:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, action);
        break;

        case 4:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, action);
        break;

        case 5:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, action);
        break;

        case 6:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, action);
        break;

        case 7:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, action);
        break;

        case 8:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, action);
        break;

        case 9:
            HAL_GPIO_WritePin(trig_pos_1_GPIO_Port, trig_pos_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_2_GPIO_Port, trig_pos_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_3_GPIO_Port, trig_pos_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_4_GPIO_Port, trig_pos_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_5_GPIO_Port, trig_pos_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_6_GPIO_Port, trig_pos_6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_7_GPIO_Port, trig_pos_7_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_8_GPIO_Port, trig_pos_8_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(trig_pos_9_GPIO_Port, trig_pos_9_Pin, action);
        break;
        
        default:
            // Error_Handler();
        break;
    }
}


void set_reset_trig_DCDC(DCDCState state) 
{
    switch(state) {

        case DCDC_Off:

            HAL_GPIO_WritePin(DCDC_RST1_GPIO_Port, DCDC_RST1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
            HAL_Delay(1);

            // reset optos
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_n_GPIO_Port, reset_ax2pack_AXBATT_i_n_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_p_GPIO_Port, reset_ax2pack_AXBATT_i_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_p_GPIO_Port, reset_ax2pack_DCDC_o_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_n_GPIO_Port, reset_ax2pack_DCDC_o_n_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_p_GPIO_Port, reset_pack2ax_DCDC_i_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_n_GPIO_Port, reset_pack2ax_DCDC_i_n_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_p_GPIO_Port, reset_pack2ax_AXBATT_o_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_n_GPIO_Port, reset_pack2ax_AXBATT_o_n_Pin, GPIO_PIN_SET);

            // reset timers
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_4); // pwm_ax2pack_AXBATT_i_n (1)
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_n (2)
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_n (3)
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1); // pwm_ax2pack_DCDC_o_n (4)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1); // pwm_ax2pack_AXBATT_i_p (5)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_p (6)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_p (7)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4); // pwm_ax2pack_DCDC_o_p (8)



        break;

        case DCDC_P2B:

            // set timers
            HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_n (3) (C)
            HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_n (2)
            
            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_p (7) (M)
            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_p (6)

            // set optos
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_n_GPIO_Port, reset_ax2pack_AXBATT_i_n_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_p_GPIO_Port, reset_ax2pack_AXBATT_i_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_p_GPIO_Port, reset_ax2pack_DCDC_o_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_n_GPIO_Port, reset_ax2pack_DCDC_o_n_Pin, GPIO_PIN_SET);

            // reset optos
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_p_GPIO_Port, reset_pack2ax_DCDC_i_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_n_GPIO_Port, reset_pack2ax_DCDC_i_n_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_p_GPIO_Port, reset_pack2ax_AXBATT_o_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_n_GPIO_Port, reset_pack2ax_AXBATT_o_n_Pin, GPIO_PIN_RESET);

            // reset timers
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1); // pwm_ax2pack_DCDC_o_n (4)
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_4); // pwm_ax2pack_AXBATT_i_n (1)

            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1); // pwm_ax2pack_AXBATT_i_p (5)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4); // pwm_ax2pack_DCDC_o_p (8)

            HAL_Delay(1);
            HAL_GPIO_WritePin(DCDC_RST1_GPIO_Port, DCDC_RST1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
        break;

        case DCDC_B2P:

            // set timers
            HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); // pwm_ax2pack_DCDC_o_n (4)
            HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); // pwm_ax2pack_AXBATT_i_n (1)

            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // pwm_ax2pack_AXBATT_i_p (5)
            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); // pwm_ax2pack_DCDC_o_p (8)

            // set optos
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_p_GPIO_Port, reset_pack2ax_DCDC_i_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_DCDC_i_n_GPIO_Port, reset_pack2ax_DCDC_i_n_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_p_GPIO_Port, reset_pack2ax_AXBATT_o_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(reset_pack2ax_AXBATT_o_n_GPIO_Port, reset_pack2ax_AXBATT_o_n_Pin, GPIO_PIN_SET);

            // reset optos
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_n_GPIO_Port, reset_ax2pack_AXBATT_i_n_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_ax2pack_AXBATT_i_p_GPIO_Port, reset_ax2pack_AXBATT_i_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_p_GPIO_Port, reset_ax2pack_DCDC_o_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(reset_ax2pack_DCDC_o_n_GPIO_Port, reset_ax2pack_DCDC_o_n_Pin, GPIO_PIN_RESET);

            // reset timers
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_n (3)
            HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_n (2)
            
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2); // pwm_pack2ax_DCDC_i_p (7)
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3); // pwm_pack2ax_AXBATT_o_p (6)

            HAL_Delay(1);
            HAL_GPIO_WritePin(DCDC_RST1_GPIO_Port, DCDC_RST1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);

        break;

        default:
            // Error_Handler();
        break;
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    flag_equalizer_step = 1;
    static uint16_t cnt = 0;
    if(cnt > sizeof(adc_current)/sizeof(uint16_t))
        cnt = 0;
    
    adc_current[cnt] = HAL_ADC_GetValue(&hadc1);
    cnt++;
    HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);


}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

