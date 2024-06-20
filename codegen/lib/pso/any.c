/*
 * File: any.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "any.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x_data[]
 *                boolean_T y_data[]
 * Return Type  : int
 */
int any(const boolean_T x_data[], boolean_T y_data[])
{
  int i1;
  int i2;
  int ix;
  int j;
  int y_size;
  boolean_T exitg1;
  y_size = 100;
  i1 = 0;
  i2 = 800;
  for (j = 0; j < 100; j++) {
    y_data[j] = false;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += 100;
      }
    }
  }
  return y_size;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
