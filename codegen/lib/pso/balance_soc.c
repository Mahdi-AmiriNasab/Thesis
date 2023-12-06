/*
 * File: balance_soc.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
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
#include <string.h>

/* Function Definitions */
/*
 * function [soc_transfered, soc_out, blc_time, eq_step] = balance_soc(cluster,
 * soc_in, mp, ep, blc_range, capacity, blc_current)
 *
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
 *                double eq_step_source_queue_cells[2]
 *                double eq_step_destination_queue_cells[2]
 *                double *eq_step_source_target_soc_av
 *                double *c_eq_step_destination_target_so
 * Return Type  : void
 */
void balance_soc(const double cluster_clt_res_cell[81],
                 const double cluster_clt_res_soc_av[18],
                 double cluster_clt_max_count,
                 const double cluster_noise_max[2],
                 const double cluster_noise_min[2], double soc_in[9],
                 double *soc_transfered, double *blc_time,
                 double eq_step_source_queue_cells[2],
                 double eq_step_destination_queue_cells[2],
                 double *eq_step_source_target_soc_av,
                 double *c_eq_step_destination_target_so)
{
  emxArray_real_T *varargin_1;
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
  double *varargin_1_data;
  double *y_data;
  int cluster_clt_res_cell_size[2];
  int soc_sorted_clusters_size[2];
  int b_loop_ub;
  int destination_clt_cnt;
  int i;
  int loop_ub;
  int snlc_validity;
  int snuc_validity;
  int soc_mismatch;
  int source_clt_cnt;
  /* 'balance_soc:4' blc_time = 0; */
  *blc_time = 0.0;
  /* 'balance_soc:5' soc_out = soc_in; */
  /* 'balance_soc:6' soc_transfered_s = 0; */
  soc_transfered_s = 0.0;
  /* 'balance_soc:6' soc_transfered_d = 0; */
  soc_transfered_d = 0.0;
  /* 'balance_soc:7' soc_transfered = 0; */
  *soc_transfered = 0.0;
  /* 'balance_soc:8' cell_count = length(soc_in); */
  /*  equalization steps storage */
  /* 'balance_soc:11' eq_step.source_queue_cells = [0, 0]; */
  /*  [start_cell, stop_cell] */
  /* 'balance_soc:13' eq_step.destination_queue_cells = [0, 0]; */
  /*  [start_cell, stop_cell]        */
  /* 'balance_soc:15' eq_step.source_target_soc_av = 0; */
  *eq_step_source_target_soc_av = 0.0;
  /*  [src cluster average soc]   */
  /* 'balance_soc:17' eq_step.destination_target_soc_av = 0; */
  *c_eq_step_destination_target_so = 0.0;
  /*  [des cluster average soc] */
  /*  validity of source/destination cluster neighbors (valid by default) */
  /* 'balance_soc:20' snlc_validity = 1; */
  /* 'balance_soc:21' snuc_validity = 1; */
  /* 'balance_soc:23' dnlc_validity = 1; */
  /* 'balance_soc:24' dnuc_validity = 1; */
  /*  conditional flag */
  /* 'balance_soc:27' soc_mismatch = 1; */
  soc_mismatch = 1;
  /*  valid balance range soc */
  /* blc_range = 2; */
  /*  assaign weight to each noise cluster by each cell in it */
  /*  number of elements in noise clusters */
  /* 'balance_soc:34' source_clt_cnt =
   * nnz(cluster.clt_res_cell(cluster.noise_max(1, 1), :)); */
  source_clt_cnt = 0;
  /* 'balance_soc:35' destination_clt_cnt =
   * nnz(cluster.clt_res_cell(cluster.noise_min(1, 1), :)); */
  destination_clt_cnt = 0;
  for (snlc_validity = 0; snlc_validity < 9; snlc_validity++) {
    if (cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * snlc_validity) -
                             1] != 0.0) {
      source_clt_cnt++;
    }
    if (cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * snlc_validity) -
                             1] != 0.0) {
      destination_clt_cnt++;
    }
  }
  /* 	%% define source and destination clusters */
  /* 'balance_soc:38' source_clt = cluster.noise_max; */
  /* 'balance_soc:39' destination_clt = cluster.noise_min; */
  source_clt_idx_1 = cluster_noise_max[1];
  destination_clt_idx_1 = cluster_noise_min[1];
  /*  find neighbor cells of each source and destination cell */
  /*  source cluster neighbors */
  /* 'balance_soc:43' source_cells = cluster.clt_res_cell(source_clt(1, 1),
   * 1:source_clt_cnt); */
  if (source_clt_cnt < 1) {
    loop_ub = 0;
  } else {
    loop_ub = source_clt_cnt;
  }
  /* 'balance_soc:45' source_neighbor_lower_cell = min(source_cells) - 1; */
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
  /* 'balance_soc:49' if source_neighbor_lower_cell  > 0 */
  if (step_source - 1.0 > 0.0) {
    /* 'balance_soc:50' if soc_out(1, source_neighbor_lower_cell) < source_clt(2
     * ,1) */
    if (soc_in[(int)(step_source - 1.0) - 1] < cluster_noise_max[1]) {
      /* 'balance_soc:51' snlc_validity = 1; */
      snlc_validity = 1;
    } else {
      /* 'balance_soc:52' else */
      /* 'balance_soc:53' snlc_validity = 0; */
      snlc_validity = 0;
    }
  } else {
    /* 'balance_soc:55' else */
    /* 'balance_soc:56' snlc_validity = 0; */
    snlc_validity = 0;
  }
  /* 'balance_soc:59' source_neighbor_upper_cell = max(source_cells) + 1; */
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  step_source = d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
  }
  source_neighbor_upper_cell =
      d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  /*  check the validity of upper cell */
  /* 'balance_soc:62' if source_neighbor_upper_cell <= cell_count */
  if (step_source + 1.0 <= 9.0) {
    /* 'balance_soc:63' if soc_out(1, source_neighbor_upper_cell) < source_clt(2
     * ,1) */
    if (soc_in[(int)(step_source + 1.0) - 1] < cluster_noise_max[1]) {
      /* 'balance_soc:64' snuc_validity = 1; */
      snuc_validity = 1;
    } else {
      /* 'balance_soc:65' else */
      /* 'balance_soc:66' snuc_validity = 0; */
      snuc_validity = 0;
    }
  } else {
    /* 'balance_soc:68' else */
    /* 'balance_soc:69' snuc_validity = 0; */
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  /* 'balance_soc:73' if snlc_validity || snuc_validity */
  emxInit_real_T(&y, 2);
  emxInit_real_T(&varargin_1, 1);
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /* 'balance_soc:75' else */
    /*  select a source cluster with valid neighbors */
    /*  sorting */
    /* 'balance_soc:79' soc_sorted_clusters =
     * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
     */
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
    /* 'balance_soc:81' [source_clt(2, 1), source_clt(1, 1)] =
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
      loop_ub = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    i = varargin_1->size[0];
    varargin_1->size[0] = y->size[1];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_1_data[i] = soc_sorted_clusters_data[(int)y_data[i] - 1];
    }
    e_maximum(varargin_1, &source_clt_idx_1, &snuc_validity);
    /*  number of elements in the clusters */
    /* 'balance_soc:84' source_clt_cnt = nnz(cluster.clt_res_cell(source_clt(1,
     * 1), :)); */
    source_clt_cnt = 0;
    for (snlc_validity = 0; snlc_validity < 9; snlc_validity++) {
      if (cluster_clt_res_cell[(snuc_validity + 9 * snlc_validity) - 1] !=
          0.0) {
        source_clt_cnt++;
      }
    }
    /*  source cluster neighbors */
    /* 'balance_soc:87' source_cells = cluster.clt_res_cell(source_clt(1, 1),
     * 1:source_clt_cnt); */
    if (source_clt_cnt < 1) {
      loop_ub = 0;
    } else {
      loop_ub = source_clt_cnt;
    }
    /* 'balance_soc:88' source_neighbor_lower_cell = min(source_cells) - 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      step_source = cluster_clt_res_cell[(snuc_validity + 9 * i) - 1];
      source_cells_data[i] = step_source;
      cluster_clt_res_cell_data[i] = step_source;
    }
    source_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    /* 'balance_soc:89' source_neighbor_upper_cell = max(source_cells) + 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[(snuc_validity + 9 * i) - 1];
    }
    source_neighbor_upper_cell =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  } else {
    /*  we are good */
  }
  /*  destination cluster neighbors */
  /* 'balance_soc:94' destination_cells =
   * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
  if (destination_clt_cnt < 1) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = destination_clt_cnt;
  }
  /* 'balance_soc:96' destination_neighbor_lower_cell = min(destination_cells) -
   * 1; */
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    step_source = cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
    destination_cells_data[i] = step_source;
    cluster_clt_res_cell_data[i] = step_source;
  }
  step_source = c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  destination_neighbor_lower_cell =
      c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
  /*  the destination cell must have a lower value neighbor */
  /*  check the validity of lower cell */
  /* 'balance_soc:100' if destination_neighbor_lower_cell  > 0 */
  if (step_source - 1.0 > 0.0) {
    /* 'balance_soc:101' if soc_out(1, destination_neighbor_lower_cell) >
     * destination_clt(2 ,1) */
    if (soc_in[(int)(step_source - 1.0) - 1] > cluster_noise_min[1]) {
      /* 'balance_soc:102' dnlc_validity = 1; */
      snlc_validity = 1;
    } else {
      /* 'balance_soc:103' else */
      /* 'balance_soc:104' dnlc_validity = 0; */
      snlc_validity = 0;
    }
  } else {
    /* 'balance_soc:106' else */
    /* 'balance_soc:107' dnlc_validity = 0; */
    snlc_validity = 0;
  }
  /* 'balance_soc:110' destination_neighbor_upper_cell = max(destination_cells)
   * + 1; */
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  step_source = d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
  cluster_clt_res_cell_size[0] = 1;
  cluster_clt_res_cell_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    cluster_clt_res_cell_data[i] =
        cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
  }
  destination_neighbor_upper_cell =
      d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  /*  check the validity of upper cell */
  /* 'balance_soc:113' if destination_neighbor_upper_cell <= cell_count */
  if (step_source + 1.0 <= 9.0) {
    /* 'balance_soc:114' if soc_out(1, destination_neighbor_upper_cell) >
     * destination_clt(2 ,1) */
    if (soc_in[(int)(step_source + 1.0) - 1] > cluster_noise_min[1]) {
      /* 'balance_soc:115' dnuc_validity = 1; */
      snuc_validity = 1;
    } else {
      /* 'balance_soc:116' else */
      /* 'balance_soc:117' dnuc_validity = 0; */
      snuc_validity = 0;
    }
  } else {
    /* 'balance_soc:119' else */
    /* 'balance_soc:120' dnuc_validity = 0; */
    snuc_validity = 0;
  }
  /*  check if any valid neighbor found */
  /* 'balance_soc:124' if dnlc_validity || dnuc_validity */
  if ((snlc_validity == 0) && (snuc_validity == 0)) {
    /* 'balance_soc:126' else */
    /*  select a destination cluster with valid neighbors */
    /*  sorting */
    /* 'balance_soc:130' soc_sorted_clusters =
     * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
     */
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
    /* 'balance_soc:132' [destination_clt(2, 1), destination_clt(1, 1)] =
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
      b_loop_ub = (int)(cluster_clt_max_count - 1.0);
      for (i = 0; i <= b_loop_ub; i++) {
        y_data[i] = (double)i + 1.0;
      }
    }
    i = varargin_1->size[0];
    varargin_1->size[0] = y->size[1];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    b_loop_ub = y->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      varargin_1_data[i] = soc_sorted_clusters_data[(int)y_data[i] - 1];
    }
    d_minimum(varargin_1, &destination_clt_idx_1, &snuc_validity);
    /*  number of elements in the clusters */
    /* 'balance_soc:135' destination_clt_cnt =
     * nnz(cluster.clt_res_cell(destination_clt(1, 1), :)); */
    destination_clt_cnt = 0;
    for (snlc_validity = 0; snlc_validity < 9; snlc_validity++) {
      if (cluster_clt_res_cell[(snuc_validity + 9 * snlc_validity) - 1] !=
          0.0) {
        destination_clt_cnt++;
      }
    }
    /*  destination cluster neighbors */
    /* 'balance_soc:138' destination_cells =
     * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
    if (destination_clt_cnt < 1) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = destination_clt_cnt;
    }
    /* 'balance_soc:139' destination_neighbor_lower_cell =
     * min(destination_cells) - 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = b_loop_ub;
    for (i = 0; i < b_loop_ub; i++) {
      step_source = cluster_clt_res_cell[(snuc_validity + 9 * i) - 1];
      destination_cells_data[i] = step_source;
      cluster_clt_res_cell_data[i] = step_source;
    }
    destination_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    /* 'balance_soc:140' destination_neighbor_upper_cell =
     * max(destination_cells) + 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = b_loop_ub;
    for (i = 0; i < b_loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[(snuc_validity + 9 * i) - 1];
    }
    destination_neighbor_upper_cell =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
  } else {
    /*  we are good */
  }
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&y);
  /*  store source and destination clusters */
  /* 'balance_soc:145' eq_step.source_queue_cells = [source_neighbor_lower_cell
   * + 1, source_neighbor_upper_cell - 1]; */
  eq_step_source_queue_cells[0] = source_neighbor_lower_cell + 1.0;
  eq_step_source_queue_cells[1] = source_neighbor_upper_cell - 1.0;
  /* 'balance_soc:146' eq_step.destination_queue_cells =
   * [destination_neighbor_lower_cell + 1, destination_neighbor_upper_cell - 1];
   */
  eq_step_destination_queue_cells[0] = destination_neighbor_lower_cell + 1.0;
  eq_step_destination_queue_cells[1] = destination_neighbor_upper_cell - 1.0;
  /* 	%% calculate soc step to balance */
  /*  assign step = 1 to lower cluster member count */
  /* 'balance_soc:150' if destination_clt_cnt < source_clt_cnt */
  if (destination_clt_cnt < source_clt_cnt) {
    /* 'balance_soc:152' step_source = (blc_range/2) / source_clt_cnt *
     * destination_clt_cnt; */
    step_source = 0.5 / (double)source_clt_cnt * (double)destination_clt_cnt;
    /* 'balance_soc:153' step_destination = (blc_range/2); */
    step_destination = 0.5;
  } else {
    /* 'balance_soc:155' else */
    /* 'balance_soc:157' step_source = (blc_range/2); */
    step_source = 0.5;
    /* 'balance_soc:158' step_destination = (blc_range/2) / destination_clt_cnt
     * * source_clt_cnt; */
    step_destination =
        0.5 / (double)destination_clt_cnt * (double)source_clt_cnt;
  }
  /*  soc sweep initialization */
  /* 'balance_soc:165' sweep_source = source_clt(2, 1); */
  /* 'balance_soc:166' sweep_destination = destination_clt(2, 1); */
  /*  calculation for noise_max */
  /*  selecting maximum noise to calculate neighbor distances */
  /* 'balance_soc:170' clt_number_max = source_clt(1, 1); */
  /* 'balance_soc:171' clt_number_min = destination_clt(1, 1); */
  /* 'balance_soc:173' noise_max_pre = source_clt; */
  /* 'balance_soc:174' noise_min_pre = destination_clt; */
  /* 	%% equalizing */
  /* 'balance_soc:179' while soc_mismatch */
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
    /* 'balance_soc:192' sweep_source = sweep_source - step_source; */
    source_clt_idx_1 -= step_source;
    /* 'balance_soc:193' sweep_destination = sweep_destination +
     * step_destination; */
    destination_clt_idx_1 += step_destination;
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    /* 'balance_soc:198' if source_neighbor_lower_cell - 1 > 0 */
    if ((source_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)source_neighbor_lower_cell - 1] - source_clt_idx_1) <
         1.0)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:201' value_lower_diff_s = abs(soc_out(1,
       * source_neighbor_lower_cell) - sweep_source); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:203' if value_lower_diff_s < blc_range */
      /* 'balance_soc:204' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:205' eq_step.source_target_soc_av = sweep_source; */
      *eq_step_source_target_soc_av = source_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    /* 'balance_soc:210' if source_neighbor_upper_cell + 1 <= cell_count */
    if ((source_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)source_neighbor_upper_cell - 1] - source_clt_idx_1) <
         1.0)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:213' value_higher_diff_s = abs(soc_out(1,
       * source_neighbor_upper_cell) - sweep_source); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:215' if value_higher_diff_s < blc_range */
      /* 'balance_soc:216' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:217' eq_step.source_target_soc_av = sweep_source; */
      *eq_step_source_target_soc_av = source_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  pick the neighbor values if neighbors are available in both sides */
    /*  watch for the zero index */
    /* 'balance_soc:225' if destination_neighbor_lower_cell - 1 > 0 */
    if ((destination_neighbor_lower_cell - 1.0 > 0.0) &&
        (fabs(soc_in[(int)destination_neighbor_lower_cell - 1] -
              destination_clt_idx_1) < 1.0)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:228' value_lower_diff_d = abs(soc_out(1,
       * destination_neighbor_lower_cell) - sweep_destination); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:230' if value_lower_diff_d < blc_range */
      /* 'balance_soc:231' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:232' eq_step.destination_target_soc_av =
       * sweep_destination; */
      *c_eq_step_destination_target_so = destination_clt_idx_1;
      /*  store the target soc of neighbors */
    }
    /*  watch for the maximum boundaries */
    /* 'balance_soc:237' if destination_neighbor_upper_cell + 1 <= cell_count */
    if ((destination_neighbor_upper_cell + 1.0 <= 9.0) &&
        (fabs(soc_in[(int)destination_neighbor_upper_cell - 1] -
              destination_clt_idx_1) < 1.0)) {
      /*  subtract noise value and lower neighbor value */
      /* 'balance_soc:240' value_higher_diff_d = abs(soc_out(1,
       * destination_neighbor_upper_cell) - sweep_destination); */
      /*  if the differential is within the valid range */
      /* 'balance_soc:242' if value_higher_diff_d < blc_range */
      /* 'balance_soc:243' soc_mismatch = 0; */
      soc_mismatch = 0;
      /*  the neighbors are balanced */
      /* 'balance_soc:244' eq_step.destination_target_soc_av =
       * sweep_destination; */
      *c_eq_step_destination_target_so = destination_clt_idx_1;
      /*  store the target soc of neighbors	 */
    }
    /*  transfer charges */
    /* 'balance_soc:250' soc_new = soc_out; */
    /*  calculate amount of increment and decreament after each sweep */
    /* 'balance_soc:253' inc = step_source; */
    /* 'balance_soc:254' soc_new(1 ,source_cells) = soc_new(1 ,source_cells) -
     * inc; */
    if (loop_ub - 1 >= 0) {
      memcpy(&tmp_data[0], &source_cells_data[0], loop_ub * sizeof(double));
    }
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] = soc_in[(int)tmp_data[i] - 1] - step_source;
    }
    for (i = 0; i < loop_ub; i++) {
      soc_in[(int)tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
    }
    /* 'balance_soc:256' dec = step_destination; */
    /* 'balance_soc:257' soc_new(1 ,destination_cells) = soc_new(1
     * ,destination_cells) + dec; */
    if (b_loop_ub - 1 >= 0) {
      memcpy(&tmp_data[0], &destination_cells_data[0],
             b_loop_ub * sizeof(double));
    }
    for (i = 0; i < b_loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          soc_in[(int)tmp_data[i] - 1] + step_destination;
    }
    for (i = 0; i < b_loop_ub; i++) {
      soc_in[(int)tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
    }
    /* 'balance_soc:259' soc_out = soc_new; */
    /*  increament/decreament soc calculation (both are equal) */
    /* 'balance_soc:262' soc_transfered_s = soc_transfered_s + inc *
     * source_clt_cnt; */
    soc_transfered_s += step_source * (double)source_clt_cnt;
    /* 'balance_soc:263' soc_transfered_d = soc_transfered_d + dec *
     * destination_clt_cnt; */
    soc_transfered_d += step_destination * (double)destination_clt_cnt;
    /*  round to avoid unwanted mismatch */
    /* 'balance_soc:267' if coder.target('MATLAB') */
    /* 'balance_soc:271' else */
    /* 'balance_soc:272' soc_transfered_s = round(soc_transfered_s * 100) / 100;
     */
    soc_transfered_s = rt_roundd_snf(soc_transfered_s * 100.0) / 100.0;
    /* 'balance_soc:273' soc_transfered_d = round(soc_transfered_d * 100) / 100;
     */
    soc_transfered_d = rt_roundd_snf(soc_transfered_d * 100.0) / 100.0;
    /* 'balance_soc:277' if(soc_transfered_s ~= soc_transfered_d) */
    if (!(soc_transfered_s != soc_transfered_d)) {
      /* 'balance_soc:279' else */
      /* 'balance_soc:280' soc_transfered =  soc_transfered_s; */
      *soc_transfered = soc_transfered_s;
    } else {
      /* 'balance_soc:278' error("soc transfer mismatch"); */
    }
    /* 'balance_soc:283' blc_time = (soc_transfered/100 * capacity) /
     * blc_current; */
    *blc_time = *soc_transfered / 100.0 * 2200.0 / 2000.0;
    /* 'balance_soc:285' if sweep_destination > 100 || sweep_destination < 0 ...
     */
    /* 'balance_soc:286'             || sweep_source > 100 || sweep_source < 0
     */
    /* 'balance_soc:290' if coder.target('MATLAB') */
  }
}

/*
 * File trailer for balance_soc.c
 *
 * [EOF]
 */
