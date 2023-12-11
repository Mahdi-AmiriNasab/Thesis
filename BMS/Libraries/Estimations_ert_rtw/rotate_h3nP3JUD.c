/*
 * File: rotate_h3nP3JUD.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "rotate_h3nP3JUD.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void rotate_h3nP3JUD(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T rho;
  real_T t;
  real_T xx;
  real_T yy;
  t = fabs(x);
  xx = fabs(y);
  if (xx == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (t == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    t += xx;
    xx = x / t;
    yy = y / t;
    absx = fabs(xx);
    rho = rt_hypotd_snf(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    rho *= t;
    *r = rho * xx;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
