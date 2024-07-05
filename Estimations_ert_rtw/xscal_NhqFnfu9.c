/*
 * File: xscal_NhqFnfu9.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "xscal_NhqFnfu9.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xscal_NhqFnfu9(real_T a, real_T x[9], int16_T ix0)
{
  int16_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
