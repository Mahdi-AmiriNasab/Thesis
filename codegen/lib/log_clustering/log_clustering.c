/*
 * File: log_clustering.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "log_clustering.h"
#include "balance_soc.h"
#include "find.h"
#include "islocalmax.h"
#include "islocalmin.h"
#include "log_clustering_internal_types.h"
#include "minOrMax.h"
#include "pso_DBSCAN.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double ep_arr
 *                double *lg_time
 *                double *lg_inconsistency
 *                double *lg_eq_overlap
 * Return Type  : void
 */
void log_clustering(const double soc_in[9], double mp, double ep_arr,
                    double *lg_time, double *lg_inconsistency,
                    double *lg_eq_overlap)
{
  double soc_profile_data[900];
  double local_depths_data[100];
  double local_heights_data[100];
  double c_expl_temp[81];
  double cluster_clt_res_cell[81];
  double V[18];
  double d_expl_temp[18];
  double e_expl_temp[18];
  double b_expl_temp[9];
  double soc[9];
  double cluster_noise_max[2];
  double cluster_noise_min[2];
  double f_expl_temp[2];
  double OE;
  double blc_time;
  double blc_time_total;
  double cluster_clt_max_count;
  double expl_temp;
  int peak_indices_data[100];
  int valley_indices_data[100];
  int local_heights_size[2];
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int itteration;
  int loop_ub;
  int n;
  int partialTrueCount;
  signed char c_tmp_data[100];
  signed char d_tmp_data[100];
  signed char e_tmp_data[100];
  signed char f_tmp_data[100];
  signed char b_tmp_data[9];
  signed char tmp_data[9];
  boolean_T b_data[900];
  boolean_T y_data[100];
  boolean_T b;
  boolean_T exitg1;
  e_noise_stat g_expl_temp;
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  for (i = 0; i < 900; i++) {
    soc_profile_data[i] = rtNaN;
  }
  *lg_eq_overlap = 0.0;
  itteration = 0;
  blc_time_total = 0.0;
  for (i = 0; i < 9; i++) {
    expl_temp = soc_in[i];
    soc[i] = expl_temp;
    soc_profile_data[100 * i] = expl_temp;
  }
  /*  clustering */
  pso_DBSCAN(soc_in, mp, ep_arr, &expl_temp, &OE, b_expl_temp,
             cluster_clt_res_cell, c_expl_temp, V, &cluster_clt_max_count,
             d_expl_temp, e_expl_temp, cluster_noise_max, cluster_noise_min,
             f_expl_temp, &g_expl_temp);
  exitg1 = false;
  while ((!exitg1) && (cluster_clt_max_count > 1.0)) {
    /*  balancing */
    balance_soc(cluster_clt_res_cell, V, cluster_clt_max_count,
                cluster_noise_max, cluster_noise_min, soc, &OE, &blc_time);
    /*  store charge profile */
    for (i = 0; i < 9; i++) {
      soc_profile_data[(itteration + 100 * i) + 1] = soc[i];
    }
    /*  clustering */
    pso_DBSCAN(soc, mp, ep_arr, &expl_temp, &OE, b_expl_temp,
               cluster_clt_res_cell, c_expl_temp, V, &cluster_clt_max_count,
               d_expl_temp, e_expl_temp, cluster_noise_max, cluster_noise_min,
               f_expl_temp, &g_expl_temp);
    itteration++;
    /*  sorting cluster.clt_res_soc_av  */
    i2 = 0;
    partialTrueCount = 0;
    for (b_i = 0; b_i < 9; b_i++) {
      b = (V[b_i + 9] == 0.0);
      if (b) {
        i2++;
        tmp_data[partialTrueCount] = (signed char)(b_i + 1);
        partialTrueCount++;
      }
    }
    for (i = 0; i < i2; i++) {
      V[tmp_data[i] + 8] = rtInf;
    }
    c_sortrows(V);
    i2 = 0;
    partialTrueCount = 0;
    for (b_i = 0; b_i < 9; b_i++) {
      b = (V[b_i + 9] == rtInf);
      if (b) {
        i2++;
        b_tmp_data[partialTrueCount] = (signed char)(b_i + 1);
        partialTrueCount++;
      }
    }
    for (i = 0; i < i2; i++) {
      V[b_tmp_data[i] + 8] = 0.0;
    }
    blc_time_total += blc_time;
    if (itteration > 20) {
      /*  error("maximum itteration reached"); */
      /*  disp("maximum itteration reached"); */
      exitg1 = true;
    }
  }
  for (i = 0; i < 900; i++) {
    b_data[i] = rtIsNaN(soc_profile_data[i]);
  }
  i1 = 0;
  i2 = 800;
  n = 0;
  b_i = 0;
  for (partialTrueCount = 0; partialTrueCount < 100; partialTrueCount++) {
    y_data[partialTrueCount] = false;
    i1++;
    i2++;
    itteration = i1;
    exitg1 = false;
    while ((!exitg1) && (itteration <= i2)) {
      if (b_data[itteration - 1]) {
        y_data[partialTrueCount] = true;
        exitg1 = true;
      } else {
        itteration += 100;
      }
    }
    b = y_data[partialTrueCount];
    n += b;
    if (!b) {
      for (itteration = 0; itteration < 9; itteration++) {
        soc_profile_data[b_i + 100 * itteration] =
            soc_profile_data[partialTrueCount + 100 * itteration];
      }
      b_i++;
    }
  }
  if (100 - n < 1) {
    loop_ub = 0;
  } else {
    loop_ub = 100 - n;
  }
  for (i = 0; i < 9; i++) {
    for (itteration = 0; itteration < loop_ub; itteration++) {
      soc_profile_data[itteration + loop_ub * i] =
          soc_profile_data[itteration + 100 * i];
    }
  }
  /*  Remove any row with NaN */
  if (ep_arr == ep_arr) {
    itteration = 1;
    i1 = 1;
  } else {
    itteration = 0;
    i1 = 0;
  }
  expl_temp = 0.0;
  i2 = itteration * i1;
  for (i = 0; i < i2; i++) {
    expl_temp = blc_time_total;
  }
  *lg_time = expl_temp;
  *lg_inconsistency = 0.0;
  OE = d_maximum(soc);
  expl_temp = d_minimum(soc);
  for (i = 0; i < i2; i++) {
    *lg_inconsistency = OE - expl_temp;
  }
  /*  summing equalization overlap value of each cell after balancing  */
  b_loop_ub = (signed char)itteration * (signed char)i1;
  for (n = 0; n < 9; n++) {
    int tmp_size[2];
    int valley_indices_size[2];
    int c_loop_ub;
    int local_depths_size_idx_1_tmp;
    /*  Find local maxima (peaks) and minima (valleys) */
    local_heights_size[0] = 1;
    local_heights_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      local_heights_data[i] = soc_profile_data[i + loop_ub * n];
    }
    islocalmax(local_heights_data, local_heights_size, y_data, tmp_size);
    c_eml_find(y_data, tmp_size, valley_indices_data, valley_indices_size);
    c_loop_ub = valley_indices_size[1];
    if (c_loop_ub - 1 >= 0) {
      memcpy(&peak_indices_data[0], &valley_indices_data[0],
             c_loop_ub * sizeof(int));
    }
    local_heights_size[0] = 1;
    local_heights_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      local_heights_data[i] = soc_profile_data[i + loop_ub * n];
    }
    islocalmin(local_heights_data, local_heights_size, y_data, tmp_size);
    c_eml_find(y_data, tmp_size, valley_indices_data, valley_indices_size);
    /*  Calculate local heights of peaks */
    itteration = (signed char)c_loop_ub;
    if (itteration - 1 >= 0) {
      memset(&local_heights_data[0], 0, itteration * sizeof(double));
    }
    for (b_i = 0; b_i < c_loop_ub; b_i++) {
      itteration = valley_indices_size[1];
      i2 = 0;
      for (i1 = 0; i1 < itteration; i1++) {
        if (valley_indices_data[i1] < peak_indices_data[b_i]) {
          i2++;
        }
      }
      if (i2 == 0) {
        OE = soc_profile_data[loop_ub * n];
      } else {
        itteration = valley_indices_size[1] - 1;
        i2 = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (valley_indices_data[i1] < peak_indices_data[b_i]) {
            i2++;
          }
        }
        partialTrueCount = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (valley_indices_data[i1] < peak_indices_data[b_i]) {
            c_tmp_data[partialTrueCount] = (signed char)(i1 + 1);
            partialTrueCount++;
          }
        }
        OE = soc_profile_data[(valley_indices_data[c_tmp_data[i2 - 1] - 1] +
                               loop_ub * n) -
                              1];
      }
      itteration = valley_indices_size[1];
      i2 = 0;
      for (i1 = 0; i1 < itteration; i1++) {
        if (valley_indices_data[i1] > peak_indices_data[b_i]) {
          i2++;
        }
      }
      if (i2 == 0) {
        expl_temp = soc_profile_data[(loop_ub + loop_ub * n) - 1];
      } else {
        itteration = valley_indices_size[1] - 1;
        partialTrueCount = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (valley_indices_data[i1] > peak_indices_data[b_i]) {
            d_tmp_data[partialTrueCount] = (signed char)(i1 + 1);
            partialTrueCount++;
          }
        }
        expl_temp = soc_profile_data[(valley_indices_data[d_tmp_data[0] - 1] +
                                      loop_ub * n) -
                                     1];
      }
      local_heights_data[b_i] =
          soc_profile_data[(peak_indices_data[b_i] + loop_ub * n) - 1] -
          fmax(OE, expl_temp);
    }
    /*  Calculate local depths of valleys */
    local_depths_size_idx_1_tmp = (signed char)valley_indices_size[1];
    if (local_depths_size_idx_1_tmp - 1 >= 0) {
      memset(&local_depths_data[0], 0,
             local_depths_size_idx_1_tmp * sizeof(double));
    }
    i = valley_indices_size[1];
    for (b_i = 0; b_i < i; b_i++) {
      i2 = 0;
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        if (peak_indices_data[i1] < valley_indices_data[b_i]) {
          i2++;
        }
      }
      if (i2 == 0) {
        OE = soc_profile_data[loop_ub * n];
      } else {
        itteration = c_loop_ub - 1;
        i2 = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (peak_indices_data[i1] < valley_indices_data[b_i]) {
            i2++;
          }
        }
        partialTrueCount = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (peak_indices_data[i1] < valley_indices_data[b_i]) {
            e_tmp_data[partialTrueCount] = (signed char)(i1 + 1);
            partialTrueCount++;
          }
        }
        OE = soc_profile_data[(peak_indices_data[e_tmp_data[i2 - 1] - 1] +
                               loop_ub * n) -
                              1];
      }
      i2 = 0;
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        if (peak_indices_data[i1] > valley_indices_data[b_i]) {
          i2++;
        }
      }
      if (i2 == 0) {
        expl_temp = soc_profile_data[(loop_ub + loop_ub * n) - 1];
      } else {
        itteration = c_loop_ub - 1;
        partialTrueCount = 0;
        for (i1 = 0; i1 <= itteration; i1++) {
          if (peak_indices_data[i1] > valley_indices_data[b_i]) {
            f_tmp_data[partialTrueCount] = (signed char)(i1 + 1);
            partialTrueCount++;
          }
        }
        expl_temp = soc_profile_data[(peak_indices_data[f_tmp_data[0] - 1] +
                                      loop_ub * n) -
                                     1];
      }
      local_depths_data[b_i] =
          fmin(OE, expl_temp) -
          soc_profile_data[(valley_indices_data[b_i] + loop_ub * n) - 1];
    }
    /*  Calculate equalization overlap */
    i1 = (signed char)c_loop_ub;
    if ((signed char)c_loop_ub == 0) {
      expl_temp = 0.0;
    } else {
      expl_temp = local_heights_data[0];
      for (itteration = 2; itteration <= i1; itteration++) {
        expl_temp += local_heights_data[itteration - 1];
      }
    }
    if ((signed char)valley_indices_size[1] == 0) {
      OE = 0.0;
    } else {
      OE = local_depths_data[0];
      for (itteration = 2; itteration <= local_depths_size_idx_1_tmp;
           itteration++) {
        OE += local_depths_data[itteration - 1];
      }
    }
    OE += expl_temp;
    /*  Plot cell_values with peaks and valleys highlighted */
    /*  plot(cell_values) */
    /*  hold on */
    /*  plot(peak_indices, cell_values(peak_indices), 'ro') */
    /*  plot(valley_indices, cell_values(valley_indices), 'bo') */
    /*  hold off */
    expl_temp = *lg_eq_overlap;
    for (i = 0; i < b_loop_ub; i++) {
      expl_temp = *lg_eq_overlap + OE;
    }
    *lg_eq_overlap = expl_temp;
  }
  /*  Create a 2x1 grid layout */
}

/*
 * File trailer for log_clustering.c
 *
 * [EOF]
 */
