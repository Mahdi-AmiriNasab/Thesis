/*
 * File: calculate_overlap.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
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
 * global no_ovp_plot_flag;
 * if isempty(no_ovp_plot_flag)
 *  no_ovp_plot_flag = 0;
 * end
 *
 * Arguments    : const double cell_values_data[]
 *                const int cell_values_size[2]
 * Return Type  : double
 */
double calculate_overlap(const double cell_values_data[],
                         const int cell_values_size[2])
{
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
  static bool isnanA_data[100];
  static bool tf_data[100];
  double b_y;
  double x;
  int is_peak_size[2];
  int valley_indices_size[2];
  int b_i;
  int c_i;
  int i;
  int i1;
  int isnanA_size;
  int local_depths_size_idx_1_tmp;
  int local_heights_size_idx_1_tmp;
  int loop_ub;
  int partialTrueCount;
  int peak_indices_size_idx_1;
  int tf_size;
  int trueCount;
  bool y;
  /* 'calculate_overlap:8' no_ovp_plot_flag = 0; */
  /*  Find local maxima (peaks) and minima (valleys) */
  /* 'calculate_overlap:11' is_peak = islocalmax(cell_values); */
  if (cell_values_size[1] == 0) {
    is_peak_size[0] = 1;
    is_peak_size[1] = 0;
  } else {
    loop_ub = cell_values_size[1L];
    y = true;
    for (i = 0; i < loop_ub; i++) {
      x = cell_values_data[i];
      A_data[i] = x;
      y = (y && (!rtIsNaN(x)));
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
             (unsigned int)tf_size * sizeof(bool));
    }
  }
  /* 'calculate_overlap:12' is_valley = islocalmin(cell_values); */
  /* 'calculate_overlap:14' peak_indices = find(is_peak); */
  c_eml_find(isnanA_data, is_peak_size, valley_indices_data,
             valley_indices_size);
  peak_indices_size_idx_1 = valley_indices_size[1];
  loop_ub = valley_indices_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&peak_indices_data[0], &valley_indices_data[0],
           (unsigned int)loop_ub * sizeof(int));
  }
  /* 'calculate_overlap:15' valley_indices = find(is_valley); */
  if (cell_values_size[1] == 0) {
    is_peak_size[0] = 1;
    is_peak_size[1] = 0;
  } else {
    isnanA_size = cell_values_size[1];
    loop_ub = cell_values_size[1];
    y = true;
    for (i = 0; i < loop_ub; i++) {
      x = -cell_values_data[i];
      A_data[i] = x;
      y = (y && (!rtIsNaN(x)));
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
             (unsigned int)tf_size * sizeof(bool));
    }
  }
  c_eml_find(isnanA_data, is_peak_size, valley_indices_data,
             valley_indices_size);
  /*  Calculate local heights of peaks */
  /* 'calculate_overlap:18' local_heights = zeros(size(peak_indices)); */
  local_heights_size_idx_1_tmp = (signed char)peak_indices_size_idx_1;
  if (local_heights_size_idx_1_tmp - 1 >= 0) {
    memset(&A_data[0], 0,
           (unsigned int)local_heights_size_idx_1_tmp * sizeof(double));
  }
  /* 'calculate_overlap:19' for i = 1:length(peak_indices) */
  for (i = 0; i < peak_indices_size_idx_1; i++) {
    /* 'calculate_overlap:20' left_valleys = valley_indices(valley_indices <
     * peak_indices(i)); */
    loop_ub = valley_indices_size[1] - 1;
    trueCount = 0;
    partialTrueCount = 0;
    /* 'calculate_overlap:21' right_valleys = valley_indices(valley_indices >
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
    /* 'calculate_overlap:22' if isempty(left_valleys) */
    if (trueCount == 0) {
      /* 'calculate_overlap:23' left_min = cell_values(1); */
      x = cell_values_data[0];
    } else {
      /* 'calculate_overlap:24' else */
      /* 'calculate_overlap:25' left_min = cell_values(left_valleys(end)); */
      x = cell_values_data[valley_indices_data[c_tmp_data[trueCount - 1]] - 1];
    }
    /* 'calculate_overlap:27' if isempty(right_valleys) */
    if (isnanA_size == 0) {
      /* 'calculate_overlap:28' right_min = cell_values(end); */
      b_y = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:29' else */
      /* 'calculate_overlap:30' right_min = cell_values(right_valleys(1)); */
      b_y = cell_values_data[valley_indices_data[d_tmp_data[0]] - 1];
    }
    /* 'calculate_overlap:32' local_heights(i) = cell_values(peak_indices(i)) -
     * max(left_min, right_min); */
    A_data[i] = cell_values_data[peak_indices_data[i] - 1] - fmax(x, b_y);
  }
  /*  Calculate local depths of valleys */
  /* 'calculate_overlap:36' local_depths = zeros(size(valley_indices)); */
  local_depths_size_idx_1_tmp = (signed char)valley_indices_size[1];
  if (local_depths_size_idx_1_tmp - 1 >= 0) {
    memset(&local_depths_data[0], 0,
           (unsigned int)local_depths_size_idx_1_tmp * sizeof(double));
  }
  /* 'calculate_overlap:37' for i = 1:length(valley_indices) */
  b_i = valley_indices_size[1];
  for (i = 0; i < b_i; i++) {
    /* 'calculate_overlap:38' left_peaks = peak_indices(peak_indices <
     * valley_indices(i)); */
    loop_ub = peak_indices_size_idx_1 - 1;
    trueCount = 0;
    partialTrueCount = 0;
    /* 'calculate_overlap:39' right_peaks = peak_indices(peak_indices >
     * valley_indices(i)); */
    isnanA_size = 0;
    tf_size = 0;
    for (c_i = 0; c_i <= loop_ub; c_i++) {
      int i2;
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
    /* 'calculate_overlap:40' if isempty(left_peaks) */
    if (trueCount == 0) {
      /* 'calculate_overlap:41' left_max = cell_values(1); */
      x = cell_values_data[0];
    } else {
      /* 'calculate_overlap:42' else */
      /* 'calculate_overlap:43' left_max = cell_values(left_peaks(end)); */
      x = cell_values_data[peak_indices_data[e_tmp_data[trueCount - 1]] - 1];
    }
    /* 'calculate_overlap:45' if isempty(right_peaks) */
    if (isnanA_size == 0) {
      /* 'calculate_overlap:46' right_max = cell_values(end); */
      b_y = cell_values_data[cell_values_size[1] - 1];
    } else {
      /* 'calculate_overlap:47' else */
      /* 'calculate_overlap:48' right_max = cell_values(right_peaks(1)); */
      b_y = cell_values_data[peak_indices_data[f_tmp_data[0]] - 1];
    }
    /* 'calculate_overlap:50' local_depths(i) = min(left_max, right_max) -
     * cell_values(valley_indices(i)); */
    local_depths_data[i] =
        fmin(x, b_y) - cell_values_data[valley_indices_data[i] - 1];
  }
  /*  Calculate equalization overlap */
  /* 'calculate_overlap:54' equalization_overlap = sum(local_heights) +
   * sum(local_depths); */
  if ((signed char)peak_indices_size_idx_1 == 0) {
    b_y = 0.0;
  } else {
    b_y = A_data[0];
    for (loop_ub = 2; loop_ub <= local_heights_size_idx_1_tmp; loop_ub++) {
      b_y += A_data[loop_ub - 1];
    }
  }
  if ((signed char)valley_indices_size[1] == 0) {
    x = 0.0;
  } else {
    x = local_depths_data[0];
    for (loop_ub = 2; loop_ub <= local_depths_size_idx_1_tmp; loop_ub++) {
      x += local_depths_data[loop_ub - 1];
    }
  }
  return b_y + x;
  /*  Plot cell_values with peaks and valleys highlighted */
  /* 'calculate_overlap:57' if coder.target('MATLAB') */
}

/*
 * File trailer for calculate_overlap.c
 *
 * [EOF]
 */
