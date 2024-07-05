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
#include <Estimations.h>

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

// DC DC variables
float vol = 0.7, cur = 0.7;
uint8_t current_percent = 20;
float vout = 2.0;

typedef enum 
{
	DCDC_Off,
	DCDC_P2B,
	DCDC_B2P
}DCDCState;

uint8_t num_neg = 1, num_pos = 1;
DCDCState e_DCDC_status = DCDC_Off;

// pso variables
double w_time = 0.4;
double w_inc = 0.4;
double w_ovp = 0.2;
double soc_init[9] = {39,   39,    20,    72,    81,    92,    51,    11,    60};
double soc[9];
uint16_t adc_current [300];
uint16_t adc_current_window [50];
uint8_t pso_run = 1;
uint8_t step_cnt_max = 0;

emxArray_struct1_T_1x100 eq_step;
struct2_T stio;

uint8_t step_cnt = 0;


GPIO_PinState dcdc_rst1 = 0, dcdc_rst2 = 0;
GPIO_PinState main_relay = 0;
uint8_t flag_equalizer_step = 0;

// measurement
uint16_t cnt = 0;
uint32_t adc_mean = 0; 
uint32_t adc_sum = 0; 

void sort_and_extract_window(uint16_t *array, uint16_t array_size, uint16_t window_size, uint16_t start_index, uint16_t *window);


GPIO_PinState pinstate_pos = GPIO_PIN_RESET;
GPIO_PinState pinstate_neg = GPIO_PIN_RESET;

// equalizer

real_T I_cells [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

/* External inputs (root inport signals with default storage) */
extern ExtU_equalizer_T equalizer_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_equalizer_T equalizer_Y;

// estimations

uint8_t flag_estimations_step = 0;
float V_cells[9] = {3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3};

double ntcTable[138] =
{
    183,    173,    163,    153,    144,    135,    120,    128,    113,
    107,    101,    90,     85,     80.6,   76.02,  72.01,  68.14,
    64.47,  61.03,  57.8,   54.77,  51.82,  49.28,  46,89,  44.62,
    42.48,  40.45,  38.53,  36.70,  34.97,  33.33,  31.77,  30.25,
    28.82,   27.45, 26.16,  24.94, 23.77,   22.67,  21.62,  20.63,  19.68,  18.78,  17.93,  17.12,   16.35, 15.62,
    14.93,  14.26,  13.63,  13.04,  12.47,  11.92,  11.41, 10.91,
    10.45,  10.00,  9.575,  9.170,  8.784,  8.416,  8.064, 7.730,
    7.410,  7.106,  6.815,  6.538,  6.273,  6.020,  5.778, 5.548,
    5.327,  5.117,  4.915,  4.723,  4.539,  4.363,  4.195, 4.034,
    3.880,  3.733,  3.592,  3.457,  3.328,  3.204,  3.086, 2.972,
    2.863,  2.759,  2.659,  2.564,  2.472,  2.384,  2.292, 2.218,
    2.141,  2.066,  1.994,  1.926,  1.860,  1.796,  1.735, 1.677,
    1.621,  1.567,  1.515,  1.465,  1.417,  1.371,  1.326, 1.284,
    1.243,  1.203,  1.165,  1.128,  1.093,  1.059,  1.027, 0.9955,
    0.9654, 0.9363, 0.9083, 0.8812, 0.8550, 0.8297, 0.8052, 0.7816,
    0.7587, 0.7366, 0.7152, 0.6945, 0.6744, 0.6558, 0.6376, 0.6199,
    0.6026, 0.5858
};

double OCV_Curve[101]=
{   
    4.1629, 4.1223, 4.1043, 4.0910, 4.0804, 4.0724, 4.0659, 4.0597, 4.0539, 4.0482, 4.0432,
    4.0389, 4.0333, 4.0268, 4.0200, 4.0128, 4.0035, 3.9930, 3.9812, 3.9694, 3.9580, 3.9471,
    3.9353, 3.9220, 3.9090, 3.8972, 3.8864, 3.8771, 3.8678, 3.8585, 3.8501, 3.8423, 3.8349,
    3.8268, 3.8188, 3.8110, 3.8033, 3.7955, 3.7875, 3.7788, 3.7698, 3.7611, 3.7524, 3.7431,
    3.7338, 3.7248, 3.7165, 3.7075, 3.6979, 3.6879, 3.6780, 3.6687, 3.6588, 3.6489, 3.6393,
    3.6303, 3.6213, 3.6120, 3.6027, 3.5943, 3.5850, 3.5757, 3.5661, 3.5565, 3.5469, 3.5363,
    3.5252, 3.5131, 3.5016, 3.4911, 3.4824, 3.4743, 3.4666, 3.4588, 3.4505, 3.4412, 3.4306,
    3.4185, 3.4046, 3.3885, 3.3717, 3.3544, 3.3364, 3.3175, 3.2961, 3.2722, 3.2468, 3.2201,
    3.1913, 3.1600, 3.1274, 3.0952, 3.0633, 3.0298, 2.9907, 2.9454, 2.8931, 2.8357, 2.7610,
    2.6534, 2.5000
};

double OCV_Curve_new[21]={
4.164, 4.098, 4.077, 4.050, 4.002, 3.951, 3.910, 3.854, 3.808, 3.766, 3.729, 3.686, 3.634, 3.578, 3.524, 3.489, 3.429, 3.341, 3.235, 3.125, 2.877};


double OCV(double v){
    uint16_t i;
    for(i=0;i<101;i++){
        if( v > OCV_Curve[i] ){
            return 100 - (double)i;
        }
    }
}

double new_OCV(double v){
    uint16_t i;
    for(i=0;i<21;i++){
        if( v > OCV_Curve_new[i] ){
            if(i==0)
                return 100;
            return 100 - 5*(double)i + 5.00* (v - OCV_Curve_new[i]) / (OCV_Curve_new[i-1]-OCV_Curve_new[i]);
        }
    }
}


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
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);


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

        // if(__HAL_ADC_GET_FLAG(&hadc1, ADC_FLAG_EOC))
        // {

        // }

        if(pso_run)
        {
            pso_run = 0;
            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
            pso(soc, 2, w_time, w_inc, w_ovp, &global_best, eq_step.data, eq_step.size, &stio);
            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
            
            // initialize soc
            memcpy(soc, soc_init, sizeof(soc));

            // step size determination
            for(uint8_t i= 0; i < eq_step.size[1]; i++)
            {
                if(eq_step.data[i].source_queue_cells.data[0] > 0)
                    step_cnt_max++;
                else
                    break;
            }
        }

        if(flag_estimations_step)
        {
            flag_estimations_step = 0;

            Estimations_DW.x[0] = new_OCV(V_cells[0]) * 0.01;

            Estimations_U.voltage = V_cells[0];
            Estimations_U.current = I_cells[0];
            Estimations_U.temp = 25;
            Estimations_U.Cq = 2200;
            Estimations_step();
        }
		
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
                equalizer_U.current_sensor_pb_ADC = adc_mean;
                
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
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_64CYCLES_5;
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
  htim6.Init.Prescaler = 12000-1;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 10-1;
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
    uint16_t adc_current_size = sizeof(adc_current)/sizeof(uint16_t);
    uint16_t adc_current_window_size = sizeof(adc_current_window)/sizeof(uint16_t);
    flag_equalizer_step = 1;
    flag_estimations_step = 1;
    
    adc_current[cnt] = HAL_ADC_GetValue(&hadc1);
    cnt++;

    if(cnt > adc_current_size)
    {
        cnt = 0;
        adc_sum = 0; 
        sort_and_extract_window(adc_current, adc_current_size, adc_current_window_size, adc_current_size/2 - adc_current_window_size/2, adc_current_window);
        
        for(uint16_t i = 0; i < adc_current_window_size; i++)
        {
            adc_sum += adc_current_window[i];
        }
        adc_mean =  adc_sum / adc_current_window_size;


    }


    

    
    HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
    // HAL_ADC_Start_IT(&hadc1);


}

// Function to compare two elements for qsort
int compare(const void *a, const void *b)
{
    return (*(uint16_t*)a - *(uint16_t*)b);
}

// Function to sort the array and extract a window
void sort_and_extract_window(uint16_t *array, uint16_t array_size, uint16_t window_size, uint16_t start_index, uint16_t *window)
{
    // Step 1: Sort the array
    qsort(array, array_size, sizeof(uint16_t), compare);

    // Step 2: Extract the window
    for (int i = 0; i < window_size; i++)
    {
        if (start_index + i < array_size)
        {
            window[i] = array[start_index + i];
        }
        else
        {
            // Handle case where window exceeds array bounds
            window[i] = -1;  // or some other sentinel value or error handling
        }
    }
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

