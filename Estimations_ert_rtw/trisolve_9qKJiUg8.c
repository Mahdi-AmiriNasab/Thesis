/*
 * File: trisolve_9qKJiUg8.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "trisolve_9qKJiUg8.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void trisolve_9qKJiUg8(real_T A, real_T B[3])
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
