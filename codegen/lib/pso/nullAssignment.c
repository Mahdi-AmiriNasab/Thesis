/*
 * File: nullAssignment.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "nullAssignment.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x_data[]
 *                int x_size[2]
 *                const boolean_T idx_data[]
 * Return Type  : void
 */
void nullAssignment(double x_data[], int x_size[2], const boolean_T idx_data[])
{
  int b_i;
  int i;
  int j;
  int k;
  int n;
  n = 0;
  i = 0;
  for (k = 0; k < 100; k++) {
    n += idx_data[k];
    if (!idx_data[k]) {
      for (j = 0; j < 9; j++) {
        b_i = x_size[0] * j;
        x_data[i + b_i] = x_data[k + b_i];
      }
      i++;
    }
  }
  if (100 - n < 1) {
    n = 0;
  } else {
    n = 100 - n;
  }
  for (b_i = 0; b_i < 9; b_i++) {
    for (i = 0; i < n; i++) {
      x_data[i + n * b_i] = x_data[i + x_size[0] * b_i];
    }
  }
  x_size[0] = n;
  x_size[1] = 9;
}

/*
 * File trailer for nullAssignment.c
 *
 * [EOF]
 */
