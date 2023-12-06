/*
 * File: islocalmin.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "islocalmin.h"
#include "isLocalExtrema.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A_data[]
 *                const int A_size[2]
 *                boolean_T tf_data[]
 *                int tf_size[2]
 * Return Type  : void
 */
void islocalmin(const double A_data[], const int A_size[2], boolean_T tf_data[],
                int tf_size[2])
{
  int i;
  int loop_ub;
  int outputs_f1_size;
  int tmp_size;
  signed char b_tmp_data[100];
  signed char c_tmp_data[100];
  boolean_T outputs_f1_data[100];
  boolean_T tmp_data[100];
  if (A_size[1] == 0) {
    tf_size[0] = 1;
    tf_size[1] = 0;
  } else {
    double b_A_data[100];
    double outputs_f2_data[100];
    int b_A_size;
    boolean_T isnanA_data[100];
    boolean_T y;
    b_A_size = A_size[1];
    loop_ub = A_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_A_data[i] = -A_data[i];
    }
    for (i = 0; i < b_A_size; i++) {
      isnanA_data[i] = rtIsNaN(b_A_data[i]);
    }
    y = true;
    for (i = 0; i < b_A_size; i++) {
      y = (y && (!isnanA_data[i]));
    }
    if (!y) {
      double c_A_data[100];
      int trueCount;
      outputs_f1_size = A_size[1];
      memset(&outputs_f1_data[0], 0, b_A_size * sizeof(boolean_T));
      b_A_size = A_size[1] - 1;
      trueCount = 0;
      loop_ub = 0;
      for (i = 0; i <= b_A_size; i++) {
        y = !isnanA_data[i];
        isnanA_data[i] = y;
        if (y) {
          trueCount++;
          b_tmp_data[loop_ub] = (signed char)(i + 1);
          loop_ub++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        c_A_data[i] = b_A_data[b_tmp_data[i] - 1];
      }
      doLocalMaxSearch(c_A_data, trueCount, A_size[1], tmp_data, &tmp_size,
                       outputs_f2_data, &loop_ub);
      loop_ub = 0;
      for (i = 0; i <= b_A_size; i++) {
        if (isnanA_data[i]) {
          c_tmp_data[loop_ub] = (signed char)(i + 1);
          loop_ub++;
        }
      }
      for (i = 0; i < tmp_size; i++) {
        outputs_f1_data[c_tmp_data[i] - 1] = tmp_data[i];
      }
    } else {
      doLocalMaxSearch(b_A_data, A_size[1], A_size[1], outputs_f1_data,
                       &outputs_f1_size, outputs_f2_data, &loop_ub);
    }
    tf_size[0] = 1;
    tf_size[1] = outputs_f1_size;
    if (outputs_f1_size - 1 >= 0) {
      memcpy(&tf_data[0], &outputs_f1_data[0],
             outputs_f1_size * sizeof(boolean_T));
    }
  }
}

/*
 * File trailer for islocalmin.c
 *
 * [EOF]
 */
