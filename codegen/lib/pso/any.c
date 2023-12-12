/*
 * File: any.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

/* Include Files */
#include "any.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x_data[]
 *                boolean_T y_data[]
 *                int *y_size
 * Return Type  : void
 */
void any(const boolean_T x_data[], boolean_T y_data[], int *y_size)
{
  int i1;
  int i2;
  int j;
  *y_size = 100;
  i1 = 0;
  i2 = 800;
  for (j = 0; j < 100; j++) {
    int ix;
    boolean_T exitg1;
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
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
