/*
 * File: balance_soc.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "balance_soc.h"
#include "minOrMax.h"
#include "pso_emxutil.h"
#include "pso_rtwutil.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * function [soc_transfered, soc_out, blc_time, eq_step] = balance_soc(cluster,
 * soc_in, mp, ep, capacity, blc_current)
 *
 * %% init
 *
 * Arguments    : const double cluster_clt_res_cell[81]
 *                const double cluster_clt_res_soc_av[18]
 *                double cluster_clt_max_count
 *                const double cluster_noise_max[2]
 *                const double cluster_noise_min[2]
 *                double soc_in[9]
 *                double ep
 *                double *blc_time
 *                double eq_step_source_queue_cells[2]
 *                double eq_step_destination_queue_cells[2]
 *                double *eq_step_source_target_soc_av
 *                double *c_eq_step_destination_target_so
 * Return Type  : double
 */
double balance_soc(const double cluster_clt_res_cell[81],
                   const double cluster_clt_res_soc_av[18],
                   double cluster_clt_max_count,
                   const double cluster_noise_max[2],
                   const double cluster_noise_min[2], double soc_in[9],
                   double ep, double *blc_time,
                   double eq_step_source_queue_cells[2],
                   double eq_step_destination_queue_cells[2],
                   double *eq_step_source_target_soc_av,
                   double *c_eq_step_destination_target_so)
{
  static double soc_sorted_clusters_data[18];
  static double destination_cells_data[9];
  static double soc_in_data[9];
  static double source_cells_data[9];
  emxArray_real_T *varargin_1;
  emxArray_real_T *y;
  double destination_clt_idx_1;
  double destination_neighbor_lower_cell;
  double destination_neighbor_upper_cell;
  double soc_diff_d;
  double soc_diff_s;
  double soc_transfered;
  double soc_transfered_d;
  double soc_transfered_s;
  double source_clt_idx_1;
  double source_neighbor_lower_cell;
  double source_neighbor_upper_cell;
  double step_destination;
  double step_source;
  double *varargin_1_data;
  double *y_data;
  int destination_cells_size[2];
  int soc_sorted_clusters_size[2];
  int source_cells_size[2];
  int destination_clt_cnt;
  int i;
  int snlc_validity;
  int snuc_validity;
  int soc_mismatch;
  int source_clt_cnt;
  /* 'balance_soc:4' blc_time = 0; */
  /* 'balance_soc:5' blc_range = ep; */
  /* 'balance_soc:6' soc_out = soc_in; */
  /* 'balance_soc:7' soc_transfered_s = 0; */
  soc_transfered_s = 0.0;
  /* 'balance_soc:7' soc_transfered_d = 0; */
  soc_transfered_d = 0.0;
  /* 'balance_soc:8' soc_transfered = 0; */
  soc_transfered = 0.0;
  /* 'balance_soc:9' cell_count = length(soc_in); */
  /*  equalization steps storage */
  /* 'balance_soc:12' eq_step.source_queue_cells = [0, 0]; */
  /*  [start_cell, stop_cell] */
  /* 'balance_soc:14' eq_step.destination_queue_cells = [0, 0]; */
  /*  [start_cell, stop_cell]        */
  /* 'balance_soc:16' eq_step.source_target_soc_av = 0; */
  *eq_step_source_target_soc_av = 0.0;
  /*  [src cluster average soc]   */
  /* 'balance_soc:18' eq_step.destination_target_soc_av = 0; */
  *c_eq_step_destination_target_so = 0.0;
  /*  [des cluster average soc] */
  /* 'balance_soc:20' soc_diff_s = 0; */
  soc_diff_s = 0.0;
  /*  Initialize soc_diff_s */
  /* 'balance_soc:21' soc_diff_d = 0; */
  soc_diff_d = 0.0;
  /*  Initialize soc_diff_d */
  /*  validity of source/destination cluster neighbors (valid by default) */
  /* 'balance_soc:24' snlc_validity = 1; */
  /* 'balance_soc:25' snuc_validity = 1; */
  /* 'balance_soc:27' dnlc_validity = 1; */
  /* 'balance_soc:28' dnuc_validity = 1; */
  /*  conditional flag */
  /* 'balance_soc:31' soc_mismatch = 1; */
  soc_mismatch = 1;
  /*  valid balance range soc */
  /* blc_range = 2; */
  /*  assaign weight to each noise cluster by each cell in it */
  /*  number of elements in noise clusters */
  /* 'balance_soc:38' source_clt_cnt =
   * nnz(cluster.clt_res_cell(cluster.noise_max(1, 1), :)); */
  source_clt_cnt = 0;
  /* 'balance_soc:39' destination_clt_cnt =
   * nnz(cluster.clt_res_cell(cluster.noise_min(1, 1), :)); */
  destination_clt_cnt = 0;
  for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
    if (cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * snuc_validity) -
                             1] != 0.0) {
      source_clt_cnt++;
    }
    if (cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * snuc_validity) -
                             1] != 0.0) {
      destination_clt_cnt++;
    }
  }
  /* 	%% define source and destination clusters */
  /* 'balance_soc:42' source_clt = cluster.noise_max; */
  /* 'balance_soc:43' destination_clt = cluster.noise_min; */
  source_clt_idx_1 = cluster_noise_max[1];
  destination_clt_idx_1 = cluster_noise_min[1];
  /*  find neighbor cells of each source and destination cell */
  /*  source cluster neighbors */
  /* 'balance_soc:47' source_cells = cluster.clt_res_cell(source_clt(1, 1),
   * 1:source_clt_cnt); */
  source_cells_size[0] = 1;
  source_cells_size[1] = source_clt_cnt;
  for (i = 0; i < source_clt_cnt; i++) {
    source_cells_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  /* 'balance_soc:49' source_neighbor_lower_cell = min(source_cells) - 1; */
  step_source = c_minimum(source_cells_data, source_cells_size);
  source_neighbor_lower_cell = step_source - 1.0;
  /*  the source cell must have a lower value neighbor */
  /*  check the validity of lower cell */
  /* 'balance_soc:53' if source_neighbor_lower_cell  > 0 */
  if (step_source - 1.0 > 0.0) {
    /* 'balance_soc:54' if soc_out(1, source_neighbor_lower_cell) < source_clt(2
     * ,1) */
    if (soc_in[(int)(step_source - 1.0) - 1] < cluster_noise_max[1]) {
      /* 'balance_soc:55' snlc_validity = 1; */
      snlc_validity = 1;
    } else {
      /* 'balance_soc:56' else */
      /* 'balance_soc:57' snlc_validity = 0; */
      snlc_validity = 0;
    }
  } else {
    /* 'balance_soc:59' else */
    /* 'balance_soc:60' snlc_validity = 0; */
    snlc_validity = 0;
  }
  /* 'balance_soc:63' source_neighbor_upper_cell = max(source_cells) + 1; */
  step_source = d_maximum(source_cells_data, source_cells_size);
  source_neighbor_upper_cell = step_source + 1.0;
  /*  check the validity of upper cell */
  /* 'balance_soc:66' if source_neighbor_upper_cell <= cell_count */
  if (step_source + 1.0 <= 9.0) {
    /* 'balance_soc:67' if soc_out(1, source_neighbor_upper_cell) < source_clt(2
     * ,1) */
    if (soc_in[(int)(step_source + 1.0) - 1] < cluster_noise_max[1]) {
      /* 'balance_soc:68' snuc_validity = 1; */
      snuc_validity = 1;
    } else {
      /* 'balance_soc:69' else */
      /* 'balance_soc:70' snuc_validity = 0; */
      snuc_validity = 0;
    }
  } else {
    /* 'balance_soc:72' else */
    /* 'balance_soc:73' snuc_validity = 0; */
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  /* 'balance_soc:77' if snlc_validity || snuc_validity */
  emxInit_real_T(&y, 2);
  emxInit_real_T(&varargin_1, 1);
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /* 'balance_soc:79' else */
    /*  select a source cluster with valid neighbors */
    /*  sorting */
    /* 'balance_soc:83' soc_sorted_clusters =
     * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
     */
    snlc_validity = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (snuc_validity = 0; snuc_validity < snlc_validity; snuc_validity++) {
        soc_sorted_clusters_data[snuc_validity +
                                 (int)cluster_clt_max_count * i] =
            cluster_clt_res_soc_av[snuc_validity + 9 * i];
      }
    }
    b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
    /*  pick the maximum soc cluster regarding noise  */
    /* 'balance_soc:85' [source_clt(2, 1), source_clt(1, 1)] =
     * max(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
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
      snlc_validity = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= snlc_validity; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    i = varargin_1->size[0];
    varargin_1->size[0] = y->size[1L];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    snlc_validity = y->size[1L];
    for (i = 0; i < snlc_validity; i++) {
      varargin_1_data[i] = soc_sorted_clusters_data[(int)y_data[i] - 1];
    }
    source_clt_idx_1 = e_maximum(varargin_1, &snlc_validity);
    /*  number of elements in the clusters */
    /* 'balance_soc:88' source_clt_cnt = nnz(cluster.clt_res_cell(source_clt(1,
     * 1), :)); */
    source_clt_cnt = 0;
    for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
      if (cluster_clt_res_cell[(snlc_validity + 9 * snuc_validity) - 1] !=
          0.0) {
        source_clt_cnt++;
      }
    }
    /*  source cluster neighbors */
    /* 'balance_soc:91' source_cells = cluster.clt_res_cell(source_clt(1, 1),
     * 1:source_clt_cnt); */
    source_cells_size[0] = 1;
    source_cells_size[1] = source_clt_cnt;
    for (i = 0; i < source_clt_cnt; i++) {
      source_cells_data[i] = cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
    }
    /* 'balance_soc:92' source_neighbor_lower_cell = min(source_cells) - 1; */
    source_neighbor_lower_cell =
        c_minimum(source_cells_data, source_cells_size) - 1.0;
    /* 'balance_soc:93' source_neighbor_upper_cell = max(source_cells) + 1; */
    source_neighbor_upper_cell =
        d_maximum(source_cells_data, source_cells_size) + 1.0;
  } else {
    /*  we are good */
  }
  /*  destination cluster neighbors */
  /* 'balance_soc:98' destination_cells =
   * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
  destination_cells_size[0] = 1;
  destination_cells_size[1] = destination_clt_cnt;
  for (i = 0; i < destination_clt_cnt; i++) {
    destination_cells_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  /* 'balance_soc:100' destination_neighbor_lower_cell = min(destination_cells)
   * - 1; */
  step_source = c_minimum(destination_cells_data, destination_cells_size);
  destination_neighbor_lower_cell = step_source - 1.0;
  /*  the destination cell must have a lower value neighbor */
  /*  check the validity of lower cell */
  /* 'balance_soc:104' if destination_neighbor_lower_cell  > 0 */
  if (step_source - 1.0 > 0.0) {
    /* 'balance_soc:105' if soc_out(1, destination_neighbor_lower_cell) >
     * destination_clt(2 ,1) */
    if (soc_in[(int)(step_source - 1.0) - 1] > cluster_noise_min[1]) {
      /* 'balance_soc:106' dnlc_validity = 1; */
      snlc_validity = 1;
    } else {
      /* 'balance_soc:107' else */
      /* 'balance_soc:108' dnlc_validity = 0; */
      snlc_validity = 0;
    }
  } else {
    /* 'balance_soc:110' else */
    /* 'balance_soc:111' dnlc_validity = 0; */
    snlc_validity = 0;
  }
  /* 'balance_soc:114' destination_neighbor_upper_cell = max(destination_cells)
   * + 1; */
  step_source = d_maximum(destination_cells_data, destination_cells_size);
  destination_neighbor_upper_cell = step_source + 1.0;
  /*  check the validity of upper cell */
  /* 'balance_soc:117' if destination_neighbor_upper_cell <= cell_count */
  if (step_source + 1.0 <= 9.0) {
    /* 'balance_soc:118' if soc_out(1, destination_neighbor_upper_cell) >
     * destination_clt(2 ,1) */
    if (soc_in[(int)(step_source + 1.0) - 1] > cluster_noise_min[1]) {
      /* 'balance_soc:119' dnuc_validity = 1; */
      snuc_validity = 1;
    } else {
      /* 'balance_soc:120' else */
      /* 'balance_soc:121' dnuc_validity = 0; */
      snuc_validity = 0;
    }
  } else {
    /* 'balance_soc:123' else */
    /* 'balance_soc:124' dnuc_validity = 0; */
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  /* 'balance_soc:128' if dnlc_validity || dnuc_validity */
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /* 'balance_soc:130' else */
    /*  select a destination cluster with valid neighbors */
    /*  sorting */
    /* 'balance_soc:134' soc_sorted_clusters =
     * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
     */
    snlc_validity = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
    soc_sorted_clusters_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (snuc_validity = 0; snuc_validity < snlc_validity; snuc_validity++) {
        soc_sorted_clusters_data[snuc_validity +
                                 (int)cluster_clt_max_count * i] =
            cluster_clt_res_soc_av[snuc_validity + 9 * i];
      }
    }
    b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
    /*  pick the minimum soc cluster regarding noise  */
    /* 'balance_soc:136' [destination_clt(2, 1), destination_clt(1, 1)] =
     * min(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
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
      snlc_validity = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= snlc_validity; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    i = varargin_1->size[0];
    varargin_1->size[0] = y->size[1L];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    snlc_validity = y->size[1L];
    for (i = 0; i < snlc_validity; i++) {
      varargin_1_data[i] = soc_sorted_clusters_data[(int)y_data[i] - 1];
    }
    destination_clt_idx_1 = d_minimum(varargin_1, &snlc_validity);
    /*  number of elements in the clusters */
    /* 'balance_soc:139' destination_clt_cnt =
     * nnz(cluster.clt_res_cell(destination_clt(1, 1), :)); */
    destination_clt_cnt = 0;
    for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
      if (cluster_clt_res_cell[(snlc_validity + 9 * snuc_validity) - 1] !=
          0.0) {
        destination_clt_cnt++;
      }
    }
    /*  destination cluster neighbors */
    /* 'balance_soc:142' destination_cells =
     * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
    destination_cells_size[0] = 1;
    destination_cells_size[1] = destination_clt_cnt;
    for (i = 0; i < destination_clt_cnt; i++) {
      destination_cells_data[i] =
          cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
    }
    /* 'balance_soc:143' destination_neighbor_lower_cell =
     * min(destination_cells) - 1; */
    destination_neighbor_lower_cell =
        c_minimum(destination_cells_data, destination_cells_size) - 1.0;
    /* 'balance_soc:144' destination_neighbor_upper_cell =
     * max(destination_cells) + 1; */
    destination_neighbor_upper_cell =
        d_maximum(destination_cells_data, destination_cells_size) + 1.0;
  } else {
    /*  we are good */
  }
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&y);
  /*  store source and destination clusters */
  /* 'balance_soc:149' eq_step.source_queue_cells = [source_neighbor_lower_cell
   * + 1, source_neighbor_upper_cell - 1]; */
  eq_step_source_queue_cells[0] = source_neighbor_lower_cell + 1.0;
  eq_step_source_queue_cells[1] = source_neighbor_upper_cell - 1.0;
  /* 'balance_soc:150' eq_step.destination_queue_cells =
   * [destination_neighbor_lower_cell + 1, destination_neighbor_upper_cell - 1];
   */
  eq_step_destination_queue_cells[0] = destination_neighbor_lower_cell + 1.0;
  eq_step_destination_queue_cells[1] = destination_neighbor_upper_cell - 1.0;
  /* 	%% calculate soc step to balance */
  /*  assign step = 1 to lower cluster member count */
  /* 'balance_soc:154' if destination_clt_cnt < source_clt_cnt */
  if (destination_clt_cnt < source_clt_cnt) {
    /* 'balance_soc:156' step_source = (blc_range/2) / source_clt_cnt *
     * destination_clt_cnt; */
    step_source =
        ep / 2.0 / (double)source_clt_cnt * (double)destination_clt_cnt;
    /* 'balance_soc:157' step_destination = (blc_range/2); */
    step_destination = ep / 2.0;
  } else {
    /* 'balance_soc:159' else */
    /* 'balance_soc:161' step_source = (blc_range/2); */
    step_source = ep / 2.0;
    /* 'balance_soc:162' step_destination = (blc_range/2) / destination_clt_cnt
     * * source_clt_cnt; */
    step_destination =
        ep / 2.0 / (double)destination_clt_cnt * (double)source_clt_cnt;
  }
  /*  soc sweep initialization */
  /* 'balance_soc:169' sweep_source = source_clt(2, 1); */
  /* 'balance_soc:170' sweep_destination = destination_clt(2, 1); */
  /*  calculation for noise_max */
  /*  selecting maximum noise to calculate neighbor distances */
  /* 'balance_soc:174' clt_number_max = source_clt(1, 1); */
  /* 'balance_soc:175' clt_number_min = destination_clt(1, 1); */
  /* 'balance_soc:177' noise_max_pre = source_clt; */
  /* 'balance_soc:178' noise_min_pre = destination_clt; */
  /* 	%% equalizing */
  /* 'balance_soc:183' while soc_mismatch */
  while (soc_mismatch != 0) {
    double d;
    signed char tmp_data[9];
    /*  % clustering */
    /*  [cluster] = pso_DBSCAN(soc_out, mp, ep); */
    /*  % sorting cluster.clt_res_soc_av  */
    /*  V = cluster.clt_res_soc_av; */
    /*  V(V(:,2)==0,2) = Inf; */
    /*  cluster.clt_res_soc_av = sortrows(V, 2,'ascend'); */
    /*  cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0; */
    /*  clear V */
    /*  soc sweep */
    /* 'balance_soc:196' sweep_source = sweep_source - step_source; */
    source_clt_idx_1 -= step_source;
    /* 'balance_soc:197' sweep_destination = sweep_destination +
     * step_destination; */
    destination_clt_idx_1 += step_destination;
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    /* 'balance_soc:202' if source_neighbor_lower_cell - 1 > 0 */
    if ((source_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)source_neighbor_lower_cell - 1] - source_clt_idx_1) <
         ep)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:205' value_lower_diff_s = abs(soc_out(1,
       * source_neighbor_lower_cell) - sweep_source); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:207' if value_lower_diff_s < blc_range */
      /* 'balance_soc:208' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:209' eq_step.source_target_soc_av = sweep_source; */
      *eq_step_source_target_soc_av = source_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    /* 'balance_soc:214' if source_neighbor_upper_cell + 1 <= cell_count */
    if ((source_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)source_neighbor_upper_cell - 1] - source_clt_idx_1) <
         ep)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:217' value_higher_diff_s = abs(soc_out(1,
       * source_neighbor_upper_cell) - sweep_source); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:219' if value_higher_diff_s < blc_range */
      /* 'balance_soc:220' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:221' eq_step.source_target_soc_av = sweep_source; */
      *eq_step_source_target_soc_av = source_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    /* 'balance_soc:229' if destination_neighbor_lower_cell - 1 > 0 */
    if ((destination_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)destination_neighbor_lower_cell - 1] -
              destination_clt_idx_1) < ep)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:232' value_lower_diff_d = abs(soc_out(1,
       * destination_neighbor_lower_cell) - sweep_destination); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:234' if value_lower_diff_d < blc_range */
      /* 'balance_soc:235' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:236' eq_step.destination_target_soc_av =
       * sweep_destination; */
      *c_eq_step_destination_target_so = destination_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    /* 'balance_soc:241' if destination_neighbor_upper_cell + 1 <= cell_count */
    if ((destination_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)destination_neighbor_upper_cell - 1] -
              destination_clt_idx_1) < ep)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:244' value_higher_diff_d = abs(soc_out(1,
       * destination_neighbor_upper_cell) - sweep_destination); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:246' if value_higher_diff_d < blc_range */
      /* 'balance_soc:247' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:248' eq_step.destination_target_soc_av =
       * sweep_destination; */
      *c_eq_step_destination_target_so = destination_clt_idx_1;
      /*  store the target soc of neighbors	 */
    }
    /*  transfer charges */
    /* 'balance_soc:254' soc_new = soc_out; */
    /*  calculate amount of increment and decreament after each sweep */
    /* 'balance_soc:257' inc = step_source; */
    /* 'balance_soc:258' soc_new(1 ,source_cells) = soc_new(1 ,source_cells) -
     * inc; */
    snuc_validity = source_cells_size[1L];
    snlc_validity = source_cells_size[1L];
    for (i = 0; i < snlc_validity; i++) {
      d = source_cells_data[i];
      tmp_data[i] = (signed char)((signed char)(int)d - 1);
      soc_in_data[i] = soc_in[(int)d - 1] - step_source;
    }
    for (i = 0; i < snuc_validity; i++) {
      soc_in[tmp_data[i]] = soc_in_data[i];
    }
    /* 'balance_soc:260' dec = step_destination; */
    /* 'balance_soc:261' soc_new(1 ,destination_cells) = soc_new(1
     * ,destination_cells) + dec; */
    snuc_validity = destination_cells_size[1L];
    snlc_validity = destination_cells_size[1L];
    for (i = 0; i < snlc_validity; i++) {
      d = destination_cells_data[i];
      tmp_data[i] = (signed char)((signed char)(int)d - 1);
      soc_in_data[i] = soc_in[(int)d - 1] + step_destination;
    }
    for (i = 0; i < snuc_validity; i++) {
      soc_in[tmp_data[i]] = soc_in_data[i];
    }
    /* 'balance_soc:263' soc_out = soc_new; */
    /*  increament/decreament soc calculation (both are equal) */
    /* 'balance_soc:266' soc_transfered_s = soc_transfered_s + inc *
     * source_clt_cnt; */
    soc_transfered_s += step_source * (double)source_clt_cnt;
    /* 'balance_soc:267' soc_transfered_d = soc_transfered_d + dec *
     * destination_clt_cnt; */
    soc_transfered_d += step_destination * (double)destination_clt_cnt;
    /*  round to avoid unwanted mismatch */
    /* 'balance_soc:271' if coder.target('MATLAB') */
    /* 'balance_soc:275' else */
    /* 'balance_soc:276' soc_transfered_s = round(soc_transfered_s * 100) / 100;
     */
    soc_transfered_s = rt_roundd_snf(soc_transfered_s * 100.0) / 100.0;
    /* 'balance_soc:277' soc_transfered_d = round(soc_transfered_d * 100) / 100;
     */
    soc_transfered_d = rt_roundd_snf(soc_transfered_d * 100.0) / 100.0;
    /* 'balance_soc:281' if(soc_transfered_s ~= soc_transfered_d) */
    if (!(soc_transfered_s != soc_transfered_d)) {
      /* 'balance_soc:283' else */
      /* 'balance_soc:284' soc_transfered =  soc_transfered_s; */
      soc_transfered = soc_transfered_s;
      /* 'balance_soc:285' soc_diff_s = soc_transfered_s / source_clt_cnt; */
      soc_diff_s = soc_transfered_s / (double)source_clt_cnt;
      /*  single cell soc transfer */
      /* 'balance_soc:286' soc_diff_d = soc_transfered_d / destination_clt_cnt;
       */
      soc_diff_d = soc_transfered_d / (double)destination_clt_cnt;
      /*  single cell  soc transfer */
    } else {
      /* 'balance_soc:282' error("soc transfer mismatch"); */
    }
    /* 'balance_soc:289' if sweep_destination > 100 || sweep_destination < 0 ...
     */
    /* 'balance_soc:290'             || sweep_source > 100 || sweep_source < 0
     */
    /* 'balance_soc:294' if coder.target('MATLAB') */
  }
  /* 		%% calculate balancing time */
  /* 'balance_soc:300' source_batt_number = source_clt_cnt; */
  /* 'balance_soc:301' destination_batt_number = destination_clt_cnt; */
  /*  calculate balancing current */
  /* 'balance_soc:306' if (source_batt_number > destination_batt_number) */
  if (source_clt_cnt > destination_clt_cnt) {
    /* 'balance_soc:307' blc_current_actual = ((destination_batt_number /
     * source_batt_number)/3 + 1/6) * blc_current; */
    step_destination =
        ((double)destination_clt_cnt / (double)source_clt_cnt / 3.0 +
         0.16666666666666666) *
        2000.0;
    /* 'balance_soc:308' cap_diff = soc_diff_s / 100 * capacity; */
    step_source = soc_diff_s / 100.0 * 2200.0;
    /*  calculate transfered capacity for source */
  } else if (source_clt_cnt < destination_clt_cnt) {
    /* 'balance_soc:309' elseif source_batt_number < destination_batt_number */
    /* 'balance_soc:310' cap_diff = soc_diff_d / 100 * capacity; */
    step_source = soc_diff_d / 100.0 * 2200.0;
    /*  calculate transfered capacity for source */
    /* 'balance_soc:311' blc_current_actual = ((source_batt_number /
     * destination_batt_number)/3 + 1/6) * blc_current; */
    step_destination =
        ((double)source_clt_cnt / (double)destination_clt_cnt / 3.0 +
         0.16666666666666666) *
        2000.0;
  } else {
    /* 'balance_soc:312' else */
    /* 'balance_soc:313' blc_current_actual = ((1)/3 + 1/6) * blc_current; */
    step_destination = 1000.0;
    /* 'balance_soc:314' cap_diff = soc_diff_s / 100 * capacity; */
    step_source = soc_diff_s / 100.0 * 2200.0;
    /*  calculate transfered capacity for source */
  }
  /*  calculate the final balancing time (hour) */
  /* 'balance_soc:318' blc_time = cap_diff / blc_current_actual; */
  /*  convert to seconds */
  /* 'balance_soc:321' blc_time = blc_time * 60 * 60; */
  *blc_time = step_source / step_destination * 60.0 * 60.0;
  return soc_transfered;
}

/*
 * File trailer for balance_soc.c
 *
 * [EOF]
 */
