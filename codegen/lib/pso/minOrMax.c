/*
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "minOrMax.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                int x_size
 * Return Type  : double
 */
double b_maximum(const double x_data[], int x_size)
{
  double d;
  double ex;
  int idx;
  int k;
  boolean_T exitg1;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size - 1];
      if ((!(x_data[0] < ex)) && ((!rtIsNaN(x_data[0])) || rtIsNaN(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= x_size; k++) {
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                int *idx
 * Return Type  : double
 */
double b_minimum(const double x_data[], const int x_size[2], int *idx)
{
  double d;
  double ex;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x_size[1] - 1];
      if ((x_data[0] > ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x_size[1];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                int *idx
 * Return Type  : double
 */
double c_maximum(const double x_data[], const int x_size[2], int *idx)
{
  double d;
  double ex;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x_size[1] - 1];
      if ((x_data[0] < ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x_size[1];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 * Return Type  : double
 */
double c_minimum(const double x_data[], const int x_size[2])
{
  double d;
  double ex;
  int idx;
  int k;
  int last;
  boolean_T exitg1;
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size[1] - 1];
      if ((!(x_data[0] > ex)) && ((!rtIsNaN(x_data[0])) || rtIsNaN(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 * Return Type  : double
 */
double d_maximum(const double x_data[], const int x_size[2])
{
  double d;
  double ex;
  int idx;
  int k;
  int last;
  boolean_T exitg1;
  last = x_size[1];
  if (x_size[1] <= 2) {
    if (x_size[1] == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size[1] - 1];
      if ((!(x_data[0] < ex)) && ((!rtIsNaN(x_data[0])) || rtIsNaN(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int *idx
 * Return Type  : double
 */
double d_minimum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double d;
  double ex;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if ((x_data[0] > ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int *idx
 * Return Type  : double
 */
double e_maximum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double d;
  double ex;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if ((x_data[0] < ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x[9]
 * Return Type  : double
 */
double e_minimum(const double x[9])
{
  double d;
  double ex;
  int idx;
  int k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 10; k++) {
      d = x[k - 1];
      if (ex > d) {
        ex = d;
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x[9]
 * Return Type  : double
 */
double f_maximum(const double x[9])
{
  double d;
  double ex;
  int idx;
  int k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 10; k++) {
      d = x[k - 1];
      if (ex < d) {
        ex = d;
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x[9]
 * Return Type  : double
 */
double maximum(const double x[9])
{
  double d;
  double ex;
  int idx;
  int k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 10; k++) {
      d = x[k - 1];
      if (ex < d) {
        ex = d;
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const double x_data[]
 *                int x_size
 * Return Type  : double
 */
double minimum(const double x_data[], int x_size)
{
  double d;
  double ex;
  int idx;
  int k;
  boolean_T exitg1;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size - 1];
      if ((!(x_data[0] > ex)) && ((!rtIsNaN(x_data[0])) || rtIsNaN(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= x_size; k++) {
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
