/*
 * File: CANBMB.c
 *
 * Code generated for Simulink model 'CANBMB'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jan 23 14:03:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CANBMB.h"
#include "CANBMB_private.h"

/* Block states (default storage) */
DW_CANBMB_T CANBMB_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CANBMB_T CANBMB_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CANBMB_T CANBMB_Y;

/* Real-time model */
RT_MODEL_CANBMB_T CANBMB_M_;
RT_MODEL_CANBMB_T *const CANBMB_M = &CANBMB_M_;

/* Model step function */
void CANBMB_step(void)
{
  /* S-Function (scanunpack): '<Root>/CAN Unpack2' incorporates:
   *  Inport: '<Root>/m1_1'
   *  Outport: '<Root>/t1_1'
   *  Outport: '<Root>/v1_1'
   *  Outport: '<Root>/v1_2'
   *  Outport: '<Root>/v1_3'
   *  Outport: '<Root>/v1_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
    if ((8 == CANBMB_U.m1_1.Length) && (CANBMB_U.m1_1.ID != INVALID_CAN_ID) ) {
      if ((3 == CANBMB_U.m1_1.ID) && (0U == CANBMB_U.m1_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m1_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m1_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m1_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m1_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m1_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t1_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack3' incorporates:
   *  Inport: '<Root>/m1_2'
   *  Outport: '<Root>/t1_2'
   *  Outport: '<Root>/v1_5'
   *  Outport: '<Root>/v1_6'
   *  Outport: '<Root>/v1_7'
   *  Outport: '<Root>/v1_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack3' */
    if ((8 == CANBMB_U.m1_2.Length) && (CANBMB_U.m1_2.ID != INVALID_CAN_ID) ) {
      if ((4 == CANBMB_U.m1_2.ID) && (0U == CANBMB_U.m1_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m1_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m1_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m1_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m1_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m1_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t1_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack4' incorporates:
   *  Inport: '<Root>/m1_3'
   *  Outport: '<Root>/counter1'
   *  Outport: '<Root>/v1_10'
   *  Outport: '<Root>/v1_11'
   *  Outport: '<Root>/v1_12'
   *  Outport: '<Root>/v1_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack4' */
    if ((8 == CANBMB_U.m1_3.Length) && (CANBMB_U.m1_3.ID != INVALID_CAN_ID) ) {
      if ((5 == CANBMB_U.m1_3.ID) && (0U == CANBMB_U.m1_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m1_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m1_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m1_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m1_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v1_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m1_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m1_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack5' incorporates:
   *  Inport: '<Root>/m2_1'
   *  Outport: '<Root>/t2_1'
   *  Outport: '<Root>/v2_1'
   *  Outport: '<Root>/v2_2'
   *  Outport: '<Root>/v2_3'
   *  Outport: '<Root>/v2_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack5' */
    if ((8 == CANBMB_U.m2_1.Length) && (CANBMB_U.m2_1.ID != INVALID_CAN_ID) ) {
      if ((6 == CANBMB_U.m2_1.ID) && (0U == CANBMB_U.m2_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m2_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m2_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m2_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m2_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m2_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t2_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack7' incorporates:
   *  Inport: '<Root>/m2_3'
   *  Outport: '<Root>/counter2'
   *  Outport: '<Root>/v2_10'
   *  Outport: '<Root>/v2_11'
   *  Outport: '<Root>/v2_12'
   *  Outport: '<Root>/v2_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack7' */
    if ((8 == CANBMB_U.m2_3.Length) && (CANBMB_U.m2_3.ID != INVALID_CAN_ID) ) {
      if ((8 == CANBMB_U.m2_3.ID) && (0U == CANBMB_U.m2_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m2_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m2_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m2_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m2_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m2_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack6' incorporates:
   *  Inport: '<Root>/m2_2'
   *  Outport: '<Root>/t2_2'
   *  Outport: '<Root>/v2_5'
   *  Outport: '<Root>/v2_6'
   *  Outport: '<Root>/v2_7'
   *  Outport: '<Root>/v2_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack6' */
    if ((8 == CANBMB_U.m2_2.Length) && (CANBMB_U.m2_2.ID != INVALID_CAN_ID) ) {
      if ((7 == CANBMB_U.m2_2.ID) && (0U == CANBMB_U.m2_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m2_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m2_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m2_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m2_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v2_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m2_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m2_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t2_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack8' incorporates:
   *  Inport: '<Root>/m3_1'
   *  Outport: '<Root>/t3_1'
   *  Outport: '<Root>/v3_1'
   *  Outport: '<Root>/v3_2'
   *  Outport: '<Root>/v3_3'
   *  Outport: '<Root>/v3_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack8' */
    if ((8 == CANBMB_U.m3_1.Length) && (CANBMB_U.m3_1.ID != INVALID_CAN_ID) ) {
      if ((9 == CANBMB_U.m3_1.ID) && (0U == CANBMB_U.m3_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m3_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m3_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m3_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m3_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m3_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t3_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack10' incorporates:
   *  Inport: '<Root>/m3_3'
   *  Outport: '<Root>/counter3'
   *  Outport: '<Root>/v3_10'
   *  Outport: '<Root>/v3_11'
   *  Outport: '<Root>/v3_12'
   *  Outport: '<Root>/v3_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack10' */
    if ((8 == CANBMB_U.m3_3.Length) && (CANBMB_U.m3_3.ID != INVALID_CAN_ID) ) {
      if ((11 == CANBMB_U.m3_3.ID) && (0U == CANBMB_U.m3_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m3_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m3_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m3_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m3_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m3_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter3 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack9' incorporates:
   *  Inport: '<Root>/m3_2'
   *  Outport: '<Root>/t3_2'
   *  Outport: '<Root>/v3_5'
   *  Outport: '<Root>/v3_6'
   *  Outport: '<Root>/v3_7'
   *  Outport: '<Root>/v3_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack9' */
    if ((8 == CANBMB_U.m3_2.Length) && (CANBMB_U.m3_2.ID != INVALID_CAN_ID) ) {
      if ((10 == CANBMB_U.m3_2.ID) && (0U == CANBMB_U.m3_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m3_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m3_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m3_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m3_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v3_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m3_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m3_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t3_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack12' incorporates:
   *  Inport: '<Root>/m4_1'
   *  Outport: '<Root>/t4_1'
   *  Outport: '<Root>/v4_1'
   *  Outport: '<Root>/v4_2'
   *  Outport: '<Root>/v4_3'
   *  Outport: '<Root>/v4_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack12' */
    if ((8 == CANBMB_U.m4_1.Length) && (CANBMB_U.m4_1.ID != INVALID_CAN_ID) ) {
      if ((12 == CANBMB_U.m4_1.ID) && (0U == CANBMB_U.m4_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m4_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m4_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m4_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m4_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m4_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t4_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack11' incorporates:
   *  Inport: '<Root>/m4_3'
   *  Outport: '<Root>/counter4'
   *  Outport: '<Root>/v4_10'
   *  Outport: '<Root>/v4_11'
   *  Outport: '<Root>/v4_12'
   *  Outport: '<Root>/v4_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack11' */
    if ((8 == CANBMB_U.m4_3.Length) && (CANBMB_U.m4_3.ID != INVALID_CAN_ID) ) {
      if ((14 == CANBMB_U.m4_3.ID) && (0U == CANBMB_U.m4_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m4_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m4_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m4_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m4_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m4_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter4 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack13' incorporates:
   *  Inport: '<Root>/m4_2'
   *  Outport: '<Root>/t4_2'
   *  Outport: '<Root>/v4_5'
   *  Outport: '<Root>/v4_6'
   *  Outport: '<Root>/v4_7'
   *  Outport: '<Root>/v4_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack13' */
    if ((8 == CANBMB_U.m4_2.Length) && (CANBMB_U.m4_2.ID != INVALID_CAN_ID) ) {
      if ((13 == CANBMB_U.m4_2.ID) && (0U == CANBMB_U.m4_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m4_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m4_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m4_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m4_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v4_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m4_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m4_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t4_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack15' incorporates:
   *  Inport: '<Root>/m5_1'
   *  Outport: '<Root>/t5_1'
   *  Outport: '<Root>/v5_1'
   *  Outport: '<Root>/v5_2'
   *  Outport: '<Root>/v5_3'
   *  Outport: '<Root>/v5_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack15' */
    if ((8 == CANBMB_U.m5_1.Length) && (CANBMB_U.m5_1.ID != INVALID_CAN_ID) ) {
      if ((15 == CANBMB_U.m5_1.ID) && (0U == CANBMB_U.m5_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m5_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m5_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m5_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m5_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m5_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t5_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack14' incorporates:
   *  Inport: '<Root>/m5_3'
   *  Outport: '<Root>/counter5'
   *  Outport: '<Root>/v5_10'
   *  Outport: '<Root>/v5_11'
   *  Outport: '<Root>/v5_12'
   *  Outport: '<Root>/v5_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack14' */
    if ((8 == CANBMB_U.m5_3.Length) && (CANBMB_U.m5_3.ID != INVALID_CAN_ID) ) {
      if ((17 == CANBMB_U.m5_3.ID) && (0U == CANBMB_U.m5_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m5_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m5_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m5_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m5_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m5_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter5 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack16' incorporates:
   *  Inport: '<Root>/m5_2'
   *  Outport: '<Root>/t5_2'
   *  Outport: '<Root>/v5_5'
   *  Outport: '<Root>/v5_6'
   *  Outport: '<Root>/v5_7'
   *  Outport: '<Root>/v5_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack16' */
    if ((8 == CANBMB_U.m5_2.Length) && (CANBMB_U.m5_2.ID != INVALID_CAN_ID) ) {
      if ((16 == CANBMB_U.m5_2.ID) && (0U == CANBMB_U.m5_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m5_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m5_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m5_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m5_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v5_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m5_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m5_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t5_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack18' incorporates:
   *  Inport: '<Root>/m6_1'
   *  Outport: '<Root>/t6_1'
   *  Outport: '<Root>/v6_1'
   *  Outport: '<Root>/v6_2'
   *  Outport: '<Root>/v6_3'
   *  Outport: '<Root>/v6_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack18' */
    if ((8 == CANBMB_U.m6_1.Length) && (CANBMB_U.m6_1.ID != INVALID_CAN_ID) ) {
      if ((18 == CANBMB_U.m6_1.ID) && (0U == CANBMB_U.m6_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m6_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m6_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m6_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m6_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m6_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t6_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack17' incorporates:
   *  Inport: '<Root>/m6_3'
   *  Outport: '<Root>/counter6'
   *  Outport: '<Root>/v6_10'
   *  Outport: '<Root>/v6_11'
   *  Outport: '<Root>/v6_12'
   *  Outport: '<Root>/v6_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack17' */
    if ((8 == CANBMB_U.m6_3.Length) && (CANBMB_U.m6_3.ID != INVALID_CAN_ID) ) {
      if ((20 == CANBMB_U.m6_3.ID) && (0U == CANBMB_U.m6_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m6_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m6_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m6_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m6_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m6_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter6 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack19' incorporates:
   *  Inport: '<Root>/m6_2'
   *  Outport: '<Root>/t6_2'
   *  Outport: '<Root>/v6_5'
   *  Outport: '<Root>/v6_6'
   *  Outport: '<Root>/v6_7'
   *  Outport: '<Root>/v6_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack19' */
    if ((8 == CANBMB_U.m6_2.Length) && (CANBMB_U.m6_2.ID != INVALID_CAN_ID) ) {
      if ((19 == CANBMB_U.m6_2.ID) && (0U == CANBMB_U.m6_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m6_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m6_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m6_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m6_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v6_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m6_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m6_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t6_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack21' incorporates:
   *  Inport: '<Root>/m7_1'
   *  Outport: '<Root>/t7_1'
   *  Outport: '<Root>/v7_1'
   *  Outport: '<Root>/v7_2'
   *  Outport: '<Root>/v7_3'
   *  Outport: '<Root>/v7_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack21' */
    if ((8 == CANBMB_U.m7_1.Length) && (CANBMB_U.m7_1.ID != INVALID_CAN_ID) ) {
      if ((21 == CANBMB_U.m7_1.ID) && (0U == CANBMB_U.m7_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m7_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m7_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m7_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m7_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m7_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t7_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack20' incorporates:
   *  Inport: '<Root>/m7_3'
   *  Outport: '<Root>/counter7'
   *  Outport: '<Root>/v7_10'
   *  Outport: '<Root>/v7_11'
   *  Outport: '<Root>/v7_12'
   *  Outport: '<Root>/v7_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack20' */
    if ((8 == CANBMB_U.m7_3.Length) && (CANBMB_U.m7_3.ID != INVALID_CAN_ID) ) {
      if ((23 == CANBMB_U.m7_3.ID) && (0U == CANBMB_U.m7_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m7_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m7_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m7_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m7_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m7_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter7 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack22' incorporates:
   *  Inport: '<Root>/m7_2'
   *  Outport: '<Root>/t7_2'
   *  Outport: '<Root>/v7_5'
   *  Outport: '<Root>/v7_6'
   *  Outport: '<Root>/v7_7'
   *  Outport: '<Root>/v7_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack22' */
    if ((8 == CANBMB_U.m7_2.Length) && (CANBMB_U.m7_2.ID != INVALID_CAN_ID) ) {
      if ((22 == CANBMB_U.m7_2.ID) && (0U == CANBMB_U.m7_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m7_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m7_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m7_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m7_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v7_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m7_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m7_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t7_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack24' incorporates:
   *  Inport: '<Root>/m8_1'
   *  Outport: '<Root>/t8_1'
   *  Outport: '<Root>/v8_1'
   *  Outport: '<Root>/v8_2'
   *  Outport: '<Root>/v8_3'
   *  Outport: '<Root>/v8_4'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack24' */
    if ((8 == CANBMB_U.m8_1.Length) && (CANBMB_U.m8_1.ID != INVALID_CAN_ID) ) {
      if ((24 == CANBMB_U.m8_1.ID) && (0U == CANBMB_U.m8_1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m8_1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m8_1.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m8_1.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m8_1.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m8_1.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_1.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t8_1 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack23' incorporates:
   *  Inport: '<Root>/m8_3'
   *  Outport: '<Root>/counter8'
   *  Outport: '<Root>/v8_10'
   *  Outport: '<Root>/v8_11'
   *  Outport: '<Root>/v8_12'
   *  Outport: '<Root>/v8_9'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack23' */
    if ((8 == CANBMB_U.m8_3.Length) && (CANBMB_U.m8_3.ID != INVALID_CAN_ID) ) {
      if ((26 == CANBMB_U.m8_3.ID) && (0U == CANBMB_U.m8_3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m8_3.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_9 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m8_3.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_10 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m8_3.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_11 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m8_3.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_12 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m8_3.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_3.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.counter8 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack25' incorporates:
   *  Inport: '<Root>/m8_2'
   *  Outport: '<Root>/t8_2'
   *  Outport: '<Root>/v8_5'
   *  Outport: '<Root>/v8_6'
   *  Outport: '<Root>/v8_7'
   *  Outport: '<Root>/v8_8'
   */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack25' */
    if ((8 == CANBMB_U.m8_2.Length) && (CANBMB_U.m8_2.ID != INVALID_CAN_ID) ) {
      if ((25 == CANBMB_U.m8_2.ID) && (0U == CANBMB_U.m8_2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 13
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
                  tempValue = tempValue | (uint16_T)(CANBMB_U.m8_2.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[1]) & (uint16_T)(0x1FU)) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_5 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 13
           *  length                  = 13
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
                    (CANBMB_U.m8_2.Data[1]) & (uint16_T)(0xE0U)) >> 5);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[2]) << 3);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[3]) & (uint16_T)(0x3U)) << 11);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_6 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 26
           *  length                  = 13
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
                    (CANBMB_U.m8_2.Data[3]) & (uint16_T)(0xFCU)) >> 2);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[4]) & (uint16_T)(0x7FU)) << 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_7 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 39
           *  length                  = 13
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
                    (CANBMB_U.m8_2.Data[4]) & (uint16_T)(0x80U)) >> 7);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[5]) << 1);
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[6]) & (uint16_T)(0xFU)) << 9);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.v8_8 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 52
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
                    (CANBMB_U.m8_2.Data[6]) & (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANBMB_U.m8_2.Data[7]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANBMB_Y.t8_2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Inport: '<Root>/b1'
   *  Inport: '<Root>/b2'
   *  Inport: '<Root>/b3'
   *  Inport: '<Root>/b4'
   *  Inport: '<Root>/b5'
   *  Outport: '<Root>/balaner1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  CANBMB_Y.balaner1.ID = 1U;
  CANBMB_Y.balaner1.Length = 8U;
  CANBMB_Y.balaner1.Extended = 0U;
  CANBMB_Y.balaner1.Remote = 0;
  CANBMB_Y.balaner1.Data[0] = 0;
  CANBMB_Y.balaner1.Data[1] = 0;
  CANBMB_Y.balaner1.Data[2] = 0;
  CANBMB_Y.balaner1.Data[3] = 0;
  CANBMB_Y.balaner1.Data[4] = 0;
  CANBMB_Y.balaner1.Data[5] = 0;
  CANBMB_Y.balaner1.Data[6] = 0;
  CANBMB_Y.balaner1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
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
        uint32_T result = (uint32_T) (CANBMB_U.b1);

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
            CANBMB_Y.balaner1.Data[0] = CANBMB_Y.balaner1.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CANBMB_Y.balaner1.Data[1] = CANBMB_Y.balaner1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 12
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
        uint32_T result = (uint32_T) (CANBMB_U.b2);

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
            CANBMB_Y.balaner1.Data[1] = CANBMB_Y.balaner1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CANBMB_Y.balaner1.Data[2] = CANBMB_Y.balaner1.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
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
        uint32_T result = (uint32_T) (CANBMB_U.b3);

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
            CANBMB_Y.balaner1.Data[3] = CANBMB_Y.balaner1.Data[3] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CANBMB_Y.balaner1.Data[4] = CANBMB_Y.balaner1.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 36
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
        uint32_T result = (uint32_T) (CANBMB_U.b4);

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
            CANBMB_Y.balaner1.Data[4] = CANBMB_Y.balaner1.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CANBMB_Y.balaner1.Data[5] = CANBMB_Y.balaner1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
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
        uint32_T result = (uint32_T) (CANBMB_U.b5);

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
            CANBMB_Y.balaner1.Data[6] = CANBMB_Y.balaner1.Data[6] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CANBMB_Y.balaner1.Data[7] = CANBMB_Y.balaner1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (scanpack): '<Root>/CAN Pack1' incorporates:
   *  Inport: '<Root>/b6'
   *  Inport: '<Root>/b7'
   *  Inport: '<Root>/b8'
   *  Outport: '<Root>/balaner2'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  CANBMB_Y.balaner2.ID = 2U;
  CANBMB_Y.balaner2.Length = 8U;
  CANBMB_Y.balaner2.Extended = 0U;
  CANBMB_Y.balaner2.Remote = 0;
  CANBMB_Y.balaner2.Data[0] = 0;
  CANBMB_Y.balaner2.Data[1] = 0;
  CANBMB_Y.balaner2.Data[2] = 0;
  CANBMB_Y.balaner2.Data[3] = 0;
  CANBMB_Y.balaner2.Data[4] = 0;
  CANBMB_Y.balaner2.Data[5] = 0;
  CANBMB_Y.balaner2.Data[6] = 0;
  CANBMB_Y.balaner2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
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
        uint32_T result = (uint32_T) (CANBMB_U.b6);

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
            CANBMB_Y.balaner2.Data[0] = CANBMB_Y.balaner2.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CANBMB_Y.balaner2.Data[1] = CANBMB_Y.balaner2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 12
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
        uint32_T result = (uint32_T) (CANBMB_U.b7);

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
            CANBMB_Y.balaner2.Data[1] = CANBMB_Y.balaner2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            CANBMB_Y.balaner2.Data[2] = CANBMB_Y.balaner2.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF0U) >> 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
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
        uint32_T result = (uint32_T) (CANBMB_U.b8);

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
            CANBMB_Y.balaner2.Data[3] = CANBMB_Y.balaner2.Data[3] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            CANBMB_Y.balaner2.Data[4] = CANBMB_Y.balaner2.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }
  }
}

/* Model initialize function */
void CANBMB_initialize(void)
{
  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack2' incorporates:
   *  Inport: '<Root>/m1_1'
   *  Outport: '<Root>/t1_1'
   *  Outport: '<Root>/v1_1'
   *  Outport: '<Root>/v1_2'
   *  Outport: '<Root>/v1_3'
   *  Outport: '<Root>/v1_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack2 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack3' incorporates:
   *  Inport: '<Root>/m1_2'
   *  Outport: '<Root>/t1_2'
   *  Outport: '<Root>/v1_5'
   *  Outport: '<Root>/v1_6'
   *  Outport: '<Root>/v1_7'
   *  Outport: '<Root>/v1_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack3 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack4' incorporates:
   *  Inport: '<Root>/m1_3'
   *  Outport: '<Root>/counter1'
   *  Outport: '<Root>/v1_10'
   *  Outport: '<Root>/v1_11'
   *  Outport: '<Root>/v1_12'
   *  Outport: '<Root>/v1_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack4 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack5' incorporates:
   *  Inport: '<Root>/m2_1'
   *  Outport: '<Root>/t2_1'
   *  Outport: '<Root>/v2_1'
   *  Outport: '<Root>/v2_2'
   *  Outport: '<Root>/v2_3'
   *  Outport: '<Root>/v2_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack5 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack7' incorporates:
   *  Inport: '<Root>/m2_3'
   *  Outport: '<Root>/counter2'
   *  Outport: '<Root>/v2_10'
   *  Outport: '<Root>/v2_11'
   *  Outport: '<Root>/v2_12'
   *  Outport: '<Root>/v2_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack7 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack6' incorporates:
   *  Inport: '<Root>/m2_2'
   *  Outport: '<Root>/t2_2'
   *  Outport: '<Root>/v2_5'
   *  Outport: '<Root>/v2_6'
   *  Outport: '<Root>/v2_7'
   *  Outport: '<Root>/v2_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack6 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack8' incorporates:
   *  Inport: '<Root>/m3_1'
   *  Outport: '<Root>/t3_1'
   *  Outport: '<Root>/v3_1'
   *  Outport: '<Root>/v3_2'
   *  Outport: '<Root>/v3_3'
   *  Outport: '<Root>/v3_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack8 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack10' incorporates:
   *  Inport: '<Root>/m3_3'
   *  Outport: '<Root>/counter3'
   *  Outport: '<Root>/v3_10'
   *  Outport: '<Root>/v3_11'
   *  Outport: '<Root>/v3_12'
   *  Outport: '<Root>/v3_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack10 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack9' incorporates:
   *  Inport: '<Root>/m3_2'
   *  Outport: '<Root>/t3_2'
   *  Outport: '<Root>/v3_5'
   *  Outport: '<Root>/v3_6'
   *  Outport: '<Root>/v3_7'
   *  Outport: '<Root>/v3_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack9 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack12' incorporates:
   *  Inport: '<Root>/m4_1'
   *  Outport: '<Root>/t4_1'
   *  Outport: '<Root>/v4_1'
   *  Outport: '<Root>/v4_2'
   *  Outport: '<Root>/v4_3'
   *  Outport: '<Root>/v4_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack12 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack11' incorporates:
   *  Inport: '<Root>/m4_3'
   *  Outport: '<Root>/counter4'
   *  Outport: '<Root>/v4_10'
   *  Outport: '<Root>/v4_11'
   *  Outport: '<Root>/v4_12'
   *  Outport: '<Root>/v4_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack11 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack13' incorporates:
   *  Inport: '<Root>/m4_2'
   *  Outport: '<Root>/t4_2'
   *  Outport: '<Root>/v4_5'
   *  Outport: '<Root>/v4_6'
   *  Outport: '<Root>/v4_7'
   *  Outport: '<Root>/v4_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack13 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack15' incorporates:
   *  Inport: '<Root>/m5_1'
   *  Outport: '<Root>/t5_1'
   *  Outport: '<Root>/v5_1'
   *  Outport: '<Root>/v5_2'
   *  Outport: '<Root>/v5_3'
   *  Outport: '<Root>/v5_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack15 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack14' incorporates:
   *  Inport: '<Root>/m5_3'
   *  Outport: '<Root>/counter5'
   *  Outport: '<Root>/v5_10'
   *  Outport: '<Root>/v5_11'
   *  Outport: '<Root>/v5_12'
   *  Outport: '<Root>/v5_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack14 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack16' incorporates:
   *  Inport: '<Root>/m5_2'
   *  Outport: '<Root>/t5_2'
   *  Outport: '<Root>/v5_5'
   *  Outport: '<Root>/v5_6'
   *  Outport: '<Root>/v5_7'
   *  Outport: '<Root>/v5_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack16 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack18' incorporates:
   *  Inport: '<Root>/m6_1'
   *  Outport: '<Root>/t6_1'
   *  Outport: '<Root>/v6_1'
   *  Outport: '<Root>/v6_2'
   *  Outport: '<Root>/v6_3'
   *  Outport: '<Root>/v6_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack18 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack17' incorporates:
   *  Inport: '<Root>/m6_3'
   *  Outport: '<Root>/counter6'
   *  Outport: '<Root>/v6_10'
   *  Outport: '<Root>/v6_11'
   *  Outport: '<Root>/v6_12'
   *  Outport: '<Root>/v6_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack17 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack19' incorporates:
   *  Inport: '<Root>/m6_2'
   *  Outport: '<Root>/t6_2'
   *  Outport: '<Root>/v6_5'
   *  Outport: '<Root>/v6_6'
   *  Outport: '<Root>/v6_7'
   *  Outport: '<Root>/v6_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack19 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack21' incorporates:
   *  Inport: '<Root>/m7_1'
   *  Outport: '<Root>/t7_1'
   *  Outport: '<Root>/v7_1'
   *  Outport: '<Root>/v7_2'
   *  Outport: '<Root>/v7_3'
   *  Outport: '<Root>/v7_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack21 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack20' incorporates:
   *  Inport: '<Root>/m7_3'
   *  Outport: '<Root>/counter7'
   *  Outport: '<Root>/v7_10'
   *  Outport: '<Root>/v7_11'
   *  Outport: '<Root>/v7_12'
   *  Outport: '<Root>/v7_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack20 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack22' incorporates:
   *  Inport: '<Root>/m7_2'
   *  Outport: '<Root>/t7_2'
   *  Outport: '<Root>/v7_5'
   *  Outport: '<Root>/v7_6'
   *  Outport: '<Root>/v7_7'
   *  Outport: '<Root>/v7_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack22 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack24' incorporates:
   *  Inport: '<Root>/m8_1'
   *  Outport: '<Root>/t8_1'
   *  Outport: '<Root>/v8_1'
   *  Outport: '<Root>/v8_2'
   *  Outport: '<Root>/v8_3'
   *  Outport: '<Root>/v8_4'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack24 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack23' incorporates:
   *  Inport: '<Root>/m8_3'
   *  Outport: '<Root>/counter8'
   *  Outport: '<Root>/v8_10'
   *  Outport: '<Root>/v8_11'
   *  Outport: '<Root>/v8_12'
   *  Outport: '<Root>/v8_9'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack23 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack25' incorporates:
   *  Inport: '<Root>/m8_2'
   *  Outport: '<Root>/t8_2'
   *  Outport: '<Root>/v8_5'
   *  Outport: '<Root>/v8_6'
   *  Outport: '<Root>/v8_7'
   *  Outport: '<Root>/v8_8'
   */

  /*-----------S-Function Block: <Root>/CAN Unpack25 -----------------*/
}

/* Model terminate function */
void CANBMB_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
