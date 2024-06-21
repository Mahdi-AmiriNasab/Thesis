/*
 * File: calculate_overlap.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "calculate_overlap.h"
#include "find.h"
#include "isLocalExtrema.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>
  static double A_data[100];
  static double b_A_data[100];
  static double local_depths_data[100];
  static int peak_indices_data[100];
  static int valley_indices_data[100];
  static signed char b_tmp_data[100];
  static signed char c_tmp_data[100];
  static signed char d_tmp_data[100];
  static signed char e_tmp_data[100];
  static signed char f_tmp_data[100];
  static signed char tmp_data[100];
  static boolean_T isnanA_data[100];
  static boolean_T tf_data[100];

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
  double b_A_data[100];
  double local_depths_data[100];
  double u0;
  double u1;
  int peak_indices_data[100];
  int valley_indices_data[100];
  int is_peak_size[2];
  int valley_indices_size[2];
  int b_i;
  int c_i;
  int i;
  int i1;
  int i2;
  int isnanA_size;
  int local_depths_size_idx_1_tmp;
  int local_heights_size_idx_1_tmp;
  int loop_ub;
  int partialTrueCount;
  int peak_indices_size_idx_1;
  int tf_size;
  int trueCount;
  signed char b_tmp_data[100];
  signed char c_tmp_data[100];
  signed char d_tmp_data[100];
  signed char e_tmp_data[100];
  signed char f_tmp_data[100];
  signed char tmp_data[100];
  boolean_T isnanA_data[100];
  boolean_T tf_data[100];
  boolean_T y;
  /* 'calculate_overlap:4' is_peak = islocalmax(cell_values); */
  if (cell_values_size[1] == 0) {
    is_peak_size[0] = 1;
    is_peak_size[1] = 0;
  } else {
    loop_ub = cell_values_size[1];
    y = true;
    for (i = 0; i < loop_ub; i++) {
      u0 = cell_values_data[i];
      A_data[i] = u0;
      y = (y && (!rtIsNaN(u0)));
    }
    if (!y) {
      tf_size = cell_values_size[1];
      loop_ub = cell_values_size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        tf_data[b_i] = false;
        isnanA_data[b_i] = !rtIsNaN(A_data[b_i]);
      }
      loop_ub = cell_values_size[1] - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (isnanA_data[i]) {
          trueCount++;
          tmp_data[partialTrueCount] = (signed char)i;
          partialTrueCount++;
        }
      }
      for (b_i = 0; b_i < trueCount; b_i++) {
        b_A_data[b_i] = A_data[tmp_data[b_i]];
      }
      doLocalMaxSearch(b_A_data, trueCount, cell_values_size[1], isnanA_data,
                       local_depths_data, &loop_ub);
      for (b_i = 0; b_i < trueCount; b_i++) {
        tf_data[tmp_data[b_i]] = isnanA_data[b_i];
      }
    } else {
      tf_size =
          doLocalMaxSearch(A_data, cell_values_size[1], cell_values_size[1],
                           tf_data, local_depths_data, &loop_ub);
    }
    is_peak_size[0] = 1;
    is_peak_size[1] = tf_size;
    if (tf_size - 1 >= 0) {
      memcpy(&isnanA_data[0], &tf_data[0],
             (unsigned int)tf_size * sizeof(boolean_T));
    }
  }
  /* 'calculate_overlap:5' is_valley = islocalmin(cell_values); */
  /* 'calculate_overlap:7' peak_indices = find(is_peak); */
  c_eml_find(isnanA_data, is_peak_size, valley_indices_data,
             valley_indices_size);
  peak_indices_size_idx_1 = valley_indices_size[1];
  loop_ub = valley_indices_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&peak_indices_data[0], &valley_indices_data[0],
           (unsigned int)loop_ub * sizeof(int));
  }
  /* 'calculate_overlap:8' valley_indices = find(is_valley); */
  if (cell_values_size[1] == 0) {
    is_peak_size[0] = 1;
    is_peak_size[1] = 0;
  } else {
    isnanA_size = cell_values_size[1];
    loop_ub = cell_values_size[1];
    y = true;
    for (i = 0; i < loop_ub; i++) {
      u0 = -cell_values_data[i];
      A_data[i] = u0;
      y = (y && (!rtIsNaN(u0)));
    }
    if (!y) {
      tf_size = cell_values_size[1];
      for (b_i = 0; b_i < isnanA_size; b_i++) {
        tf_data[b_i] = false;
        isnanA_data[b_i] = !rtIsNaN(A_data[b_i]);
      }
      loop_ub = cell_values_size[1] - 1;
      trueCount = 0;
      partialTrueCount = 0;
      for (i = 0; i <= loop_ub; i++) {
        if (isnanA_data[i]) {
          trueCount++;
          b_tmp_data[partialTrueCount] = (signed char)i;
          partialTrueCount++;
        }
      }
      for (b_i = 0; b_i < trueCount; b_i++) {
        b_A_data[b_i] = A_data[b_tmp_data[b_i]];
      }
      doLocalMaxSearch(b_A_data, trueCount, cell_values_size[1], isnanA_data,
                       A_data, &loop_ub);
      for (b_i = 0; b_i < trueCount; b_i++) {
        tf_data[b_tmp_data[b_i]] = isnanA_data[b_i];
      }
    } else {
      tf_size =
          doLocalMaxSearch(A_data, cell_values_size[1], cell_values_size[1],
                           tf_data, local_depths_data, &loop_ub);
    }
    is_peak_size[0] = 1;
    is_peak_size[1] = tf_size;
    if (tf_size - 1 >= 0) {
      memcpy(&isnanA_data[0], &tf_data[0],
             (unsigned int)tf_size * sizeof(boolean_T));
    }
  }
  c_eml_find(isnanA_data, is_peak_size, valley_indices_data,
             valley_indices_size);
  /*  Calculate local heights of peaks */
  /* 'calculate_overlap:11' local_heights = zeros(size(peak_indices)); */
  local_heights_size_idx_1_tmp = (signed char)peak_indices_size_idx_1;
  if (local_heights_size_idx_1_tmp - 1 >= 0) {
    memset(&A_data[0], 0,
           (unsigned int)local_heights_size_idx_1_tmp * sizeof(double));
  }
  /* 'calculate_overlap:12' for i = 1:length(peak_indices) */
  for (i = 0; i < peak_indices_size_idx_1; i++) {
    /* 'calculate_overlap:13' left_valleys = valley_indices(valley_indices <
     * peak_indices(i)); */
    loop_ub = valley_indices_size[1] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    /* 'calculate_overlap:14' right_valleys = valley_indices(valley_indices >
     * peak_indices(i)); */
    isnanA_size = 0;
    tf_size = 0;
    for (c_i = 0; c_i <= loop_ub; c_i++) {
      b_i = valley_indices_data[c_i];
      i1 = peak_indices_data[i];
      if (b_i < i1) {
        trueCount++;
        c_tmp_data[partialTrueCount] = (signed char)c_i;
        partialTrueCount++;
      }
      if (b_i > i1) {
        isnanA_size++;
        d_tmp_data[tf_size] = (signed char)c_i;
        tf_size++;
      }
    }
    /* 'calculate_overlap:15' if isempty(left_valleys) */
    if (trueCount == 0) {
      /* 'calculate_overlap:16' left_min = cell_values(1); */
      u0 = cell_values_data[0];
    } else {
      /* 'calculate_overlap:17' else */
      /* 'calculate_overlap:18' left_min = cell_values(left_valleys(end)); */
      u0 = cell_values_data[valley_indices_data[c_tmp_data[trueCount - 1]] - 1];
    }
    /* 'calculate_overlap:20' if isempty(right_valleys) */
    if (isnanA_size == 0) {
      /* 'calculate_overlap:21' right_min = cell_values(end); */
      u1 = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:22' else */
      /* 'calculate_overlap:23' right_min = cell_values(right_valleys(1)); */
      u1 = cell_values_data[valley_indices_data[d_tmp_data[0]] - 1];
    }
    /* 'calculate_overlap:25' local_heights(i) = cell_values(peak_indices(i)) -
     * max(left_min, right_min); */
    if ((u0 >= u1) || rtIsNaN(u1)) {
      u1 = u0;
    }
    A_data[i] = cell_values_data[peak_indices_data[i] - 1] - u1;
  }
  /*  Calculate local depths of valleys */
  /* 'calculate_overlap:29' local_depths = zeros(size(valley_indices)); */
  local_depths_size_idx_1_tmp = (signed char)valley_indices_size[1];
  if (local_depths_size_idx_1_tmp - 1 >= 0) {
    memset(&local_depths_data[0], 0,
           (unsigned int)local_depths_size_idx_1_tmp * sizeof(double));
  }
  /* 'calculate_overlap:30' for i = 1:length(valley_indices) */
  b_i = valley_indices_size[1];
  for (i = 0; i < b_i; i++) {
    /* 'calculate_overlap:31' left_peaks = peak_indices(peak_indices <
     * valley_indices(i)); */
    loop_ub = peak_indices_size_idx_1 - 1;
    trueCount = 0;
    partialTrueCount = 0;
    /* 'calculate_overlap:32' right_peaks = peak_indices(peak_indices >
     * valley_indices(i)); */
    isnanA_size = 0;
    tf_size = 0;
    for (c_i = 0; c_i <= loop_ub; c_i++) {
      i1 = peak_indices_data[c_i];
      i2 = valley_indices_data[i];
      if (i1 < i2) {
        trueCount++;
        e_tmp_data[partialTrueCount] = (signed char)c_i;
        partialTrueCount++;
      }
      if (i1 > i2) {
        isnanA_size++;
        f_tmp_data[tf_size] = (signed char)c_i;
        tf_size++;
      }
    }
    /* 'calculate_overlap:33' if isempty(left_peaks) */
    if (trueCount == 0) {
      /* 'calculate_overlap:34' left_max = cell_values(1); */
      u0 = cell_values_data[0];
    } else {
      /* 'calculate_overlap:35' else */
      /* 'calculate_overlap:36' left_max = cell_values(left_peaks(end)); */
      u0 = cell_values_data[peak_indices_data[e_tmp_data[trueCount - 1]] - 1];
    }
    /* 'calculate_overlap:38' if isempty(right_peaks) */
    if (isnanA_size == 0) {
      /* 'calculate_overlap:39' right_max = cell_values(end); */
      u1 = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:40' else */
      /* 'calculate_overlap:41' right_max = cell_values(right_peaks(1)); */
      u1 = cell_values_data[peak_indices_data[f_tmp_data[0]] - 1];
    }
    /* 'calculate_overlap:43' local_depths(i) = min(left_max, right_max) -
     * cell_values(valley_indices(i)); */
    if ((u0 <= u1) || rtIsNaN(u1)) {
      u1 = u0;
    }
    local_depths_data[i] = u1 - cell_values_data[valley_indices_data[i] - 1];
  }
  /*  Calculate equalization overlap */
  /* 'calculate_overlap:47' equalization_overlap = sum(local_heights) +
   * sum(local_depths); */
  if ((signed char)peak_indices_size_idx_1 == 0) {
    u0 = 0.0;
  } else {
    u0 = A_data[0];
    for (loop_ub = 2; loop_ub <= local_heights_size_idx_1_tmp; loop_ub++) {
      u0 += A_data[loop_ub - 1];
    }
  }
  if ((signed char)valley_indices_size[1] == 0) {
    u1 = 0.0;
  } else {
    u1 = local_depths_data[0];
    for (loop_ub = 2; loop_ub <= local_depths_size_idx_1_tmp; loop_ub++) {
      u1 += local_depths_data[loop_ub - 1];
    }
  }
  return u0 + u1;
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
