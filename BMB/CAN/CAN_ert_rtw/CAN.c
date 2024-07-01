/*
 * File: CAN.c
 *
 * Code generated for Simulink model 'CAN'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 10 13:24:14 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CAN.h"
#include "CAN_private.h"

/* Block signals (default storage) */
B_CAN_T CAN_B;

/* Block states (default storage) */
DW_CAN_T CAN_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CAN_T CAN_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CAN_T CAN_Y;

/* Real-time model */
RT_MODEL_CAN_T CAN_M_;
RT_MODEL_CAN_T *const CAN_M = &CAN_M_;

/* Model step function */
void CAN_step(void)
{
  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/v1'
   */
  CAN_B.Divide = CAN_U.v1 / 10U;

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Inport: '<Root>/v2'
   */
  CAN_B.Divide1 = CAN_U.v2 / 10U;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/v3'
   */
  CAN_B.Divide2 = CAN_U.v3 / 10U;

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Inport: '<Root>/v4'
   */
  CAN_B.Divide3 = CAN_U.v4 / 10U;

  /* Product: '<Root>/Divide12' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Inport: '<Root>/t1'
   */
  CAN_B.Divide12 = CAN_U.t1 / 20U;

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Outport: '<Root>/Voltage1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  CAN_Y.Voltage1.ID = 0U;
  CAN_Y.Voltage1.Length = 8U;
  CAN_Y.Voltage1.Extended = 0U;
  CAN_Y.Voltage1.Remote = 0;
  CAN_Y.Voltage1.Data[0] = 0;
  CAN_Y.Voltage1.Data[1] = 0;
  CAN_Y.Voltage1.Data[2] = 0;
  CAN_Y.Voltage1.Data[3] = 0;
  CAN_Y.Voltage1.Data[4] = 0;
  CAN_Y.Voltage1.Data[5] = 0;
  CAN_Y.Voltage1.Data[6] = 0;
  CAN_Y.Voltage1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage1.Data[0] = CAN_Y.Voltage1.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Voltage1.Data[1] = CAN_Y.Voltage1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1F00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 13
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage1.Data[1] = CAN_Y.Voltage1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7U) << 5));
            CAN_Y.Voltage1.Data[2] = CAN_Y.Voltage1.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7F8U) >> 3));
            CAN_Y.Voltage1.Data[3] = CAN_Y.Voltage1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1800U) >> 11));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 26
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide2);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage1.Data[3] = CAN_Y.Voltage1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x3FU) << 2));
            CAN_Y.Voltage1.Data[4] = CAN_Y.Voltage1.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FC0U) >> 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 39
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide3);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage1.Data[4] = CAN_Y.Voltage1.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1U) << 7));
            CAN_Y.Voltage1.Data[5] = CAN_Y.Voltage1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FEU) >> 1));
            CAN_Y.Voltage1.Data[6] = CAN_Y.Voltage1.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1E00U) >> 9));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 52
     *  length                  = 12
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
        uint32_T result = (uint32_T) (CAN_B.Divide12);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage1.Data[6] = CAN_Y.Voltage1.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CAN_Y.Voltage1.Data[7] = CAN_Y.Voltage1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }
  }

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Inport: '<Root>/v5'
   */
  CAN_B.Divide4 = CAN_U.v5 / 10U;

  /* Product: '<Root>/Divide5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/v6'
   */
  CAN_B.Divide5 = CAN_U.v6 / 10U;

  /* Product: '<Root>/Divide6' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Inport: '<Root>/v7'
   */
  CAN_B.Divide6 = CAN_U.v7 / 10U;

  /* Product: '<Root>/Divide7' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Inport: '<Root>/v8'
   */
  CAN_B.Divide7 = CAN_U.v8 / 10U;

  /* Product: '<Root>/Divide13' incorporates:
   *  Constant: '<Root>/Constant13'
   *  Inport: '<Root>/t2'
   */
  CAN_B.Divide13 = CAN_U.t2 / 20U;

  /* S-Function (scanpack): '<Root>/CAN Pack1' incorporates:
   *  Outport: '<Root>/Voltage2'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  CAN_Y.Voltage2.ID = 0U;
  CAN_Y.Voltage2.Length = 8U;
  CAN_Y.Voltage2.Extended = 0U;
  CAN_Y.Voltage2.Remote = 0;
  CAN_Y.Voltage2.Data[0] = 0;
  CAN_Y.Voltage2.Data[1] = 0;
  CAN_Y.Voltage2.Data[2] = 0;
  CAN_Y.Voltage2.Data[3] = 0;
  CAN_Y.Voltage2.Data[4] = 0;
  CAN_Y.Voltage2.Data[5] = 0;
  CAN_Y.Voltage2.Data[6] = 0;
  CAN_Y.Voltage2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide4);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage2.Data[0] = CAN_Y.Voltage2.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Voltage2.Data[1] = CAN_Y.Voltage2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1F00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 13
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide5);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage2.Data[1] = CAN_Y.Voltage2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7U) << 5));
            CAN_Y.Voltage2.Data[2] = CAN_Y.Voltage2.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7F8U) >> 3));
            CAN_Y.Voltage2.Data[3] = CAN_Y.Voltage2.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1800U) >> 11));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 26
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide6);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage2.Data[3] = CAN_Y.Voltage2.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x3FU) << 2));
            CAN_Y.Voltage2.Data[4] = CAN_Y.Voltage2.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FC0U) >> 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 39
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide7);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage2.Data[4] = CAN_Y.Voltage2.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1U) << 7));
            CAN_Y.Voltage2.Data[5] = CAN_Y.Voltage2.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FEU) >> 1));
            CAN_Y.Voltage2.Data[6] = CAN_Y.Voltage2.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1E00U) >> 9));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 52
     *  length                  = 12
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
        uint32_T result = (uint32_T) (CAN_B.Divide13);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage2.Data[6] = CAN_Y.Voltage2.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CAN_Y.Voltage2.Data[7] = CAN_Y.Voltage2.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }
  }

  /* Product: '<Root>/Divide8' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Inport: '<Root>/v9'
   */
  CAN_B.Divide8 = CAN_U.v9 / 10U;

  /* Product: '<Root>/Divide9' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Inport: '<Root>/v10'
   */
  CAN_B.Divide9 = CAN_U.v10 / 10U;

  /* Product: '<Root>/Divide10' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Inport: '<Root>/v11'
   */
  CAN_B.Divide10 = CAN_U.v11 / 10U;

  /* Product: '<Root>/Divide11' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Inport: '<Root>/v12'
   */
  CAN_B.Divide11 = CAN_U.v12 / 10U;

  /* S-Function (scanpack): '<Root>/CAN Pack2' incorporates:
   *  Inport: '<Root>/counter'
   *  Outport: '<Root>/Voltage3'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack2' */
  CAN_Y.Voltage3.ID = 0U;
  CAN_Y.Voltage3.Length = 8U;
  CAN_Y.Voltage3.Extended = 0U;
  CAN_Y.Voltage3.Remote = 0;
  CAN_Y.Voltage3.Data[0] = 0;
  CAN_Y.Voltage3.Data[1] = 0;
  CAN_Y.Voltage3.Data[2] = 0;
  CAN_Y.Voltage3.Data[3] = 0;
  CAN_Y.Voltage3.Data[4] = 0;
  CAN_Y.Voltage3.Data[5] = 0;
  CAN_Y.Voltage3.Data[6] = 0;
  CAN_Y.Voltage3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide8);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage3.Data[0] = CAN_Y.Voltage3.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CAN_Y.Voltage3.Data[1] = CAN_Y.Voltage3.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1F00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 13
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide9);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage3.Data[1] = CAN_Y.Voltage3.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7U) << 5));
            CAN_Y.Voltage3.Data[2] = CAN_Y.Voltage3.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x7F8U) >> 3));
            CAN_Y.Voltage3.Data[3] = CAN_Y.Voltage3.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1800U) >> 11));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 26
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide10);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage3.Data[3] = CAN_Y.Voltage3.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x3FU) << 2));
            CAN_Y.Voltage3.Data[4] = CAN_Y.Voltage3.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FC0U) >> 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 39
     *  length                  = 13
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
        uint32_T result = (uint32_T) (CAN_B.Divide11);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(8191)) {
          packedValue = (uint16_T) 8191;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage3.Data[4] = CAN_Y.Voltage3.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1U) << 7));
            CAN_Y.Voltage3.Data[5] = CAN_Y.Voltage3.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1FEU) >> 1));
            CAN_Y.Voltage3.Data[6] = CAN_Y.Voltage3.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0x1E00U) >> 9));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 52
     *  length                  = 12
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
        uint32_T result = (uint32_T) (CAN_U.counter);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        if (packingValue > (uint16_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else {
          packedValue = (uint16_T) (packingValue);
        }

        {
          {
            CAN_Y.Voltage3.Data[6] = CAN_Y.Voltage3.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CAN_Y.Voltage3.Data[7] = CAN_Y.Voltage3.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack' incorporates:
   *  Inport: '<Root>/balance1'
   *  Outport: '<Root>/b1'
   *  Outport: '<Root>/b2'
   *  Outport: '<Root>/b3'
   *  Outport: '<Root>/b4'
   *  Outport: '<Root>/b5'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == CAN_U.balance1.Length) && (CAN_U.balance1.ID != INVALID_CAN_ID) )
    {
      if ((1 == CAN_U.balance1.ID) && (0U == CAN_U.balance1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CAN_U.balance1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[1]) & (uint16_T)(0xFU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 12
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[1]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[2]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 24
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CAN_U.balance1.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[4]) & (uint16_T)(0xFU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 36
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[4]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[5]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 48
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CAN_U.balance1.Data[6]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance1.Data[7]) & (uint16_T)(0xFU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b5 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack1' incorporates:
   *  Inport: '<Root>/balance2'
   *  Outport: '<Root>/b6'
   *  Outport: '<Root>/b7'
   *  Outport: '<Root>/b8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack1' */
    if ((8 == CAN_U.balance2.Length) && (CAN_U.balance2.ID != INVALID_CAN_ID) )
    {
      if ((2 == CAN_U.balance2.ID) && (0U == CAN_U.balance2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CAN_U.balance2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance2.Data[1]) & (uint16_T)(0xFU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b6 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 12
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance2.Data[1]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CAN_U.balance2.Data[2]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b7 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 24
           *  length                  = 12
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CAN_U.balance2.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CAN_U.balance2.Data[4]) & (uint16_T)(0xFU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CAN_Y.b8 = result;
            }
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
   *  Inport: '<Root>/balance1'
   *  Outport: '<Root>/b1'
   *  Outport: '<Root>/b2'
   *  Outport: '<Root>/b3'
   *  Outport: '<Root>/b4'
   *  Outport: '<Root>/b5'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack1' incorporates:
   *  Inport: '<Root>/balance2'
   *  Outport: '<Root>/b6'
   *  Outport: '<Root>/b7'
   *  Outport: '<Root>/b8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack1 -----------------*/
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
