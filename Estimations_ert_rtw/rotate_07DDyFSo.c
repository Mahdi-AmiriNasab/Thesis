/*
 * File: rotate_07DDyFSo.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "rotate_07DDyFSo.h"
#include <math.h>
#include "rt_hypotd_snf.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void rotate_07DDyFSo(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T absy;
  real_T rho;
  real_T xx;
  real_T yy;
  absx = fabs(x);
  absy = fabs(y);
  if (absy == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (absx == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    absy += absx;
    xx = x / absy;
    yy = y / absy;
    absx = fabs(xx);
    rho = rt_hypotd_snf(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    *r = rho * absy * xx;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
