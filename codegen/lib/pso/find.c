/*
 * File: find.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "find.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[9]
 *                int i_data[]
 * Return Type  : int
 */
int b_eml_find(const boolean_T x[9], int i_data[])
{
  int i_size;
  int ii;
  boolean_T exitg1;
  i_size = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 9)) {
    if (x[ii]) {
      i_size++;
      i_data[i_size - 1] = ii + 1;
      if (i_size >= 9) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (i_size < 1) {
    i_size = 0;
  }
  return i_size;
}

/*
 * Arguments    : const boolean_T x_data[]
 *                const int x_size[2]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void c_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
                int i_size[2])
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x_size[1];
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/*
 * Arguments    : const boolean_T x[9]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void eml_find(const boolean_T x[9], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 9)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 9) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
