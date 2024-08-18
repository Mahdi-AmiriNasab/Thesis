/*
 * File: div_nde_s16_floor.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "div_nde_s16_floor.h"
#include "rtwtypes.h"

int16_T div_nde_s16_floor(int16_T numerator, int16_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
