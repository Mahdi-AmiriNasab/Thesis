/*
 * File: pso.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "pso.h"
#include "any.h"
#include "balance_soc.h"
#include "calculate_overlap.h"
#include "log_clustering.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "pso_DBSCAN.h"
#include "pso_data.h"
#include "pso_initialize.h"
#include "pso_internal_types.h"
#include "pso_types.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
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
static void
cast(const double t2_source_queue_cells[2],
     const double t2_destination_queue_cells[2], double t2_source_target_soc_av,
     double t2_destination_target_soc_av, double t0_source_queue_cells_data[],
     int t0_source_queue_cells_size[2],
     double t0_destination_queue_cells_data[],
     int t0_destination_queue_cells_size[2],
     double t0_source_target_soc_av_data[], int *t0_source_target_soc_av_size,
     double c_t0_destination_target_soc_av_[],
     int *d_t0_destination_target_soc_av_);

static void pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                         double w_inconsistency, double w_eq_overlap, double ep,
                         double *varargout_1, struct1_T varargout_2_data[],
                         int varargout_2_size[2], double varargout_3[9],
                         double *varargout_4, double *varargout_5,
                         double *varargout_6);

/* Function Definitions */
/*
 * Arguments    : const double t2_source_queue_cells[2]
 *                const double t2_destination_queue_cells[2]
 *                double t2_source_target_soc_av
 *                double t2_destination_target_soc_av
 *                double t0_source_queue_cells_data[]
 *                int t0_source_queue_cells_size[2]
 *                double t0_destination_queue_cells_data[]
 *                int t0_destination_queue_cells_size[2]
 *                double t0_source_target_soc_av_data[]
 *                int *t0_source_target_soc_av_size
 *                double c_t0_destination_target_soc_av_[]
 *                int *d_t0_destination_target_soc_av_
 * Return Type  : void
 */
static void
cast(const double t2_source_queue_cells[2],
     const double t2_destination_queue_cells[2], double t2_source_target_soc_av,
     double t2_destination_target_soc_av, double t0_source_queue_cells_data[],
     int t0_source_queue_cells_size[2],
     double t0_destination_queue_cells_data[],
     int t0_destination_queue_cells_size[2],
     double t0_source_target_soc_av_data[], int *t0_source_target_soc_av_size,
     double c_t0_destination_target_soc_av_[],
     int *d_t0_destination_target_soc_av_)
{
  t0_source_queue_cells_size[0] = 1;
  t0_source_queue_cells_size[1] = 2;
  t0_destination_queue_cells_size[0] = 1;
  t0_destination_queue_cells_size[1] = 2;
  t0_source_queue_cells_data[0] = t2_source_queue_cells[0];
  t0_destination_queue_cells_data[0] = t2_destination_queue_cells[0];
  t0_source_queue_cells_data[1] = t2_source_queue_cells[1];
  t0_destination_queue_cells_data[1] = t2_destination_queue_cells[1];
  *t0_source_target_soc_av_size = 1;
  t0_source_target_soc_av_data[0] = t2_source_target_soc_av;
  *d_t0_destination_target_soc_av_ = 1;
  c_t0_destination_target_soc_av_[0] = t2_destination_target_soc_av;
}

/*
 * @(ep)
 *
 * Arguments    : const double soc_in[9]
 *                double mp
 *                double w_time
 *                double w_inconsistency
 *                double w_eq_overlap
 *                double ep
 *                double *varargout_1
 *                struct1_T varargout_2_data[]
 *                int varargout_2_size[2]
 *                double varargout_3[9]
 *                double *varargout_4
 *                double *varargout_5
 *                double *varargout_6
 * Return Type  : void
 */
static void pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                         double w_inconsistency, double w_eq_overlap, double ep,
                         double *varargout_1, struct1_T varargout_2_data[],
                         int varargout_2_size[2], double varargout_3[9],
                         double *varargout_4, double *varargout_5,
                         double *varargout_6)
{
  static double max_t_res;
  emxArray_struct1_T_1x100 varargout_2;
  struct1_T rv[100];
  double soc_profile_data[900];
  double b_expl_temp[81];
  double cluster_clt_res_cell[81];
  double V[18];
  double c_expl_temp[18];
  double d_expl_temp[18];
  double expl_temp[9];
  double cluster_noise_max[2];
  double cluster_noise_min[2];
  double e_expl_temp[2];
  double OE;
  double blc_time;
  double blc_time_total;
  double cluster_clt_max_count;
  double f_expl_temp;
  double lg_eq_overlap;
  double lg_inconsistency;
  int b_soc_profile_size[2];
  int soc_profile_size[2];
  int i;
  int itteration;
  int partialTrueCount;
  signed char c_tmp_data[9];
  signed char d_tmp_data[9];
  boolean_T tmp_data[900];
  boolean_T b_tmp_data[100];
  boolean_T exitg1;
  e_noise_stat g_expl_temp;
  /* 'pso:5' @(ep) balance_costF(soc_in, mp, ep, w_time, w_inconsistency,
   * w_eq_overlap) */
  /* 'balance_costF:3' cell_count = length(soc_in); */
  /* 'balance_costF:5' eq_step = struct('source_queue_cells', zeros(0,2),... */
  /* 'balance_costF:6'                      'destination_queue_cells',
   * zeros(0,2),... */
  /* 'balance_costF:7'                      'source_target_soc_av',
   * zeros(0,1),... */
  /* 'balance_costF:8'                      'destination_target_soc_av',
   * zeros(0,1)); */
  /* 'balance_costF:9' max_itteration = 100; */
  /*  or whatever the maximum value of itteration is */
  /*  Initialize eq_step as an empty structure array with max_itteration
   * elements */
  /* 'balance_costF:12' eq_step = repmat(struct('source_queue_cells',
   * zeros(0,2),... */
  /* 'balance_costF:13'                        'destination_queue_cells',
   * zeros(0,2),... */
  /* 'balance_costF:14'                        'source_target_soc_av',
   * zeros(0,1),... */
  /* 'balance_costF:15'                        'destination_target_soc_av',
   * zeros(0,1)), 1, max_itteration); */
  rv[0].source_queue_cells.size[0] = 0;
  rv[0].source_queue_cells.size[1] = 2;
  rv[0].destination_queue_cells.size[0] = 0;
  rv[0].destination_queue_cells.size[1] = 2;
  rv[0].source_target_soc_av.size[0] = 0;
  rv[0].destination_target_soc_av.size[0] = 0;
  rv[1].source_queue_cells.size[0] = 0;
  rv[1].source_queue_cells.size[1] = 2;
  rv[1].destination_queue_cells.size[0] = 0;
  rv[1].destination_queue_cells.size[1] = 2;
  rv[1].source_target_soc_av.size[0] = 0;
  rv[1].destination_target_soc_av.size[0] = 0;
  rv[2].source_queue_cells.size[0] = 0;
  rv[2].source_queue_cells.size[1] = 2;
  rv[2].destination_queue_cells.size[0] = 0;
  rv[2].destination_queue_cells.size[1] = 2;
  rv[2].source_target_soc_av.size[0] = 0;
  rv[2].destination_target_soc_av.size[0] = 0;
  rv[3].source_queue_cells.size[0] = 0;
  rv[3].source_queue_cells.size[1] = 2;
  rv[3].destination_queue_cells.size[0] = 0;
  rv[3].destination_queue_cells.size[1] = 2;
  rv[3].source_target_soc_av.size[0] = 0;
  rv[3].destination_target_soc_av.size[0] = 0;
  rv[4].source_queue_cells.size[0] = 0;
  rv[4].source_queue_cells.size[1] = 2;
  rv[4].destination_queue_cells.size[0] = 0;
  rv[4].destination_queue_cells.size[1] = 2;
  rv[4].source_target_soc_av.size[0] = 0;
  rv[4].destination_target_soc_av.size[0] = 0;
  rv[5].source_queue_cells.size[0] = 0;
  rv[5].source_queue_cells.size[1] = 2;
  rv[5].destination_queue_cells.size[0] = 0;
  rv[5].destination_queue_cells.size[1] = 2;
  rv[5].source_target_soc_av.size[0] = 0;
  rv[5].destination_target_soc_av.size[0] = 0;
  rv[6].source_queue_cells.size[0] = 0;
  rv[6].source_queue_cells.size[1] = 2;
  rv[6].destination_queue_cells.size[0] = 0;
  rv[6].destination_queue_cells.size[1] = 2;
  rv[6].source_target_soc_av.size[0] = 0;
  rv[6].destination_target_soc_av.size[0] = 0;
  rv[7].source_queue_cells.size[0] = 0;
  rv[7].source_queue_cells.size[1] = 2;
  rv[7].destination_queue_cells.size[0] = 0;
  rv[7].destination_queue_cells.size[1] = 2;
  rv[7].source_target_soc_av.size[0] = 0;
  rv[7].destination_target_soc_av.size[0] = 0;
  rv[8].source_queue_cells.size[0] = 0;
  rv[8].source_queue_cells.size[1] = 2;
  rv[8].destination_queue_cells.size[0] = 0;
  rv[8].destination_queue_cells.size[1] = 2;
  rv[8].source_target_soc_av.size[0] = 0;
  rv[8].destination_target_soc_av.size[0] = 0;
  rv[9].source_queue_cells.size[0] = 0;
  rv[9].source_queue_cells.size[1] = 2;
  rv[9].destination_queue_cells.size[0] = 0;
  rv[9].destination_queue_cells.size[1] = 2;
  rv[9].source_target_soc_av.size[0] = 0;
  rv[9].destination_target_soc_av.size[0] = 0;
  rv[10].source_queue_cells.size[0] = 0;
  rv[10].source_queue_cells.size[1] = 2;
  rv[10].destination_queue_cells.size[0] = 0;
  rv[10].destination_queue_cells.size[1] = 2;
  rv[10].source_target_soc_av.size[0] = 0;
  rv[10].destination_target_soc_av.size[0] = 0;
  rv[11].source_queue_cells.size[0] = 0;
  rv[11].source_queue_cells.size[1] = 2;
  rv[11].destination_queue_cells.size[0] = 0;
  rv[11].destination_queue_cells.size[1] = 2;
  rv[11].source_target_soc_av.size[0] = 0;
  rv[11].destination_target_soc_av.size[0] = 0;
  rv[12].source_queue_cells.size[0] = 0;
  rv[12].source_queue_cells.size[1] = 2;
  rv[12].destination_queue_cells.size[0] = 0;
  rv[12].destination_queue_cells.size[1] = 2;
  rv[12].source_target_soc_av.size[0] = 0;
  rv[12].destination_target_soc_av.size[0] = 0;
  rv[13].source_queue_cells.size[0] = 0;
  rv[13].source_queue_cells.size[1] = 2;
  rv[13].destination_queue_cells.size[0] = 0;
  rv[13].destination_queue_cells.size[1] = 2;
  rv[13].source_target_soc_av.size[0] = 0;
  rv[13].destination_target_soc_av.size[0] = 0;
  rv[14].source_queue_cells.size[0] = 0;
  rv[14].source_queue_cells.size[1] = 2;
  rv[14].destination_queue_cells.size[0] = 0;
  rv[14].destination_queue_cells.size[1] = 2;
  rv[14].source_target_soc_av.size[0] = 0;
  rv[14].destination_target_soc_av.size[0] = 0;
  rv[15].source_queue_cells.size[0] = 0;
  rv[15].source_queue_cells.size[1] = 2;
  rv[15].destination_queue_cells.size[0] = 0;
  rv[15].destination_queue_cells.size[1] = 2;
  rv[15].source_target_soc_av.size[0] = 0;
  rv[15].destination_target_soc_av.size[0] = 0;
  rv[16].source_queue_cells.size[0] = 0;
  rv[16].source_queue_cells.size[1] = 2;
  rv[16].destination_queue_cells.size[0] = 0;
  rv[16].destination_queue_cells.size[1] = 2;
  rv[16].source_target_soc_av.size[0] = 0;
  rv[16].destination_target_soc_av.size[0] = 0;
  rv[17].source_queue_cells.size[0] = 0;
  rv[17].source_queue_cells.size[1] = 2;
  rv[17].destination_queue_cells.size[0] = 0;
  rv[17].destination_queue_cells.size[1] = 2;
  rv[17].source_target_soc_av.size[0] = 0;
  rv[17].destination_target_soc_av.size[0] = 0;
  rv[18].source_queue_cells.size[0] = 0;
  rv[18].source_queue_cells.size[1] = 2;
  rv[18].destination_queue_cells.size[0] = 0;
  rv[18].destination_queue_cells.size[1] = 2;
  rv[18].source_target_soc_av.size[0] = 0;
  rv[18].destination_target_soc_av.size[0] = 0;
  rv[19].source_queue_cells.size[0] = 0;
  rv[19].source_queue_cells.size[1] = 2;
  rv[19].destination_queue_cells.size[0] = 0;
  rv[19].destination_queue_cells.size[1] = 2;
  rv[19].source_target_soc_av.size[0] = 0;
  rv[19].destination_target_soc_av.size[0] = 0;
  rv[20].source_queue_cells.size[0] = 0;
  rv[20].source_queue_cells.size[1] = 2;
  rv[20].destination_queue_cells.size[0] = 0;
  rv[20].destination_queue_cells.size[1] = 2;
  rv[20].source_target_soc_av.size[0] = 0;
  rv[20].destination_target_soc_av.size[0] = 0;
  rv[21].source_queue_cells.size[0] = 0;
  rv[21].source_queue_cells.size[1] = 2;
  rv[21].destination_queue_cells.size[0] = 0;
  rv[21].destination_queue_cells.size[1] = 2;
  rv[21].source_target_soc_av.size[0] = 0;
  rv[21].destination_target_soc_av.size[0] = 0;
  rv[22].source_queue_cells.size[0] = 0;
  rv[22].source_queue_cells.size[1] = 2;
  rv[22].destination_queue_cells.size[0] = 0;
  rv[22].destination_queue_cells.size[1] = 2;
  rv[22].source_target_soc_av.size[0] = 0;
  rv[22].destination_target_soc_av.size[0] = 0;
  rv[23].source_queue_cells.size[0] = 0;
  rv[23].source_queue_cells.size[1] = 2;
  rv[23].destination_queue_cells.size[0] = 0;
  rv[23].destination_queue_cells.size[1] = 2;
  rv[23].source_target_soc_av.size[0] = 0;
  rv[23].destination_target_soc_av.size[0] = 0;
  rv[24].source_queue_cells.size[0] = 0;
  rv[24].source_queue_cells.size[1] = 2;
  rv[24].destination_queue_cells.size[0] = 0;
  rv[24].destination_queue_cells.size[1] = 2;
  rv[24].source_target_soc_av.size[0] = 0;
  rv[24].destination_target_soc_av.size[0] = 0;
  rv[25].source_queue_cells.size[0] = 0;
  rv[25].source_queue_cells.size[1] = 2;
  rv[25].destination_queue_cells.size[0] = 0;
  rv[25].destination_queue_cells.size[1] = 2;
  rv[25].source_target_soc_av.size[0] = 0;
  rv[25].destination_target_soc_av.size[0] = 0;
  rv[26].source_queue_cells.size[0] = 0;
  rv[26].source_queue_cells.size[1] = 2;
  rv[26].destination_queue_cells.size[0] = 0;
  rv[26].destination_queue_cells.size[1] = 2;
  rv[26].source_target_soc_av.size[0] = 0;
  rv[26].destination_target_soc_av.size[0] = 0;
  rv[27].source_queue_cells.size[0] = 0;
  rv[27].source_queue_cells.size[1] = 2;
  rv[27].destination_queue_cells.size[0] = 0;
  rv[27].destination_queue_cells.size[1] = 2;
  rv[27].source_target_soc_av.size[0] = 0;
  rv[27].destination_target_soc_av.size[0] = 0;
  rv[28].source_queue_cells.size[0] = 0;
  rv[28].source_queue_cells.size[1] = 2;
  rv[28].destination_queue_cells.size[0] = 0;
  rv[28].destination_queue_cells.size[1] = 2;
  rv[28].source_target_soc_av.size[0] = 0;
  rv[28].destination_target_soc_av.size[0] = 0;
  rv[29].source_queue_cells.size[0] = 0;
  rv[29].source_queue_cells.size[1] = 2;
  rv[29].destination_queue_cells.size[0] = 0;
  rv[29].destination_queue_cells.size[1] = 2;
  rv[29].source_target_soc_av.size[0] = 0;
  rv[29].destination_target_soc_av.size[0] = 0;
  rv[30].source_queue_cells.size[0] = 0;
  rv[30].source_queue_cells.size[1] = 2;
  rv[30].destination_queue_cells.size[0] = 0;
  rv[30].destination_queue_cells.size[1] = 2;
  rv[30].source_target_soc_av.size[0] = 0;
  rv[30].destination_target_soc_av.size[0] = 0;
  rv[31].source_queue_cells.size[0] = 0;
  rv[31].source_queue_cells.size[1] = 2;
  rv[31].destination_queue_cells.size[0] = 0;
  rv[31].destination_queue_cells.size[1] = 2;
  rv[31].source_target_soc_av.size[0] = 0;
  rv[31].destination_target_soc_av.size[0] = 0;
  rv[32].source_queue_cells.size[0] = 0;
  rv[32].source_queue_cells.size[1] = 2;
  rv[32].destination_queue_cells.size[0] = 0;
  rv[32].destination_queue_cells.size[1] = 2;
  rv[32].source_target_soc_av.size[0] = 0;
  rv[32].destination_target_soc_av.size[0] = 0;
  rv[33].source_queue_cells.size[0] = 0;
  rv[33].source_queue_cells.size[1] = 2;
  rv[33].destination_queue_cells.size[0] = 0;
  rv[33].destination_queue_cells.size[1] = 2;
  rv[33].source_target_soc_av.size[0] = 0;
  rv[33].destination_target_soc_av.size[0] = 0;
  rv[34].source_queue_cells.size[0] = 0;
  rv[34].source_queue_cells.size[1] = 2;
  rv[34].destination_queue_cells.size[0] = 0;
  rv[34].destination_queue_cells.size[1] = 2;
  rv[34].source_target_soc_av.size[0] = 0;
  rv[34].destination_target_soc_av.size[0] = 0;
  rv[35].source_queue_cells.size[0] = 0;
  rv[35].source_queue_cells.size[1] = 2;
  rv[35].destination_queue_cells.size[0] = 0;
  rv[35].destination_queue_cells.size[1] = 2;
  rv[35].source_target_soc_av.size[0] = 0;
  rv[35].destination_target_soc_av.size[0] = 0;
  rv[36].source_queue_cells.size[0] = 0;
  rv[36].source_queue_cells.size[1] = 2;
  rv[36].destination_queue_cells.size[0] = 0;
  rv[36].destination_queue_cells.size[1] = 2;
  rv[36].source_target_soc_av.size[0] = 0;
  rv[36].destination_target_soc_av.size[0] = 0;
  rv[37].source_queue_cells.size[0] = 0;
  rv[37].source_queue_cells.size[1] = 2;
  rv[37].destination_queue_cells.size[0] = 0;
  rv[37].destination_queue_cells.size[1] = 2;
  rv[37].source_target_soc_av.size[0] = 0;
  rv[37].destination_target_soc_av.size[0] = 0;
  rv[38].source_queue_cells.size[0] = 0;
  rv[38].source_queue_cells.size[1] = 2;
  rv[38].destination_queue_cells.size[0] = 0;
  rv[38].destination_queue_cells.size[1] = 2;
  rv[38].source_target_soc_av.size[0] = 0;
  rv[38].destination_target_soc_av.size[0] = 0;
  rv[39].source_queue_cells.size[0] = 0;
  rv[39].source_queue_cells.size[1] = 2;
  rv[39].destination_queue_cells.size[0] = 0;
  rv[39].destination_queue_cells.size[1] = 2;
  rv[39].source_target_soc_av.size[0] = 0;
  rv[39].destination_target_soc_av.size[0] = 0;
  rv[40].source_queue_cells.size[0] = 0;
  rv[40].source_queue_cells.size[1] = 2;
  rv[40].destination_queue_cells.size[0] = 0;
  rv[40].destination_queue_cells.size[1] = 2;
  rv[40].source_target_soc_av.size[0] = 0;
  rv[40].destination_target_soc_av.size[0] = 0;
  rv[41].source_queue_cells.size[0] = 0;
  rv[41].source_queue_cells.size[1] = 2;
  rv[41].destination_queue_cells.size[0] = 0;
  rv[41].destination_queue_cells.size[1] = 2;
  rv[41].source_target_soc_av.size[0] = 0;
  rv[41].destination_target_soc_av.size[0] = 0;
  rv[42].source_queue_cells.size[0] = 0;
  rv[42].source_queue_cells.size[1] = 2;
  rv[42].destination_queue_cells.size[0] = 0;
  rv[42].destination_queue_cells.size[1] = 2;
  rv[42].source_target_soc_av.size[0] = 0;
  rv[42].destination_target_soc_av.size[0] = 0;
  rv[43].source_queue_cells.size[0] = 0;
  rv[43].source_queue_cells.size[1] = 2;
  rv[43].destination_queue_cells.size[0] = 0;
  rv[43].destination_queue_cells.size[1] = 2;
  rv[43].source_target_soc_av.size[0] = 0;
  rv[43].destination_target_soc_av.size[0] = 0;
  rv[44].source_queue_cells.size[0] = 0;
  rv[44].source_queue_cells.size[1] = 2;
  rv[44].destination_queue_cells.size[0] = 0;
  rv[44].destination_queue_cells.size[1] = 2;
  rv[44].source_target_soc_av.size[0] = 0;
  rv[44].destination_target_soc_av.size[0] = 0;
  rv[45].source_queue_cells.size[0] = 0;
  rv[45].source_queue_cells.size[1] = 2;
  rv[45].destination_queue_cells.size[0] = 0;
  rv[45].destination_queue_cells.size[1] = 2;
  rv[45].source_target_soc_av.size[0] = 0;
  rv[45].destination_target_soc_av.size[0] = 0;
  rv[46].source_queue_cells.size[0] = 0;
  rv[46].source_queue_cells.size[1] = 2;
  rv[46].destination_queue_cells.size[0] = 0;
  rv[46].destination_queue_cells.size[1] = 2;
  rv[46].source_target_soc_av.size[0] = 0;
  rv[46].destination_target_soc_av.size[0] = 0;
  rv[47].source_queue_cells.size[0] = 0;
  rv[47].source_queue_cells.size[1] = 2;
  rv[47].destination_queue_cells.size[0] = 0;
  rv[47].destination_queue_cells.size[1] = 2;
  rv[47].source_target_soc_av.size[0] = 0;
  rv[47].destination_target_soc_av.size[0] = 0;
  rv[48].source_queue_cells.size[0] = 0;
  rv[48].source_queue_cells.size[1] = 2;
  rv[48].destination_queue_cells.size[0] = 0;
  rv[48].destination_queue_cells.size[1] = 2;
  rv[48].source_target_soc_av.size[0] = 0;
  rv[48].destination_target_soc_av.size[0] = 0;
  rv[49].source_queue_cells.size[0] = 0;
  rv[49].source_queue_cells.size[1] = 2;
  rv[49].destination_queue_cells.size[0] = 0;
  rv[49].destination_queue_cells.size[1] = 2;
  rv[49].source_target_soc_av.size[0] = 0;
  rv[49].destination_target_soc_av.size[0] = 0;
  rv[50].source_queue_cells.size[0] = 0;
  rv[50].source_queue_cells.size[1] = 2;
  rv[50].destination_queue_cells.size[0] = 0;
  rv[50].destination_queue_cells.size[1] = 2;
  rv[50].source_target_soc_av.size[0] = 0;
  rv[50].destination_target_soc_av.size[0] = 0;
  rv[51].source_queue_cells.size[0] = 0;
  rv[51].source_queue_cells.size[1] = 2;
  rv[51].destination_queue_cells.size[0] = 0;
  rv[51].destination_queue_cells.size[1] = 2;
  rv[51].source_target_soc_av.size[0] = 0;
  rv[51].destination_target_soc_av.size[0] = 0;
  rv[52].source_queue_cells.size[0] = 0;
  rv[52].source_queue_cells.size[1] = 2;
  rv[52].destination_queue_cells.size[0] = 0;
  rv[52].destination_queue_cells.size[1] = 2;
  rv[52].source_target_soc_av.size[0] = 0;
  rv[52].destination_target_soc_av.size[0] = 0;
  rv[53].source_queue_cells.size[0] = 0;
  rv[53].source_queue_cells.size[1] = 2;
  rv[53].destination_queue_cells.size[0] = 0;
  rv[53].destination_queue_cells.size[1] = 2;
  rv[53].source_target_soc_av.size[0] = 0;
  rv[53].destination_target_soc_av.size[0] = 0;
  rv[54].source_queue_cells.size[0] = 0;
  rv[54].source_queue_cells.size[1] = 2;
  rv[54].destination_queue_cells.size[0] = 0;
  rv[54].destination_queue_cells.size[1] = 2;
  rv[54].source_target_soc_av.size[0] = 0;
  rv[54].destination_target_soc_av.size[0] = 0;
  rv[55].source_queue_cells.size[0] = 0;
  rv[55].source_queue_cells.size[1] = 2;
  rv[55].destination_queue_cells.size[0] = 0;
  rv[55].destination_queue_cells.size[1] = 2;
  rv[55].source_target_soc_av.size[0] = 0;
  rv[55].destination_target_soc_av.size[0] = 0;
  rv[56].source_queue_cells.size[0] = 0;
  rv[56].source_queue_cells.size[1] = 2;
  rv[56].destination_queue_cells.size[0] = 0;
  rv[56].destination_queue_cells.size[1] = 2;
  rv[56].source_target_soc_av.size[0] = 0;
  rv[56].destination_target_soc_av.size[0] = 0;
  rv[57].source_queue_cells.size[0] = 0;
  rv[57].source_queue_cells.size[1] = 2;
  rv[57].destination_queue_cells.size[0] = 0;
  rv[57].destination_queue_cells.size[1] = 2;
  rv[57].source_target_soc_av.size[0] = 0;
  rv[57].destination_target_soc_av.size[0] = 0;
  rv[58].source_queue_cells.size[0] = 0;
  rv[58].source_queue_cells.size[1] = 2;
  rv[58].destination_queue_cells.size[0] = 0;
  rv[58].destination_queue_cells.size[1] = 2;
  rv[58].source_target_soc_av.size[0] = 0;
  rv[58].destination_target_soc_av.size[0] = 0;
  rv[59].source_queue_cells.size[0] = 0;
  rv[59].source_queue_cells.size[1] = 2;
  rv[59].destination_queue_cells.size[0] = 0;
  rv[59].destination_queue_cells.size[1] = 2;
  rv[59].source_target_soc_av.size[0] = 0;
  rv[59].destination_target_soc_av.size[0] = 0;
  rv[60].source_queue_cells.size[0] = 0;
  rv[60].source_queue_cells.size[1] = 2;
  rv[60].destination_queue_cells.size[0] = 0;
  rv[60].destination_queue_cells.size[1] = 2;
  rv[60].source_target_soc_av.size[0] = 0;
  rv[60].destination_target_soc_av.size[0] = 0;
  rv[61].source_queue_cells.size[0] = 0;
  rv[61].source_queue_cells.size[1] = 2;
  rv[61].destination_queue_cells.size[0] = 0;
  rv[61].destination_queue_cells.size[1] = 2;
  rv[61].source_target_soc_av.size[0] = 0;
  rv[61].destination_target_soc_av.size[0] = 0;
  rv[62].source_queue_cells.size[0] = 0;
  rv[62].source_queue_cells.size[1] = 2;
  rv[62].destination_queue_cells.size[0] = 0;
  rv[62].destination_queue_cells.size[1] = 2;
  rv[62].source_target_soc_av.size[0] = 0;
  rv[62].destination_target_soc_av.size[0] = 0;
  rv[63].source_queue_cells.size[0] = 0;
  rv[63].source_queue_cells.size[1] = 2;
  rv[63].destination_queue_cells.size[0] = 0;
  rv[63].destination_queue_cells.size[1] = 2;
  rv[63].source_target_soc_av.size[0] = 0;
  rv[63].destination_target_soc_av.size[0] = 0;
  rv[64].source_queue_cells.size[0] = 0;
  rv[64].source_queue_cells.size[1] = 2;
  rv[64].destination_queue_cells.size[0] = 0;
  rv[64].destination_queue_cells.size[1] = 2;
  rv[64].source_target_soc_av.size[0] = 0;
  rv[64].destination_target_soc_av.size[0] = 0;
  rv[65].source_queue_cells.size[0] = 0;
  rv[65].source_queue_cells.size[1] = 2;
  rv[65].destination_queue_cells.size[0] = 0;
  rv[65].destination_queue_cells.size[1] = 2;
  rv[65].source_target_soc_av.size[0] = 0;
  rv[65].destination_target_soc_av.size[0] = 0;
  rv[66].source_queue_cells.size[0] = 0;
  rv[66].source_queue_cells.size[1] = 2;
  rv[66].destination_queue_cells.size[0] = 0;
  rv[66].destination_queue_cells.size[1] = 2;
  rv[66].source_target_soc_av.size[0] = 0;
  rv[66].destination_target_soc_av.size[0] = 0;
  rv[67].source_queue_cells.size[0] = 0;
  rv[67].source_queue_cells.size[1] = 2;
  rv[67].destination_queue_cells.size[0] = 0;
  rv[67].destination_queue_cells.size[1] = 2;
  rv[67].source_target_soc_av.size[0] = 0;
  rv[67].destination_target_soc_av.size[0] = 0;
  rv[68].source_queue_cells.size[0] = 0;
  rv[68].source_queue_cells.size[1] = 2;
  rv[68].destination_queue_cells.size[0] = 0;
  rv[68].destination_queue_cells.size[1] = 2;
  rv[68].source_target_soc_av.size[0] = 0;
  rv[68].destination_target_soc_av.size[0] = 0;
  rv[69].source_queue_cells.size[0] = 0;
  rv[69].source_queue_cells.size[1] = 2;
  rv[69].destination_queue_cells.size[0] = 0;
  rv[69].destination_queue_cells.size[1] = 2;
  rv[69].source_target_soc_av.size[0] = 0;
  rv[69].destination_target_soc_av.size[0] = 0;
  rv[70].source_queue_cells.size[0] = 0;
  rv[70].source_queue_cells.size[1] = 2;
  rv[70].destination_queue_cells.size[0] = 0;
  rv[70].destination_queue_cells.size[1] = 2;
  rv[70].source_target_soc_av.size[0] = 0;
  rv[70].destination_target_soc_av.size[0] = 0;
  rv[71].source_queue_cells.size[0] = 0;
  rv[71].source_queue_cells.size[1] = 2;
  rv[71].destination_queue_cells.size[0] = 0;
  rv[71].destination_queue_cells.size[1] = 2;
  rv[71].source_target_soc_av.size[0] = 0;
  rv[71].destination_target_soc_av.size[0] = 0;
  rv[72].source_queue_cells.size[0] = 0;
  rv[72].source_queue_cells.size[1] = 2;
  rv[72].destination_queue_cells.size[0] = 0;
  rv[72].destination_queue_cells.size[1] = 2;
  rv[72].source_target_soc_av.size[0] = 0;
  rv[72].destination_target_soc_av.size[0] = 0;
  rv[73].source_queue_cells.size[0] = 0;
  rv[73].source_queue_cells.size[1] = 2;
  rv[73].destination_queue_cells.size[0] = 0;
  rv[73].destination_queue_cells.size[1] = 2;
  rv[73].source_target_soc_av.size[0] = 0;
  rv[73].destination_target_soc_av.size[0] = 0;
  rv[74].source_queue_cells.size[0] = 0;
  rv[74].source_queue_cells.size[1] = 2;
  rv[74].destination_queue_cells.size[0] = 0;
  rv[74].destination_queue_cells.size[1] = 2;
  rv[74].source_target_soc_av.size[0] = 0;
  rv[74].destination_target_soc_av.size[0] = 0;
  rv[75].source_queue_cells.size[0] = 0;
  rv[75].source_queue_cells.size[1] = 2;
  rv[75].destination_queue_cells.size[0] = 0;
  rv[75].destination_queue_cells.size[1] = 2;
  rv[75].source_target_soc_av.size[0] = 0;
  rv[75].destination_target_soc_av.size[0] = 0;
  rv[76].source_queue_cells.size[0] = 0;
  rv[76].source_queue_cells.size[1] = 2;
  rv[76].destination_queue_cells.size[0] = 0;
  rv[76].destination_queue_cells.size[1] = 2;
  rv[76].source_target_soc_av.size[0] = 0;
  rv[76].destination_target_soc_av.size[0] = 0;
  rv[77].source_queue_cells.size[0] = 0;
  rv[77].source_queue_cells.size[1] = 2;
  rv[77].destination_queue_cells.size[0] = 0;
  rv[77].destination_queue_cells.size[1] = 2;
  rv[77].source_target_soc_av.size[0] = 0;
  rv[77].destination_target_soc_av.size[0] = 0;
  rv[78].source_queue_cells.size[0] = 0;
  rv[78].source_queue_cells.size[1] = 2;
  rv[78].destination_queue_cells.size[0] = 0;
  rv[78].destination_queue_cells.size[1] = 2;
  rv[78].source_target_soc_av.size[0] = 0;
  rv[78].destination_target_soc_av.size[0] = 0;
  rv[79].source_queue_cells.size[0] = 0;
  rv[79].source_queue_cells.size[1] = 2;
  rv[79].destination_queue_cells.size[0] = 0;
  rv[79].destination_queue_cells.size[1] = 2;
  rv[79].source_target_soc_av.size[0] = 0;
  rv[79].destination_target_soc_av.size[0] = 0;
  rv[80].source_queue_cells.size[0] = 0;
  rv[80].source_queue_cells.size[1] = 2;
  rv[80].destination_queue_cells.size[0] = 0;
  rv[80].destination_queue_cells.size[1] = 2;
  rv[80].source_target_soc_av.size[0] = 0;
  rv[80].destination_target_soc_av.size[0] = 0;
  rv[81].source_queue_cells.size[0] = 0;
  rv[81].source_queue_cells.size[1] = 2;
  rv[81].destination_queue_cells.size[0] = 0;
  rv[81].destination_queue_cells.size[1] = 2;
  rv[81].source_target_soc_av.size[0] = 0;
  rv[81].destination_target_soc_av.size[0] = 0;
  rv[82].source_queue_cells.size[0] = 0;
  rv[82].source_queue_cells.size[1] = 2;
  rv[82].destination_queue_cells.size[0] = 0;
  rv[82].destination_queue_cells.size[1] = 2;
  rv[82].source_target_soc_av.size[0] = 0;
  rv[82].destination_target_soc_av.size[0] = 0;
  rv[83].source_queue_cells.size[0] = 0;
  rv[83].source_queue_cells.size[1] = 2;
  rv[83].destination_queue_cells.size[0] = 0;
  rv[83].destination_queue_cells.size[1] = 2;
  rv[83].source_target_soc_av.size[0] = 0;
  rv[83].destination_target_soc_av.size[0] = 0;
  rv[84].source_queue_cells.size[0] = 0;
  rv[84].source_queue_cells.size[1] = 2;
  rv[84].destination_queue_cells.size[0] = 0;
  rv[84].destination_queue_cells.size[1] = 2;
  rv[84].source_target_soc_av.size[0] = 0;
  rv[84].destination_target_soc_av.size[0] = 0;
  rv[85].source_queue_cells.size[0] = 0;
  rv[85].source_queue_cells.size[1] = 2;
  rv[85].destination_queue_cells.size[0] = 0;
  rv[85].destination_queue_cells.size[1] = 2;
  rv[85].source_target_soc_av.size[0] = 0;
  rv[85].destination_target_soc_av.size[0] = 0;
  rv[86].source_queue_cells.size[0] = 0;
  rv[86].source_queue_cells.size[1] = 2;
  rv[86].destination_queue_cells.size[0] = 0;
  rv[86].destination_queue_cells.size[1] = 2;
  rv[86].source_target_soc_av.size[0] = 0;
  rv[86].destination_target_soc_av.size[0] = 0;
  rv[87].source_queue_cells.size[0] = 0;
  rv[87].source_queue_cells.size[1] = 2;
  rv[87].destination_queue_cells.size[0] = 0;
  rv[87].destination_queue_cells.size[1] = 2;
  rv[87].source_target_soc_av.size[0] = 0;
  rv[87].destination_target_soc_av.size[0] = 0;
  rv[88].source_queue_cells.size[0] = 0;
  rv[88].source_queue_cells.size[1] = 2;
  rv[88].destination_queue_cells.size[0] = 0;
  rv[88].destination_queue_cells.size[1] = 2;
  rv[88].source_target_soc_av.size[0] = 0;
  rv[88].destination_target_soc_av.size[0] = 0;
  rv[89].source_queue_cells.size[0] = 0;
  rv[89].source_queue_cells.size[1] = 2;
  rv[89].destination_queue_cells.size[0] = 0;
  rv[89].destination_queue_cells.size[1] = 2;
  rv[89].source_target_soc_av.size[0] = 0;
  rv[89].destination_target_soc_av.size[0] = 0;
  rv[90].source_queue_cells.size[0] = 0;
  rv[90].source_queue_cells.size[1] = 2;
  rv[90].destination_queue_cells.size[0] = 0;
  rv[90].destination_queue_cells.size[1] = 2;
  rv[90].source_target_soc_av.size[0] = 0;
  rv[90].destination_target_soc_av.size[0] = 0;
  rv[91].source_queue_cells.size[0] = 0;
  rv[91].source_queue_cells.size[1] = 2;
  rv[91].destination_queue_cells.size[0] = 0;
  rv[91].destination_queue_cells.size[1] = 2;
  rv[91].source_target_soc_av.size[0] = 0;
  rv[91].destination_target_soc_av.size[0] = 0;
  rv[92].source_queue_cells.size[0] = 0;
  rv[92].source_queue_cells.size[1] = 2;
  rv[92].destination_queue_cells.size[0] = 0;
  rv[92].destination_queue_cells.size[1] = 2;
  rv[92].source_target_soc_av.size[0] = 0;
  rv[92].destination_target_soc_av.size[0] = 0;
  rv[93].source_queue_cells.size[0] = 0;
  rv[93].source_queue_cells.size[1] = 2;
  rv[93].destination_queue_cells.size[0] = 0;
  rv[93].destination_queue_cells.size[1] = 2;
  rv[93].source_target_soc_av.size[0] = 0;
  rv[93].destination_target_soc_av.size[0] = 0;
  rv[94].source_queue_cells.size[0] = 0;
  rv[94].source_queue_cells.size[1] = 2;
  rv[94].destination_queue_cells.size[0] = 0;
  rv[94].destination_queue_cells.size[1] = 2;
  rv[94].source_target_soc_av.size[0] = 0;
  rv[94].destination_target_soc_av.size[0] = 0;
  rv[95].source_queue_cells.size[0] = 0;
  rv[95].source_queue_cells.size[1] = 2;
  rv[95].destination_queue_cells.size[0] = 0;
  rv[95].destination_queue_cells.size[1] = 2;
  rv[95].source_target_soc_av.size[0] = 0;
  rv[95].destination_target_soc_av.size[0] = 0;
  rv[96].source_queue_cells.size[0] = 0;
  rv[96].source_queue_cells.size[1] = 2;
  rv[96].destination_queue_cells.size[0] = 0;
  rv[96].destination_queue_cells.size[1] = 2;
  rv[96].source_target_soc_av.size[0] = 0;
  rv[96].destination_target_soc_av.size[0] = 0;
  rv[97].source_queue_cells.size[0] = 0;
  rv[97].source_queue_cells.size[1] = 2;
  rv[97].destination_queue_cells.size[0] = 0;
  rv[97].destination_queue_cells.size[1] = 2;
  rv[97].source_target_soc_av.size[0] = 0;
  rv[97].destination_target_soc_av.size[0] = 0;
  rv[98].source_queue_cells.size[0] = 0;
  rv[98].source_queue_cells.size[1] = 2;
  rv[98].destination_queue_cells.size[0] = 0;
  rv[98].destination_queue_cells.size[1] = 2;
  rv[98].source_target_soc_av.size[0] = 0;
  rv[98].destination_target_soc_av.size[0] = 0;
  rv[99].source_queue_cells.size[0] = 0;
  rv[99].source_queue_cells.size[1] = 2;
  rv[99].destination_queue_cells.size[0] = 0;
  rv[99].destination_queue_cells.size[1] = 2;
  rv[99].source_target_soc_av.size[0] = 0;
  rv[99].destination_target_soc_av.size[0] = 0;
  memcpy(&varargout_2.data[0], &rv[0], 100U * sizeof(struct1_T));
  /* 'balance_costF:17' coder.varsize('eq_step.source_queue_cells', [inf, 2],
   * [1, 0]); */
  /* 'balance_costF:18' coder.varsize('eq_step.destination_queue_cells', [inf,
   * 2], [1, 0]); */
  /* 'balance_costF:19' coder.varsize('eq_step.source_target_soc_av', [inf, 1],
   * [1, 0]); */
  /* 'balance_costF:20' coder.varsize('eq_step.destination_target_soc_av', [inf,
   * 1], [1, 0]); */
  /* 'balance_costF:23' coder.varsize('soc_profile', [inf, cell_count], [1, 0]);
   */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* 'balance_costF:24' soc_profile = NaN(100, cell_count); */
  soc_profile_size[0] = 100;
  soc_profile_size[1] = 9;
  for (i = 0; i < 900; i++) {
    soc_profile_data[i] = rtNaN;
  }
  /*  equalization steps storage */
  /* eq_step.source_queue_cells = [];            % [start_cell, stop_cell]
   * step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n */
  /* eq_step.destination_queue_cells = [];       % [start_cell, stop_cell]
   * step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n */
  /* eq_step.source_target_soc_av = [];          % [src cluster average soc]
   * step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n      */
  /* eq_step.destination_target_soc_av = [];     % [des cluster average soc]
   * step 1 */
  /*            .                   step 2 */
  /*            .                   step 3 */
  /*            .                   step n      */
  /* 'balance_costF:48' lg_time = 0; */
  /* 'balance_costF:49' lg_inconsistency = 0; */
  /* 'balance_costF:50' lg_eq_overlap = 0; */
  lg_eq_overlap = 0.0;
  /*  assume eps = 0.1         */
  /*  maximum possible values */
  /* 'balance_costF:54' max_lg_time = 1.5; */
  /* 'balance_costF:55' max_lg_inconsistency = 100; */
  /* 'balance_costF:56' max_lg_eq_overlap = 300; */
  /*  w_time = 0.8;           % weight for time */
  /*  w_inconsistency = 0.2;  % weight for inconsitency */
  /*  w_eq_overlap = 0;     % weight for overlap equalization */
  /* 'balance_costF:64' soc = soc_in; */
  /* 'balance_costF:65' itteration = 0; */
  itteration = 0;
  /* 'balance_costF:66' soc_transfered_total = 0; */
  /* 'balance_costF:67' blc_time_total = 0; */
  blc_time_total = 0.0;
  /* 'balance_costF:68' soc_profile(itteration + 1, :) = soc; */
  for (i = 0; i < 9; i++) {
    OE = soc_in[i];
    varargout_3[i] = OE;
    soc_profile_data[100 * i] = OE;
  }
  /*  clustering */
  /* 'balance_costF:72' [cluster] = pso_DBSCAN(soc, mp, ep); */
  pso_DBSCAN(soc_in, mp, ep, &OE, &f_expl_temp, expl_temp, cluster_clt_res_cell,
             b_expl_temp, V, &cluster_clt_max_count, c_expl_temp, d_expl_temp,
             cluster_noise_max, cluster_noise_min, e_expl_temp, &g_expl_temp);
  /* 'balance_costF:74' while cluster.clt_max_count > 1 */
  exitg1 = false;
  while ((!exitg1) && (cluster_clt_max_count > 1.0)) {
    double t3_destination_queue_cells[2];
    int trueCount;
    boolean_T b;
    /*  balancing */
    /* 'balance_costF:78' [soc_transfered, soc, blc_time, eq_step(itteration +
     * 1)] = balance_soc(cluster, soc, mp, ep, 1, 2200, 2000); */
    balance_soc(cluster_clt_res_cell, V, cluster_clt_max_count,
                cluster_noise_max, cluster_noise_min, varargout_3, &OE,
                &blc_time, e_expl_temp, t3_destination_queue_cells,
                &f_expl_temp, &lg_inconsistency);
    cast(e_expl_temp, t3_destination_queue_cells, f_expl_temp, lg_inconsistency,
         varargout_2.data[itteration].source_queue_cells.data,
         varargout_2.data[itteration].source_queue_cells.size,
         varargout_2.data[itteration].destination_queue_cells.data,
         varargout_2.data[itteration].destination_queue_cells.size,
         varargout_2.data[itteration].source_target_soc_av.data,
         &varargout_2.data[itteration].source_target_soc_av.size[0],
         varargout_2.data[itteration].destination_target_soc_av.data,
         &varargout_2.data[itteration].destination_target_soc_av.size[0]);
    /*  store charge profile */
    /* 'balance_costF:81' soc_profile(itteration + 2, :) = soc; */
    for (i = 0; i < 9; i++) {
      soc_profile_data[(itteration + 100 * i) + 1] = varargout_3[i];
    }
    /*  clustering */
    /* 'balance_costF:84' [cluster] = pso_DBSCAN(soc, mp, ep); */
    pso_DBSCAN(varargout_3, mp, ep, &OE, &f_expl_temp, expl_temp,
               cluster_clt_res_cell, b_expl_temp, V, &cluster_clt_max_count,
               c_expl_temp, d_expl_temp, cluster_noise_max, cluster_noise_min,
               e_expl_temp, &g_expl_temp);
    /* 'balance_costF:86' itteration = itteration + 1; */
    itteration++;
    /*  sorting cluster.clt_res_soc_av  */
    /* 'balance_costF:89' V = cluster.clt_res_soc_av; */
    /* 'balance_costF:90' V(V(:,2)==0,2) = Inf; */
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 9; i++) {
      b = (V[i + 9] == 0.0);
      if (b) {
        trueCount++;
        c_tmp_data[partialTrueCount] = (signed char)(i + 1);
        partialTrueCount++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      V[c_tmp_data[i] + 8] = rtInf;
    }
    /* 'balance_costF:91' cluster.clt_res_soc_av = sortrows(V, 2,'ascend'); */
    c_sortrows(V);
    /* 'balance_costF:92'
     * cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0; */
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 9; i++) {
      b = (V[i + 9] == rtInf);
      if (b) {
        trueCount++;
        d_tmp_data[partialTrueCount] = (signed char)(i + 1);
        partialTrueCount++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      V[d_tmp_data[i] + 8] = 0.0;
    }
    /* 'balance_costF:93' soc_transfered_total = soc_transfered_total +
     * soc_transfered; */
    /* 'balance_costF:94' blc_time_total = blc_time_total + blc_time; */
    blc_time_total += blc_time;
    /* 'balance_costF:96' if itteration > 20 */
    if (itteration > 20) {
      /*  error("maximum itteration reached"); */
      /*  disp("maximum itteration reached"); */
      exitg1 = true;
    }
  }
  /* 'balance_costF:103' if coder.target('MATLAB') */
  /* 'balance_costF:107' soc_profile(any(isnan(soc_profile), 2), :) = []; */
  for (i = 0; i < 900; i++) {
    tmp_data[i] = rtIsNaN(soc_profile_data[i]);
  }
  any(tmp_data, b_tmp_data, &partialTrueCount);
  nullAssignment(soc_profile_data, soc_profile_size, b_tmp_data);
  /*  Remove any row with NaN */
  /* 'balance_costF:109' lg_time = blc_time_total; */
  /* 'balance_costF:110' lg_inconsistency = max(soc) - min(soc); */
  lg_inconsistency = f_maximum(varargout_3) - e_minimum(varargout_3);
  /*  summing equalization overlap value of each cell after balancing  */
  /* 'balance_costF:113' for n = 1:cluster.cell_cnt */
  partialTrueCount = soc_profile_size[0];
  b_soc_profile_size[0] = 1;
  b_soc_profile_size[1] = partialTrueCount;
  for (itteration = 0; itteration < 9; itteration++) {
    double b_soc_profile_data[100];
    /* 'balance_costF:114' OE = calculate_overlap(soc_profile(:, n)'); */
    for (i = 0; i < partialTrueCount; i++) {
      b_soc_profile_data[i] =
          soc_profile_data[i + soc_profile_size[0] * itteration];
    }
    OE = calculate_overlap(b_soc_profile_data, b_soc_profile_size);
    /* 'balance_costF:115' lg_eq_overlap = lg_eq_overlap + OE; */
    lg_eq_overlap += OE;
  }
  /*  results */
  /* 'balance_costF:119' time = lg_time; */
  /* 'balance_costF:120' inconsistency = lg_inconsistency; */
  *varargout_5 = lg_inconsistency;
  /* 'balance_costF:121' eq_overlap = lg_eq_overlap; */
  *varargout_6 = lg_eq_overlap;
  /*  normalize each component */
  /*  calculating maximum time just once */
  /* 'balance_costF:126' if isempty(max_t_res) */
  if (!max_t_res_not_empty) {
    /* 'balance_costF:127' ep = 0.1; */
    /* 'balance_costF:128' [max_t_res, ~, ~] = log_clustering(soc_in, mp, ep);
     */
    log_clustering(soc_in, mp, &max_t_res, &OE, &f_expl_temp);
    max_t_res_not_empty = true;
  }
  /* 'balance_costF:131' lg_time = lg_time / max_t_res; */
  /* 'balance_costF:132' lg_inconsistency = lg_inconsistency /
   * max_lg_inconsistency; */
  lg_inconsistency /= 100.0;
  /* 'balance_costF:133' lg_eq_overlap = lg_eq_overlap / max_lg_eq_overlap; */
  lg_eq_overlap /= 300.0;
  /*  combined cost */
  /* 'balance_costF:136' cost = w_time * lg_time + w_inconsistency *
   * lg_inconsistency + w_eq_overlap * lg_eq_overlap; */
  varargout_2_size[0] = 1;
  varargout_2_size[1] = 100;
  memcpy(&varargout_2_data[0], &varargout_2.data[0], 100U * sizeof(struct1_T));
  *varargout_1 = (w_time * (blc_time_total / max_t_res) +
                  w_inconsistency * lg_inconsistency) +
                 w_eq_overlap * lg_eq_overlap;
  *varargout_4 = blc_time_total;
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
 *                struct1_T eq_step_data[]
 *                int eq_step_size[2]
 *                struct2_T *stio
 * Return Type  : void
 */
void pso(const double soc_in[9], double mp, double w_time,
         double w_inconsistency, double w_eq_overlap, struct0_T *global_best,
         struct1_T eq_step_data[], int eq_step_size[2], struct2_T *stio)
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
  int i;
  int it;
  if (!isInitialized_pso) {
    pso_initialize();
  }
  /* 'pso:5' costfunction = @(ep) balance_costF(soc_in, mp, ep, w_time,
   * w_inconsistency, w_eq_overlap); */
  /*  cost function  */
  /* 'pso:7' nvar = 1; */
  /*  number of unknown (decision) variables */
  /* 'pso:9' varsize = [1 nvar]; */
  /*  matrix size of decision variables */
  /* 'pso:10' varmin = 0.1; */
  /*  lower bound of dicision of variables */
  /* 'pso:11' varmax = 20; */
  /*  upper bound of dicision of variables */
  /*  parameters of PSO */
  /* 'pso:14' maxit   = 20; */
  /*  maximum itteration  */
  /* 'pso:16' npop    = 10; */
  /*  population size */
  /* 'pso:17' w       = 1; */
  w = 1.0;
  /*  inertia coefficient */
  /* 'pso:18' wdamp   = 0.99; */
  /*  inertia damping ratio coefficient */
  /* 'pso:19' c1      = 2; */
  /*  personal acceleration coefficient  */
  /* 'pso:20' c2      = 2; */
  /*  social acceleration coefficient */
  /*  initialization */
  /*  the particel template */
  /* 'pso:26' empty_particle = struct('position', zeros(varsize), ... */
  /* 'pso:27'                         'cost', zeros(varsize),'velocity',
   * zeros(varsize), ... */
  /* 'pso:28'                         'best', struct('position', zeros(varsize),
   * 'cost', zeros(varsize))); */
  /* 'pso:30' global_best = struct('position', zeros(varsize), 'cost',
   * zeros(varsize)); */
  global_best->position = 0.0;
  /*  create population array */
  /* 'pso:33' particle = repmat(empty_particle, npop, 1); */
  for (i = 0; i < 10; i++) {
    particle[i] = r;
  }
  /*  global best */
  /* 'pso:38' global_best.cost = inf; */
  global_best->cost = rtInf;
  /*  start with the +infinity value to move toward least values... */
  /*  (this is the worst value)  */
  /* 'pso:43' for i=1:npop */
  for (i = 0; i < 10; i++) {
    /*  generate randon solution */
    /* 'pso:45' particle(i).position = unifrnd(varmin, varmax, varsize); */
    b_r = 2.0 * b_rand() - 1.0;
    particle[i].position = 9.95 * b_r + 10.05;
    /*  initialize velocity */
    /* 'pso:48' particle(i).velocity = zeros(varsize); */
    particle[i].velocity = 0.0;
    /*  evaluation  */
    /* 'pso:51' [particle(i).cost, eq_step, stio.soc, stio.time,
     * stio.inconsistency, stio.eq_overlap] =
     * costfunction(particle(i).position); */
    pso_anonFcn1(soc_in, mp, w_time, w_inconsistency, w_eq_overlap,
                 particle[i].position, &particle[i].cost, eq_step_data,
                 eq_step_size, stio->soc, &stio->time, &stio->inconsistency,
                 &stio->eq_overlap);
    /* update the personal best */
    /* 'pso:54' particle(i).best.position = particle(i).position; */
    particle[i].best.position = particle[i].position;
    /* 'pso:55' particle(i).best.cost = particle(i).cost; */
    particle[i].best.cost = particle[i].cost;
    /* update global best */
    /* 'pso:58' if(particle(i).best.cost < global_best.cost) */
    if (particle[i].best.cost < global_best->cost) {
      /* 'pso:59' global_best = particle(i).best; */
      *global_best = particle[i].best;
    }
  }
  /*  array to hold best costs */
  /* 'pso:64' best_costs = zeros(maxit, 1); */
  /*  main loop of PSO */
  /* 'pso:67' for it=1:maxit */
  for (it = 0; it < 20; it++) {
    /* 'pso:68' for i=1:npop */
    for (i = 0; i < 10; i++) {
      /*  update velocity */
      /* 'pso:71' particle(i).velocity = w*particle(i).velocity... */
      /* 'pso:72'             + c1*rand(varsize).*(particle(i).best.position -
       * particle(i).position)... */
      /* 'pso:73'             + c2*rand(varsize).*(global_best.position -
       * particle(i).position); */
      b_r = particle[i].position;
      particle[i].velocity =
          (w * particle[i].velocity +
           2.0 * b_rand() * (particle[i].best.position - b_r)) +
          2.0 * b_rand() * (global_best->position - b_r);
      /*  update position */
      /* 'pso:76' particle(i).position = particle(i).position +
       * particle(i).velocity; */
      particle[i].position = b_r + particle[i].velocity;
      /*  limitation */
      /* 'pso:79' particle(i).position = max(particle(i).position, varmin); */
      particle[i].position = fmax(particle[i].position, 0.1);
      /* 'pso:80' particle(i).position = min(particle(i).position, varmax); */
      particle[i].position = fmin(particle[i].position, 20.0);
      /*  evaluation */
      /* 'pso:84' [particle(i).cost, eq_step, stio.soc, stio.time,
       * stio.inconsistency, stio.eq_overlap] =
       * costfunction(particle(i).position); */
      pso_anonFcn1(soc_in, mp, w_time, w_inconsistency, w_eq_overlap,
                   particle[i].position, &particle[i].cost, eq_step_data,
                   eq_step_size, stio->soc, &stio->time, &stio->inconsistency,
                   &stio->eq_overlap);
      /*  update personal best */
      /* 'pso:87' if(particle(i).cost < particle(i).best.cost) */
      if (particle[i].cost < particle[i].best.cost) {
        /* 'pso:89' particle(i).best.cost = particle(i).cost; */
        particle[i].best.cost = particle[i].cost;
        /* 'pso:90' particle(i).best.position = particle(i).position; */
        particle[i].best.position = particle[i].position;
        /* update global best */
        /* 'pso:93' if(particle(i).best.cost < global_best.cost) */
        if (particle[i].best.cost < global_best->cost) {
          /* 'pso:94' global_best = particle(i).best; */
          *global_best = particle[i].best;
        }
      }
    }
    /*  store the best cost value */
    /* 'pso:100' best_costs(it) = global_best.cost; */
    /* 'pso:102' if coder.target('MATLAB') */
    /* 'pso:107' w = w * wdamp; */
    w *= 0.99;
  }
  /*  results */
  /* 'pso:112' figure; */
  /* 'pso:113' plot(best_costs); */
  /* 'pso:114' xlabel('iteration'); */
  /* 'pso:115' ylabel('best cost'); */
}

/*
 * File trailer for pso.c
 *
 * [EOF]
 */
