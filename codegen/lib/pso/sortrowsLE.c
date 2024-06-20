/*
 * File: sortrowsLE.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "sortrowsLE.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double v[18]
 *                int col
 *                int irow1
 *                int irow2
 * Return Type  : boolean_T
 */
boolean_T sortrowsLE(const double v[18], int col, int irow1, int irow2)
{
  double d;
  double d1;
  int abscolk;
  boolean_T b;
  boolean_T p;
  p = true;
  if (col < 0) {
    abscolk = 0;
  } else {
    abscolk = col - 1;
  }
  d = v[(irow1 + 9 * abscolk) - 1];
  d1 = v[(irow2 + 9 * abscolk) - 1];
  if (!(d == d1)) {
    b = rtIsNaN(d);
    if ((!b) || (!rtIsNaN(d1))) {
      if (col < 0) {
        if ((!(d >= d1)) && (!b)) {
          p = false;
        }
      } else if ((!(d <= d1)) && (!rtIsNaN(d1))) {
        p = false;
      }
    }
  }
  return p;
}

/*
 * File trailer for sortrowsLE.c
 *
 * [EOF]
 */
