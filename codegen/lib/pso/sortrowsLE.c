/*
 * File: sortrowsLE.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/* Include Files */
#include "sortrowsLE.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double v[18]
 *                int irow1
 *                int irow2
 * Return Type  : boolean_T
 */
boolean_T sortrowsLE(const double v[18], int irow1, int irow2)
{
  double d;
  double d1;
  boolean_T p;
  p = true;
  d = v[irow1 - 1];
  d1 = v[irow2 - 1];
  if (!(d == d1)) {
    boolean_T b;
    b = rtIsNaN(d);
    if (((!b) || (!rtIsNaN(d1))) && (!(d >= d1)) && (!b)) {
      p = false;
    }
  }
  return p;
}

/*
 * File trailer for sortrowsLE.c
 *
 * [EOF]
 */
