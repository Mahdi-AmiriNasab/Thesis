/*
 * File: ChargeAl.c
 *
 * Code generated for Simulink model 'ChargeAl'.
 *
 * Model version                  : 3.44
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 11 10:40:27 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ChargeAl.h"
#include "rtwtypes.h"
#include "ChargeAl_types.h"
#include "ChargeAl_private.h"
#include "rt_nonfinite.h"
#define Ch_IN_BHM_establish_TLS_Session (1U)
#define Ch_IN_BST_NormalShutdownBy_EVSE (7U)
#define Char_IN_seq_Communication_Setup (5U)
#define Charg_IN_BCP_BMSChargeParameter (1U)
#define Charg_IN_BCS_BSM_BCL_ChargeLoop (2U)
#define ChargeA_IN_BRO_PowerDelivery_ON (3U)
#define ChargeAl_IN_BRM_establish      (2U)
#define ChargeAl_IN_BRO_Loop_PreCharge (2U)
#define ChargeAl_IN_Charging_complete  (1U)
#define ChargeAl_IN_End_charging       (2U)
#define ChargeAl_IN_ErrorBEM           (1U)
#define ChargeAl_IN_Error_Timeout      (2U)
#define ChargeAl_IN_Loop_CableCheck    (3U)
#define ChargeAl_IN_Start_Communication (1U)
#define ChargeAl_IN_Stop_Communication (2U)
#define ChargeAl_IN_Welding_detection  (3U)
#define ChargeAl_IN_error_handling     (3U)
#define ChargeAl_IN_initialize         (3U)
#define ChargeAl_IN_loop_Charge_control (4U)
#define Charge_IN_BST_BSD_OpenContactor (5U)
#define IN_BCS_BCL_Loop_Charge_control_ (1U)
#define IN_BST_BMS_STOPPowerDeliveryOFF (4U)
#define IN_BST_EmergencyShutdownByCharg (6U)
#define IN_seq_End_of_charging_process (6U)
#define IN_seq_Target_Setting_and_Charg (7U)

/* Block signals (default storage) */
B_ChargeAl_T ChargeAl_B;

/* Block states (default storage) */
DW_ChargeAl_T ChargeAl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ChargeAl_T ChargeAl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ChargeAl_T ChargeAl_Y;

/* Real-time model */
static RT_MODEL_ChargeAl_T ChargeAl_M_;
RT_MODEL_ChargeAl_T *const ChargeAl_M = &ChargeAl_M_;

/* Forward declaration for local functions */
static void seq_Target_Setting_and_Charge_S(const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void enter_atomic_BCS_BSM_ChargeLoop(void);
static void BCS_BCL_Loop_Charge_control_and(const real32_T *ChrgCurrMax, const
  BMS *BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void ChargeAl_BCS_BSM_BCL_ChargeLoop(const real32_T *ChrgCurrMax, const
  BMS *BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void ChargeAl_BST_BSD_OpenContactor(const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void ChargeAl_loop_Charge_control(const real32_T *ChrgCurrMax, const BMS *
  BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void ChargeA_seq_Communication_Setup(const CAN_Input
  *BusConversion_InsertedFor_ISO15);
static void ChargeAl_State_B2(real32_T *Switch, real_T *DutyCycle, const
  real32_T *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF,
  const real32_T *PilotVoltSIF);
static void ChargeAl_State_C(real32_T *Switch, real_T *DutyCycle, const real32_T
  *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF, const
  real32_T *PilotVoltSIF);
static void ChargeAl_State_C1(real32_T *Switch, real_T *DutyCycle, const
  real32_T *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF,
  const real32_T *PilotVoltSIF);

/* Output and update for function-call system: '<S14>/pwm_update' */
void ChargeAl_pwm_update(real_T rtu_DutyCycle, real32_T *rty_I_max)
{
  real_T rtb_Gain;

  /* Gain: '<S15>/Gain' */
  rtb_Gain = 100.0 * rtu_DutyCycle;

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Logic: '<S15>/OR'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  Saturate: '<S15>/Saturation'
   */
  if ((rtb_Gain < 9.5) || (rtb_Gain > 96.5)) {
    *rty_I_max = 0.0F;
  } else {
    if (rtb_Gain > 96.0) {
      /* Saturate: '<S15>/Saturation' */
      rtb_Gain = 96.0;
    } else if (rtb_Gain < 10.0) {
      /* Saturate: '<S15>/Saturation' */
      rtb_Gain = 10.0;
    }

    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S18>/Constant'
     *  Gain: '<S15>/Gain1'
     *  Gain: '<S15>/Gain2'
     *  RelationalOperator: '<S18>/Compare'
     *  Saturate: '<S15>/Saturation'
     *  Sum: '<S15>/Sum'
     */
    if (rtb_Gain <= 85.0) {
      *rty_I_max = (real32_T)(0.6 * rtb_Gain);
    } else {
      *rty_I_max = (real32_T)((rtb_Gain - 64.0) * 2.5);
    }

    /* End of Switch: '<S15>/Switch1' */
  }

  /* End of Switch: '<S15>/Switch' */
}

/* Output and update for function-call system: '<S6>/Subsystem' */
void ChargeAl_Subsystem(CAN_MESSAGE_BUS *rty_BHM)
{
  /* S-Function (scanpack): '<S10>/BHM Pack' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant11'
   *  Constant: '<S10>/Constant12'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/Constant4'
   */
  /* S-Function (scanpack): '<S10>/BHM Pack' */
  (*rty_BHM).ID = 405231348U;
  (*rty_BHM).Length = 8U;
  (*rty_BHM).Extended = 1U;
  (*rty_BHM).Remote = 0;
  (*rty_BHM).Data[0] = 0;
  (*rty_BHM).Data[1] = 0;
  (*rty_BHM).Data[2] = 0;
  (*rty_BHM).Data[3] = 0;
  (*rty_BHM).Data[4] = 0;
  (*rty_BHM).Data[5] = 0;
  (*rty_BHM).Data[6] = 0;
  (*rty_BHM).Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 5000.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[0] = (*rty_BHM).Data[0] | (uint16_T)(packedValue);
            (*rty_BHM).Data[1] = (*rty_BHM).Data[1] | (uint16_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 1500.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[2] = (*rty_BHM).Data[2] | (uint16_T)(packedValue);
            (*rty_BHM).Data[3] = (*rty_BHM).Data[3] | (uint16_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 1.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(255)) {
          packedValue = (uint16_T) 255;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[4] = (*rty_BHM).Data[4] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 55.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(255)) {
          packedValue = (uint16_T) 255;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[5] = (*rty_BHM).Data[5] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 100.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(255)) {
          packedValue = (uint16_T) 255;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[6] = (*rty_BHM).Data[6] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = 80.0;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(255)) {
          packedValue = (uint16_T) 255;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            (*rty_BHM).Data[7] = (*rty_BHM).Data[7] | (uint16_T)(packedValue);
          }
        }
      }
    }
  }
}

/* Output and update for function-call system: '<S6>/Subsystem2' */
void ChargeAl_Subsystem2(uint16_T rtu_CR_Plc_VersionMinor, uint16_T
  rtu_CR_Plc_VersionMajorH, uint16_T rtu_CR_Plc_BatteryType, uint16_T
  rtu_CR_Plc_EvEnergyCapacity, uint16_T rtu_CR_Plc_VersionMajorL, uint16_T
  rtu_CR_Plc_EvmaxVolt, CAN_MESSAGE_BUS *rty_BRM)
{
  /* S-Function (scanpack): '<S13>/CAN Pack9' */
  /* S-Function (scanpack): '<S13>/CAN Pack9' */
  (*rty_BRM).ID = 469915380U;
  (*rty_BRM).Length = 8U;
  (*rty_BRM).Extended = 1U;
  (*rty_BRM).Remote = 0;
  (*rty_BRM).Data[0] = 0;
  (*rty_BRM).Data[1] = 0;
  (*rty_BRM).Data[2] = 0;
  (*rty_BRM).Data[3] = 0;
  (*rty_BRM).Data[4] = 0;
  (*rty_BRM).Data[5] = 0;
  (*rty_BRM).Data[6] = 0;
  (*rty_BRM).Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_VersionMinor);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        packedValue = (uint16_T) (packingValue);

        {
          {
            (*rty_BRM).Data[0] = (*rty_BRM).Data[0] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_VersionMajorL);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        packedValue = (uint16_T) (packingValue);

        {
          {
            (*rty_BRM).Data[1] = (*rty_BRM).Data[1] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_VersionMajorH);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(255)) {
          packedValue = (uint16_T) 255;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            (*rty_BRM).Data[2] = (*rty_BRM).Data[2] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_BatteryType);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(255)) {
          packedValue = (uint16_T) 255;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            (*rty_BRM).Data[3] = (*rty_BRM).Data[3] | (uint16_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_EvEnergyCapacity);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        packedValue = (uint16_T) (packingValue);

        {
          {
            (*rty_BRM).Data[4] = (*rty_BRM).Data[4] | (uint16_T)(packedValue);
            (*rty_BRM).Data[5] = (*rty_BRM).Data[5] | (uint16_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (rtu_CR_Plc_EvmaxVolt);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        packedValue = (uint16_T) (packingValue);

        {
          {
            (*rty_BRM).Data[6] = (*rty_BRM).Data[6] | (uint16_T)(packedValue);
            (*rty_BRM).Data[7] = (*rty_BRM).Data[7] | (uint16_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void seq_Target_Setting_and_Charge_S(const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  switch (ChargeAl_DW.is_seq_Target_Setting_and_Charg) {
   case Charg_IN_BCP_BMSChargeParameter:
    /* [V2G2-599] */
    if (BusConversion_InsertedFor_ISO15->CML.Flag &&
        BusConversion_InsertedFor_ISO15->CTS.Flag) {
      /* RecvMsg == "ChargeParameterDiscoveryRes()"] */
      ChargeAl_DW.is_seq_Target_Setting_and_Charg = ChargeAl_IN_Loop_CableCheck;
      ChargeAl_DW.temporalCounter_i1 = 0UL;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_Loop_CableCheck;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-599]
         SendMsg = "CableCheckReq()"; */
      ChargeAl_Y.CAN_Output_p.BCP.Flag = false;

      /* 500V */
      /* 100V */

      /* [V2G2-506] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 1400UL) {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CTS_CMLTimeout = 1U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Target_Setting_and_Charg = 0U;
      ChargeAl_DW.exitPortIndex_i = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 500L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BCP_ChargeParameter_Discovery;

      /* Outport: '<Root>/CAN_Output' incorporates:
       *  Constant: '<Root>/BattVolt'
       */
      /* [V2G2-505] */
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_MaxVoltSingleBattery = 4200.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxCurrent = 1500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvNormialEnergy = 4500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxVolt = 4500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvAvailableTemp = 110.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvCurrentVolt = 356.0F;
      ChargeAl_Y.CAN_Output_p.BRM.Flag = false;
      ChargeAl_Y.CAN_Output_p.BCP.Flag = true;
    } else {
      /* Outport: '<Root>/CAN_Output' incorporates:
       *  Constant: '<Root>/BattVolt'
       */
      /* [V2G2-505] */
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_MaxVoltSingleBattery = 4200.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxCurrent = 1500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvNormialEnergy = 4500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxVolt = 4500.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvAvailableTemp = 110.0F;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvCurrentVolt = 356.0F;
      ChargeAl_Y.CAN_Output_p.BRM.Flag = false;
      ChargeAl_Y.CAN_Output_p.BCP.Flag = true;

      /* SendMsg = "ChargeParameterDiscoveryReq()";%RequestedEnergyTransferMode */
    }
    break;

   case ChargeAl_IN_BRO_Loop_PreCharge:
    /* Constant: '<Root>/BattVolt' */
    /* [V2G2-528] */
    if (BusConversion_InsertedFor_ISO15->SIF.CR_Secc_EvseOutVolt / 356.0F >=
        0.96) {
      /* Outport: '<Root>/State_Mode' */
      /* RecvMsg == "PreChargeRes()"] */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Target_Setting_and_Charg = 0U;
      ChargeAl_DW.exitPortIndex_i = 3UL;

      /* [V2G2-526] */
    } else if (ChargeAl_DW.temporalCounter_i1 >=
               ChargeAl_DW.V2G_EVCC_Msg_Timeout_PreChargeR * 200.0F) {
      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Target_Setting_and_Charg = 0U;
      ChargeAl_DW.exitPortIndex_i = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 250L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BRO_Loop_PreCharge;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-525]
         SendMsg = "PreChargeReq()"; */
      ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 0.0F;
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-525]
         SendMsg = "PreChargeReq()"; */
      ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 0.0F;
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    }
    break;

   default:
    /* case IN_Loop_CableCheck: */
    /* [V2G2-525]
       [RecvMsg == "CableCheckRes()"]
       &&CAN_Input.SIF.CR_Secc_EvseOutVolt/Battery_Voltage >=vRatio] */
    ChargeAl_DW.is_seq_Target_Setting_and_Charg = ChargeAl_IN_BRO_Loop_PreCharge;
    ChargeAl_DW.temporalCounter_i1 = 0UL;
    ChargeAl_DW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BRO_Loop_PreCharge;

    /* Outport: '<Root>/CAN_Output' */
    /* [V2G2-525]
       SendMsg = "PreChargeReq()"; */
    ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 0.0F;
    ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    break;
  }

  switch (ChargeAl_DW.exitPortIndex_i) {
   case 2:
    ChargeAl_DW.exitPortIndex_i = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_error_handling;
    ChargeAl_DW.is_error_handling = ChargeAl_IN_Error_Timeout;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_Error_Timeout;

    /* [V2G2-728] */
    break;

   case 3:
    ChargeAl_DW.exitPortIndex_i = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_loop_Charge_control;
    ChargeAl_DW.is_loop_Charge_control = ChargeA_IN_BRO_PowerDelivery_ON;
    ChargeAl_DW.temporalCounter_i1 = 0UL;
    ChargeAl_DW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BRO_PowerDelivery_ON;

    /* Outport: '<Root>/CAN_Output' */
    /* [V2G2-528]
       SendMsg = "PowerDeliveryReq()";
       SendData = ""; */
    ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 170.0F;
    ChargeAl_B.PwrCmdBMS = true;

    /* Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    break;
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void enter_atomic_BCS_BSM_ChargeLoop(void)
{
  /* Outport: '<Root>/CAN_Output' */
  /* [V2G2-531] */
  ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

  /* Real Voltage 0 (no value with CCS) */
  ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

  /* Real Current 0 (no value with CCS) */
  ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

  /* (no value with CCS) */
  ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
  ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
  ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
  ChargeAl_Y.CAN_Output_p.BSM.Flag = true;
  ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumSinglePower = 2.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_HighestTemp = 95.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumHighTemp = 2.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_LowestTemp = 90.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumLowTemp = 5.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowVolSinglePowe = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowSocBat = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverCurr = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ExcexxTemp = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_InsulState = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ConnectionState = 0.0F;
  ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_EvReady = 1.0F;
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void BCS_BCL_Loop_Charge_control_and(const real32_T *ChrgCurrMax, const
  BMS *BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  /* [V2G2-531] */
  if (BusConversion_InsertedFor_ISO15->CCS.Flag && (!*AND1)) {
    /* RecvMsg == "CurrentDemandRes()" && */
    ChargeAl_DW.is_loop_Charge_control = Charg_IN_BCS_BSM_BCL_ChargeLoop;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BCS_BSM_BCL_ChargeLoop;
    ChargeAl_DW.temporalCounter_i3 = 0U;
    enter_atomic_BCS_BSM_ChargeLoop();
    ChargeAl_DW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/CAN_Output' */
    /*  wait until charging completes
       SendMsg = "CurrentDemandReq()";
       SendData = tostring (CurrCmd); */
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
      BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
      BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
    ChargeAl_Y.CAN_Output_p.BCL.Flag = true;

    /* [V2G2-532] */
  } else if (ChargeAl_DW.temporalCounter_i1 >= 400UL) {
    /* Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CCSTimeout = 1U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_None;
    ChargeAl_DW.is_loop_Charge_control = 0U;
    ChargeAl_DW.exitPortIndex_a = 2UL;
  } else {
    if ((int16_T)ChargeAl_DW.temporalCounter_i3 * 5 >= 250) {
      ChargeAl_DW.temporalCounter_i3 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-530] */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

      /* Real Voltage 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

      /* Real Current 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

      /* (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
      ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-530] */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

      /* Real Voltage 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

      /* Real Current 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

      /* (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
      ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
    }

    if (ChargeAl_DW.temporalCounter_i2 * 5L >= 50L) {
      ChargeAl_DW.temporalCounter_i3 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-530] */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

      /* Real Voltage 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

      /* Real Current 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

      /* (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
      ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
      ChargeAl_Y.CAN_Output_p.BCL.Flag = true;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
      ChargeAl_Y.CAN_Output_p.BCL.Flag = true;
    }
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void ChargeAl_BCS_BSM_BCL_ChargeLoop(const real32_T *ChrgCurrMax, const
  BMS *BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  if (BusConversion_InsertedFor_ISO15->CST.CF_Secc_ArtificialSuspend == 1.0F) {
    ChargeAl_DW.is_loop_Charge_control = Ch_IN_BST_NormalShutdownBy_EVSE;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BST_NormalShutdownBy_EVSE;

    /* Outport: '<Root>/CAN_Output' */
    /* EV will control the Charger to reduce the charging voltage and current. */
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.Flag = true;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

    /* [V2G2-527]
       RecvMsg == "CurrentDemandRes()" &&  */
  } else if (*AND1) {
    /* Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
    ChargeAl_DW.is_loop_Charge_control = IN_BST_BMS_STOPPowerDeliveryOFF;
    ChargeAl_DW.temporalCounter_i1 = 0UL;
    ChargeAl_DW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode =
      State_ModeType_BST_PowerDelivery_OFF_ShutdownByEVInCaseOfFullCharging;

    /* Outport: '<Root>/CAN_Output' */
    /* SendMsg = "PowerDeliveryStopReq()";
       SendData = ""; */
    ChargeAl_Y.CAN_Output_p.BST.Flag = true;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

    /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
       CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
  } else if (BusConversion_InsertedFor_ISO15->CST.Flag &&
             (BusConversion_InsertedFor_ISO15->CST.CF_Secc_SuddenStop == 1.0F))
  {
    ChargeAl_DW.is_loop_Charge_control = IN_BST_EmergencyShutdownByCharg;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BST_EmergencyShutdownByCharger__SECC;

    /* Outport: '<Root>/CAN_Output' */
    /* EV will control the Charger to reduce the charging voltage and current. */
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.Flag = true;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

    /* [V2G2-532] */
  } else if ((!BusConversion_InsertedFor_ISO15->CCS.Flag) &&
             (ChargeAl_DW.temporalCounter_i1 >= 400UL)) {
    /* Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CCSTimeout = 1U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_None;
    ChargeAl_DW.is_loop_Charge_control = 0U;
    ChargeAl_DW.exitPortIndex_a = 2UL;
  } else {
    if ((int16_T)ChargeAl_DW.temporalCounter_i3 * 5 >= 250) {
      ChargeAl_DW.temporalCounter_i3 = 0U;
      enter_atomic_BCS_BSM_ChargeLoop();
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /*  wait until charging completes
         SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-531] */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

      /* Real Voltage 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

      /* Real Current 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

      /* (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
      ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
      ChargeAl_Y.CAN_Output_p.BSM.Flag = true;
      ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumSinglePower = 2.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_HighestTemp = 95.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumHighTemp = 2.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_LowestTemp = 90.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumLowTemp = 5.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowVolSinglePowe = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowSocBat = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverCurr = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ExcexxTemp = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_InsulState = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ConnectionState = 0.0F;
      ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_EvReady = 1.0F;
    }

    if (ChargeAl_DW.temporalCounter_i2 * 5L >= 50L) {
      ChargeAl_DW.temporalCounter_i3 = 0U;
      enter_atomic_BCS_BSM_ChargeLoop();
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /*  wait until charging completes
         SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
      ChargeAl_Y.CAN_Output_p.BCL.Flag = true;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /*  wait until charging completes
         SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
      ChargeAl_Y.CAN_Output_p.BCL.Flag = true;
    }
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void ChargeAl_BST_BSD_OpenContactor(const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  if (BusConversion_InsertedFor_ISO15->CSD.Flag) {
    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_None;
    ChargeAl_DW.is_loop_Charge_control = 0U;
    ChargeAl_DW.exitPortIndex_a = 3UL;
  } else if (ChargeAl_DW.temporalCounter_i1 >= 400UL) {
    /* Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CSDTimeout = 1U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_None;
    ChargeAl_DW.is_loop_Charge_control = 0U;
    ChargeAl_DW.exitPortIndex_a = 2UL;
  } else {
    if (ChargeAl_DW.temporalCounter_i2 * 5L >= 10L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
      ChargeAl_DW.temporalCounter_i3 = 0U;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

      /* CAN_Output.BST.CF_Plc_InstationFault=InstationFault;
         CAN_Output.BST.CF_Plc_ConnectorHighTemp=ConnectorHighTemp;
         CAN_Output.BST.CF_Plc_BmsOverTemp=BMSOverTemp;
         CAN_Output.BST.CF_Plc_ConnectorFault=ConnectorFault;
         CAN_Output.BST.CF_Plc_BatOverTemp=BatOverTemp;
         CAN_Output.BST.CF_Plc_HighVoltRelay=HighVoltRelay;
         CAN_Output.BST.CF_Plc_ErrCheckPoint2=ErrCheckPoint2;
         CAN_Output.BST.CF_Plc_OtherFault=OtherFalt;
         CAN_Output.BST.CF_Plc_CurrOver=CurrOver;
         CAN_Output.BST.CF_Plc_AbnormalVolt=AbnormalVolt; */
    }

    if ((int16_T)ChargeAl_DW.temporalCounter_i3 * 5 >= 250) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
      ChargeAl_DW.temporalCounter_i3 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.Flag = true;
      ChargeAl_B.PwrCmdBMS = false;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.CR_Plc_SuspendSoc = 100.0F;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.Flag = true;
      ChargeAl_B.PwrCmdBMS = false;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.CR_Plc_SuspendSoc = 100.0F;
    }
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void ChargeAl_loop_Charge_control(const real32_T *ChrgCurrMax, const BMS *
  BusConversion_InsertedFor_ISO_c, const boolean_T *AND1, const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  switch (ChargeAl_DW.is_loop_Charge_control) {
   case IN_BCS_BCL_Loop_Charge_control_:
    BCS_BCL_Loop_Charge_control_and(ChrgCurrMax, BusConversion_InsertedFor_ISO_c,
      AND1, BusConversion_InsertedFor_ISO15);
    break;

   case Charg_IN_BCS_BSM_BCL_ChargeLoop:
    ChargeAl_BCS_BSM_BCL_ChargeLoop(ChrgCurrMax, BusConversion_InsertedFor_ISO_c,
      AND1, BusConversion_InsertedFor_ISO15);
    break;

   case ChargeA_IN_BRO_PowerDelivery_ON:
    /* [V2G2-530] */
    if ((BusConversion_InsertedFor_ISO15->CRO.CR_Secc_ContactorOn == 170.0F) &&
        (BusConversion_InsertedFor_ISO15->CRO.CR_IsolationStatus == 1.0F) &&
        BusConversion_InsertedFor_ISO15->CRO.Flag) {
      /* RecvMsg == "PowerDeliveryRes()"] */
      ChargeAl_DW.is_loop_Charge_control = IN_BCS_BCL_Loop_Charge_control_;
      ChargeAl_DW.temporalCounter_i1 = 0UL;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode =
        State_ModeType_BCS_BCL_Loop_Charge_control_and_Rescheduling;
      ChargeAl_DW.temporalCounter_i3 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-530] */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;

      /* Real Voltage 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;

      /* Real Current 0 (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;

      /* (no value with CCS) */
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 60.0F;
      ChargeAl_Y.CAN_Output_p.BCS.Flag = true;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "CurrentDemandReq()";
         SendData = tostring (CurrCmd); */
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 4030.0F;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = *ChrgCurrMax <=
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq ? *ChrgCurrMax :
        BusConversion_InsertedFor_ISO_c->ChargeCurrentReq;
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 1.0F;
      ChargeAl_Y.CAN_Output_p.BCL.Flag = true;

      /* [V2G2-799] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 400UL) {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CROAALTimeout = 1U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_loop_Charge_control = 0U;
      ChargeAl_DW.exitPortIndex_a = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 250L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BRO_PowerDelivery_ON;

      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-528]
         SendMsg = "PowerDeliveryReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 170.0F;
      ChargeAl_B.PwrCmdBMS = true;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* [V2G2-528]
         SendMsg = "PowerDeliveryReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 170.0F;
      ChargeAl_B.PwrCmdBMS = true;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BRO.Flag = true;
    }
    break;

   case IN_BST_BMS_STOPPowerDeliveryOFF:
    /* [V2G2-533] */
    if (BusConversion_InsertedFor_ISO15->CST.Flag) {
      /* RecvMsg == "PowerDeliveryStopRes()"] */
      ChargeAl_DW.is_loop_Charge_control = Charge_IN_BST_BSD_OpenContactor;
      ChargeAl_DW.temporalCounter_i1 = 0UL;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BST_BSD_OpenContactor;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
      ChargeAl_DW.temporalCounter_i3 = 0U;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.Flag = true;
      ChargeAl_B.PwrCmdBMS = false;

      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BSD.CR_Plc_SuspendSoc = 100.0F;

      /* [V2G2-799] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 400UL) {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CSTTimeout = 1U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_loop_Charge_control = 0U;
      ChargeAl_DW.exitPortIndex_a = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 10L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode =
        State_ModeType_BST_PowerDelivery_OFF_ShutdownByEVInCaseOfFullCharging;

      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "PowerDeliveryStopReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "PowerDeliveryStopReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

      /* CAN_Output.BST.CF_Plc_InstationFault=InstationFault;
         CAN_Output.BST.CF_Plc_ConnectorHighTemp=ConnectorHighTemp;
         CAN_Output.BST.CF_Plc_BmsOverTemp=BMSOverTemp;
         CAN_Output.BST.CF_Plc_ConnectorFault=ConnectorFault;
         CAN_Output.BST.CF_Plc_BatOverTemp=BatOverTemp;
         CAN_Output.BST.CF_Plc_HighVoltRelay=HighVoltRelay;
         CAN_Output.BST.CF_Plc_ErrCheckPoint2=ErrCheckPoint2;
         CAN_Output.BST.CF_Plc_OtherFault=OtherFalt;
         CAN_Output.BST.CF_Plc_CurrOver=CurrOver;
         CAN_Output.BST.CF_Plc_AbnormalVolt=AbnormalVolt; */
    }
    break;

   case Charge_IN_BST_BSD_OpenContactor:
    ChargeAl_BST_BSD_OpenContactor(BusConversion_InsertedFor_ISO15);
    break;

   case IN_BST_EmergencyShutdownByCharg:
    if (ChargeAl_DW.temporalCounter_i1 >= 100UL) {
      ChargeAl_DW.is_loop_Charge_control = IN_BST_BMS_STOPPowerDeliveryOFF;
      ChargeAl_DW.temporalCounter_i1 = 0UL;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode =
        State_ModeType_BST_PowerDelivery_OFF_ShutdownByEVInCaseOfFullCharging;

      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "PowerDeliveryStopReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* EV will control the Charger to reduce the charging voltage and current. */
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

      /* BST.CF_Plc_ChgFinished=1; */
    }
    break;

   default:
    /* case IN_BST_NormalShutdownBy_EVSE: */
    if (ChargeAl_DW.temporalCounter_i1 >= 100UL) {
      ChargeAl_DW.is_loop_Charge_control = IN_BST_BMS_STOPPowerDeliveryOFF;
      ChargeAl_DW.temporalCounter_i1 = 0UL;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode =
        State_ModeType_BST_PowerDelivery_OFF_ShutdownByEVInCaseOfFullCharging;

      /* Outport: '<Root>/CAN_Output' */
      /* SendMsg = "PowerDeliveryStopReq()";
         SendData = ""; */
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 1.0F;

      /* CAN_Output.BST.CF_Plc_ReachTotalVolt=ReachTotalVolt;
         CAN_Output.BST.CF_Plc_ReachSingleVolt=ReachSingleVolt; */
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /* EV will control the Charger to reduce the charging voltage and current. */
      ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
      ChargeAl_Y.CAN_Output_p.BST.Flag = true;
      ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 1.0F;

      /* BST.CF_Plc_ChgFinished=1 ; */
    }
    break;
  }

  switch (ChargeAl_DW.exitPortIndex_a) {
   case 2:
    ChargeAl_DW.exitPortIndex_a = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_error_handling;
    ChargeAl_DW.is_error_handling = ChargeAl_IN_Error_Timeout;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_Error_Timeout;

    /* [V2G2-728] */
    break;

   case 3:
    ChargeAl_DW.exitPortIndex_a = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = IN_seq_End_of_charging_process;
    ChargeAl_DW.is_seq_End_of_charging_process = ChargeAl_IN_Welding_detection;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_Welding_detection;
    break;
  }
}

/* Function for Chart: '<S9>/ISO 15118 HLC (EVCC)' */
static void ChargeA_seq_Communication_Setup(const CAN_Input
  *BusConversion_InsertedFor_ISO15)
{
  switch (ChargeAl_DW.is_seq_Communication_Setup) {
   case Ch_IN_BHM_establish_TLS_Session:
    /* [V2G2-485] */
    if (BusConversion_InsertedFor_ISO15->CRM.Flag) {
      /* && CAN_Input.CRM.CR_Secc_RecognitionResult==0]
         RecvMsg == "supportedAppProtocolRes()" */
      ChargeAl_DW.is_seq_Communication_Setup = ChargeAl_IN_BRM_establish;
      ChargeAl_DW.temporalCounter_i1 = 0UL;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BRM_establish_TLS_Session1;

      /* Outport: '<Root>/CAN_Output' */
      /*  [V2G2-485]
         Setup session
         SendMsg = "SessionSetupReq()"; */
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMinor = false;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorL = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorH = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_BatteryType = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvEnergyCapacity = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvmaxVolt = true;
      ChargeAl_Y.CAN_Output_p.BHM.Flag = false;
      ChargeAl_Y.CAN_Output_p.BRM.Flag = true;

      /* Outputs for Function Call SubSystem: '<S6>/Subsystem2' */
      /* Outport: '<Root>/BRM' */
      ChargeAl_Subsystem2(0U, 0U, 0U, 0U, 0U, 0U, &ChargeAl_Y.BRM_k);

      /* End of Outputs for SubSystem: '<S6>/Subsystem2' */

      /* [V2G2-484] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 9000UL) {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CRM00Timeout = 1U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Communication_Setup = 0U;
      ChargeAl_DW.exitPortIndex_p = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 250L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BHM_BMSHelloMessage;

      /* Outport: '<Root>/CAN_Output' */
      /*  [V2G2-483]
         Transport Layer Security (TLS)
         V2G Root Certificate needed to verify
         EVSE certificate as TLS server
         SendMsg = "supportedAppProtocolReq()"; */
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvPermissibleMaxVolt = 4032.0F;

      /*  BMS Hello Message */
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvmaxCurrent = 1500.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CF_Plc_Bhm8Bytes = 1.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_FullSOC = 100.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_BulkSOC = 90.0F;
      ChargeAl_Y.CAN_Output_p.BHM.Flag = true;

      /* Outputs for Function Call SubSystem: '<S6>/Subsystem' */
      /* Outport: '<Root>/BHM' */
      ChargeAl_Subsystem(&ChargeAl_Y.BHM_l);

      /* End of Outputs for SubSystem: '<S6>/Subsystem' */
      ChargeAl_B.InfoHLC = true;
    }
    break;

   case ChargeAl_IN_BRM_establish:
    /* [V2G2-487] */
    if (BusConversion_InsertedFor_ISO15->CRM.Flag) {
      /* Outport: '<Root>/State_Mode' */
      /* &&CRM.CR_Secc_RecognitionResult==170]
         RecvMsg == "SessionSetupRes()"] */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Communication_Setup = 0U;
      ChargeAl_DW.exitPortIndex_p = 3UL;

      /* [V2G2-448][V2G2-486] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 9000UL) {
      /* Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CRMAATimeout = 1U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Communication_Setup = 0U;
      ChargeAl_DW.exitPortIndex_p = 2UL;
    } else if (ChargeAl_DW.temporalCounter_i2 * 5L >= 250L) {
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BRM_establish_TLS_Session1;

      /* Outport: '<Root>/CAN_Output' */
      /*  [V2G2-485]
         Setup session
         SendMsg = "SessionSetupReq()"; */
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMinor = false;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorL = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorH = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_BatteryType = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvEnergyCapacity = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvmaxVolt = true;
      ChargeAl_Y.CAN_Output_p.BHM.Flag = false;
      ChargeAl_Y.CAN_Output_p.BRM.Flag = true;

      /* Outputs for Function Call SubSystem: '<S6>/Subsystem2' */
      /* Outport: '<Root>/BRM' */
      ChargeAl_Subsystem2(0U, 0U, 0U, 0U, 0U, 0U, &ChargeAl_Y.BRM_k);

      /* End of Outputs for SubSystem: '<S6>/Subsystem2' */
    } else {
      /* Outport: '<Root>/CAN_Output' */
      /*  [V2G2-485]
         Setup session
         SendMsg = "SessionSetupReq()"; */
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMinor = false;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorL = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorH = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_BatteryType = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvEnergyCapacity = true;
      ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvmaxVolt = true;
      ChargeAl_Y.CAN_Output_p.BHM.Flag = false;
      ChargeAl_Y.CAN_Output_p.BRM.Flag = true;

      /* Outputs for Function Call SubSystem: '<S6>/Subsystem2' */
      /* Outport: '<Root>/BRM' */
      ChargeAl_Subsystem2(0U, 0U, 0U, 0U, 0U, 0U, &ChargeAl_Y.BRM_k);

      /* End of Outputs for SubSystem: '<S6>/Subsystem2' */
    }
    break;

   default:
    /* case IN_initialize: */
    /* [SIF.CF_Lock_status==1&&SIF.CF_Secc_S2_OnReq==1&&CHM.CR_Secc_VersionMinor==VersionMinor&&CHM.CR_Secc_VersionMajorL==VersionMajorL&&CHM.CR_Secc_VersionMajorH==VersionMajorH&&... */
    if (BusConversion_InsertedFor_ISO15->CHM.Flag) {
      /* RecvMsg == "Server Hello()" */
      ChargeAl_DW.is_seq_Communication_Setup = Ch_IN_BHM_establish_TLS_Session;
      ChargeAl_DW.temporalCounter_i1 = 0UL;
      ChargeAl_DW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_BHM_BMSHelloMessage;

      /* Outport: '<Root>/CAN_Output' */
      /*  [V2G2-483]
         Transport Layer Security (TLS)
         V2G Root Certificate needed to verify
         EVSE certificate as TLS server
         SendMsg = "supportedAppProtocolReq()"; */
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvPermissibleMaxVolt = 4032.0F;

      /*  BMS Hello Message */
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvmaxCurrent = 1500.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CF_Plc_Bhm8Bytes = 1.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_FullSOC = 100.0F;
      ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_BulkSOC = 90.0F;
      ChargeAl_Y.CAN_Output_p.BHM.Flag = true;

      /* Outputs for Function Call SubSystem: '<S6>/Subsystem' */
      /* Outport: '<Root>/BHM' */
      ChargeAl_Subsystem(&ChargeAl_Y.BHM_l);

      /* End of Outputs for SubSystem: '<S6>/Subsystem' */
      ChargeAl_B.InfoHLC = true;

      /* [V2G2-446][V2G2-447][V2G2-448][V2G2-449] */
    } else if (ChargeAl_DW.temporalCounter_i1 >= 30000UL) {
      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_None;
      ChargeAl_DW.is_seq_Communication_Setup = 0U;
      ChargeAl_DW.exitPortIndex_p = 2UL;
    } else {
      /* [V2G2-446]
         Establish communication session setup
         SendMsg = "Client Hello()";
         [V2G2-651] The EVCC shall send a list of V2G Root Certificates it possesses, an extension of type
         "trusted_ca_keys" in the (extended) client hello as defined in IETF RFC 6066.
         SendData = ""; */
    }
    break;
  }

  switch (ChargeAl_DW.exitPortIndex_p) {
   case 2:
    ChargeAl_DW.exitPortIndex_p = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_error_handling;
    ChargeAl_DW.is_error_handling = ChargeAl_IN_Error_Timeout;
    ChargeAl_DW.temporalCounter_i1 = 0UL;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_Error_Timeout;

    /* [V2G2-728] */
    break;

   case 3:
    ChargeAl_DW.exitPortIndex_p = 0UL;
    ChargeAl_DW.is_c11_ChargeAl = IN_seq_Target_Setting_and_Charg;
    ChargeAl_DW.is_seq_Target_Setting_and_Charg =
      Charg_IN_BCP_BMSChargeParameter;
    ChargeAl_DW.temporalCounter_i1 = 0UL;
    ChargeAl_DW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_BCP_ChargeParameter_Discovery;

    /* Outport: '<Root>/CAN_Output' incorporates:
     *  Constant: '<Root>/BattVolt'
     */
    /* [V2G2-505] */
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_MaxVoltSingleBattery = 4200.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxCurrent = 1500.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvNormialEnergy = 4500.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxVolt = 4500.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvAvailableTemp = 110.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvRessSOC = ChargeAl_ConstB.BattSoc;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvCurrentVolt = 356.0F;
    ChargeAl_Y.CAN_Output_p.BRM.Flag = false;
    ChargeAl_Y.CAN_Output_p.BCP.Flag = true;
    break;
  }
}

/* Function for Chart: '<S7>/SAE J1772 DC Chargng (EV)' */
static void ChargeAl_State_B2(real32_T *Switch, real_T *DutyCycle, const
  real32_T *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF,
  const real32_T *PilotVoltSIF)
{
  boolean_T guard1;
  boolean_T guard2;
  boolean_T tmp;

  /* UnitDelay: '<S9>/Unit Delay1' incorporates:
   *  Outport: '<Root>/ContCmd'
   */
  if ((*ChrgCurrMax >= 0.095) && (*ChrgCurrMax <= 0.965) && ((*DutyCycleSIF >=
        0.095) && (*DutyCycleSIF <= 0.965)) && ChargeAl_DW.UnitDelay1_DSTATE &&
      ChargeAl_B.PwrCmdBMS) {
    ChargeAl_B.EVState_i = EVState_State_C1;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & ready to charge
       EVSE ready
       Basic Charging without digital communication */
    ChargeAl_B.EVReady = 1.0;

    /* S2 */
    ChargeAl_Y.ContCmd = 1.0;
    ChargeAl_B.ConnLock = 1.0;

    /* EnHLC = false; */
    ChargeAl_DW.EnHLC1 = 0.0;
    *DutyCycle = *ChrgCurrMax;

    /* Outputs for Function Call SubSystem: '<S14>/pwm_update' */
    ChargeAl_pwm_update(*DutyCycle, Switch);

    /* End of Outputs for SubSystem: '<S14>/pwm_update' */
    ChargeAl_B.MaxCurr = *Switch;
  } else {
    tmp = !ChargeAl_DW.UnitDelay1_DSTATE;
    guard1 = false;
    guard2 = false;
    if ((*ChrgCurrMax > 0.965) || (tmp && ChargeAl_ConstB.ChargingComplete) ||
        ((ChargeAl_B.ProxVolt > 2.38) && (ChargeAl_B.ProxVolt < 3.16))) {
      guard1 = true;
    } else if ((*PilotVolt < -11.0F) || (*PilotVoltSIF < -11.0F) ||
               (ChargeAl_B.MaxCurr < 0.1)) {
      /* || (BattCurr > 1)|| (BattCurr < -MaxCurr) ... */
      guard2 = true;
    } else if ((*ChrgCurrMax <= 0.03) || (*DutyCycleSIF <= 0.03) ||
               ((*ChrgCurrMax > 0.07) && (*ChrgCurrMax < 0.08)) ||
               ((*DutyCycleSIF > 0.07) && (*DutyCycleSIF < 0.08))) {
      /* added ME */
      ChargeAl_DW.durationCounter_1_d = 0UL;
      ChargeAl_B.EVState_i = EVState_State_E;

      /*  EVSE disconnected from Vehicle / Utility
         EVSE loss of utility power or
         control pilot short to control pilot reference
         no charging allowed */
      ChargeAl_B.EVReady = 0.0;
      ChargeAl_Y.ContCmd = 0.0;
    } else if ((ChargeAl_DW.EnHLC1 != 0.0) && tmp &&
               (!ChargeAl_ConstB.ChargingComplete) &&
               (ChargeAl_DW.temporalCounter_i1_h >= 1600.0F)) {
      /* added ME */
      guard2 = true;
    } else if ((*ChrgCurrMax >= 0.045) && (*ChrgCurrMax <= 0.055) &&
               ((*DutyCycleSIF >= 0.045) && (*DutyCycleSIF <= 0.055)) &&
               ChargeAl_DW.UnitDelay1_DSTATE && ChargeAl_B.PwrCmdBMS) {
      ChargeAl_B.EVState_i = EVState_State_C;
      ChargeAl_DW.temporalCounter_i1_h = 0UL;

      /*  Vehicle connected & ready to charge
         EVSE ready
         digital communication based charging
         EnHLC = true; */
      ChargeAl_DW.EnHLC1 = 1.0;
      ChargeAl_B.EVReady = 1.0;

      /* S2 */
      ChargeAl_Y.ContCmd = 1.0;
      ChargeAl_B.ConnLock = 1.0;
      ChargeAl_B.MaxCurr = *ChrgCurrMax * 1.1;
    } else if ((*ChrgCurrMax > 0.965) || (*DutyCycleSIF < 0.965) ||
               ((ChargeAl_B.ProxVolt <= 1.23) || (ChargeAl_B.ProxVolt >= 1.82)) ||
               ChargeAl_ConstB.ChargingComplete) {
      guard1 = true;
    } else if (*PilotVolt < 0.1) {
      ChargeAl_B.EVState_i = EVState_State_A;

      /*  Disconnected;
         Vehicle not connected. Waiting for connection. */
      ChargeAl_B.EVReady = 0.0;

      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;

      /* EnHLC = false; */
      ChargeAl_DW.EnHLC1 = 0.0;
    } else {
      /*  Vehicle connected & not ready to charge; % EVSE ready */
      ChargeAl_B.EVReady = 0.0;

      /* waiting for PWM detection S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;

      /* EnHLC = true; */
      ChargeAl_DW.EnHLC1 = 1.0;
    }

    if (guard2) {
      ChargeAl_DW.durationCounter_1 = 0UL;
      ChargeAl_B.EVState_i = EVState_State_F;
      ChargeAl_DW.temporalCounter_i1_h = 0UL;

      /*  EVSE Problem
         no charging allowed */
      ChargeAl_B.EVReady = 0.0;
      ChargeAl_Y.ContCmd = 0.0;
    }

    if (guard1) {
      ChargeAl_B.EVState_i = EVState_State_B1;
      ChargeAl_DW.temporalCounter_i1_h = 0UL;

      /*  Vehicle connected & not ready to charge
         EVSE not ready
         No HLC; Proceed for Basic Charging
         EnHLC =false; */
      ChargeAl_DW.EnHLC1 = 0.0;
      ChargeAl_B.EVReady = 0.0;

      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;
    }
  }

  /* End of UnitDelay: '<S9>/Unit Delay1' */
}

/* Function for Chart: '<S7>/SAE J1772 DC Chargng (EV)' */
static void ChargeAl_State_C(real32_T *Switch, real_T *DutyCycle, const real32_T
  *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF, const
  real32_T *PilotVoltSIF)
{
  boolean_T guard1;
  boolean_T tmp;
  if (((*PilotVolt > 8.0F) && (*PilotVolt < 10.0F) && ((*PilotVoltSIF > 8.0F) &&
        (*PilotVoltSIF < 10.0F)) && (ChargeAl_DW.temporalCounter_i1_h >= 200UL))
      || (*ChrgCurrMax > 0.965) || (*DutyCycleSIF > 0.965)) {
    ChargeAl_B.EVState_i = EVState_State_B2;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & not ready to charge; % EVSE ready */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    /* waiting for PWM detection S2 */
    ChargeAl_Y.ContCmd = 0.0;
    ChargeAl_B.ConnLock = 0.0;

    /* EnHLC = true; */
    ChargeAl_DW.EnHLC1 = 1.0;
  } else if ((*ChrgCurrMax >= 0.095) && (*ChrgCurrMax <= 0.965) &&
             (*DutyCycleSIF >= 0.095) && (*DutyCycleSIF <= 0.965)) {
    ChargeAl_B.EVState_i = EVState_State_C1;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & ready to charge
       EVSE ready
       Basic Charging without digital communication */
    ChargeAl_B.EVReady = 1.0;

    /* Outport: '<Root>/ContCmd' */
    /* S2 */
    ChargeAl_Y.ContCmd = 1.0;
    ChargeAl_B.ConnLock = 1.0;

    /* EnHLC = false; */
    ChargeAl_DW.EnHLC1 = 0.0;
    *DutyCycle = *ChrgCurrMax;

    /* Outputs for Function Call SubSystem: '<S14>/pwm_update' */
    ChargeAl_pwm_update(*DutyCycle, Switch);

    /* End of Outputs for SubSystem: '<S14>/pwm_update' */
    ChargeAl_B.MaxCurr = *Switch;
  } else {
    /* UnitDelay: '<S9>/Unit Delay1' */
    tmp = !ChargeAl_DW.UnitDelay1_DSTATE;
    if ((*ChrgCurrMax > 0.965) || (tmp && ChargeAl_ConstB.ChargingComplete) ||
        ((ChargeAl_B.ProxVolt > 2.38) && (ChargeAl_B.ProxVolt < 3.16))) {
      ChargeAl_B.EVState_i = EVState_State_B1;
      ChargeAl_DW.temporalCounter_i1_h = 0UL;

      /*  Vehicle connected & not ready to charge
         EVSE not ready
         No HLC; Proceed for Basic Charging
         EnHLC =false; */
      ChargeAl_DW.EnHLC1 = 0.0;
      ChargeAl_B.EVReady = 0.0;

      /* Outport: '<Root>/ContCmd' */
      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;
    } else {
      guard1 = false;
      if ((*PilotVolt < -11.0F) || (*PilotVoltSIF < -11.0F) ||
          (ChargeAl_B.MaxCurr < 0.1)) {
        /* || (BattCurr > 1)|| (BattCurr < -MaxCurr) ... */
        guard1 = true;
      } else if ((*ChrgCurrMax <= 0.03) || (*DutyCycleSIF <= 0.03) ||
                 ((*ChrgCurrMax > 0.07) && (*ChrgCurrMax < 0.08)) ||
                 ((*DutyCycleSIF > 0.07) && (*DutyCycleSIF < 0.08))) {
        /* added ME */
        ChargeAl_DW.durationCounter_1_d = 0UL;
        ChargeAl_B.EVState_i = EVState_State_E;

        /*  EVSE disconnected from Vehicle / Utility
           EVSE loss of utility power or
           control pilot short to control pilot reference
           no charging allowed */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        ChargeAl_Y.ContCmd = 0.0;
      } else if ((ChargeAl_DW.EnHLC1 != 0.0) && tmp &&
                 (!ChargeAl_ConstB.ChargingComplete) &&
                 (ChargeAl_DW.temporalCounter_i1_h >= 1600.0F)) {
        /* added ME */
        guard1 = true;
      } else if (*PilotVolt < 0.1) {
        ChargeAl_B.EVState_i = EVState_State_A;

        /*  Disconnected;
           Vehicle not connected. Waiting for connection. */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        /* vehicle not ready to charge S2 */
        ChargeAl_Y.ContCmd = 0.0;
        ChargeAl_B.ConnLock = 0.0;

        /* EnHLC = false; */
        ChargeAl_DW.EnHLC1 = 0.0;
      } else {
        /*  Vehicle connected & ready to charge
           EVSE ready
           digital communication based charging
           EnHLC = true; */
        ChargeAl_DW.EnHLC1 = 1.0;
        ChargeAl_B.EVReady = 1.0;

        /* Outport: '<Root>/ContCmd' */
        /* S2 */
        ChargeAl_Y.ContCmd = 1.0;
        ChargeAl_B.ConnLock = 1.0;
        ChargeAl_B.MaxCurr = *ChrgCurrMax * 1.1;
      }

      if (guard1) {
        ChargeAl_DW.durationCounter_1 = 0UL;
        ChargeAl_B.EVState_i = EVState_State_F;
        ChargeAl_DW.temporalCounter_i1_h = 0UL;

        /*  EVSE Problem
           no charging allowed */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        ChargeAl_Y.ContCmd = 0.0;
      }
    }
  }
}

/* Function for Chart: '<S7>/SAE J1772 DC Chargng (EV)' */
static void ChargeAl_State_C1(real32_T *Switch, real_T *DutyCycle, const
  real32_T *ChrgCurrMax, const real32_T *PilotVolt, const real_T *DutyCycleSIF,
  const real32_T *PilotVoltSIF)
{
  if (((*PilotVolt > 8.0F) && (*PilotVolt < 10.0F) && ((*PilotVoltSIF > 8.0F) &&
        (*PilotVoltSIF < 10.0F)) && (ChargeAl_DW.temporalCounter_i1_h >= 600UL))
      || (*ChrgCurrMax > 0.965) || (*DutyCycleSIF > 0.965)) {
    ChargeAl_B.EVState_i = EVState_State_B2;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & not ready to charge; % EVSE ready */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    /* waiting for PWM detection S2 */
    ChargeAl_Y.ContCmd = 0.0;
    ChargeAl_B.ConnLock = 0.0;

    /* EnHLC = true; */
    ChargeAl_DW.EnHLC1 = 1.0;
  } else if (ChargeAl_DW.temporalCounter_i1_h >= 20UL) {
    ChargeAl_B.EVState_i = EVState_State_C2;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;
  } else if ((*ChrgCurrMax > 0.965) || ((!ChargeAl_DW.UnitDelay1_DSTATE) &&
              ChargeAl_ConstB.ChargingComplete) || ((ChargeAl_B.ProxVolt > 2.38)
              && (ChargeAl_B.ProxVolt < 3.16))) {
    ChargeAl_B.EVState_i = EVState_State_B1;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & not ready to charge
       EVSE not ready
       No HLC; Proceed for Basic Charging
       EnHLC =false; */
    ChargeAl_DW.EnHLC1 = 0.0;
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    /* vehicle not ready to charge S2 */
    ChargeAl_Y.ContCmd = 0.0;
    ChargeAl_B.ConnLock = 0.0;
  } else if ((*PilotVolt < -11.0F) || (*PilotVoltSIF < -11.0F) ||
             (ChargeAl_B.MaxCurr < 0.1)) {
    /* || (BattCurr > 1)|| (BattCurr < -MaxCurr) ... */
    ChargeAl_DW.durationCounter_1 = 0UL;
    ChargeAl_B.EVState_i = EVState_State_F;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  EVSE Problem
       no charging allowed */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    ChargeAl_Y.ContCmd = 0.0;
  } else if ((*ChrgCurrMax <= 0.03) || (*DutyCycleSIF <= 0.03) || ((*ChrgCurrMax
    > 0.07) && (*ChrgCurrMax < 0.08)) || ((*DutyCycleSIF > 0.07) &&
              (*DutyCycleSIF < 0.08))) {
    /* added ME */
    ChargeAl_DW.durationCounter_1_d = 0UL;
    ChargeAl_B.EVState_i = EVState_State_E;

    /*  EVSE disconnected from Vehicle / Utility
       EVSE loss of utility power or
       control pilot short to control pilot reference
       no charging allowed */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    ChargeAl_Y.ContCmd = 0.0;
  } else if (*PilotVolt < 0.1) {
    ChargeAl_B.EVState_i = EVState_State_A;

    /*  Disconnected;
       Vehicle not connected. Waiting for connection. */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    /* vehicle not ready to charge S2 */
    ChargeAl_Y.ContCmd = 0.0;
    ChargeAl_B.ConnLock = 0.0;

    /* EnHLC = false; */
    ChargeAl_DW.EnHLC1 = 0.0;
  } else if ((*ChrgCurrMax >= 0.045) && (*ChrgCurrMax <= 0.055) &&
             (*DutyCycleSIF >= 0.045) && (*DutyCycleSIF <= 0.055)) {
    ChargeAl_B.EVState_i = EVState_State_C;
    ChargeAl_DW.temporalCounter_i1_h = 0UL;

    /*  Vehicle connected & ready to charge
       EVSE ready
       digital communication based charging
       EnHLC = true; */
    ChargeAl_DW.EnHLC1 = 1.0;
    ChargeAl_B.EVReady = 1.0;

    /* Outport: '<Root>/ContCmd' */
    /* S2 */
    ChargeAl_Y.ContCmd = 1.0;
    ChargeAl_B.ConnLock = 1.0;
    ChargeAl_B.MaxCurr = *ChrgCurrMax * 1.1;
  } else {
    /*  Vehicle connected & ready to charge
       EVSE ready
       Basic Charging without digital communication */
    ChargeAl_B.EVReady = 1.0;

    /* Outport: '<Root>/ContCmd' */
    /* S2 */
    ChargeAl_Y.ContCmd = 1.0;
    ChargeAl_B.ConnLock = 1.0;

    /* EnHLC = false; */
    ChargeAl_DW.EnHLC1 = 0.0;
    *DutyCycle = *ChrgCurrMax;

    /* Outputs for Function Call SubSystem: '<S14>/pwm_update' */
    ChargeAl_pwm_update(*DutyCycle, Switch);

    /* End of Outputs for SubSystem: '<S14>/pwm_update' */
    ChargeAl_B.MaxCurr = *Switch;
  }
}

/* Model step function */
void ChargeAl_step(void)
{
  BMS BusConversion_InsertedFor_ISO_c;
  real_T DutyCycleSIF;
  real_T V_latch;
  real32_T ChrgCurrMax;
  real32_T PilotVolt;
  real32_T PilotVoltSIF;
  real32_T Switch;
  int16_T V_cp;

  /* MATLAB Function: '<S8>/SensorsEV' incorporates:
   *  Constant: '<Root>/Plugged in'
   *  Logic: '<S19>/AND'
   *  UnitDelay generated from: '<S7>/Unit Delay4'
   */
  DutyCycleSIF = 0.0;
  PilotVoltSIF = 12.0F;
  switch ((int16_T)((4.0 * ChargeAl_DW.UnitDelay4_1_DSTATE + 2.0) + 1.0)) {
   case 0:
   case 1:
    V_cp = 0;
    V_latch = 4.46;
    break;

   case 2:
    V_cp = 9;
    V_latch = 2.77;
    break;

   case 3:
    V_cp = 9;
    V_latch = 1.53;
    break;

   case 6:
    V_cp = 6;
    V_latch = 2.77;
    break;

   case 7:
    V_cp = 6;
    V_latch = 1.53;
    break;

   default:
    V_cp = -12;
    V_latch = -12.0;
    break;
  }

  PilotVolt = V_cp;
  ChargeAl_B.ProxVolt = (real32_T)V_latch;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<Root>/DC charging'
   *  Gain: '<S2>/Gain3'
   *  Math: '<S2>/Pow'
   */
  ChrgCurrMax = 148.8F;

  /* BusCreator generated from: '<S9>/ISO 15118 HLC (EVCC)' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/Constant6'
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S3>/Constant8'
   *  Constant: '<S3>/Constant9'
   */
  BusConversion_InsertedFor_ISO_c.RCT = 400.0F;
  BusConversion_InsertedFor_ISO_c.ChargeCurrentReq = 150.0F;
  BusConversion_InsertedFor_ISO_c.Fake_SOC = 100.0F;
  BusConversion_InsertedFor_ISO_c.SumOfVoltages = 50.0F;
  BusConversion_InsertedFor_ISO_c.ChargeVoltReq = 360.0F;
  BusConversion_InsertedFor_ISO_c.Pack_Current = 50.0F;
  BusConversion_InsertedFor_ISO_c.MaxCellVolt = 4000.0F;
  BusConversion_InsertedFor_ISO_c.MinCellTemp = 30.0F;
  BusConversion_InsertedFor_ISO_c.MaxCellTemp = 30.0F;
  BusConversion_InsertedFor_ISO_c.Fault_out_HighTemp = 0.0F;

  /* Chart: '<S9>/ISO 15118 HLC (EVCC)' incorporates:
   *  Inport: '<Root>/CAN_Input'
   *  Logic: '<S9>/AND1'
   */
  if (ChargeAl_DW.temporalCounter_i1 < MAX_uint32_T) {
    ChargeAl_DW.temporalCounter_i1++;
  }

  if (ChargeAl_DW.temporalCounter_i2 < 16383U) {
    ChargeAl_DW.temporalCounter_i2 = (uint16_T)((int16_T)
      ChargeAl_DW.temporalCounter_i2 + 1);
  }

  if (ChargeAl_DW.temporalCounter_i3 < 63U) {
    ChargeAl_DW.temporalCounter_i3 = (uint16_T)((int16_T)
      ChargeAl_DW.temporalCounter_i3 + 1);
  }

  if (ChargeAl_DW.is_active_c11_ChargeAl == 0U) {
    ChargeAl_DW.is_active_c11_ChargeAl = 1U;
    ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_Start_Communication;

    /* Outport: '<Root>/State_Mode' */
    ChargeAl_Y.State_Mode = State_ModeType_Start_Communication;
    ChargeAl_B.InfoHLC = false;

    /* add by ME
       CurrCmdBMS = 0;%add by ME */
    ChargeAl_B.PwrCmdBMS = false;

    /* add by ME
       wait state for start command */
  } else {
    switch (ChargeAl_DW.is_c11_ChargeAl) {
     case ChargeAl_IN_Start_Communication:
      /* {SendCmd = true;} */
      ChargeAl_DW.is_c11_ChargeAl = Char_IN_seq_Communication_Setup;
      ChargeAl_DW.is_seq_Communication_Setup = ChargeAl_IN_initialize;
      ChargeAl_DW.temporalCounter_i1 = 0UL;

      /* Outport: '<Root>/State_Mode' */
      ChargeAl_Y.State_Mode = State_ModeType_initialize;
      break;

     case ChargeAl_IN_Stop_Communication:
      /*  [V2G2-025]
         End digital communication session
         SendCmd = false; */
      ChargeAl_B.InfoHLC = false;
      ChargeAl_B.PwrCmdBMS = false;
      break;

     case ChargeAl_IN_error_handling:
      if (ChargeAl_DW.is_error_handling == 1U) {
        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_None;
        ChargeAl_DW.is_error_handling = 0U;
        ChargeAl_DW.exitPortIndex = 2UL;

        /* case IN_Error_Timeout: */
        /* [V2G2-728] */
      } else if (ChargeAl_DW.temporalCounter_i1 >= 400UL) {
        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_None;
        ChargeAl_DW.is_error_handling = 0U;
        ChargeAl_DW.exitPortIndex = 2UL;
      } else if (ChargeAl_U.CAN_Input_d.CRM.Flag &&
                 (ChargeAl_U.CAN_Input_d.CRM.CR_Secc_RecognitionResult == 0.0F))
      {
        ChargeAl_DW.is_error_handling = ChargeAl_IN_ErrorBEM;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_ErrorBEM;
      } else {
        /* [V2G2-728] */
        /* PwrCmdBMS = false; */
      }

      if (ChargeAl_DW.exitPortIndex == 2UL) {
        ChargeAl_DW.exitPortIndex = 0UL;
        ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_Stop_Communication;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_Stop_Communication;

        /*  [V2G2-025]
           End digital communication session
           SendCmd = false; */
        ChargeAl_B.InfoHLC = false;
        ChargeAl_B.PwrCmdBMS = false;
      }
      break;

     case ChargeAl_IN_loop_Charge_control:
      ChargeAl_loop_Charge_control(&ChrgCurrMax,
        &BusConversion_InsertedFor_ISO_c, &ChargeAl_ConstB.ChargingComplete,
        &ChargeAl_U.CAN_Input_d);
      break;

     case Char_IN_seq_Communication_Setup:
      ChargeA_seq_Communication_Setup(&ChargeAl_U.CAN_Input_d);
      break;

     case IN_seq_End_of_charging_process:
      switch (ChargeAl_DW.is_seq_End_of_charging_process) {
       case ChargeAl_IN_Charging_complete:
        /* Outport: '<Root>/State_Mode' */
        /* [V2G2-508]
           [RecvMsg == "SessionStopRes()"] */
        ChargeAl_Y.State_Mode = State_ModeType_None;
        ChargeAl_DW.is_seq_End_of_charging_process = 0U;
        ChargeAl_DW.exitPortIndex_l = 3UL;
        break;

       case ChargeAl_IN_End_charging:
        /* [V2G2-535]
           [RecvMsg == "MeteringReceiptRes()"] */
        ChargeAl_DW.is_seq_End_of_charging_process =
          ChargeAl_IN_Charging_complete;
        ChargeAl_DW.temporalCounter_i1 = 0UL;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_Charging_complete;
        break;

       default:
        /* case IN_Welding_detection: */
        /* [V2G2-790]
           [RecvMsg == "WeldingDetectionRes()"] */
        ChargeAl_DW.is_seq_End_of_charging_process = ChargeAl_IN_End_charging;
        ChargeAl_DW.temporalCounter_i1 = 0UL;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_End_charging;
        break;
      }

      switch (ChargeAl_DW.exitPortIndex_l) {
       case 2:
        ChargeAl_DW.exitPortIndex_l = 0UL;
        ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_error_handling;
        ChargeAl_DW.is_error_handling = ChargeAl_IN_Error_Timeout;
        ChargeAl_DW.temporalCounter_i1 = 0UL;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_Error_Timeout;

        /* [V2G2-728] */
        break;

       case 3:
        ChargeAl_DW.exitPortIndex_l = 0UL;
        ChargeAl_DW.is_c11_ChargeAl = ChargeAl_IN_Stop_Communication;

        /* Outport: '<Root>/State_Mode' */
        ChargeAl_Y.State_Mode = State_ModeType_Stop_Communication;

        /*  [V2G2-025]
           End digital communication session
           SendCmd = false; */
        ChargeAl_B.InfoHLC = false;
        ChargeAl_B.PwrCmdBMS = false;
        break;
      }
      break;

     default:
      /* case IN_seq_Target_Setting_and_Charge_Scheduling: */
      seq_Target_Setting_and_Charge_S(&ChargeAl_U.CAN_Input_d);
      break;
    }
  }

  /* End of Chart: '<S9>/ISO 15118 HLC (EVCC)' */

  /* Chart: '<S7>/SAE J1772 DC Chargng (EV)' incorporates:
   *  MATLAB Function: '<S8>/SensorsEV'
   */
  if (ChargeAl_DW.temporalCounter_i1_h < MAX_uint32_T) {
    ChargeAl_DW.temporalCounter_i1_h++;
  }

  if (ChargeAl_DW.is_active_c6_ChargeAl == 0U) {
    ChargeAl_DW.is_active_c6_ChargeAl = 1U;
    ChargeAl_B.MaxCurr = 178.56000366210938;
    ChargeAl_B.EVState_i = EVState_State_A;

    /*  Disconnected;
       Vehicle not connected. Waiting for connection. */
    ChargeAl_B.EVReady = 0.0;

    /* Outport: '<Root>/ContCmd' */
    /* vehicle not ready to charge S2 */
    ChargeAl_Y.ContCmd = 0.0;
    ChargeAl_B.ConnLock = 0.0;

    /* EnHLC = false; */
    ChargeAl_DW.EnHLC1 = 0.0;
  } else {
    switch (ChargeAl_B.EVState_i) {
     case EVState_DefineTheTimeOutValue:
      break;

     case EVState_State_A:
      /*  Disconnected;
         Vehicle not connected. Waiting for connection. */
      ChargeAl_B.EVReady = 0.0;

      /* Outport: '<Root>/ContCmd' */
      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;

      /* EnHLC = false; */
      ChargeAl_DW.EnHLC1 = 0.0;
      break;

     case EVState_State_B1:
      ChargeAl_B.EVState_i = EVState_State_A;

      /*  Disconnected;
         Vehicle not connected. Waiting for connection. */
      ChargeAl_B.EVReady = 0.0;

      /* Outport: '<Root>/ContCmd' */
      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;

      /* EnHLC = false; */
      ChargeAl_DW.EnHLC1 = 0.0;
      break;

     case EVState_State_B2:
      ChargeAl_State_B2(&Switch, &V_latch, &ChrgCurrMax, &PilotVolt,
                        &DutyCycleSIF, &PilotVoltSIF);
      break;

     case EVState_State_C:
      ChargeAl_State_C(&Switch, &V_latch, &ChrgCurrMax, &PilotVolt,
                       &DutyCycleSIF, &PilotVoltSIF);
      break;

     case EVState_State_C1:
      ChargeAl_State_C1(&Switch, &V_latch, &ChrgCurrMax, &PilotVolt,
                        &DutyCycleSIF, &PilotVoltSIF);
      break;

     case EVState_State_C2:
      if (ChargeAl_DW.temporalCounter_i1_h >= 600UL) {
        ChargeAl_DW.durationCounter_1 = 0UL;
        ChargeAl_B.EVState_i = EVState_State_F;
        ChargeAl_DW.temporalCounter_i1_h = 0UL;

        /*  EVSE Problem
           no charging allowed */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        ChargeAl_Y.ContCmd = 0.0;
      } else {
        ChargeAl_B.EVState_i = EVState_State_B1;
        ChargeAl_DW.temporalCounter_i1_h = 0UL;

        /*  Vehicle connected & not ready to charge
           EVSE not ready
           No HLC; Proceed for Basic Charging
           EnHLC =false; */
        ChargeAl_DW.EnHLC1 = 0.0;
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        /* vehicle not ready to charge S2 */
        ChargeAl_Y.ContCmd = 0.0;
        ChargeAl_B.ConnLock = 0.0;
      }
      break;

     case EVState_State_C3:
      ChargeAl_B.EVState_i = EVState_State_B1;
      ChargeAl_DW.temporalCounter_i1_h = 0UL;

      /*  Vehicle connected & not ready to charge
         EVSE not ready
         No HLC; Proceed for Basic Charging
         EnHLC =false; */
      ChargeAl_DW.EnHLC1 = 0.0;
      ChargeAl_B.EVReady = 0.0;

      /* Outport: '<Root>/ContCmd' */
      /* vehicle not ready to charge S2 */
      ChargeAl_Y.ContCmd = 0.0;
      ChargeAl_B.ConnLock = 0.0;
      break;

     case EVState_State_E:
      if (ChargeAl_DW.durationCounter_1_d > 40UL) {
        ChargeAl_B.EVState_i = EVState_UnlockState_E;
        ChargeAl_B.ConnLock = 0.0;
      } else {
        /*  EVSE disconnected from Vehicle / Utility
           EVSE loss of utility power or
           control pilot short to control pilot reference
           no charging allowed */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        ChargeAl_Y.ContCmd = 0.0;
      }
      break;

     case EVState_State_F:
      if (ChargeAl_DW.durationCounter_1 > 40UL) {
        ChargeAl_B.EVState_i = EVState_UnlockState_F;
        ChargeAl_DW.temporalCounter_i1_h = 0UL;
        ChargeAl_B.ConnLock = 0.0;
      } else if (ChargeAl_DW.temporalCounter_i1_h >= 2000UL) {
        ChargeAl_B.EVState_i = EVState_DefineTheTimeOutValue;

        /* Display Problem
           sensing current < 5A Fault
           Sensing voltage < 60VFualt */
      } else {
        /*  EVSE Problem
           no charging allowed */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        ChargeAl_Y.ContCmd = 0.0;
      }
      break;

     case EVState_UnlockState_E:
      if (V_cp < 0.1) {
        ChargeAl_B.EVState_i = EVState_State_A;

        /*  Disconnected;
           Vehicle not connected. Waiting for connection. */
        ChargeAl_B.EVReady = 0.0;

        /* Outport: '<Root>/ContCmd' */
        /* vehicle not ready to charge S2 */
        ChargeAl_Y.ContCmd = 0.0;
        ChargeAl_B.ConnLock = 0.0;

        /* EnHLC = false; */
        ChargeAl_DW.EnHLC1 = 0.0;
      }
      break;

     default:
      /* State UnlockState_F */
      break;
    }
  }

  ChargeAl_DW.durationCounter_1++;
  ChargeAl_DW.durationCounter_1_d++;

  /* End of Chart: '<S7>/SAE J1772 DC Chargng (EV)' */

  /* Outport: '<Root>/ConnLock1' incorporates:
   *  UnitDelay generated from: '<S7>/Unit Delay4'
   */
  ChargeAl_Y.ConnLock1 = ChargeAl_DW.UnitDelay4_2_DSTATE;

  /* Switch: '<S1>/Switch' incorporates:
   *  Outport: '<Root>/ContCmd'
   */
  if (ChargeAl_Y.ContCmd > 0.0) {
    /* Outport: '<Root>/ChargerBattCurrent' incorporates:
     *  Gain: '<Root>/Gain'
     */
    ChargeAl_Y.ChargerBattCurrent = -178.560013F;
  } else {
    /* Outport: '<Root>/ChargerBattCurrent' incorporates:
     *  Constant: '<S1>/NoCharging'
     */
    ChargeAl_Y.ChargerBattCurrent = 0.0F;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Chart: '<S4>/Chart' */
  if (ChargeAl_DW.temporalCounter_i1_l < 255U) {
    ChargeAl_DW.temporalCounter_i1_l = (uint16_T)((int16_T)
      ChargeAl_DW.temporalCounter_i1_l + 1);
  }

  if (ChargeAl_DW.is_active_c3_ChargeAl == 0U) {
    ChargeAl_DW.is_active_c3_ChargeAl = 1U;
    ChargeAl_DW.temporalCounter_i1_l = 0U;

    /* Outport: '<Root>/Second' */
    ChargeAl_Y.Second = 1.0;
  } else if (ChargeAl_DW.temporalCounter_i1_l >= 200U) {
    ChargeAl_DW.temporalCounter_i1_l = 0U;

    /* Outport: '<Root>/Second' */
    ChargeAl_Y.Second++;
  }

  /* End of Chart: '<S4>/Chart' */

  /* Update for UnitDelay generated from: '<S7>/Unit Delay4' */
  ChargeAl_DW.UnitDelay4_2_DSTATE = ChargeAl_B.ConnLock;

  /* Update for UnitDelay generated from: '<S7>/Unit Delay4' */
  ChargeAl_DW.UnitDelay4_1_DSTATE = ChargeAl_B.EVReady;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  ChargeAl_DW.UnitDelay1_DSTATE = ChargeAl_B.InfoHLC;
}

/* Model initialize function */
void ChargeAl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;
    ChargeAl_DW.V2G_EVCC_Msg_Timeout_PreChargeR = 2.0F;

    /* SystemInitialize for Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvPermissibleMaxVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvmaxCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.CF_Plc_Bhm8Bytes = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_EvRessSOC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_FullSOC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.CR_Plc_BulkSOC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BHM.Flag = false;
    ChargeAl_Y.CAN_Output_p.BRM.Flag = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMinor = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorL = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_VersionMajorH = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_BatteryType = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvEnergyCapacity = false;
    ChargeAl_Y.CAN_Output_p.BRM.CR_Plc_EvmaxVolt = false;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_MaxVoltSingleBattery = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvNormialEnergy = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvmaxVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvAvailableTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvRessSOC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.CR_Plc_EvCurrentVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCP.Flag = false;
    ChargeAl_Y.CAN_Output_p.BRO.Flag = false;
    ChargeAl_Y.CAN_Output_p.BRO.CF_Plc_PowerDeliveryStart = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_SensingCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_HighestVoltSingle = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_EvRessSOC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.CR_Plc_FullSOCRemainedTime = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCS.Flag = false;
    ChargeAl_Y.CAN_Output_p.BSM.Flag = false;
    ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumSinglePower = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_HighestTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumHighTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_LowestTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CR_Plc_SernumLowTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowVolSinglePowe = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverlowSocBat = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_OverCurr = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ExcexxTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_InsulState = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_ConnectionState = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSM.CF_Plc_EvReady = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.Flag = false;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSoC = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachTotalVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ReachSingleVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ChargerSuspend = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_InstationFault = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ConnectorHighTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_BmsOverTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ConnectorFault = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_BatOverTemp = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_HighVoltRelay = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_ErrCheckPoint2 = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_OtherFault = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_CurrOver = 0.0F;
    ChargeAl_Y.CAN_Output_p.BST.CF_Plc_AbnormalVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSD.Flag = false;
    ChargeAl_Y.CAN_Output_p.BSD.CR_Plc_SuspendSoc = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSD.CR_MinVoltSinglePower = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSD.CR_MaxVoltSinglePower = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSD.CR_MinTempPower = 0.0F;
    ChargeAl_Y.CAN_Output_p.BSD.CR_MaxTempPower = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetVolt = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_EvTargetCurrent = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCL.CR_Plc_ChargingMode = 0.0F;
    ChargeAl_Y.CAN_Output_p.BCL.Flag = false;
    ChargeAl_Y.CAN_Output_p.BEM.Flag = false;
    for (i = 0; i < 8; i++) {
      /* SystemInitialize for Outport: '<Root>/CAN_Output' */
      ChargeAl_Y.CAN_Output_p.BHM.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BRM.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BCP.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BRO.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BCS.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BSM.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BST.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BSD.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BCL.Data[i] = 0U;
      ChargeAl_Y.CAN_Output_p.BEM.Data[i] = 0U;
    }

    /* SystemInitialize for Outport: '<Root>/CAN_Output' */
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CRM00Timeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CRMAATimeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CTS_CMLTimeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CROAALTimeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CCSTimeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CSTTimeout = 0U;
    ChargeAl_Y.CAN_Output_p.BEM.CF_Plc_CSDTimeout = 0U;

    /* SystemInitialize for Chart: '<S9>/ISO 15118 HLC (EVCC)' incorporates:
     *  SubSystem: '<S6>/Subsystem'
     */
    /* SystemInitialize for Outport: '<Root>/BHM' */
    /* SystemInitialize for Outport: '<Root>/BRM' */
  }
}

/* Model terminate function */
void ChargeAl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
