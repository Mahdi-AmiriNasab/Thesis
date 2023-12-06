/*
 * File: balance_soc.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "balance_soc.h"
#include "log_clustering_emxutil.h"
#include "log_clustering_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * %% init
 *
 * Arguments    : const double cluster_clt_res_cell[81]
 *                const double cluster_clt_res_soc_av[18]
 *                double cluster_clt_max_count
 *                const double cluster_noise_max[2]
 *                const double cluster_noise_min[2]
 *                double soc_in[9]
 *                double *soc_transfered
 *                double *blc_time
 * Return Type  : void
 */
void balance_soc(const double cluster_clt_res_cell[81],
                 const double cluster_clt_res_soc_av[18],
                 double cluster_clt_max_count,
                 const double cluster_noise_max[2],
                 const double cluster_noise_min[2], double soc_in[9],
                 double *soc_transfered, double *blc_time)
{
  emxArray_real_T *y;
  double soc_sorted_clusters_data[18];
  double cluster_clt_res_cell_data[9];
  double destination_cells_data[9];
  double source_cells_data[9];
  double tmp_data[9];
  double destination_clt_idx_1;
  double destination_neighbor_lower_cell;
  double destination_neighbor_upper_cell;
  double soc_transfered_d;
  double soc_transfered_s;
  double source_clt_idx_1;
  double source_neighbor_lower_cell;
  double source_neighbor_upper_cell;
  double step_destination;
  double step_source;
  double *y_data;
  int cluster_clt_res_cell_size[2];
  int soc_sorted_clusters_size[2];
  int destination_clt_cnt;
  int i;
  int iindx;
  int k;
  int loop_ub;
  int snlc_validity;
  int snuc_validity;
  int soc_mismatch;
  int source_clt_cnt;
  boolean_T exitg1;
  *blc_time = 0.0;
  soc_transfered_s = 0.0;
  soc_transfered_d = 0.0;
  *soc_transfered = 0.0;
  /*  equalization steps storage */
  /*  [start_cell, stop_cell] */
  /*  [start_cell, stop_cell]        */
  /*  [src cluster average soc]   */
  /*  [des cluster average soc] */
  /*  validity of source/destination cluster neighbors (valid by default) */
  /*  conditional flag */
  soc_mismatch = 1;
  /*  valid balance range soc */
  /* blc_range = 2; */
  /*  assaign weight to each noise cluster by each cell in it */
  /*  number of elements in noise clusters */
  source_clt_cnt = 0;
  destination_clt_cnt = 0;
  for (k = 0; k < 9; k++) {
    if (cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * k) - 1] != 0.0) {
      source_clt_cnt++;
    }
    if (cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * k) - 1] != 0.0) {
      destination_clt_cnt++;
    }
  }
  /* 	%% define source and destination clusters */
  source_clt_idx_1 = cluster_noise_max[1];
  destination_clt_idx_1 = cluster_noise_min[1];
  /*  find neighbor cells of each source and destination cell */
  /*  source cluster neighbors */
  if (source_clt_cnt < 1) {
    loop_ub = 0;
  } else {
    loop_ub = source_clt_cnt;
  }
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    step_source = cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
    source_cells_data[i] = step_source;
    cluster_clt_res_cell_data[i] = step_source;
  }
  step_source = c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  source_neighbor_lower_cell =
      c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
  /*  the source cell must have a lower value neighbor */
  /*  check the validity of lower cell */
  if (step_source - 1.0 > 0.0) {
    snlc_validity =
        (soc_in[(int)(step_source - 1.0) - 1] < cluster_noise_max[1]);
  } else {
    snlc_validity = 0;
  }
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  step_source = c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  source_neighbor_upper_cell =
      c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  /*  check the validity of upper cell */
  if (step_source + 1.0 <= 9.0) {
    snuc_validity =
        (soc_in[(int)(step_source + 1.0) - 1] < cluster_noise_max[1]);
  } else {
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  emxInit_real_T(&y);
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /*  select a source cluster with valid neighbors */
    /*  sorting */
    snuc_validity = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (snlc_validity = 0; snlc_validity < snuc_validity; snlc_validity++) {
        soc_sorted_clusters_data[snlc_validity +
                                 (int)cluster_clt_max_count * i] =
            cluster_clt_res_soc_av[snlc_validity + 9 * i];
      }
    }
    b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
    /*  pick the maximum soc cluster regarding noise  */
    if (rtIsNaN(cluster_clt_max_count)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      y_data[0] = rtNaN;
    } else {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int)(cluster_clt_max_count - 1.0) + 1;
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      loop_ub = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    snlc_validity = y->size[1];
    if (y->size[1] <= 2) {
      if (y->size[1] == 1) {
        source_clt_idx_1 = soc_sorted_clusters_data[(int)y_data[0] - 1];
        iindx = 0;
      } else {
        i = (int)y_data[0] - 1;
        source_clt_idx_1 = soc_sorted_clusters_data[i];
        if ((source_clt_idx_1 <
             soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1]) ||
            (rtIsNaN(soc_sorted_clusters_data[i]) &&
             (!rtIsNaN(
                 soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1])))) {
          source_clt_idx_1 =
              soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1];
          iindx = y->size[1] - 1;
        } else {
          iindx = 0;
        }
      }
    } else {
      source_clt_idx_1 = soc_sorted_clusters_data[(int)y_data[0] - 1];
      if (!rtIsNaN(source_clt_idx_1)) {
        snuc_validity = 1;
      } else {
        snuc_validity = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= snlc_validity)) {
          if (!rtIsNaN(soc_sorted_clusters_data[(int)y_data[k - 1] - 1])) {
            snuc_validity = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (snuc_validity == 0) {
        iindx = 0;
      } else {
        source_clt_idx_1 =
            soc_sorted_clusters_data[(int)y_data[snuc_validity - 1] - 1];
        iindx = snuc_validity - 1;
        i = snuc_validity + 1;
        for (k = i; k <= snlc_validity; k++) {
          step_source = soc_sorted_clusters_data[(int)y_data[k - 1] - 1];
          if (source_clt_idx_1 < step_source) {
            source_clt_idx_1 = step_source;
            iindx = k - 1;
          }
        }
      }
    }
    /*  number of elements in the clusters */
    source_clt_cnt = 0;
    for (k = 0; k < 9; k++) {
      if (cluster_clt_res_cell[iindx + 9 * k] != 0.0) {
        source_clt_cnt++;
      }
    }
    /*  source cluster neighbors */
    if (source_clt_cnt < 1) {
      loop_ub = 0;
    } else {
      loop_ub = source_clt_cnt;
    }
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      step_source = cluster_clt_res_cell[iindx + 9 * i];
      source_cells_data[i] = step_source;
      cluster_clt_res_cell_data[i] = step_source;
    }
    source_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] = cluster_clt_res_cell[iindx + 9 * i];
    }
    source_neighbor_upper_cell =
        c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  } else {
    /*  we are good */
  }
  /*  destination cluster neighbors */
  if (destination_clt_cnt < 1) {
    k = 0;
  } else {
    k = destination_clt_cnt;
  }
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = k;
  for (i = 0; i < k; i++) {
    step_source = cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
    destination_cells_data[i] = step_source;
    cluster_clt_res_cell_data[i] = step_source;
  }
  step_source = c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = k;
  for (i = 0; i < k; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  destination_neighbor_lower_cell =
      c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
  /*  the destination cell must have a lower value neighbor */
  /*  check the validity of lower cell */
  if (step_source - 1.0 > 0.0) {
    snlc_validity =
        (soc_in[(int)(step_source - 1.0) - 1] > cluster_noise_min[1]);
  } else {
    snlc_validity = 0;
  }
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = k;
  for (i = 0; i < k; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  step_source = c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = k;
  for (i = 0; i < k; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  destination_neighbor_upper_cell =
      c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  /*  check the validity of upper cell */
  if (step_source + 1.0 <= 9.0) {
    snuc_validity =
        (soc_in[(int)(step_source + 1.0) - 1] > cluster_noise_min[1]);
  } else {
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /*  select a destination cluster with valid neighbors */
    /*  sorting */
    snuc_validity = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (snlc_validity = 0; snlc_validity < snuc_validity; snlc_validity++) {
        soc_sorted_clusters_data[snlc_validity +
                                 (int)cluster_clt_max_count * i] =
            cluster_clt_res_soc_av[snlc_validity + 9 * i];
      }
    }
    b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
    /*  pick the minimum soc cluster regarding noise  */
    if (rtIsNaN(cluster_clt_max_count)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      y_data[0] = rtNaN;
    } else {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int)(cluster_clt_max_count - 1.0) + 1;
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      k = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= k; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    snlc_validity = y->size[1];
    if (y->size[1] <= 2) {
      if (y->size[1] == 1) {
        destination_clt_idx_1 = soc_sorted_clusters_data[(int)y_data[0] - 1];
        iindx = 0;
      } else {
        i = (int)y_data[0] - 1;
        destination_clt_idx_1 = soc_sorted_clusters_data[i];
        if ((destination_clt_idx_1 >
             soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1]) ||
            (rtIsNaN(soc_sorted_clusters_data[i]) &&
             (!rtIsNaN(
                 soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1])))) {
          destination_clt_idx_1 =
              soc_sorted_clusters_data[(int)y_data[y->size[1] - 1] - 1];
          iindx = y->size[1] - 1;
        } else {
          iindx = 0;
        }
      }
    } else {
      destination_clt_idx_1 = soc_sorted_clusters_data[(int)y_data[0] - 1];
      if (!rtIsNaN(destination_clt_idx_1)) {
        snuc_validity = 1;
      } else {
        snuc_validity = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= snlc_validity)) {
          if (!rtIsNaN(soc_sorted_clusters_data[(int)y_data[k - 1] - 1])) {
            snuc_validity = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (snuc_validity == 0) {
        iindx = 0;
      } else {
        destination_clt_idx_1 =
            soc_sorted_clusters_data[(int)y_data[snuc_validity - 1] - 1];
        iindx = snuc_validity - 1;
        i = snuc_validity + 1;
        for (k = i; k <= snlc_validity; k++) {
          step_source = soc_sorted_clusters_data[(int)y_data[k - 1] - 1];
          if (destination_clt_idx_1 > step_source) {
            destination_clt_idx_1 = step_source;
            iindx = k - 1;
          }
        }
      }
    }
    /*  number of elements in the clusters */
    destination_clt_cnt = 0;
    for (k = 0; k < 9; k++) {
      if (cluster_clt_res_cell[iindx + 9 * k] != 0.0) {
        destination_clt_cnt++;
      }
    }
    /*  destination cluster neighbors */
    if (destination_clt_cnt < 1) {
      k = 0;
    } else {
      k = destination_clt_cnt;
    }
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = k;
    for (i = 0; i < k; i++) {
      step_source = cluster_clt_res_cell[iindx + 9 * i];
      destination_cells_data[i] = step_source;
      cluster_clt_res_cell_data[i] = step_source;
    }
    destination_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = k;
    for (i = 0; i < k; i++) {
      cluster_clt_res_cell_data[i] = cluster_clt_res_cell[iindx + 9 * i];
    }
    destination_neighbor_upper_cell =
        c_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  } else {
    /*  we are good */
  }
  emxFree_real_T(&y);
  /*  store source and destination clusters */
  /* 	%% calculate soc step to balance */
  /*  assign step = 1 to lower cluster member count */
  if (destination_clt_cnt < source_clt_cnt) {
    step_source = 0.5 / (double)source_clt_cnt * (double)destination_clt_cnt;
    step_destination = 0.5;
  } else {
    step_source = 0.5;
    step_destination =
        0.5 / (double)destination_clt_cnt * (double)source_clt_cnt;
  }
  /*  soc sweep initialization */
  /*  calculation for noise_max */
  /*  selecting maximum noise to calculate neighbor distances */
  /* 	%% equalizing */
  while (soc_mismatch != 0) {
    /*  % clustering */
    /*  [cluster] = pso_DBSCAN(soc_out, mp, ep); */
    /*  % sorting cluster.clt_res_soc_av  */
    /*  V = cluster.clt_res_soc_av; */
    /*  V(V(:,2)==0,2) = Inf; */
    /*  cluster.clt_res_soc_av = sortrows(V, 2,'ascend'); */
    /*  cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0; */
    /*  clear V */
    /*  soc sweep */
    source_clt_idx_1 -= step_source;
    destination_clt_idx_1 += step_destination;
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    if ((source_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)source_neighbor_lower_cell - 1] - source_clt_idx_1) <
         1.0)) {
      /*  subtract noise value and lower neighbor value */
      /*  if the differential is within the valid range */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    if ((source_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)source_neighbor_upper_cell - 1] - source_clt_idx_1) <
         1.0)) {
      /*  subtract noise value and lower neighbor value */
      /*  if the differential is within the valid range */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /*  store the target soc of neighbors */
    }
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    if ((destination_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)destination_neighbor_lower_cell - 1] -
              destination_clt_idx_1) < 1.0)) {
      /*  subtract noise value and lower neighbor value */
      /*  if the differential is within the valid range */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    if ((destination_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)destination_neighbor_upper_cell - 1] -
              destination_clt_idx_1) < 1.0)) {
      /*  subtract noise value and lower neighbor value */
      /*  if the differential is within the valid range */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /*  store the target soc of neighbors	 */
    }
    /*  transfer charges */
    /*  calculate amount of increment and decreament after each sweep */
    if (loop_ub - 1 >= 0) {
      memcpy(&tmp_data[0], &source_cells_data[0], loop_ub * sizeof(double));
    }
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] = soc_in[(int)tmp_data[i] - 1] - step_source;
    }
    for (i = 0; i < loop_ub; i++) {
      soc_in[(int)tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
    }
    if (k - 1 >= 0) {
      memcpy(&tmp_data[0], &destination_cells_data[0], k * sizeof(double));
    }
    for (i = 0; i < k; i++) {
      cluster_clt_res_cell_data[i] =
          soc_in[(int)tmp_data[i] - 1] + step_destination;
    }
    for (i = 0; i < k; i++) {
      soc_in[(int)tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
    }
    /*  increament/decreament soc calculation (both are equal) */
    soc_transfered_s += step_source * (double)source_clt_cnt;
    soc_transfered_d += step_destination * (double)destination_clt_cnt;
    /*  round to avoid unwanted mismatch */
    soc_transfered_s = rt_roundd_snf(soc_transfered_s * 100.0) / 100.0;
    soc_transfered_d = rt_roundd_snf(soc_transfered_d * 100.0) / 100.0;
    if (!(soc_transfered_s != soc_transfered_d)) {
      *soc_transfered = soc_transfered_s;
    }
    *blc_time = *soc_transfered / 100.0 * 2200.0 / 2000.0;
  }
}

/*
 * File trailer for balance_soc.c
 *
 * [EOF]
 */
