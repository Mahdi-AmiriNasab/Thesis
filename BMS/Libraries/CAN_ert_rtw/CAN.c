/*
 * File: CAN.c
 *
 * Code generated for Simulink model 'CAN'.
 *
 * Model version                  : 2.17
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb  7 16:22:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CAN.h"
#include "CAN_private.h"

/* Block states (default storage) */
DW_CAN_T CAN_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CAN_T CAN_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CAN_T CAN_Y;

/* Real-time model */
static RT_MODEL_CAN_T CAN_M_;
RT_MODEL_CAN_T *const CAN_M = &CAN_M_;

/* Model step function */
void CAN_step(void)
{
  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Inport: '<Root>/DC_Link_Volt'
   *  Inport: '<Root>/Max_Cell_Temp'
   *  Inport: '<Root>/Max_Cell_Volt'
   *  Inport: '<Root>/Min_Cell_Temp1'
   *  Inport: '<Root>/Min_Cell_Volt1'
   *  Outport: '<Root>/Measurement1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  CAN_Y.Measurement1.ID = 402653184U;
  CAN_Y.Measurement1.Length = 8U;
  CAN_Y.Measurement1.Extended = 1U;
  CAN_Y.Measurement1.Remote = 0;
  CAN_Y.Measurement1.Data[0] = 0;
  CAN_Y.Measurement1.Data[1] = 0;
  CAN_Y.Measurement1.Data[2] = 0;
  CAN_Y.Measurement1.Data[3] = 0;
  CAN_Y.Measurement1.Data[4] = 0;
  CAN_Y.Measurement1.Data[5] = 0;
  CAN_Y.Measurement1.Data[6] = 0;
  CAN_Y.Measurement1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Max_Cell_Temp;

        /* no factor to apply */
        result = result - -40.0;

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement1.Data[0] = CAN_Y.Measurement1.Data[0] | (uint8_T)
              (packedValue);
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
     *  offset                  = -40.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Min_Cell_Temp1;

        /* no factor to apply */
        result = result - -40.0;

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement1.Data[1] = CAN_Y.Measurement1.Data[1] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0001
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Max_Cell_Volt;

        /* no offset to apply */
        result = result * (1 / 0.0001);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement1.Data[2] = CAN_Y.Measurement1.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement1.Data[3] = CAN_Y.Measurement1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0001
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Min_Cell_Volt1;

        /* no offset to apply */
        result = result * (1 / 0.0001);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement1.Data[4] = CAN_Y.Measurement1.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement1.Data[5] = CAN_Y.Measurement1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.DC_Link_Volt;

        /* no offset to apply */
        result = result * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement1.Data[6] = CAN_Y.Measurement1.Data[6] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement1.Data[7] = CAN_Y.Measurement1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack1' incorporates:
   *  Inport: '<Root>/Input_Voltage'
   *  Inport: '<Root>/PackVoltageSensor'
   *  Inport: '<Root>/PackVoltageSum'
   *  Inport: '<Root>/Pack_Current'
   *  Outport: '<Root>/Measurement2'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  CAN_Y.Measurement2.ID = 402653185U;
  CAN_Y.Measurement2.Length = 8U;
  CAN_Y.Measurement2.Extended = 1U;
  CAN_Y.Measurement2.Remote = 0;
  CAN_Y.Measurement2.Data[0] = 0;
  CAN_Y.Measurement2.Data[1] = 0;
  CAN_Y.Measurement2.Data[2] = 0;
  CAN_Y.Measurement2.Data[3] = 0;
  CAN_Y.Measurement2.Data[4] = 0;
  CAN_Y.Measurement2.Data[5] = 0;
  CAN_Y.Measurement2.Data[6] = 0;
  CAN_Y.Measurement2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -500.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Pack_Current;

        /* full scaling operation */
        result = (result - -500.0) * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement2.Data[0] = CAN_Y.Measurement2.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement2.Data[1] = CAN_Y.Measurement2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Input_Voltage;

        /* no offset to apply */
        result = result * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement2.Data[2] = CAN_Y.Measurement2.Data[2] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.PackVoltageSensor;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement2.Data[3] = CAN_Y.Measurement2.Data[3] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement2.Data[4] = CAN_Y.Measurement2.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 40
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.PackVoltageSum;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Measurement2.Data[5] = CAN_Y.Measurement2.Data[5] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Measurement2.Data[6] = CAN_Y.Measurement2.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack2' incorporates:
   *  Inport: '<Root>/Charge_Current_Limit'
   *  Inport: '<Root>/Charge_Voltage_Limit'
   *  Inport: '<Root>/Discharge_Current_Limit'
   *  Inport: '<Root>/SOC'
   *  Inport: '<Root>/SOH'
   *  Outport: '<Root>/Estimation1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack2' */
  CAN_Y.Estimation1.ID = 402653186U;
  CAN_Y.Estimation1.Length = 8U;
  CAN_Y.Estimation1.Extended = 1U;
  CAN_Y.Estimation1.Remote = 0;
  CAN_Y.Estimation1.Data[0] = 0;
  CAN_Y.Estimation1.Data[1] = 0;
  CAN_Y.Estimation1.Data[2] = 0;
  CAN_Y.Estimation1.Data[3] = 0;
  CAN_Y.Estimation1.Data[4] = 0;
  CAN_Y.Estimation1.Data[5] = 0;
  CAN_Y.Estimation1.Data[6] = 0;
  CAN_Y.Estimation1.Data[7] = 0;

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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.SOC;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation1.Data[0] = CAN_Y.Estimation1.Data[0] | (uint8_T)
              (packedValue);
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.SOH;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation1.Data[1] = CAN_Y.Estimation1.Data[1] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Discharge_Current_Limit;

        /* no offset to apply */
        result = result * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation1.Data[2] = CAN_Y.Estimation1.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation1.Data[3] = CAN_Y.Estimation1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Charge_Current_Limit;

        /* no offset to apply */
        result = result * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation1.Data[4] = CAN_Y.Estimation1.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation1.Data[5] = CAN_Y.Estimation1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Charge_Voltage_Limit;

        /* no offset to apply */
        result = result * (1 / 0.1);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation1.Data[6] = CAN_Y.Estimation1.Data[6] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation1.Data[7] = CAN_Y.Estimation1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack3' incorporates:
   *  Inport: '<Root>/BMBQualityCounter'
   *  Inport: '<Root>/Charge_Remaining_Time'
   *  Inport: '<Root>/Disharge_Remaining_Time'
   *  Inport: '<Root>/Mileage'
   *  Inport: '<Root>/balanceCounter'
   *  Outport: '<Root>/Estimation2'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack3' */
  CAN_Y.Estimation2.ID = 402653187U;
  CAN_Y.Estimation2.Length = 8U;
  CAN_Y.Estimation2.Extended = 1U;
  CAN_Y.Estimation2.Remote = 0;
  CAN_Y.Estimation2.Data[0] = 0;
  CAN_Y.Estimation2.Data[1] = 0;
  CAN_Y.Estimation2.Data[2] = 0;
  CAN_Y.Estimation2.Data[3] = 0;
  CAN_Y.Estimation2.Data[4] = 0;
  CAN_Y.Estimation2.Data[5] = 0;
  CAN_Y.Estimation2.Data[6] = 0;
  CAN_Y.Estimation2.Data[7] = 0;

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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Mileage;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation2.Data[0] = CAN_Y.Estimation2.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation2.Data[1] = CAN_Y.Estimation2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Charge_Remaining_Time;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation2.Data[2] = CAN_Y.Estimation2.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation2.Data[3] = CAN_Y.Estimation2.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.Disharge_Remaining_Time;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation2.Data[4] = CAN_Y.Estimation2.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Estimation2.Data[5] = CAN_Y.Estimation2.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.BMBQualityCounter;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation2.Data[6] = CAN_Y.Estimation2.Data[6] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.balanceCounter;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real64_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Estimation2.Data[7] = CAN_Y.Estimation2.Data[7] | (uint8_T)
              (packedValue);
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack4' incorporates:
   *  Inport: '<Root>/BMBFault'
   *  Inport: '<Root>/Bal_En'
   *  Inport: '<Root>/Charger'
   *  Inport: '<Root>/Communication_Fault'
   *  Inport: '<Root>/CurrentSensor'
   *  Inport: '<Root>/HighTemp'
   *  Inport: '<Root>/InputPowerFault'
   *  Inport: '<Root>/Inverter'
   *  Inport: '<Root>/LowTemp'
   *  Inport: '<Root>/MemoryFault'
   *  Inport: '<Root>/OverChargeCurrent'
   *  Inport: '<Root>/OverCurrent'
   *  Inport: '<Root>/OverDischargeCurrent'
   *  Inport: '<Root>/OverVolt'
   *  Inport: '<Root>/PreChargeFault'
   *  Inport: '<Root>/ShortCircuitFault'
   *  Inport: '<Root>/TempSensor'
   *  Inport: '<Root>/UnderVoltage'
   *  Inport: '<Root>/VoltSensor'
   *  Outport: '<Root>/Fault'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack4' */
  CAN_Y.Fault.ID = 402653188U;
  CAN_Y.Fault.Length = 8U;
  CAN_Y.Fault.Extended = 1U;
  CAN_Y.Fault.Remote = 0;
  CAN_Y.Fault.Data[0] = 0;
  CAN_Y.Fault.Data[1] = 0;
  CAN_Y.Fault.Data[2] = 0;
  CAN_Y.Fault.Data[3] = 0;
  CAN_Y.Fault.Data[4] = 0;
  CAN_Y.Fault.Data[5] = 0;
  CAN_Y.Fault.Data[6] = 0;
  CAN_Y.Fault.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.BMBFault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 1
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Bal_En);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 2
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Charger);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 3
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.CurrentSensor);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 4
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.HighTemp);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 5
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.InputPowerFault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 6
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Inverter);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 7
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.LowTemp);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[0] = CAN_Y.Fault.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 8
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.MemoryFault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 9
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.OverChargeCurrent);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 10
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.OverCurrent);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 11
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.OverDischargeCurrent);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 12
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.OverVolt);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 13
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.PreChargeFault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 14
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.ShortCircuitFault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 15
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.TempSensor);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[1] = CAN_Y.Fault.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 16
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.UnderVoltage);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[2] = CAN_Y.Fault.Data[2] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 17
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.VoltSensor);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[2] = CAN_Y.Fault.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 18
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Communication_Fault);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Fault.Data[2] = CAN_Y.Fault.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack5' incorporates:
   *  Inport: '<Root>/maxTempIndex'
   *  Inport: '<Root>/maxVoltageIndex'
   *  Inport: '<Root>/minTempIndex'
   *  Inport: '<Root>/minVoltageIndex'
   *  Inport: '<Root>/test1'
   *  Inport: '<Root>/test2'
   *  Inport: '<Root>/test3'
   *  Inport: '<Root>/test4'
   *  Outport: '<Root>/Diagnosis'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack5' */
  CAN_Y.Diagnosis.ID = 402653190U;
  CAN_Y.Diagnosis.Length = 8U;
  CAN_Y.Diagnosis.Extended = 1U;
  CAN_Y.Diagnosis.Remote = 0;
  CAN_Y.Diagnosis.Data[0] = 0;
  CAN_Y.Diagnosis.Data[1] = 0;
  CAN_Y.Diagnosis.Data[2] = 0;
  CAN_Y.Diagnosis.Data[3] = 0;
  CAN_Y.Diagnosis.Data[4] = 0;
  CAN_Y.Diagnosis.Data[5] = 0;
  CAN_Y.Diagnosis.Data[6] = 0;
  CAN_Y.Diagnosis.Data[7] = 0;

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
        uint32_T result = (uint32_T) (CAN_U.maxVoltageIndex);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(255)) {
          packedValue = (uint8_T) 255;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Diagnosis.Data[0] = CAN_Y.Diagnosis.Data[0] | (uint8_T)
              (packedValue);
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
        uint32_T result = (uint32_T) (CAN_U.minVoltageIndex);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(255)) {
          packedValue = (uint8_T) 255;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Diagnosis.Data[1] = CAN_Y.Diagnosis.Data[1] | (uint8_T)
              (packedValue);
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
        uint32_T result = (uint32_T) (CAN_U.maxTempIndex);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[2] = CAN_Y.Diagnosis.Data[2] | (uint8_T)
              (packedValue);
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
        uint32_T result = (uint32_T) (CAN_U.minTempIndex);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[3] = CAN_Y.Diagnosis.Data[3] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
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
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (CAN_U.test1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[4] = CAN_Y.Diagnosis.Data[4] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
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
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (CAN_U.test2);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[5] = CAN_Y.Diagnosis.Data[5] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
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
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (CAN_U.test3);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[6] = CAN_Y.Diagnosis.Data[6] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
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
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (CAN_U.test4);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            CAN_Y.Diagnosis.Data[7] = CAN_Y.Diagnosis.Data[7] | (uint8_T)
              (packedValue);
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack6' incorporates:
   *  Inport: '<Root>/BMS_DI'
   *  Inport: '<Root>/Bal_Complete'
   *  Inport: '<Root>/Charge_Complete'
   *  Inport: '<Root>/Contactor_State'
   *  Inport: '<Root>/State'
   *  Inport: '<Root>/kwh'
   *  Inport: '<Root>/kwh_noFilter'
   *  Inport: '<Root>/signal'
   *  Outport: '<Root>/Status'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack6' */
  CAN_Y.Status.ID = 402653189U;
  CAN_Y.Status.Length = 8U;
  CAN_Y.Status.Extended = 1U;
  CAN_Y.Status.Remote = 0;
  CAN_Y.Status.Data[0] = 0;
  CAN_Y.Status.Data[1] = 0;
  CAN_Y.Status.Data[2] = 0;
  CAN_Y.Status.Data[3] = 0;
  CAN_Y.Status.Data[4] = 0;
  CAN_Y.Status.Data[5] = 0;
  CAN_Y.Status.Data[6] = 0;
  CAN_Y.Status.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 3
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
        uint32_T result = (uint32_T) (CAN_U.State);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(7)) {
          packedValue = (uint8_T) 7;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Status.Data[0] = CAN_Y.Status.Data[0] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x7U));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 3
     *  length                  = 2
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
        uint32_T result = (uint32_T) (CAN_U.Contactor_State);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Status.Data[0] = CAN_Y.Status.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 5
     *  length                  = 4
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
        uint32_T result = (uint32_T) (CAN_U.BMS_DI);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(15)) {
          packedValue = (uint8_T) 15;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Status.Data[0] = CAN_Y.Status.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x7U) << 5));
            CAN_Y.Status.Data[1] = CAN_Y.Status.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x8U) >> 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 9
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Charge_Complete);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Status.Data[1] = CAN_Y.Status.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 10
     *  length                  = 1
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
        uint32_T result = (uint32_T) (CAN_U.Bal_Complete);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint16_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            CAN_Y.Status.Data[1] = CAN_Y.Status.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 11
     *  length                  = 5
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = CAN_U.signal;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(31)) {
          packedValue = (uint8_T) 31;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            CAN_Y.Status.Data[1] = CAN_Y.Status.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1FU) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -60.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = CAN_U.kwh;

        /* full scaling operation */
        result = (result - -60.0F) * (1 / 0.1F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.Status.Data[2] = CAN_Y.Status.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.Status.Data[3] = CAN_Y.Status.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.1
     *  offset                  = -60.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = CAN_U.kwh_noFilter;

        /* full scaling operation */
        result = (result - -60.0F) * (1 / 0.1F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (outValue > 2147483647.0) {
          scaledValue = 2147483647;
        } else if (outValue < -2147483648.0) {
          scaledValue = -2147483647 - 1;
        } else {
          scaledValue = (int32_T) outValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            CAN_Y.Status.Data[4] = CAN_Y.Status.Data[4] | (uint8_T)((uint16_T)
              (tempValue & (uint16_T)0xFFU));
            CAN_Y.Status.Data[5] = CAN_Y.Status.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack' incorporates:
   *  Inport: '<Root>/In1'
   *  Outport: '<Root>/BMS_State'
   *  Outport: '<Root>/Charge_Mode'
   *  Outport: '<Root>/Fault_Reset'
   *  Outport: '<Root>/SOC_Max'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == CAN_U.In1.Length) && (CAN_U.In1.ID != INVALID_CAN_ID) ) {
      if ((257 == CAN_U.In1.ID) && (0U == CAN_U.In1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)(CAN_U.In1.Data[0])
                    & (uint8_T)(0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.BMS_State = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 2
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CAN_U.In1.Data[0]) & (uint8_T)(0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.Fault_Reset = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 3
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CAN_U.In1.Data[0]) & (uint8_T)(0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.Charge_Mode = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 4
           *  length                  = 3
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 10.0
           *  offset                  = 50.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CAN_U.In1.Data[0]) & (uint8_T)(0x70U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              result = (result * 10U) + 50U;
              CAN_Y.SOC_Max = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack7' incorporates:
   *  Inport: '<Root>/t1'
   *  Inport: '<Root>/t2'
   *  Inport: '<Root>/t3'
   *  Inport: '<Root>/t4'
   *  Outport: '<Root>/THC1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack7' */
  CAN_Y.THC1.ID = 1281U;
  CAN_Y.THC1.Length = 8U;
  CAN_Y.THC1.Extended = 1U;
  CAN_Y.THC1.Remote = 0;
  CAN_Y.THC1.Data[0] = 0;
  CAN_Y.THC1.Data[1] = 0;
  CAN_Y.THC1.Data[2] = 0;
  CAN_Y.THC1.Data[3] = 0;
  CAN_Y.THC1.Data[4] = 0;
  CAN_Y.THC1.Data[5] = 0;
  CAN_Y.THC1.Data[6] = 0;
  CAN_Y.THC1.Data[7] = 0;

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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t1;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC1.Data[0] = CAN_Y.THC1.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC1.Data[1] = CAN_Y.THC1.Data[1] | (uint8_T)((uint16_T)
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t2;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC1.Data[2] = CAN_Y.THC1.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC1.Data[3] = CAN_Y.THC1.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t3;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC1.Data[4] = CAN_Y.THC1.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC1.Data[5] = CAN_Y.THC1.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t4;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC1.Data[6] = CAN_Y.THC1.Data[6] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC1.Data[7] = CAN_Y.THC1.Data[7] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack8' incorporates:
   *  Inport: '<Root>/t5'
   *  Inport: '<Root>/t6'
   *  Inport: '<Root>/t7'
   *  Inport: '<Root>/t8'
   *  Outport: '<Root>/THC2'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack8' */
  CAN_Y.THC2.ID = 1282U;
  CAN_Y.THC2.Length = 8U;
  CAN_Y.THC2.Extended = 1U;
  CAN_Y.THC2.Remote = 0;
  CAN_Y.THC2.Data[0] = 0;
  CAN_Y.THC2.Data[1] = 0;
  CAN_Y.THC2.Data[2] = 0;
  CAN_Y.THC2.Data[3] = 0;
  CAN_Y.THC2.Data[4] = 0;
  CAN_Y.THC2.Data[5] = 0;
  CAN_Y.THC2.Data[6] = 0;
  CAN_Y.THC2.Data[7] = 0;

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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t5;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC2.Data[0] = CAN_Y.THC2.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC2.Data[1] = CAN_Y.THC2.Data[1] | (uint8_T)((uint16_T)
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t6;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC2.Data[2] = CAN_Y.THC2.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC2.Data[3] = CAN_Y.THC2.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t7;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC2.Data[4] = CAN_Y.THC2.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC2.Data[5] = CAN_Y.THC2.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t8;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC2.Data[6] = CAN_Y.THC2.Data[6] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC2.Data[7] = CAN_Y.THC2.Data[7] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack9' incorporates:
   *  Inport: '<Root>/t10'
   *  Inport: '<Root>/t11'
   *  Inport: '<Root>/t12'
   *  Inport: '<Root>/t9'
   *  Outport: '<Root>/THC3'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack9' */
  CAN_Y.THC3.ID = 1283U;
  CAN_Y.THC3.Length = 8U;
  CAN_Y.THC3.Extended = 1U;
  CAN_Y.THC3.Remote = 0;
  CAN_Y.THC3.Data[0] = 0;
  CAN_Y.THC3.Data[1] = 0;
  CAN_Y.THC3.Data[2] = 0;
  CAN_Y.THC3.Data[3] = 0;
  CAN_Y.THC3.Data[4] = 0;
  CAN_Y.THC3.Data[5] = 0;
  CAN_Y.THC3.Data[6] = 0;
  CAN_Y.THC3.Data[7] = 0;

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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t9;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC3.Data[0] = CAN_Y.THC3.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC3.Data[1] = CAN_Y.THC3.Data[1] | (uint8_T)((uint16_T)
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t10;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC3.Data[2] = CAN_Y.THC3.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC3.Data[3] = CAN_Y.THC3.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t11;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC3.Data[4] = CAN_Y.THC3.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC3.Data[5] = CAN_Y.THC3.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
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
      real64_T outValue = 0;

      {
        real64_T result = CAN_U.t12;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            CAN_Y.THC3.Data[6] = CAN_Y.THC3.Data[6] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            CAN_Y.THC3.Data[7] = CAN_Y.THC3.Data[7] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }
}

/* Model initialize function */
void CAN_initialize(void)
{
  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack' incorporates:
   *  Inport: '<Root>/In1'
   *  Outport: '<Root>/BMS_State'
   *  Outport: '<Root>/Charge_Mode'
   *  Outport: '<Root>/Fault_Reset'
   *  Outport: '<Root>/SOC_Max'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/
}

/* Model terminate function */
void CAN_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
