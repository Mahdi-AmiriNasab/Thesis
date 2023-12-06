/*
 * File: log_clustering.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "log_clustering.h"
#include "any.h"
#include "calculate_overlap.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "pso_DBSCAN.h"
#include "pso_emxutil.h"
#include "pso_internal_types.h"
#include "pso_rtwutil.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * function [lg_time, lg_inconsistency, lg_eq_overlap] = log_clustering(soc_in,
 * mp, ep_arr)
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double *lg_time
 *                double *lg_inconsistency
 *                double *lg_eq_overlap
 * Return Type  : void
 */
void log_clustering(const double soc_in[9], double mp, double *lg_time,
                    double *lg_inconsistency, double *lg_eq_overlap)
{
  emxArray_real_T *soc_sorted_clusters;
  double soc_profile_data[900];
  double cluster_clt_res_cell[81];
  double expl_temp[81];
  double V[18];
  double b_expl_temp[18];
  double soc_sorted_clusters_data[18];
  double destination_cells_data[9];
  double e_tmp_data[9];
  double soc[9];
  double source_cells_data[9];
  double c_expl_temp[2];
  double destination_clt[2];
  double source_clt[2];
  double step_destination;
  double step_source;
  double sweep_source;
  double *b_soc_sorted_clusters_data;
  int b_soc_profile_size[2];
  int cluster_clt_res_cell_size[2];
  int soc_profile_size[2];
  int soc_sorted_clusters_size[2];
  int i;
  int itteration;
  int loop_ub;
  int loop_ub_tmp_tmp;
  int snlc_validity;
  int snuc_validity;
  signed char c_tmp_data[9];
  signed char d_tmp_data[9];
  boolean_T tmp_data[900];
  boolean_T b_tmp_data[100];
  boolean_T exitg1;
  e_noise_stat d_expl_temp;
  /* 'log_clustering:3' coder.extrinsic('plot', 'nexttile', 'tiledlayout'); */
  /* 'log_clustering:5' cell_count = length(soc_in); */
  /* 'log_clustering:7' soc_profile = zeros(1, cell_count); */
  /* 'log_clustering:8' coder.varsize('soc_profile', [inf, cell_count], [1, 0]);
   */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* 'log_clustering:9' soc_profile = NaN(100, cell_count); */
  soc_profile_size[0] = 100;
  soc_profile_size[1] = 9;
  for (i = 0; i < 900; i++) {
    soc_profile_data[i] = rtNaN;
  }
  /* 'log_clustering:11' lg_time = zeros(length(ep_arr), 1); */
  /* 'log_clustering:12' lg_inconsistency = zeros(length(ep_arr), 1); */
  /* 'log_clustering:13' lg_eq_overlap = zeros(length(ep_arr), 1); */
  *lg_eq_overlap = 0.0;
  /* 'log_clustering:15' for ep = ep_arr */
  /* 'log_clustering:17' soc = soc_in; */
  /* 'log_clustering:18' itteration = 0; */
  itteration = 0;
  /* 'log_clustering:19' soc_transfered_total = 0; */
  /* 'log_clustering:20' blc_time_total = 0; */
  *lg_time = 0.0;
  /* 'log_clustering:22' soc_profile(itteration + 1, :) = soc; */
  for (i = 0; i < 9; i++) {
    step_source = soc_in[i];
    soc[i] = step_source;
    soc_profile_data[100 * i] = step_source;
  }
  /*  clustering */
  /* 'log_clustering:26' [cluster] = pso_DBSCAN(soc, mp, ep); */
  b_pso_DBSCAN(soc_in, mp, &step_source, &step_destination, source_cells_data,
               cluster_clt_res_cell, expl_temp, V, &sweep_source,
               soc_sorted_clusters_data, b_expl_temp, source_clt,
               destination_clt, c_expl_temp, &d_expl_temp);
  /* 'log_clustering:28' while cluster.clt_max_count > 1 */
  emxInit_real_T(&soc_sorted_clusters, 1);
  exitg1 = false;
  while ((!exitg1) && (sweep_source > 1.0)) {
    double cluster_clt_res_cell_data[9];
    double blc_time;
    double destination_neighbor_lower_cell;
    double destination_neighbor_upper_cell;
    double soc_transfered;
    double soc_transfered_d;
    double soc_transfered_s;
    double source_neighbor_lower_cell;
    double source_neighbor_upper_cell;
    double sweep_destination;
    int destination_clt_cnt;
    int soc_mismatch;
    int source_clt_cnt;
    boolean_T b;
    /*  balancing */
    /* 'log_clustering:32' [soc_transfered, soc, blc_time] =
     * balance_soc(cluster, soc, mp, ep, 1, 2200, 2000); */
    /* 	%% init */
    /* 'balance_soc:4' blc_time = 0; */
    blc_time = 0.0;
    /* 'balance_soc:5' soc_out = soc_in; */
    /* 'balance_soc:6' soc_transfered_s = 0; */
    soc_transfered_s = 0.0;
    /* 'balance_soc:6' soc_transfered_d = 0; */
    soc_transfered_d = 0.0;
    /* 'balance_soc:7' soc_transfered = 0; */
    soc_transfered = 0.0;
    /* 'balance_soc:8' cell_count = length(soc_in); */
    /*  equalization steps storage */
    /* 'balance_soc:11' eq_step.source_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell] */
    /* 'balance_soc:13' eq_step.destination_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell]        */
    /* 'balance_soc:15' eq_step.source_target_soc_av = 0; */
    /*  [src cluster average soc]   */
    /* 'balance_soc:17' eq_step.destination_target_soc_av = 0; */
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
    for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
      if (cluster_clt_res_cell[((int)source_clt[0] + 9 * snuc_validity) - 1] !=
          0.0) {
        source_clt_cnt++;
      }
      if (cluster_clt_res_cell[((int)destination_clt[0] + 9 * snuc_validity) -
                               1] != 0.0) {
        destination_clt_cnt++;
      }
    }
    /* 	%% define source and destination clusters */
    /* 'balance_soc:38' source_clt = cluster.noise_max; */
    /* 'balance_soc:39' destination_clt = cluster.noise_min; */
    /*  find neighbor cells of each source and destination cell */
    /*  source cluster neighbors */
    /* 'balance_soc:43' source_cells = cluster.clt_res_cell(source_clt(1, 1),
     * 1:source_clt_cnt); */
    if (source_clt_cnt < 1) {
      loop_ub = 0;
    } else {
      loop_ub = source_clt_cnt;
    }
    for (i = 0; i < loop_ub; i++) {
      source_cells_data[i] =
          cluster_clt_res_cell[((int)source_clt[0] + 9 * i) - 1];
    }
    /* 'balance_soc:45' source_neighbor_lower_cell = min(source_cells) - 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)source_clt[0] + 9 * i) - 1];
    }
    step_source =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)source_clt[0] + 9 * i) - 1];
    }
    source_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    /*  the source cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* 'balance_soc:49' if source_neighbor_lower_cell  > 0 */
    if (step_source - 1.0 > 0.0) {
      /* 'balance_soc:50' if soc_out(1, source_neighbor_lower_cell) <
       * source_clt(2 ,1) */
      if (soc[(int)(step_source - 1.0) - 1] < source_clt[1]) {
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
          cluster_clt_res_cell[((int)source_clt[0] + 9 * i) - 1];
    }
    step_source =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)source_clt[0] + 9 * i) - 1];
    }
    source_neighbor_upper_cell =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
    /*  check the validity of upper cell */
    /* 'balance_soc:62' if source_neighbor_upper_cell <= cell_count */
    if (step_source + 1.0 <= 9.0) {
      /* 'balance_soc:63' if soc_out(1, source_neighbor_upper_cell) <
       * source_clt(2 ,1) */
      if (soc[(int)(step_source + 1.0) - 1] < source_clt[1]) {
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
    if ((snlc_validity == 0) && (snuc_validity == 0)) {
      /* 'balance_soc:75' else */
      /*  select a source cluster with valid neighbors */
      /*  sorting */
      /* 'balance_soc:79' soc_sorted_clusters =
       * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2,
       * 'ascend'); */
      loop_ub_tmp_tmp = (int)sweep_source;
      soc_sorted_clusters_size[0] = (int)sweep_source;
      soc_sorted_clusters_size[1] = 2;
      for (i = 0; i < 2; i++) {
        for (snuc_validity = 0; snuc_validity < loop_ub_tmp_tmp;
             snuc_validity++) {
          soc_sorted_clusters_data[snuc_validity + (int)sweep_source * i] =
              V[snuc_validity + 9 * i];
        }
      }
      b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
      /*  pick the maximum soc cluster regarding noise  */
      /* 'balance_soc:81' [source_clt(2, 1), source_clt(1, 1)] =
       * max(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      i = soc_sorted_clusters->size[0];
      soc_sorted_clusters->size[0] = (int)(sweep_source - 1.0) + 1;
      emxEnsureCapacity_real_T(soc_sorted_clusters, i);
      b_soc_sorted_clusters_data = soc_sorted_clusters->data;
      loop_ub = (int)(sweep_source - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        b_soc_sorted_clusters_data[i] = soc_sorted_clusters_data[i];
      }
      e_maximum(soc_sorted_clusters, &source_clt[1], &snlc_validity);
      /*  number of elements in the clusters */
      /* 'balance_soc:84' source_clt_cnt =
       * nnz(cluster.clt_res_cell(source_clt(1, 1), :)); */
      source_clt_cnt = 0;
      for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
        if (cluster_clt_res_cell[(snlc_validity + 9 * snuc_validity) - 1] !=
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
      for (i = 0; i < loop_ub; i++) {
        source_cells_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
      }
      /* 'balance_soc:88' source_neighbor_lower_cell = min(source_cells) - 1; */
      cluster_clt_res_cell_size[0] = 1;
      cluster_clt_res_cell_size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        cluster_clt_res_cell_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
      }
      source_neighbor_lower_cell =
          c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
      /* 'balance_soc:89' source_neighbor_upper_cell = max(source_cells) + 1; */
      cluster_clt_res_cell_size[0] = 1;
      cluster_clt_res_cell_size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        cluster_clt_res_cell_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
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
      loop_ub_tmp_tmp = 0;
    } else {
      loop_ub_tmp_tmp = destination_clt_cnt;
    }
    for (i = 0; i < loop_ub_tmp_tmp; i++) {
      destination_cells_data[i] =
          cluster_clt_res_cell[((int)destination_clt[0] + 9 * i) - 1];
    }
    /* 'balance_soc:96' destination_neighbor_lower_cell = min(destination_cells)
     * - 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
    for (i = 0; i < loop_ub_tmp_tmp; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)destination_clt[0] + 9 * i) - 1];
    }
    step_source =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
    for (i = 0; i < loop_ub_tmp_tmp; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)destination_clt[0] + 9 * i) - 1];
    }
    destination_neighbor_lower_cell =
        c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
    /*  the destination cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* 'balance_soc:100' if destination_neighbor_lower_cell  > 0 */
    if (step_source - 1.0 > 0.0) {
      /* 'balance_soc:101' if soc_out(1, destination_neighbor_lower_cell) >
       * destination_clt(2 ,1) */
      if (soc[(int)(step_source - 1.0) - 1] > destination_clt[1]) {
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
    /* 'balance_soc:110' destination_neighbor_upper_cell =
     * max(destination_cells) + 1; */
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
    for (i = 0; i < loop_ub_tmp_tmp; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)destination_clt[0] + 9 * i) - 1];
    }
    step_source =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size);
    cluster_clt_res_cell_size[0] = 1;
    cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
    for (i = 0; i < loop_ub_tmp_tmp; i++) {
      cluster_clt_res_cell_data[i] =
          cluster_clt_res_cell[((int)destination_clt[0] + 9 * i) - 1];
    }
    destination_neighbor_upper_cell =
        d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
    /*  check the validity of upper cell */
    /* 'balance_soc:113' if destination_neighbor_upper_cell <= cell_count */
    if (step_source + 1.0 <= 9.0) {
      /* 'balance_soc:114' if soc_out(1, destination_neighbor_upper_cell) >
       * destination_clt(2 ,1) */
      if (soc[(int)(step_source + 1.0) - 1] > destination_clt[1]) {
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
       * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2,
       * 'ascend'); */
      loop_ub_tmp_tmp = (int)sweep_source;
      soc_sorted_clusters_size[0] = (int)sweep_source;
      soc_sorted_clusters_size[1] = 2;
      for (i = 0; i < 2; i++) {
        for (snuc_validity = 0; snuc_validity < loop_ub_tmp_tmp;
             snuc_validity++) {
          soc_sorted_clusters_data[snuc_validity + (int)sweep_source * i] =
              V[snuc_validity + 9 * i];
        }
      }
      b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
      /*  pick the minimum soc cluster regarding noise  */
      /* 'balance_soc:132' [destination_clt(2, 1), destination_clt(1, 1)] =
       * min(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      i = soc_sorted_clusters->size[0];
      soc_sorted_clusters->size[0] = (int)(sweep_source - 1.0) + 1;
      emxEnsureCapacity_real_T(soc_sorted_clusters, i);
      b_soc_sorted_clusters_data = soc_sorted_clusters->data;
      loop_ub_tmp_tmp = (int)(sweep_source - 1.0);
      for (i = 0; i <= loop_ub_tmp_tmp; i++) {
        b_soc_sorted_clusters_data[i] = soc_sorted_clusters_data[i];
      }
      d_minimum(soc_sorted_clusters, &destination_clt[1], &snlc_validity);
      /*  number of elements in the clusters */
      /* 'balance_soc:135' destination_clt_cnt =
       * nnz(cluster.clt_res_cell(destination_clt(1, 1), :)); */
      destination_clt_cnt = 0;
      for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
        if (cluster_clt_res_cell[(snlc_validity + 9 * snuc_validity) - 1] !=
            0.0) {
          destination_clt_cnt++;
        }
      }
      /*  destination cluster neighbors */
      /* 'balance_soc:138' destination_cells =
       * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
      if (destination_clt_cnt < 1) {
        loop_ub_tmp_tmp = 0;
      } else {
        loop_ub_tmp_tmp = destination_clt_cnt;
      }
      for (i = 0; i < loop_ub_tmp_tmp; i++) {
        destination_cells_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
      }
      /* 'balance_soc:139' destination_neighbor_lower_cell =
       * min(destination_cells) - 1; */
      cluster_clt_res_cell_size[0] = 1;
      cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
      for (i = 0; i < loop_ub_tmp_tmp; i++) {
        cluster_clt_res_cell_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
      }
      destination_neighbor_lower_cell =
          c_minimum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) - 1.0;
      /* 'balance_soc:140' destination_neighbor_upper_cell =
       * max(destination_cells) + 1; */
      cluster_clt_res_cell_size[0] = 1;
      cluster_clt_res_cell_size[1] = loop_ub_tmp_tmp;
      for (i = 0; i < loop_ub_tmp_tmp; i++) {
        cluster_clt_res_cell_data[i] =
            cluster_clt_res_cell[(snlc_validity + 9 * i) - 1];
      }
      destination_neighbor_upper_cell =
          d_maximum(cluster_clt_res_cell_data, cluster_clt_res_cell_size) + 1.0;
    } else {
      /*  we are good */
    }
    /*  store source and destination clusters */
    /* 'balance_soc:145' eq_step.source_queue_cells =
     * [source_neighbor_lower_cell + 1, source_neighbor_upper_cell - 1]; */
    /* 'balance_soc:146' eq_step.destination_queue_cells =
     * [destination_neighbor_lower_cell + 1, destination_neighbor_upper_cell -
     * 1]; */
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
      /* 'balance_soc:158' step_destination = (blc_range/2) /
       * destination_clt_cnt * source_clt_cnt; */
      step_destination =
          0.5 / (double)destination_clt_cnt * (double)source_clt_cnt;
    }
    /*  soc sweep initialization */
    /* 'balance_soc:165' sweep_source = source_clt(2, 1); */
    sweep_source = source_clt[1];
    /* 'balance_soc:166' sweep_destination = destination_clt(2, 1); */
    sweep_destination = destination_clt[1];
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
      sweep_source -= step_source;
      /* 'balance_soc:193' sweep_destination = sweep_destination +
       * step_destination; */
      sweep_destination += step_destination;
      /*  pick the neighbor values if neighbors are available in both sides */
      /*  watch for the zero index */
      /* 'balance_soc:198' if source_neighbor_lower_cell - 1 > 0 */
      if ((source_neighbor_lower_cell - 1.0 > 0.0) &&
          (fabs(soc[(int)source_neighbor_lower_cell - 1] - sweep_source) <
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
        /*  store the target soc of neighbors */
      }
      /*  watch for the maximum boundaries */
      /* 'balance_soc:210' if source_neighbor_upper_cell + 1 <= cell_count */
      if ((source_neighbor_upper_cell + 1.0 <= 9.0) &&
          (fabs(soc[(int)source_neighbor_upper_cell - 1] - sweep_source) <
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
        /*  store the target soc of neighbors */
      }
      /*  pick the neighbor values if neighbors are available in both sides */
      /*  watch for the zero index */
      /* 'balance_soc:225' if destination_neighbor_lower_cell - 1 > 0 */
      if ((destination_neighbor_lower_cell - 1.0 > 0.0) &&
          (fabs(soc[(int)destination_neighbor_lower_cell - 1] -
                sweep_destination) < 1.0)) {
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
        /*  store the target soc of neighbors */
      }
      /*  watch for the maximum boundaries */
      /* 'balance_soc:237' if destination_neighbor_upper_cell + 1 <= cell_count
       */
      if ((destination_neighbor_upper_cell + 1.0 <= 9.0) &&
          (fabs(soc[(int)destination_neighbor_upper_cell - 1] -
                sweep_destination) < 1.0)) {
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
        /*  store the target soc of neighbors	 */
      }
      /*  transfer charges */
      /* 'balance_soc:250' soc_new = soc_out; */
      /*  calculate amount of increment and decreament after each sweep */
      /* 'balance_soc:253' inc = step_source; */
      /* 'balance_soc:254' soc_new(1 ,source_cells) = soc_new(1 ,source_cells) -
       * inc; */
      if (loop_ub - 1 >= 0) {
        memcpy(&e_tmp_data[0], &source_cells_data[0], loop_ub * sizeof(double));
      }
      for (i = 0; i < loop_ub; i++) {
        cluster_clt_res_cell_data[i] =
            soc[(int)e_tmp_data[i] - 1] - step_source;
      }
      for (i = 0; i < loop_ub; i++) {
        soc[(int)e_tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
      }
      /* 'balance_soc:256' dec = step_destination; */
      /* 'balance_soc:257' soc_new(1 ,destination_cells) = soc_new(1
       * ,destination_cells) + dec; */
      if (loop_ub_tmp_tmp - 1 >= 0) {
        memcpy(&e_tmp_data[0], &destination_cells_data[0],
               loop_ub_tmp_tmp * sizeof(double));
      }
      for (i = 0; i < loop_ub_tmp_tmp; i++) {
        cluster_clt_res_cell_data[i] =
            soc[(int)e_tmp_data[i] - 1] + step_destination;
      }
      for (i = 0; i < loop_ub_tmp_tmp; i++) {
        soc[(int)e_tmp_data[i] - 1] = cluster_clt_res_cell_data[i];
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
      /* 'balance_soc:272' soc_transfered_s = round(soc_transfered_s * 100) /
       * 100; */
      soc_transfered_s = rt_roundd_snf(soc_transfered_s * 100.0) / 100.0;
      /* 'balance_soc:273' soc_transfered_d = round(soc_transfered_d * 100) /
       * 100; */
      soc_transfered_d = rt_roundd_snf(soc_transfered_d * 100.0) / 100.0;
      /* 'balance_soc:277' if(soc_transfered_s ~= soc_transfered_d) */
      if (!(soc_transfered_s != soc_transfered_d)) {
        /* 'balance_soc:279' else */
        /* 'balance_soc:280' soc_transfered =  soc_transfered_s; */
        soc_transfered = soc_transfered_s;
      } else {
        /* 'balance_soc:278' error("soc transfer mismatch"); */
      }
      /* 'balance_soc:283' blc_time = (soc_transfered/100 * capacity) /
       * blc_current; */
      blc_time = soc_transfered / 100.0 * 2200.0 / 2000.0;
      /* 'balance_soc:285' if sweep_destination > 100 || sweep_destination < 0
       * ... */
      /* 'balance_soc:286'             || sweep_source > 100 || sweep_source < 0
       */
      /* 'balance_soc:290' if coder.target('MATLAB') */
    }
    /*  store charge profile */
    /* 'log_clustering:35' soc_profile(itteration + 2, :) = soc; */
    for (i = 0; i < 9; i++) {
      soc_profile_data[(itteration + 100 * i) + 1] = soc[i];
    }
    /*  clustering */
    /* 'log_clustering:38' [cluster] = pso_DBSCAN(soc, mp, ep); */
    b_pso_DBSCAN(soc, mp, &step_source, &step_destination, source_cells_data,
                 cluster_clt_res_cell, expl_temp, V, &sweep_source,
                 soc_sorted_clusters_data, b_expl_temp, source_clt,
                 destination_clt, c_expl_temp, &d_expl_temp);
    /* 'log_clustering:40' itteration = itteration + 1; */
    itteration++;
    /*  sorting cluster.clt_res_soc_av  */
    /* 'log_clustering:43' V = cluster.clt_res_soc_av; */
    /* 'log_clustering:44' V(V(:,2)==0,2) = Inf; */
    snlc_validity = 0;
    snuc_validity = 0;
    for (loop_ub_tmp_tmp = 0; loop_ub_tmp_tmp < 9; loop_ub_tmp_tmp++) {
      b = (V[loop_ub_tmp_tmp + 9] == 0.0);
      if (b) {
        snlc_validity++;
        c_tmp_data[snuc_validity] = (signed char)(loop_ub_tmp_tmp + 1);
        snuc_validity++;
      }
    }
    for (i = 0; i < snlc_validity; i++) {
      V[c_tmp_data[i] + 8] = rtInf;
    }
    /* 'log_clustering:45' cluster.clt_res_soc_av = sortrows(V, 2,'ascend'); */
    c_sortrows(V);
    /* 'log_clustering:46'
     * cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0; */
    snlc_validity = 0;
    snuc_validity = 0;
    for (loop_ub_tmp_tmp = 0; loop_ub_tmp_tmp < 9; loop_ub_tmp_tmp++) {
      b = (V[loop_ub_tmp_tmp + 9] == rtInf);
      if (b) {
        snlc_validity++;
        d_tmp_data[snuc_validity] = (signed char)(loop_ub_tmp_tmp + 1);
        snuc_validity++;
      }
    }
    for (i = 0; i < snlc_validity; i++) {
      V[d_tmp_data[i] + 8] = 0.0;
    }
    /* 'log_clustering:47' soc_transfered_total = soc_transfered_total +
     * soc_transfered; */
    /* 'log_clustering:48' blc_time_total = blc_time_total + blc_time; */
    *lg_time += blc_time;
    /* 'log_clustering:50' if itteration > 20 */
    if (itteration > 20) {
      /*  error("maximum itteration reached"); */
      /*  disp("maximum itteration reached"); */
      exitg1 = true;
    }
  }
  emxFree_real_T(&soc_sorted_clusters);
  /* 'log_clustering:58' if coder.target('MATLAB') */
  /* 'log_clustering:62' soc_profile(any(isnan(soc_profile), 2), :) = []; */
  for (i = 0; i < 900; i++) {
    tmp_data[i] = rtIsNaN(soc_profile_data[i]);
  }
  any(tmp_data, b_tmp_data, &snuc_validity);
  nullAssignment(soc_profile_data, soc_profile_size, b_tmp_data);
  /*  Remove any row with NaN */
  /* 'log_clustering:64' ep_i = find(ep_arr == ep); */
  /* 'log_clustering:66' lg_time(ep_i) = blc_time_total; */
  /* 'log_clustering:67' lg_inconsistency(ep_i) = max(soc) - min(soc); */
  *lg_inconsistency = f_maximum(soc) - e_minimum(soc);
  /*  summing equalization overlap value of each cell after balancing  */
  /* 'log_clustering:70' for n = 1:cluster.cell_cnt */
  loop_ub = soc_profile_size[0];
  b_soc_profile_size[0] = 1;
  b_soc_profile_size[1] = loop_ub;
  for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
    double b_soc_profile_data[100];
    /* 'log_clustering:71' OE = calculate_overlap(soc_profile(:, n)'); */
    for (i = 0; i < loop_ub; i++) {
      b_soc_profile_data[i] =
          soc_profile_data[i + soc_profile_size[0] * snuc_validity];
    }
    step_source = calculate_overlap(b_soc_profile_data, b_soc_profile_size);
    /* 'log_clustering:72' lg_eq_overlap(ep_i) = lg_eq_overlap(ep_i) + OE; */
    *lg_eq_overlap += step_source;
  }
  /* 'log_clustering:79' figure; */
  /* 'log_clustering:80' tiledlayout(3 ,1); */
  /*  Create a 2x1 grid layout */
  /* 'log_clustering:82' nexttile; */
  /* 'log_clustering:83' plot(ep_arr', lg_inconsistency); */
  /* 'log_clustering:84' title('inconsistency') */
  /* 'log_clustering:85' xlabel('eps') */
  /* 'log_clustering:86' ylabel('% SOC') */
  /* 'log_clustering:91' nexttile; */
  /* 'log_clustering:92' plot(ep_arr', lg_time); */
  /* 'log_clustering:93' title('equalization time') */
  /* 'log_clustering:94' xlabel('eps') */
  /* 'log_clustering:95' ylabel('time(h)') */
  /* 'log_clustering:97' nexttile; */
  /* 'log_clustering:98' plot(ep_arr', lg_eq_overlap); */
  /* 'log_clustering:99' title('equalization overlap') */
  /* 'log_clustering:100' xlabel('eps') */
  /* 'log_clustering:101' ylabel('% SOC') */
}

/*
 * File trailer for log_clustering.c
 *
 * [EOF]
 */
