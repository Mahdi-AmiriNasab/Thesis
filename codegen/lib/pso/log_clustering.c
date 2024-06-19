/*
 * File: log_clustering.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "log_clustering.h"
#include "any.h"
#include "calculate_overlap.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "pso_DBSCAN.h"
#include "pso_internal_types.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * function [lg_time, lg_inconsistency, lg_eq_overlap, soc_profile] =
 * log_clustering(soc_in, mp, ep_arr)
 *
 * global no_ovp_plot_flag;
 *  if isempty(no_ovp_plot_flag)
 *   no_ovp_plot_flag = 0;
 * end
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double *lg_inconsistency
 *                double *lg_eq_overlap
 *                double soc_profile_data[]
 *                int soc_profile_size[2]
 * Return Type  : double
 */
double log_clustering(const double soc_in[9], double mp,
                      double *lg_inconsistency, double *lg_eq_overlap,
                      double soc_profile_data[], int soc_profile_size[2])
{
  static double cluster_clt_res_cell[81];
  static double expl_temp[81];
  static double b_expl_temp[18];
  static double cluster_clt_res_soc_av[18];
  static double soc_sorted_clusters_data[18];
  static double source_cells_data[9];
  static bool tmp_data[900];
  static bool b_tmp_data[100];
  double c_expl_temp[2];
  double cluster_noise_max[2];
  double cluster_noise_min[2];
  double OE;
  double cluster_clt_max_count;
  double lg_time;
  int b_soc_profile_size[2];
  int soc_sorted_clusters_size[2];
  int source_cells_size[2];
  int tmp_size[2];
  int i;
  int snlc_validity;
  int snuc_validity;
  e_noise_stat d_expl_temp;
  /* 'log_clustering:7' coder.extrinsic('plot', 'nexttile', 'tiledlayout',
   * 'figure', 'set', 'ylabel', 'title', 'xlabel', 'yyaxis', 'gca'); */
  /* 'log_clustering:9' cell_count = length(soc_in); */
  /* 'log_clustering:11' soc_profile = zeros(1, cell_count); */
  /* 'log_clustering:12' soc_profile_index = 0; */
  /* 'log_clustering:13' coder.varsize('soc_profile', [inf, cell_count], [1,
   * 0]); */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* 'log_clustering:14' soc_profile = NaN(100, cell_count); */
  /* 'log_clustering:16' lg_time = zeros(length(ep_arr), 1); */
  /* 'log_clustering:17' lg_inconsistency = zeros(length(ep_arr), 1); */
  /* 'log_clustering:18' lg_eq_overlap = zeros(length(ep_arr), 1); */
  *lg_eq_overlap = 0.0;
  /* 'log_clustering:20' for ep = ep_arr */
  /* 'log_clustering:22' soc = soc_in; */
  /* 'log_clustering:23' itteration = 0; */
  /* 'log_clustering:24' soc_transfered_total = 0; */
  /* 'log_clustering:25' blc_time_total = 0; */
  /* 'log_clustering:27' soc_profile = zeros(1, cell_count); */
  soc_profile_size[0] = 1;
  soc_profile_size[1] = 9;
  memset(&soc_profile_data[0], 0, 9U * sizeof(double));
  /* 'log_clustering:28' soc_profile(itteration + 1, :) = soc; */
  memcpy(&soc_profile_data[0], &soc_in[0], 9U * sizeof(double));
  /*  clustering */
  /* 'log_clustering:32' [cluster] = pso_DBSCAN(soc, mp, ep); */
  b_pso_DBSCAN(soc_in, mp, &OE, source_cells_data, cluster_clt_res_cell,
               expl_temp, cluster_clt_res_soc_av, &cluster_clt_max_count,
               soc_sorted_clusters_data, b_expl_temp, cluster_noise_max,
               cluster_noise_min, c_expl_temp, &d_expl_temp);
  /* 'log_clustering:34' while cluster.clt_max_count > 1 */
  if (cluster_clt_max_count > 1.0) {
    int n;
    /*  balancing */
    /* 'log_clustering:38' [soc_transfered, soc, blc_time] =
     * balance_soc(cluster, soc, mp, ep, 2200, 2000); */
    /* 	%% init */
    /* 'balance_soc:4' blc_time = 0; */
    /* 'balance_soc:5' blc_range = ep; */
    /* 'balance_soc:6' soc_out = soc_in; */
    /* 'balance_soc:7' soc_transfered_s = 0; */
    /* 'balance_soc:7' soc_transfered_d = 0; */
    /* 'balance_soc:8' soc_transfered = 0; */
    /* 'balance_soc:9' cell_count = length(soc_in); */
    /*  equalization steps storage */
    /* 'balance_soc:12' eq_step.source_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell] */
    /* 'balance_soc:14' eq_step.destination_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell]        */
    /* 'balance_soc:16' eq_step.source_target_soc_av = 0; */
    /*  [src cluster average soc]   */
    /* 'balance_soc:18' eq_step.destination_target_soc_av = 0; */
    /*  [des cluster average soc] */
    /* 'balance_soc:20' soc_diff_s = 0; */
    /*  Initialize soc_diff_s */
    /* 'balance_soc:21' soc_diff_d = 0; */
    /*  Initialize soc_diff_d */
    /*  validity of source/destination cluster neighbors (valid by default) */
    /* 'balance_soc:24' snlc_validity = 1; */
    /* 'balance_soc:25' snuc_validity = 1; */
    /* 'balance_soc:27' dnlc_validity = 1; */
    /* 'balance_soc:28' dnuc_validity = 1; */
    /*  conditional flag */
    /* 'balance_soc:31' soc_mismatch = 1; */
    /*  valid balance range soc */
    /* blc_range = 2; */
    /*  assaign weight to each noise cluster by each cell in it */
    /*  number of elements in noise clusters */
    /* 'balance_soc:38' source_clt_cnt =
     * nnz(cluster.clt_res_cell(cluster.noise_max(1, 1), :)); */
    snuc_validity = -1;
    /* 'balance_soc:39' destination_clt_cnt =
     * nnz(cluster.clt_res_cell(cluster.noise_min(1, 1), :)); */
    n = -1;
    for (snlc_validity = 0; snlc_validity < 9; snlc_validity++) {
      if (cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * snlc_validity) -
                               1] != 0.0) {
        snuc_validity++;
      }
      if (cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * snlc_validity) -
                               1] != 0.0) {
        n++;
      }
    }
    /* 	%% define source and destination clusters */
    /* 'balance_soc:42' source_clt = cluster.noise_max; */
    /* 'balance_soc:43' destination_clt = cluster.noise_min; */
    /*  find neighbor cells of each source and destination cell */
    /*  source cluster neighbors */
    /* 'balance_soc:47' source_cells = cluster.clt_res_cell(source_clt(1, 1),
     * 1:source_clt_cnt); */
    if (snuc_validity + 1 < 1) {
      snlc_validity = -1;
    } else {
      snlc_validity = snuc_validity;
    }
    source_cells_size[0] = 1;
    source_cells_size[1] = snlc_validity + 1;
    for (i = 0; i <= snlc_validity; i++) {
      source_cells_data[i] =
          cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
    }
    /* 'balance_soc:49' source_neighbor_lower_cell = min(source_cells) - 1; */
    OE = c_minimum(source_cells_data, source_cells_size);
    /*  the source cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* 'balance_soc:53' if source_neighbor_lower_cell  > 0 */
    if (OE - 1.0 > 0.0) {
      /* 'balance_soc:54' if soc_out(1, source_neighbor_lower_cell) <
       * source_clt(2 ,1) */
      if (soc_in[(int)(OE - 1.0) - 1] < cluster_noise_max[1]) {
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
    OE = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* 'balance_soc:66' if source_neighbor_upper_cell <= cell_count */
    if (OE + 1.0 <= 9.0) {
      /* 'balance_soc:67' if soc_out(1, source_neighbor_upper_cell) <
       * source_clt(2 ,1) */
      if (soc_in[(int)(OE + 1.0) - 1] < cluster_noise_max[1]) {
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
    if ((snlc_validity == 0) && (snuc_validity == 0)) {
      /* 'balance_soc:79' else */
      /*  select a source cluster with valid neighbors */
      /*  sorting */
      /* 'balance_soc:83' soc_sorted_clusters =
       * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2,
       * 'ascend'); */
      snlc_validity = (int)cluster_clt_max_count;
      soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
      soc_sorted_clusters_size[1] = 2;
      for (i = 0; i < 2; i++) {
        for (snuc_validity = 0; snuc_validity < snlc_validity;
             snuc_validity++) {
          soc_sorted_clusters_data[snuc_validity +
                                   (int)cluster_clt_max_count * i] =
              cluster_clt_res_soc_av[snuc_validity + 9 * i];
        }
      }
      b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
      /*  pick the maximum soc cluster regarding noise  */
      /* 'balance_soc:85' [source_clt(2, 1), source_clt(1, 1)] =
       * max(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      /*  number of elements in the clusters */
      /* 'balance_soc:88' source_clt_cnt =
       * nnz(cluster.clt_res_cell(source_clt(1, 1), :)); */
      /*  source cluster neighbors */
      /* 'balance_soc:91' source_cells = cluster.clt_res_cell(source_clt(1, 1),
       * 1:source_clt_cnt); */
      /* 'balance_soc:92' source_neighbor_lower_cell = min(source_cells) - 1; */
      /* 'balance_soc:93' source_neighbor_upper_cell = max(source_cells) + 1; */
    } else {
      /*  we are good */
    }
    /*  destination cluster neighbors */
    /* 'balance_soc:98' destination_cells =
     * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
    if (n + 1 < 1) {
      snlc_validity = -1;
    } else {
      snlc_validity = n;
    }
    source_cells_size[0] = 1;
    source_cells_size[1] = snlc_validity + 1;
    for (i = 0; i <= snlc_validity; i++) {
      source_cells_data[i] =
          cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * i) - 1];
    }
    /* 'balance_soc:100' destination_neighbor_lower_cell =
     * min(destination_cells) - 1; */
    OE = c_minimum(source_cells_data, source_cells_size);
    /*  the destination cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* 'balance_soc:104' if destination_neighbor_lower_cell  > 0 */
    if (OE - 1.0 > 0.0) {
      /* 'balance_soc:105' if soc_out(1, destination_neighbor_lower_cell) >
       * destination_clt(2 ,1) */
      if (soc_in[(int)(OE - 1.0) - 1] > cluster_noise_min[1]) {
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
    /* 'balance_soc:114' destination_neighbor_upper_cell =
     * max(destination_cells) + 1; */
    OE = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* 'balance_soc:117' if destination_neighbor_upper_cell <= cell_count */
    if (OE + 1.0 <= 9.0) {
      /* 'balance_soc:118' if soc_out(1, destination_neighbor_upper_cell) >
       * destination_clt(2 ,1) */
      if (soc_in[(int)(OE + 1.0) - 1] > cluster_noise_min[1]) {
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
       * sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2,
       * 'ascend'); */
      snlc_validity = (int)cluster_clt_max_count;
      soc_sorted_clusters_size[0] = (int)cluster_clt_max_count;
      soc_sorted_clusters_size[1] = 2;
      for (i = 0; i < 2; i++) {
        for (snuc_validity = 0; snuc_validity < snlc_validity;
             snuc_validity++) {
          soc_sorted_clusters_data[snuc_validity +
                                   (int)cluster_clt_max_count * i] =
              cluster_clt_res_soc_av[snuc_validity + 9 * i];
        }
      }
      b_sortrows(soc_sorted_clusters_data, soc_sorted_clusters_size);
      /*  pick the minimum soc cluster regarding noise  */
      /* 'balance_soc:136' [destination_clt(2, 1), destination_clt(1, 1)] =
       * min(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      /*  number of elements in the clusters */
      /* 'balance_soc:139' destination_clt_cnt =
       * nnz(cluster.clt_res_cell(destination_clt(1, 1), :)); */
      /*  destination cluster neighbors */
      /* 'balance_soc:142' destination_cells =
       * cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt); */
      /* 'balance_soc:143' destination_neighbor_lower_cell =
       * min(destination_cells) - 1; */
      /* 'balance_soc:144' destination_neighbor_upper_cell =
       * max(destination_cells) + 1; */
    } else {
      /*  we are good */
    }
    /*  store source and destination clusters */
    /* 'balance_soc:149' eq_step.source_queue_cells =
     * [source_neighbor_lower_cell + 1, source_neighbor_upper_cell - 1]; */
    /* 'balance_soc:150' eq_step.destination_queue_cells =
     * [destination_neighbor_lower_cell + 1, destination_neighbor_upper_cell -
     * 1]; */
    /* 	%% calculate soc step to balance */
    /*  assign step = 1 to lower cluster member count */
    /* 'balance_soc:154' if destination_clt_cnt < source_clt_cnt */
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
    /* 		%% calculate balancing time */
    /* 'balance_soc:300' source_batt_number = source_clt_cnt; */
    /* 'balance_soc:301' destination_batt_number = destination_clt_cnt; */
    /*  calculate balancing current */
    /* 'balance_soc:306' if (source_batt_number > destination_batt_number) */
    /*  calculate the final balancing time (hour) */
    /* 'balance_soc:318' blc_time = cap_diff / blc_current_actual; */
    /*  convert to seconds */
    /* 'balance_soc:321' blc_time = blc_time * 60 * 60; */
    /*  store charge profile */
    /* 'log_clustering:41' soc_profile(itteration + 2, :) = soc; */
    /* A check that is always false is detected at compile-time. Eliminating
     * code that follows. */
  }
  /* 'log_clustering:64' if coder.target('MATLAB') */
  /* 'log_clustering:68' soc_profile(any(isnan(soc_profile), 2), :) = []; */
  tmp_size[0] = 1;
  tmp_size[1] = 9;
  for (i = 0; i < 9; i++) {
    tmp_data[i] = rtIsNaN(soc_profile_data[i]);
  }
  snlc_validity = any(tmp_data, tmp_size, b_tmp_data);
  nullAssignment(soc_profile_data, soc_profile_size, b_tmp_data, snlc_validity);
  /*  Remove any row with NaN */
  /*  soc_profile(itteration + 2, :) = [];                  % Remove any row
   * with NaN */
  /* 'log_clustering:71' ep_i = find(ep_arr == ep); */
  /* 'log_clustering:73' lg_time(ep_i) = blc_time_total; */
  lg_time = 0.0;
  /* 'log_clustering:74' lg_inconsistency(ep_i) = max(soc) - min(soc); */
  *lg_inconsistency = f_maximum(soc_in) - e_minimum(soc_in);
  /*  summing equalization overlap value of each cell after balancing  */
  /* 'log_clustering:76' for n = 1:cluster.cell_cnt */
  snlc_validity = soc_profile_size[0];
  b_soc_profile_size[0] = 1;
  b_soc_profile_size[1] = soc_profile_size[0];
  for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
    /*  no_ovp_plot_flag = 0; */
    /* 'log_clustering:78' OE = calculate_overlap(soc_profile(:, n)'); */
    for (i = 0; i < snlc_validity; i++) {
      OE = soc_profile_data[i + soc_profile_size[0] * snuc_validity];
    }
    OE = calculate_overlap((double *)&OE, b_soc_profile_size);
    /* 'log_clustering:79' lg_eq_overlap(ep_i) = lg_eq_overlap(ep_i) + OE; */
    *lg_eq_overlap += OE;
  }
  /* 'log_clustering:85' if coder.target('MATLAB') */
  return lg_time;
}

/*
 * File trailer for log_clustering.c
 *
 * [EOF]
 */
