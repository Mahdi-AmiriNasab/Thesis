/*
 * File: rtmodel.c
 *
 * Code generated for Simulink model 'test3'.
 *
 * Model version                  : 2.234
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jan 24 14:29:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void test3_step(int_T tid)
{
  switch (tid) {
   case 0 :
    test3_step0();
    break;

   case 1 :
    test3_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
