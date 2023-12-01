/*
 * File: log_clustering.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/* Include Files */
#include "log_clustering.h"
#include "minOrMax.h"
#include "pso_DBSCAN.h"
#include "pso_internal_types.h"
#include "rt_nonfinite.h"
#include "sortrows.h"

/* Function Definitions */
/*
 * function [lg_time, lg_inconsistency, lg_eq_overlap] = log_clustering(soc_in,
 * mp, ep_arr)
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double *lg_inconsistency
 *                double *lg_eq_overlap
 * Return Type  : double
 */
double log_clustering(const double soc_in[9], double mp,
                      double *lg_inconsistency, double *lg_eq_overlap)
{
  double cluster_clt_res_cell[81];
  double expl_temp[81];
  double b_expl_temp[18];
  double cluster_clt_res_soc_av[18];
  double soc_sorted_clusters_data[18];
  double source_cells_data[9];
  double c_expl_temp[2];
  double cluster_noise_max[2];
  double cluster_noise_min[2];
  double cluster_clt_max_count;
  double d_expl_temp;
  double lg_time;
  int soc_sorted_clusters_size[2];
  int source_cells_size[2];
  int i;
  int snuc_validity;
  e_noise_stat e_expl_temp;
  /* coder.extrinsic('plot', 'nexttile', 'tiledlayout'); */
  /* cell_count = length(soc_in); */
  /* soc_profile = zeros(1, cell_count); */
  /* coder.varsize('soc_profile', [inf, cell_count], [1, 0]); */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* lg_time = zeros(length(ep_arr), 1); */
  /* lg_inconsistency = zeros(length(ep_arr), 1); */
  /* lg_eq_overlap = zeros(length(ep_arr), 1); */
  *lg_eq_overlap = 0.0;
  /* coder.varsize('soc_profile', [inf, 9], [1, 0]); */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* for ep = ep_arr */
  /* soc = soc_in; */
  /* itteration = 0; */
  /* soc_transfered_total = 0; */
  /* blc_time_total = 0; */
  /* soc_profile(itteration + 1, :) = soc; */
  /*  clustering */
  /* [cluster] = pso_DBSCAN(soc, mp, ep); */
  b_pso_DBSCAN(soc_in, mp, &d_expl_temp, source_cells_data,
               cluster_clt_res_cell, expl_temp, cluster_clt_res_soc_av,
               &cluster_clt_max_count, soc_sorted_clusters_data, b_expl_temp,
               cluster_noise_max, cluster_noise_min, c_expl_temp, &e_expl_temp);
  /* while cluster.clt_max_count > 1 */
  if (cluster_clt_max_count > 1.0) {
    int n;
    int snlc_validity;
    /*  balancing */
    /* [soc_transfered, soc, blc_time] = balance_soc(cluster, soc, mp, ep, 1,
     * 2200, 2000); */
    /* 	%% init */
    /* blc_time = 0; */
    /* soc_out = soc_in; */
    /* soc_transfered_s = 0; */
    /* soc_transfered_d = 0; */
    /* soc_transfered = 0; */
    /* cell_count = length(soc_in); */
    /*  equalization steps storage */
    /* eq_step.source_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell] */
    /* eq_step.destination_queue_cells = [0, 0]; */
    /*  [start_cell, stop_cell]        */
    /* eq_step.source_target_soc_av = 0; */
    /*  [src cluster average soc]   */
    /* eq_step.destination_target_soc_av = 0; */
    /*  [des cluster average soc] */
    /*  validity of source/destination cluster neighbors (valid by default) */
    /* snlc_validity = 1; */
    /* snuc_validity = 1; */
    /* dnlc_validity = 1; */
    /* dnuc_validity = 1; */
    /*  conditional flag */
    /* soc_mismatch = 1; */
    /*  valid balance range soc */
    /* blc_range = 2; */
    /*  assaign weight to each noise cluster by each cell in it */
    /*  number of elements in noise clusters */
    /* source_clt_cnt = nnz(cluster.clt_res_cell(cluster.noise_max(1, 1), :));
     */
    snlc_validity = -1;
    /* destination_clt_cnt = nnz(cluster.clt_res_cell(cluster.noise_min(1, 1),
     * :)); */
    n = -1;
    for (snuc_validity = 0; snuc_validity < 9; snuc_validity++) {
      if (cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * snuc_validity) -
                               1] != 0.0) {
        snlc_validity++;
      }
      if (cluster_clt_res_cell[((int)cluster_noise_min[0] + 9 * snuc_validity) -
                               1] != 0.0) {
        n++;
      }
    }
    /* 	%% define source and destination clusters */
    /* source_clt = cluster.noise_max; */
    /* destination_clt = cluster.noise_min; */
    /*  find neighbor cells of each source and destination cell */
    /*  source cluster neighbors */
    /* source_cells = cluster.clt_res_cell(source_clt(1, 1), 1:source_clt_cnt);
     */
    if (snlc_validity + 1 < 1) {
      snlc_validity = -1;
    }
    source_cells_size[0] = 1;
    source_cells_size[1] = snlc_validity + 1;
    for (i = 0; i <= snlc_validity; i++) {
      source_cells_data[i] =
          cluster_clt_res_cell[((int)cluster_noise_max[0] + 9 * i) - 1];
    }
    /* source_neighbor_lower_cell = min(source_cells) - 1; */
    d_expl_temp = c_minimum(source_cells_data, source_cells_size);
    /*  the source cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* if source_neighbor_lower_cell  > 0 */
    if (d_expl_temp - 1.0 > 0.0) {
      /* if soc_out(1, source_neighbor_lower_cell) < source_clt(2 ,1) */
      if (soc_in[(int)(d_expl_temp - 1.0) - 1] < cluster_noise_max[1]) {
        /* snlc_validity = 1; */
        snlc_validity = 1;
      } else {
        /* else */
        /* snlc_validity = 0; */
        snlc_validity = 0;
      }
    } else {
      /* else */
      /* snlc_validity = 0; */
      snlc_validity = 0;
    }
    /* source_neighbor_upper_cell = max(source_cells) + 1; */
    d_expl_temp = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* if source_neighbor_upper_cell <= cell_count */
    if (d_expl_temp + 1.0 <= 9.0) {
      /* if soc_out(1, source_neighbor_upper_cell) < source_clt(2 ,1) */
      if (soc_in[(int)(d_expl_temp + 1.0) - 1] < cluster_noise_max[1]) {
        /* snuc_validity = 1; */
        snuc_validity = 1;
      } else {
        /* else */
        /* snuc_validity = 0; */
        snuc_validity = 0;
      }
    } else {
      /* else */
      /* snuc_validity = 0; */
      snuc_validity = 0;
    }
    /*  check if any valid neighbor found */
    /* if snlc_validity || snuc_validity */
    if ((snlc_validity == 0) && (snuc_validity == 0)) {
      /* else */
      /*  select a source cluster with valid neighbors */
      /*  sorting */
      /* soc_sorted_clusters =
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
      /* [source_clt(2, 1), source_clt(1, 1)] =
       * max(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      /*  number of elements in the clusters */
      /* source_clt_cnt = nnz(cluster.clt_res_cell(source_clt(1, 1), :)); */
      /*  source cluster neighbors */
      /* source_cells = cluster.clt_res_cell(source_clt(1, 1),
       * 1:source_clt_cnt); */
      /* source_neighbor_lower_cell = min(source_cells) - 1; */
      /* source_neighbor_upper_cell = max(source_cells) + 1; */
    } else {
      /*  we are good */
    }
    /*  destination cluster neighbors */
    /* destination_cells = cluster.clt_res_cell(destination_clt(1, 1),
     * 1:destination_clt_cnt); */
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
    /* destination_neighbor_lower_cell = min(destination_cells) - 1; */
    d_expl_temp = c_minimum(source_cells_data, source_cells_size);
    /*  the destination cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* if destination_neighbor_lower_cell  > 0 */
    if (d_expl_temp - 1.0 > 0.0) {
      /* if soc_out(1, destination_neighbor_lower_cell) > destination_clt(2 ,1)
       */
      if (soc_in[(int)(d_expl_temp - 1.0) - 1] > cluster_noise_min[1]) {
        /* dnlc_validity = 1; */
        snlc_validity = 1;
      } else {
        /* else */
        /* dnlc_validity = 0; */
        snlc_validity = 0;
      }
    } else {
      /* else */
      /* dnlc_validity = 0; */
      snlc_validity = 0;
    }
    /* destination_neighbor_upper_cell = max(destination_cells) + 1; */
    d_expl_temp = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* if destination_neighbor_upper_cell <= cell_count */
    if (d_expl_temp + 1.0 <= 9.0) {
      /* if soc_out(1, destination_neighbor_upper_cell) > destination_clt(2 ,1)
       */
      if (soc_in[(int)(d_expl_temp + 1.0) - 1] > cluster_noise_min[1]) {
        /* dnuc_validity = 1; */
        snuc_validity = 1;
      } else {
        /* else */
        /* dnuc_validity = 0; */
        snuc_validity = 0;
      }
    } else {
      /* else */
      /* dnuc_validity = 0; */
      snuc_validity = 0;
    }
    /*  check if any valid neighbor found */
    /* if dnlc_validity || dnuc_validity */
    if ((snlc_validity == 0) && (snuc_validity == 0)) {
      /* else */
      /*  select a destination cluster with valid neighbors */
      /*  sorting */
      /* soc_sorted_clusters =
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
      /* [destination_clt(2, 1), destination_clt(1, 1)] =
       * min(soc_sorted_clusters([1:cluster.clt_max_count]', 1)); */
      /*  number of elements in the clusters */
      /* destination_clt_cnt = nnz(cluster.clt_res_cell(destination_clt(1, 1),
       * :)); */
      /*  destination cluster neighbors */
      /* destination_cells = cluster.clt_res_cell(destination_clt(1, 1),
       * 1:destination_clt_cnt); */
      /* destination_neighbor_lower_cell = min(destination_cells) - 1; */
      /* destination_neighbor_upper_cell = max(destination_cells) + 1; */
    } else {
      /*  we are good */
    }
    /*  store source and destination clusters */
    /* eq_step.source_queue_cells = [source_neighbor_lower_cell + 1,
     * source_neighbor_upper_cell - 1]; */
    /* eq_step.destination_queue_cells = [destination_neighbor_lower_cell + 1,
     * destination_neighbor_upper_cell - 1]; */
    /* 	%% calculate soc step to balance */
    /*  assign step = 1 to lower cluster member count */
    /* if destination_clt_cnt < source_clt_cnt */
    /*  soc sweep initialization */
    /* sweep_source = source_clt(2, 1); */
    /* sweep_destination = destination_clt(2, 1); */
    /*  calculation for noise_max */
    /*  selecting maximum noise to calculate neighbor distances */
    /* clt_number_max = source_clt(1, 1); */
    /* clt_number_min = destination_clt(1, 1); */
    /* noise_max_pre = source_clt; */
    /* noise_min_pre = destination_clt; */
    /* 	%% equalizing */
    /* while soc_mismatch */
    /*  store charge profile */
    /* soc_profile(itteration + 2, :) = soc; */
    /* A check that is always false is detected at compile-time. Eliminating
     * code that follows. */
  }
  /* clear soc_transfered V  blc_time */
  /* ep_i = find(ep_arr == ep); */
  /* lg_time(ep_i) = blc_time_total; */
  lg_time = 0.0;
  /* lg_inconsistency(ep_i) = max(soc) - min(soc); */
  *lg_inconsistency = e_maximum(soc_in) - d_minimum(soc_in);
  /*  summing equalization overlap value of each cell after balancing  */
  /* for n = 1:cluster.cell_cnt */
  /* figure; */
  /* tiledlayout(3 ,1); */
  /*  Create a 2x1 grid layout */
  /* nexttile; */
  /* plot(ep_arr', lg_inconsistency); */
  /* title('inconsistency') */
  /* xlabel('eps') */
  /* ylabel('% SOC') */
  /* nexttile; */
  /* plot(ep_arr', lg_time); */
  /* title('equalization time') */
  /* xlabel('eps') */
  /* ylabel('time(h)') */
  /* nexttile; */
  /* plot(ep_arr', lg_eq_overlap); */
  /* title('equalization overlap') */
  /* xlabel('eps') */
  /* ylabel('% SOC') */
  return lg_time;
}

/*
 * File trailer for log_clustering.c
 *
 * [EOF]
 */
