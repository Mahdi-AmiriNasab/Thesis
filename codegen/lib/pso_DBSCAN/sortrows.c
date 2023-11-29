/*
 * File: sortrows.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

/* Include Files */
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double y[18]
 * Return Type  : void
 */
void sortrows(double y[18])
{
  double ycol[9];
  double d;
  double d1;
  int idx[9];
  int iwork[9];
  int i;
  int j;
  int k;
  int pEnd;
  int qEnd;
  boolean_T b;
  boolean_T guard1 = false;
  d = y[0];
  d1 = y[1];
  guard1 = false;
  if (d == d1) {
    guard1 = true;
  } else {
    b = rtIsNaN(d);
    if ((b && rtIsNaN(d1)) || (d >= d1) || b) {
      guard1 = true;
    } else {
      idx[0] = 2;
      idx[1] = 1;
    }
  }
  if (guard1) {
    idx[0] = 1;
    idx[1] = 2;
  }
  d = y[2];
  d1 = y[3];
  guard1 = false;
  if (d == d1) {
    guard1 = true;
  } else {
    b = rtIsNaN(d);
    if ((b && rtIsNaN(d1)) || (d >= d1) || b) {
      guard1 = true;
    } else {
      idx[2] = 4;
      idx[3] = 3;
    }
  }
  if (guard1) {
    idx[2] = 3;
    idx[3] = 4;
  }
  d = y[4];
  d1 = y[5];
  guard1 = false;
  if (d == d1) {
    guard1 = true;
  } else {
    b = rtIsNaN(d);
    if ((b && rtIsNaN(d1)) || (d >= d1) || b) {
      guard1 = true;
    } else {
      idx[4] = 6;
      idx[5] = 5;
    }
  }
  if (guard1) {
    idx[4] = 5;
    idx[5] = 6;
  }
  d = y[6];
  d1 = y[7];
  guard1 = false;
  if (d == d1) {
    guard1 = true;
  } else {
    b = rtIsNaN(d);
    if ((b && rtIsNaN(d1)) || (d >= d1) || b) {
      guard1 = true;
    } else {
      idx[6] = 8;
      idx[7] = 7;
    }
  }
  if (guard1) {
    idx[6] = 7;
    idx[7] = 8;
  }
  idx[8] = 9;
  i = 2;
  while (i < 9) {
    int i2;
    i2 = i << 1;
    j = 1;
    for (pEnd = i + 1; pEnd < 10; pEnd = qEnd + i) {
      int kEnd;
      int p;
      int q;
      p = j - 1;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > 10) {
        qEnd = 10;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        d = y[idx[p] - 1];
        d1 = y[idx[q] - 1];
        guard1 = false;
        if (d == d1) {
          guard1 = true;
        } else {
          b = rtIsNaN(d);
          if ((b && rtIsNaN(d1)) || (d >= d1) || b) {
            guard1 = true;
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (p + 1 < pEnd) {
                k++;
                iwork[k] = idx[p];
                p++;
              }
            }
          }
        }
        if (guard1) {
          iwork[k] = idx[p];
          p++;
          if (p + 1 == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              iwork[k] = idx[q];
              q++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }
      j = qEnd;
    }
    i = i2;
  }
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 9; i++) {
      ycol[i] = y[(idx[i] + 9 * j) - 1];
    }
    memcpy(&y[j * 9], &ycol[0], 9U * sizeof(double));
  }
}

/*
 * File trailer for sortrows.c
 *
 * [EOF]
 */
