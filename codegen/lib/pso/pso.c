/*
 * File: pso.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/* Include Files */
#include "pso.h"
#include "log_clustering.h"
#include "minOrMax.h"
#include "pso_DBSCAN.h"
#include "pso_data.h"
#include "pso_initialize.h"
#include "pso_internal_types.h"
#include "pso_types.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double position;
  double cost;
  double velocity;
  struct0_T best;
} struct_T;
#endif /* typedef_struct_T */

/* Function Declarations */
static double pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                           double w_inconsistency, double w_eq_overlap,
                           double ep, int c_varargout_2_source_queue_cell[2],
                           int c_varargout_2_destination_queue[2],
                           int *c_varargout_2_source_target_soc,
                           int *c_varargout_2_destination_targe,
                           double varargout_3[9], double *varargout_4,
                           double *varargout_5, double *varargout_6);

/* Function Definitions */
/*
 * @(ep)
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double w_time
 *                double w_inconsistency
 *                double w_eq_overlap
 *                double ep
 *                int c_varargout_2_source_queue_cell[2]
 *                int c_varargout_2_destination_queue[2]
 *                int *c_varargout_2_source_target_soc
 *                int *c_varargout_2_destination_targe
 *                double varargout_3[9]
 *                double *varargout_4
 *                double *varargout_5
 *                double *varargout_6
 * Return Type  : double
 */
static double pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                           double w_inconsistency, double w_eq_overlap,
                           double ep, int c_varargout_2_source_queue_cell[2],
                           int c_varargout_2_destination_queue[2],
                           int *c_varargout_2_source_target_soc,
                           int *c_varargout_2_destination_targe,
                           double varargout_3[9], double *varargout_4,
                           double *varargout_5, double *varargout_6)
{
  static double max_t_res;
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
  double lg_inconsistency;
  int soc_sorted_clusters_size[2];
  int source_cells_size[2];
  int i;
  int snuc_validity;
  e_noise_stat e_expl_temp;
  /* @(ep) balance_costF(soc_in, mp, ep, w_time, w_inconsistency, w_eq_overlap)
   */
  /* cell_count = length(soc_in); */
  /* eq_step = struct('source_queue_cells', zeros(0,2),... */
  /*                      'destination_queue_cells', zeros(0,2),... */
  /*                      'source_target_soc_av', zeros(0,1),... */
  /*                      'destination_target_soc_av', zeros(0,1)); */
  /* coder.varsize('eq_step.source_queue_cells', [inf, 2], [1, 0]); */
  /* coder.varsize('eq_step.destination_queue_cells', [inf, 2], [1, 0]); */
  /* coder.varsize('eq_step.source_target_soc_av', [inf, 1], [1, 0]); */
  /* coder.varsize('eq_step.destination_target_soc_av', [inf, 1], [1, 0]); */
  /* soc_profile = zeros(1, cell_count); */
  /* coder.varsize('soc_profile', [inf, cell_count], [1, 0]); */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /*  equalization steps storage */
  /* eq_step.source_queue_cells = []; */
  c_varargout_2_source_queue_cell[0] = 0;
  c_varargout_2_source_queue_cell[1] = 2;
  /*  [start_cell, stop_cell]       step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n */
  /* eq_step.destination_queue_cells = []; */
  c_varargout_2_destination_queue[0] = 0;
  c_varargout_2_destination_queue[1] = 2;
  /*  [start_cell, stop_cell]       step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n */
  /* eq_step.source_target_soc_av = []; */
  *c_varargout_2_source_target_soc = 0;
  /*  [src cluster average soc]     step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n      */
  /* eq_step.destination_target_soc_av = []; */
  *c_varargout_2_destination_targe = 0;
  /*  [des cluster average soc]     step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n      */
  /* lg_time = 0; */
  /* lg_inconsistency = 0; */
  /* lg_eq_overlap = 0; */
  /*  assume eps = 0.1         */
  /*  maximum possible values */
  /* max_lg_time = 1.5; */
  /* max_lg_inconsistency = 100; */
  /* max_lg_eq_overlap = 300; */
  /*  w_time = 0.8;           % weight for time */
  /*  w_inconsistency = 0.2;  % weight for inconsitency */
  /*  w_eq_overlap = 0;     % weight for overlap equalization */
  /* soc = soc_in; */
  memcpy(&varargout_3[0], &soc_in[0], 9U * sizeof(double));
  /* itteration = 0; */
  /* soc_transfered_total = 0; */
  /* blc_time_total = 0; */
  /* soc_profile(itteration + 1, :) = soc; */
  /*  clustering */
  /* [cluster] = pso_DBSCAN(soc, mp, ep); */
  pso_DBSCAN(soc_in, mp, ep, &d_expl_temp, source_cells_data,
             cluster_clt_res_cell, expl_temp, cluster_clt_res_soc_av,
             &cluster_clt_max_count, soc_sorted_clusters_data, b_expl_temp,
             cluster_noise_max, cluster_noise_min, c_expl_temp, &e_expl_temp);
  /* while cluster.clt_max_count > 1 */
  if (cluster_clt_max_count > 1.0) {
    int n;
    int snlc_validity;
    /*  balancing */
    /* [soc_transfered, soc, blc_time, eq_step(itteration + 1)] =
     * balance_soc(cluster, soc, mp, ep, 1, 2200, 2000); */
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
    lg_inconsistency = c_minimum(source_cells_data, source_cells_size);
    /*  the source cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* if source_neighbor_lower_cell  > 0 */
    if (lg_inconsistency - 1.0 > 0.0) {
      /* if soc_out(1, source_neighbor_lower_cell) < source_clt(2 ,1) */
      if (varargout_3[(int)(lg_inconsistency - 1.0) - 1] <
          cluster_noise_max[1]) {
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
    lg_inconsistency = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* if source_neighbor_upper_cell <= cell_count */
    if (lg_inconsistency + 1.0 <= 9.0) {
      /* if soc_out(1, source_neighbor_upper_cell) < source_clt(2 ,1) */
      if (varargout_3[(int)(lg_inconsistency + 1.0) - 1] <
          cluster_noise_max[1]) {
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
    lg_inconsistency = c_minimum(source_cells_data, source_cells_size);
    /*  the destination cell must have a lower value neighbor */
    /*  check the validity of lower cell */
    /* if destination_neighbor_lower_cell  > 0 */
    if (lg_inconsistency - 1.0 > 0.0) {
      /* if soc_out(1, destination_neighbor_lower_cell) > destination_clt(2 ,1)
       */
      if (varargout_3[(int)(lg_inconsistency - 1.0) - 1] >
          cluster_noise_min[1]) {
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
    lg_inconsistency = d_maximum(source_cells_data, source_cells_size);
    /*  check the validity of upper cell */
    /* if destination_neighbor_upper_cell <= cell_count */
    if (lg_inconsistency + 1.0 <= 9.0) {
      /* if soc_out(1, destination_neighbor_upper_cell) > destination_clt(2 ,1)
       */
      if (varargout_3[(int)(lg_inconsistency + 1.0) - 1] >
          cluster_noise_min[1]) {
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
  /* lg_time = blc_time_total; */
  /* lg_inconsistency = max(soc) - min(soc); */
  lg_inconsistency = e_maximum(varargout_3) - d_minimum(varargout_3);
  /*  summing equalization overlap value of each cell after balancing  */
  /* for n = 1:cluster.cell_cnt */
  /*  results */
  /* time = lg_time; */
  *varargout_4 = 0.0;
  /* inconsistency = lg_inconsistency; */
  *varargout_5 = lg_inconsistency;
  /* eq_overlap = lg_eq_overlap; */
  *varargout_6 = 0.0;
  /*  normalize each component */
  /*  calculating maximum time just once */
  /* if isempty(max_t_res) */
  if (!max_t_res_not_empty) {
    /* ep = 0.1; */
    /* [max_t_res, ~, ~] = log_clustering(soc_in, mp, ep); */
    max_t_res =
        log_clustering(soc_in, mp, &d_expl_temp, &cluster_clt_max_count);
    max_t_res_not_empty = true;
  }
  /* lg_time = lg_time / max_t_res; */
  /* lg_inconsistency = lg_inconsistency / max_lg_inconsistency; */
  lg_inconsistency /= 100.0;
  /* lg_eq_overlap = lg_eq_overlap / max_lg_eq_overlap; */
  /*  combined cost */
  /* cost = w_time * lg_time + w_inconsistency * lg_inconsistency + w_eq_overlap
   * * lg_eq_overlap; */
  return (w_time * (0.0 / max_t_res) + w_inconsistency * lg_inconsistency) +
         w_eq_overlap * 0.0;
}

/*
 * function [global_best, eq_step, stio] = pso(soc_in, mp, w_time,
 * w_inconsistency, w_eq_overlap)
 *
 * problem definition
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double w_time
 *                double w_inconsistency
 *                double w_eq_overlap
 *                struct0_T *global_best
 *                struct1_T *eq_step
 *                struct2_T *stio
 * Return Type  : void
 */
void pso(const double soc_in[9], double mp, double w_time,
         double w_inconsistency, double w_eq_overlap, struct0_T *global_best,
         struct1_T *eq_step, struct2_T *stio)
{
  static const struct_T r = {
      0.0, /* position */
      0.0, /* cost */
      0.0, /* velocity */
      {
          0.0, /* position */
          0.0  /* cost */
      }        /* best */
  };
  struct_T particle[10];
  double b_r;
  double w;
  int d_expl_temp_size;
  int expl_temp_size;
  int i;
  if (!isInitialized_pso) {
    pso_initialize();
  }
  /* costfunction = @(ep) balance_costF(soc_in, mp, ep, w_time, w_inconsistency,
   * w_eq_overlap); */
  /*  cost function  */
  /* nvar = 1; */
  /*  number of unknown (decision) variables */
  /* varsize = [1 nvar]; */
  /*  matrix size of decision variables */
  /* varmin = 0.1; */
  /*  lower bound of dicision of variables */
  /* varmax = 20; */
  /*  upper bound of dicision of variables */
  /*  parameters of PSO */
  /* maxit   = 20; */
  /*  maximum itteration  */
  /* npop    = 10; */
  /*  population size */
  /* w       = 1; */
  w = 1.0;
  /*  inertia coefficient */
  /* wdamp   = 0.99; */
  /*  inertia damping ratio coefficient */
  /* c1      = 2; */
  /*  personal acceleration coefficient  */
  /* c2      = 2; */
  /*  social acceleration coefficient */
  /*  initialization */
  /*  the particel template */
  /* empty_particle = struct('position', zeros(varsize), ... */
  /*                         'cost', zeros(varsize),'velocity', zeros(varsize),
   * ... */
  /*                         'best', struct('position', zeros(varsize), 'cost',
   * zeros(varsize))); */
  /* global_best = struct('position', zeros(varsize), 'cost', zeros(varsize));
   */
  global_best->position = 0.0;
  /*  create population array */
  /* particle = repmat(empty_particle, npop, 1); */
  for (i = 0; i < 10; i++) {
    particle[i] = r;
  }
  /*  global best */
  /* global_best.cost = inf; */
  global_best->cost = rtInf;
  /*  start with the +infinity value to move toward least values... */
  /*  (this is the worst value)  */
  /* for i=1:npop */
  for (i = 0; i < 10; i++) {
    int b_expl_temp_size[2];
    int c_expl_temp_size[2];
    /*  generate randon solution */
    /* particle(i).position = unifrnd(varmin, varmax, varsize); */
    b_r = 2.0 * b_rand() - 1.0;
    particle[i].position = 9.95 * b_r + 10.05;
    /*  initialize velocity */
    /* particle(i).velocity = zeros(varsize); */
    particle[i].velocity = 0.0;
    /*  evaluation  */
    /* [particle(i).cost, eq_step, stio.soc, stio.time, stio.inconsistency,
     * stio.eq_overlap] = costfunction(particle(i).position); */
    particle[i].cost = pso_anonFcn1(
        soc_in, mp, w_time, w_inconsistency, w_eq_overlap, particle[i].position,
        b_expl_temp_size, c_expl_temp_size, &expl_temp_size, &d_expl_temp_size,
        stio->soc, &stio->time, &stio->inconsistency, &stio->eq_overlap);
    /* update the personal best */
    /* particle(i).best.position = particle(i).position; */
    particle[i].best.position = particle[i].position;
    /* particle(i).best.cost = particle(i).cost; */
    particle[i].best.cost = particle[i].cost;
    /* update global best */
    /* if(particle(i).best.cost < global_best.cost) */
    if (particle[i].best.cost < global_best->cost) {
      /* global_best = particle(i).best; */
      *global_best = particle[i].best;
    }
  }
  /*  array to hold best costs */
  /* best_costs = zeros(maxit, 1); */
  /*  main loop of PSO */
  /* for it=1:maxit */
  for (expl_temp_size = 0; expl_temp_size < 20; expl_temp_size++) {
    /* for i=1:npop */
    for (i = 0; i < 10; i++) {
      /*  update velocity */
      /* particle(i).velocity = w*particle(i).velocity... */
      /*             + c1*rand(varsize).*(particle(i).best.position -
       * particle(i).position)... */
      /*             + c2*rand(varsize).*(global_best.position -
       * particle(i).position); */
      b_r = particle[i].position;
      particle[i].velocity =
          (w * particle[i].velocity +
           2.0 * b_rand() * (particle[i].best.position - b_r)) +
          2.0 * b_rand() * (global_best->position - b_r);
      /*  update position */
      /* particle(i).position = particle(i).position + particle(i).velocity; */
      particle[i].position = b_r + particle[i].velocity;
      /*  limitation */
      /* particle(i).position = max(particle(i).position, varmin); */
      particle[i].position = fmax(particle[i].position, 0.1);
      /* particle(i).position = min(particle(i).position, varmax); */
      particle[i].position = fmin(particle[i].position, 20.0);
      /*  evaluation */
      /* [particle(i).cost, eq_step, stio.soc, stio.time, stio.inconsistency,
       * stio.eq_overlap] = costfunction(particle(i).position); */
      particle[i].cost =
          pso_anonFcn1(soc_in, mp, w_time, w_inconsistency, w_eq_overlap,
                       particle[i].position, eq_step->source_queue_cells.size,
                       eq_step->destination_queue_cells.size,
                       &eq_step->source_target_soc_av.size[0],
                       &eq_step->destination_target_soc_av.size[0], stio->soc,
                       &stio->time, &stio->inconsistency, &stio->eq_overlap);
      /*  update personal best */
      /* if(particle(i).cost < particle(i).best.cost) */
      if (particle[i].cost < particle[i].best.cost) {
        /* particle(i).best.cost = particle(i).cost; */
        particle[i].best.cost = particle[i].cost;
        /* particle(i).best.position = particle(i).position; */
        particle[i].best.position = particle[i].position;
        /* update global best */
        /* if(particle(i).best.cost < global_best.cost) */
        if (particle[i].best.cost < global_best->cost) {
          /* global_best = particle(i).best; */
          *global_best = particle[i].best;
        }
      }
    }
    /*  store the best cost value */
    /* best_costs(it) = global_best.cost; */
    /* if coder.target('MATLAB') */
    /* w = w * wdamp; */
    w *= 0.99;
  }
  /*  results */
  /* figure; */
  /* plot(best_costs); */
  /* xlabel('iteration'); */
  /* ylabel('best cost'); */
}

/*
 * File trailer for pso.c
 *
 * [EOF]
 */
