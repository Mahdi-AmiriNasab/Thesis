/*
 * File: islocalmax.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "islocalmax.h"
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
void islocalmax(const double A_data[], const int A_size[2], boolean_T tf_data[],
                int tf_size[2])
{
  double tmp_data[100];
  int i;
  int loop_ub;
  int outputs_f1_size;
  int tmp_size;
  signed char c_tmp_data[100];
  signed char d_tmp_data[100];
  boolean_T b_tmp_data[100];
  boolean_T outputs_f1_data[100];
  if (A_size[1] == 0) {
    tf_size[0] = 1;
    tf_size[1] = 0;
  } else {
    double outputs_f2_data[100];
    int isnanA_size;
    boolean_T isnanA_data[100];
    boolean_T y;
    loop_ub = A_size[1];
    memcpy(&tmp_data[0], &A_data[0], loop_ub * sizeof(double));
    isnanA_size = A_size[1];
    loop_ub = A_size[1];
    for (i = 0; i < loop_ub; i++) {
      isnanA_data[i] = rtIsNaN(tmp_data[i]);
    }
    y = true;
    for (i = 0; i < isnanA_size; i++) {
      y = (y && (!isnanA_data[i]));
    }
    if (!y) {
      int trueCount;
      outputs_f1_size = A_size[1];
      loop_ub = A_size[1];
      memset(&outputs_f1_data[0], 0, loop_ub * sizeof(boolean_T));
      isnanA_size = A_size[1] - 1;
      trueCount = 0;
      loop_ub = 0;
      for (i = 0; i <= isnanA_size; i++) {
        y = !isnanA_data[i];
        isnanA_data[i] = y;
        if (y) {
          trueCount++;
          c_tmp_data[loop_ub] = (signed char)(i + 1);
          loop_ub++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        outputs_f2_data[i] = tmp_data[c_tmp_data[i] - 1];
      }
      doLocalMaxSearch(outputs_f2_data, trueCount, A_size[1], b_tmp_data,
                       &tmp_size, tmp_data, &loop_ub);
      loop_ub = 0;
      for (i = 0; i <= isnanA_size; i++) {
        if (isnanA_data[i]) {
          d_tmp_data[loop_ub] = (signed char)(i + 1);
          loop_ub++;
        }
      }
      for (i = 0; i < tmp_size; i++) {
        outputs_f1_data[d_tmp_data[i] - 1] = b_tmp_data[i];
      }
    } else {
      doLocalMaxSearch(tmp_data, A_size[1], A_size[1], outputs_f1_data,
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
 * File trailer for islocalmax.c
 *
 * [EOF]
 */
