/*
 * File: xrot_cReDmrQt.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "xrot_cReDmrQt.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xrot_cReDmrQt(real_T x[9], int16_T ix0, int16_T iy0, real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + temp * s;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
