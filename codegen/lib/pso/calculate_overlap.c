/*
 * File: calculate_overlap.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "calculate_overlap.h"
#include "find.h"
#include "isLocalExtrema.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * function [equalization_overlap] = calculate_overlap(cell_values)
 *
 * Find local maxima (peaks) and minima (valleys)
 *
 * Arguments    : const double cell_values_data[]
 *                const int cell_values_size[2]
 * Return Type  : double
 */
double calculate_overlap(const double cell_values_data[],
                         const int cell_values_size[2])
{
  double A_data[100];
  double local_depths_data[100];
  double b_y;
  double x;
  int peak_indices_data[100];
  int valley_indices_data[100];
  int tf_size[2];
  int valley_indices_size[2];
  int A_size;
  int b_i;
  int i;
  int isnanA_size;
  int loop_ub;
  int outputs_f1_size;
  int partialTrueCount;
  int peak_indices_size_idx_1;
  int trueCount;
  signed char b_tmp_data[100];
  signed char c_tmp_data[100];
  signed char d_tmp_data[100];
  signed char e_tmp_data[100];
  signed char f_tmp_data[100];
  signed char g_tmp_data[100];
  signed char h_tmp_data[100];
  signed char i_tmp_data[100];
  boolean_T isnanA_data[100];
  boolean_T outputs_f1_data[100];
  boolean_T tmp_data[100];
  boolean_T y;
  /* 'calculate_overlap:4' is_peak = islocalmax(cell_values); */
  /* 'calculate_overlap:5' is_valley = islocalmin(cell_values); */
  /* 'calculate_overlap:7' peak_indices = find(is_peak); */
  if (cell_values_size[1] == 0) {
    tf_size[0] = 1;
    tf_size[1] = 0;
  } else {
    loop_ub = cell_values_size[1];
    memcpy(&A_data[0], &cell_values_data[0], loop_ub * sizeof(double));
    isnanA_size = cell_values_size[1];
    loop_ub = cell_values_size[1];
    for (i = 0; i < loop_ub; i++) {
      isnanA_data[i] = rtIsNaN(A_data[i]);
    }
    y = true;
    for (b_i = 0; b_i < isnanA_size; b_i++) {
      y = (y && (!isnanA_data[b_i]));
    }
    if (!y) {
      outputs_f1_size = cell_values_size[1];
      loop_ub = cell_values_size[1];
      memset(&outputs_f1_data[0], 0, loop_ub * sizeof(boolean_T));
      isnanA_size = cell_values_size[1] - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (b_i = 0; b_i <= isnanA_size; b_i++) {
        y = !isnanA_data[b_i];
        isnanA_data[b_i] = y;
        if (y) {
          trueCount++;
          b_tmp_data[partialTrueCount] = (signed char)(b_i + 1);
          partialTrueCount++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        local_depths_data[i] = A_data[b_tmp_data[i] - 1];
      }
      doLocalMaxSearch(local_depths_data, trueCount, cell_values_size[1],
                       tmp_data, &loop_ub, A_data, &A_size);
      partialTrueCount = 0;
      for (b_i = 0; b_i <= isnanA_size; b_i++) {
        if (isnanA_data[b_i]) {
          c_tmp_data[partialTrueCount] = (signed char)(b_i + 1);
          partialTrueCount++;
        }
      }
      for (i = 0; i < loop_ub; i++) {
        outputs_f1_data[c_tmp_data[i] - 1] = tmp_data[i];
      }
    } else {
      doLocalMaxSearch(A_data, cell_values_size[1], cell_values_size[1],
                       outputs_f1_data, &outputs_f1_size, local_depths_data,
                       &isnanA_size);
    }
    tf_size[0] = 1;
    tf_size[1] = outputs_f1_size;
    if (outputs_f1_size - 1 >= 0) {
      memcpy(&isnanA_data[0], &outputs_f1_data[0],
             outputs_f1_size * sizeof(boolean_T));
    }
  }
  c_eml_find(isnanA_data, tf_size, valley_indices_data, valley_indices_size);
  peak_indices_size_idx_1 = valley_indices_size[1];
  loop_ub = valley_indices_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&peak_indices_data[0], &valley_indices_data[0],
           loop_ub * sizeof(int));
  }
  /* 'calculate_overlap:8' valley_indices = find(is_valley); */
  if (cell_values_size[1] == 0) {
    tf_size[0] = 1;
    tf_size[1] = 0;
  } else {
    A_size = cell_values_size[1];
    loop_ub = cell_values_size[1];
    for (i = 0; i < loop_ub; i++) {
      A_data[i] = -cell_values_data[i];
    }
    for (i = 0; i < A_size; i++) {
      isnanA_data[i] = rtIsNaN(A_data[i]);
    }
    y = true;
    for (b_i = 0; b_i < A_size; b_i++) {
      y = (y && (!isnanA_data[b_i]));
    }
    if (!y) {
      outputs_f1_size = cell_values_size[1];
      memset(&outputs_f1_data[0], 0, A_size * sizeof(boolean_T));
      isnanA_size = cell_values_size[1] - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (b_i = 0; b_i <= isnanA_size; b_i++) {
        y = !isnanA_data[b_i];
        isnanA_data[b_i] = y;
        if (y) {
          trueCount++;
          d_tmp_data[partialTrueCount] = (signed char)(b_i + 1);
          partialTrueCount++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        local_depths_data[i] = A_data[d_tmp_data[i] - 1];
      }
      doLocalMaxSearch(local_depths_data, trueCount, cell_values_size[1],
                       tmp_data, &loop_ub, A_data, &A_size);
      partialTrueCount = 0;
      for (b_i = 0; b_i <= isnanA_size; b_i++) {
        if (isnanA_data[b_i]) {
          e_tmp_data[partialTrueCount] = (signed char)(b_i + 1);
          partialTrueCount++;
        }
      }
      for (i = 0; i < loop_ub; i++) {
        outputs_f1_data[e_tmp_data[i] - 1] = tmp_data[i];
      }
    } else {
      doLocalMaxSearch(A_data, cell_values_size[1], cell_values_size[1],
                       outputs_f1_data, &outputs_f1_size, local_depths_data,
                       &isnanA_size);
    }
    tf_size[0] = 1;
    tf_size[1] = outputs_f1_size;
    if (outputs_f1_size - 1 >= 0) {
      memcpy(&isnanA_data[0], &outputs_f1_data[0],
             outputs_f1_size * sizeof(boolean_T));
    }
  }
  c_eml_find(isnanA_data, tf_size, valley_indices_data, valley_indices_size);
  /*  Calculate local heights of peaks */
  /* 'calculate_overlap:11' local_heights = zeros(size(peak_indices)); */
  loop_ub = (signed char)peak_indices_size_idx_1;
  if (loop_ub - 1 >= 0) {
    memset(&A_data[0], 0, loop_ub * sizeof(double));
  }
  /* 'calculate_overlap:12' for i = 1:length(peak_indices) */
  for (b_i = 0; b_i < peak_indices_size_idx_1; b_i++) {
    /* 'calculate_overlap:13' left_valleys = valley_indices(valley_indices <
     * peak_indices(i)); */
    /* 'calculate_overlap:14' right_valleys = valley_indices(valley_indices >
     * peak_indices(i)); */
    /* 'calculate_overlap:15' if isempty(left_valleys) */
    isnanA_size = valley_indices_size[1];
    trueCount = 0;
    for (A_size = 0; A_size < isnanA_size; A_size++) {
      if (valley_indices_data[A_size] < peak_indices_data[b_i]) {
        trueCount++;
      }
    }
    if (trueCount == 0) {
      /* 'calculate_overlap:16' left_min = cell_values(1); */
      x = cell_values_data[0];
    } else {
      /* 'calculate_overlap:17' else */
      /* 'calculate_overlap:18' left_min = cell_values(left_valleys(end)); */
      isnanA_size = valley_indices_size[1] - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (A_size = 0; A_size <= isnanA_size; A_size++) {
        if (valley_indices_data[A_size] < peak_indices_data[b_i]) {
          trueCount++;
          f_tmp_data[partialTrueCount] = (signed char)(A_size + 1);
          partialTrueCount++;
        }
      }
      x = cell_values_data[valley_indices_data[f_tmp_data[trueCount - 1] - 1] -
                           1];
    }
    /* 'calculate_overlap:20' if isempty(right_valleys) */
    isnanA_size = valley_indices_size[1];
    trueCount = 0;
    for (A_size = 0; A_size < isnanA_size; A_size++) {
      if (valley_indices_data[A_size] > peak_indices_data[b_i]) {
        trueCount++;
      }
    }
    if (trueCount == 0) {
      /* 'calculate_overlap:21' right_min = cell_values(end); */
      b_y = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:22' else */
      /* 'calculate_overlap:23' right_min = cell_values(right_valleys(1)); */
      isnanA_size = valley_indices_size[1] - 1;
      partialTrueCount = 0;
      for (A_size = 0; A_size <= isnanA_size; A_size++) {
        if (valley_indices_data[A_size] > peak_indices_data[b_i]) {
          g_tmp_data[partialTrueCount] = (signed char)(A_size + 1);
          partialTrueCount++;
        }
      }
      b_y = cell_values_data[valley_indices_data[g_tmp_data[0] - 1] - 1];
    }
    /* 'calculate_overlap:25' local_heights(i) = cell_values(peak_indices(i)) -
     * max(left_min, right_min); */
    A_data[b_i] = cell_values_data[peak_indices_data[b_i] - 1] - fmax(x, b_y);
  }
  /*  Calculate local depths of valleys */
  /* 'calculate_overlap:29' local_depths = zeros(size(valley_indices)); */
  outputs_f1_size = (signed char)valley_indices_size[1];
  if (outputs_f1_size - 1 >= 0) {
    memset(&local_depths_data[0], 0, outputs_f1_size * sizeof(double));
  }
  /* 'calculate_overlap:30' for i = 1:length(valley_indices) */
  i = valley_indices_size[1];
  for (b_i = 0; b_i < i; b_i++) {
    /* 'calculate_overlap:31' left_peaks = peak_indices(peak_indices <
     * valley_indices(i)); */
    /* 'calculate_overlap:32' right_peaks = peak_indices(peak_indices >
     * valley_indices(i)); */
    /* 'calculate_overlap:33' if isempty(left_peaks) */
    trueCount = 0;
    for (A_size = 0; A_size < peak_indices_size_idx_1; A_size++) {
      if (peak_indices_data[A_size] < valley_indices_data[b_i]) {
        trueCount++;
      }
    }
    if (trueCount == 0) {
      /* 'calculate_overlap:34' left_max = cell_values(1); */
      x = cell_values_data[0];
    } else {
      /* 'calculate_overlap:35' else */
      /* 'calculate_overlap:36' left_max = cell_values(left_peaks(end)); */
      isnanA_size = peak_indices_size_idx_1 - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (A_size = 0; A_size <= isnanA_size; A_size++) {
        if (peak_indices_data[A_size] < valley_indices_data[b_i]) {
          trueCount++;
          h_tmp_data[partialTrueCount] = (signed char)(A_size + 1);
          partialTrueCount++;
        }
      }
      x = cell_values_data[peak_indices_data[h_tmp_data[trueCount - 1] - 1] -
                           1];
    }
    /* 'calculate_overlap:38' if isempty(right_peaks) */
    trueCount = 0;
    for (A_size = 0; A_size < peak_indices_size_idx_1; A_size++) {
      if (peak_indices_data[A_size] > valley_indices_data[b_i]) {
        trueCount++;
      }
    }
    if (trueCount == 0) {
      /* 'calculate_overlap:39' right_max = cell_values(end); */
      b_y = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:40' else */
      /* 'calculate_overlap:41' right_max = cell_values(right_peaks(1)); */
      isnanA_size = peak_indices_size_idx_1 - 1;
      partialTrueCount = 0;
      for (A_size = 0; A_size <= isnanA_size; A_size++) {
        if (peak_indices_data[A_size] > valley_indices_data[b_i]) {
          i_tmp_data[partialTrueCount] = (signed char)(A_size + 1);
          partialTrueCount++;
        }
      }
      b_y = cell_values_data[peak_indices_data[i_tmp_data[0] - 1] - 1];
    }
    /* 'calculate_overlap:43' local_depths(i) = min(left_max, right_max) -
     * cell_values(valley_indices(i)); */
    local_depths_data[b_i] =
        fmin(x, b_y) - cell_values_data[valley_indices_data[b_i] - 1];
  }
  /*  Calculate equalization overlap */
  /* 'calculate_overlap:47' equalization_overlap = sum(local_heights) +
   * sum(local_depths); */
  if ((signed char)peak_indices_size_idx_1 == 0) {
    b_y = 0.0;
  } else {
    b_y = A_data[0];
    for (isnanA_size = 2; isnanA_size <= loop_ub; isnanA_size++) {
      b_y += A_data[isnanA_size - 1];
    }
  }
  if ((signed char)valley_indices_size[1] == 0) {
    x = 0.0;
  } else {
    x = local_depths_data[0];
    for (isnanA_size = 2; isnanA_size <= outputs_f1_size; isnanA_size++) {
      x += local_depths_data[isnanA_size - 1];
    }
  }
  return b_y + x;
  /*  Plot cell_values with peaks and valleys highlighted */
  /*  plot(cell_values) */
  /*  hold on */
  /*  plot(peak_indices, cell_values(peak_indices), 'ro') */
  /*  plot(valley_indices, cell_values(valley_indices), 'bo') */
  /*  hold off */
}

/*
 * File trailer for calculate_overlap.c
 *
 * [EOF]
 */
