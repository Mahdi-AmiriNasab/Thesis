/*
 * File: trisolve_1hqRQ712.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "trisolve_1hqRQ712.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void trisolve_1hqRQ712(real_T A, real_T B[3])
{
  if (B[0] != 0.0) {
    B[0] /= A;
  }

  if (B[1] != 0.0) {
    B[1] /= A;
  }

  if (B[2] != 0.0) {
    B[2] /= A;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
