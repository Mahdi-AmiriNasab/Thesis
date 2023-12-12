/*
 * File: sortrowsLE.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
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
  int abscolk;
  boolean_T p;
  p = true;
  if (col < 0) {
    abscolk = 0;
  } else {
    abscolk = col - 1;
  }
  if ((!(v[(irow1 + 9 * abscolk) - 1] == v[(irow2 + 9 * abscolk) - 1])) &&
      ((!rtIsNaN(v[(irow1 + 9 * abscolk) - 1])) ||
       (!rtIsNaN(v[(irow2 + 9 * abscolk) - 1])))) {
    if (col < 0) {
      if ((!(v[(irow1 + 9 * abscolk) - 1] >= v[(irow2 + 9 * abscolk) - 1])) &&
          (!rtIsNaN(v[(irow1 + 9 * abscolk) - 1]))) {
        p = false;
      }
    } else if ((!(v[(irow1 + 9 * abscolk) - 1] <=
                  v[(irow2 + 9 * abscolk) - 1])) &&
               (!rtIsNaN(v[(irow2 + 9 * abscolk) - 1]))) {
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
