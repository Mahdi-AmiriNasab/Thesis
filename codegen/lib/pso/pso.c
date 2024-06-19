/*
 * File: pso.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
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
#include "pso_rtwutil.h"
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
static int cast(const double t2_source_queue_cells[2],
                const double t2_destination_queue_cells[2],
                double t2_source_target_soc_av,
                double t2_destination_target_soc_av,
                double t0_source_queue_cells_data[],
                int t0_source_queue_cells_size[2],
                double t0_destination_queue_cells_data[],
                int t0_destination_queue_cells_size[2],
                double t0_source_target_soc_av_data[],
                double c_t0_destination_target_soc_av_[],
                int *d_t0_destination_target_soc_av_);

static double pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                           double w_inconsistency, double w_eq_overlap,
                           double ep, struct1_T varargout_2_data[],
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
 *                double c_t0_destination_target_soc_av_[]
 *                int *d_t0_destination_target_soc_av_
 * Return Type  : int
 */
static int cast(const double t2_source_queue_cells[2],
                const double t2_destination_queue_cells[2],
                double t2_source_target_soc_av,
                double t2_destination_target_soc_av,
                double t0_source_queue_cells_data[],
                int t0_source_queue_cells_size[2],
                double t0_destination_queue_cells_data[],
                int t0_destination_queue_cells_size[2],
                double t0_source_target_soc_av_data[],
                double c_t0_destination_target_soc_av_[],
                int *d_t0_destination_target_soc_av_)
{
  int t0_source_target_soc_av_size;
  t0_source_queue_cells_size[0] = 1;
  t0_source_queue_cells_size[1] = 2;
  t0_destination_queue_cells_size[0] = 1;
  t0_destination_queue_cells_size[1] = 2;
  t0_source_queue_cells_data[0] = t2_source_queue_cells[0];
  t0_destination_queue_cells_data[0] = t2_destination_queue_cells[0];
  t0_source_queue_cells_data[1] = t2_source_queue_cells[1];
  t0_destination_queue_cells_data[1] = t2_destination_queue_cells[1];
  t0_source_target_soc_av_size = 1;
  t0_source_target_soc_av_data[0] = t2_source_target_soc_av;
  *d_t0_destination_target_soc_av_ = 1;
  c_t0_destination_target_soc_av_[0] = t2_destination_target_soc_av;
  return t0_source_target_soc_av_size;
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
 *                struct1_T varargout_2_data[]
 *                int varargout_2_size[2]
 *                double varargout_3[9]
 *                double *varargout_4
 *                double *varargout_5
 *                double *varargout_6
 * Return Type  : double
 */
static double pso_anonFcn1(const double soc_in[9], double mp, double w_time,
                           double w_inconsistency, double w_eq_overlap,
                           double ep, struct1_T varargout_2_data[],
                           int varargout_2_size[2], double varargout_3[9],
                           double *varargout_4, double *varargout_5,
                           double *varargout_6)
{
  static emxArray_struct1_T_1x50 varargout_2;
  static struct1_T rv[50];
  static double soc_profile_data[900];
  static double b_soc_profile_data[100];
  static double b_expl_temp[81];
  static double cluster_clt_res_cell[81];
  static double V[18];
  static double c_expl_temp[18];
  static double d_expl_temp[18];
  static double expl_temp[9];
  static double max_t_res;
  static bool tmp_data[900];
  static bool b_tmp_data[100];
  double cluster_noise_max[2];
  double cluster_noise_min[2];
  double e_expl_temp[2];
  double OE;
  double blc_time;
  double cluster_clt_max_count;
  double f_expl_temp;
  double lg_inconsistency;
  int b_soc_profile_size[2];
  int soc_profile_size[2];
  int tmp_size[2];
  int i;
  int itteration;
  int partialTrueCount;
  signed char c_tmp_data[9];
  signed char d_tmp_data[9];
  bool exitg1;
  e_noise_stat g_expl_temp;
  /* 'pso:5' @(ep) balance_costF(soc_in, mp, ep, w_time, w_inconsistency,
   * w_eq_overlap) */
  /* no_ovp_plot_flag = 0; */
  /* global no_ovp_plot_flag; */
  /* if isempty(no_ovp_plot_flag) */
  /* 	no_ovp_plot_flag = 0; */
  /* end */
  /* 'balance_costF:9' cell_count = length(soc_in); */
  /* 'balance_costF:11' if coder.target('MATLAB') */
  /* 'balance_costF:34' else */
  /* 'balance_costF:35' eq_step = struct('source_queue_cells', zeros(0,2),... */
  /* 'balance_costF:36' 		'destination_queue_cells', zeros(0,2),...
   */
  /* 'balance_costF:37' 		'source_target_soc_av', zeros(0,1),...
   */
  /* 'balance_costF:38' 		'destination_target_soc_av', zeros(0,1));
   */
  /* 'balance_costF:39' max_itteration = 50; */
  /*  or whatever the maximum value of itteration is */
  /*  Initialize eq_step as an empty structure array with max_itteration
   * elements */
  /* 'balance_costF:42' eq_step = repmat(struct('source_queue_cells',
   * zeros(0,2),... */
  /* 'balance_costF:43' 		'destination_queue_cells', zeros(0,2),...
   */
  /* 'balance_costF:44' 		'source_target_soc_av', zeros(0,1),...
   */
  /* 'balance_costF:45' 		'destination_target_soc_av', zeros(0,1)), 1,
   * max_itteration); */
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
  memcpy(&varargout_2.data[0], &rv[0], 50U * sizeof(struct1_T));
  /* 'balance_costF:47' coder.varsize('eq_step.source_queue_cells', [inf, 2],
   * [1, 0]); */
  /* 'balance_costF:48' coder.varsize('eq_step.destination_queue_cells', [inf,
   * 2], [1, 0]); */
  /* 'balance_costF:49' coder.varsize('eq_step.source_target_soc_av', [inf, 1],
   * [1, 0]); */
  /* 'balance_costF:50' coder.varsize('eq_step.destination_target_soc_av', [inf,
   * 1], [1, 0]); */
  /* 'balance_costF:53' coder.varsize('soc_profile', [inf, cell_count], [1, 0]);
   */
  /*  Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is
   * variable */
  /* 'balance_costF:54' soc_profile = NaN(100, cell_count); */
  soc_profile_size[0] = 100;
  soc_profile_size[1] = 9;
  for (i = 0; i < 900; i++) {
    soc_profile_data[i] = rtNaN;
  }
  /* 'balance_costF:59' lg_time = 0; */
  /* 'balance_costF:60' lg_inconsistency = 0; */
  /* 'balance_costF:61' lg_eq_overlap = 0; */
  *varargout_6 = 0.0;
  /*  assume eps = 0.1         */
  /*  w_time = 0.8;           % weight for time */
  /*  w_inconsistency = 0.2;  % weight for inconsitency */
  /*  w_eq_overlap = 0;     % weight for overlap equalization */
  /* 'balance_costF:70' soc = soc_in; */
  /* 'balance_costF:71' itteration = 0; */
  itteration = 0;
  /* 'balance_costF:72' soc_transfered_total = 0; */
  /* 'balance_costF:73' blc_time_total = 0; */
  *varargout_4 = 0.0;
  /* 'balance_costF:74' soc_profile(itteration + 1, :) = soc; */
  for (i = 0; i < 9; i++) {
    OE = soc_in[i];
    varargout_3[i] = OE;
    soc_profile_data[100 * i] = OE;
  }
  /*  clustering */
  /* 'balance_costF:78' [cluster] = pso_DBSCAN(soc, mp, ep); */
  OE = pso_DBSCAN(soc_in, mp, ep, &f_expl_temp, expl_temp, cluster_clt_res_cell,
                  b_expl_temp, V, &cluster_clt_max_count, c_expl_temp,
                  d_expl_temp, cluster_noise_max, cluster_noise_min,
                  e_expl_temp, &g_expl_temp);
  /* 'balance_costF:80' while cluster.clt_max_count > 1 */
  exitg1 = false;
  while ((!exitg1) && (cluster_clt_max_count > 1.0)) {
    double t3_destination_queue_cells[2];
    int trueCount;
    bool b;
    /*  balancing */
    /* 'balance_costF:84' [soc_transfered, soc, blc_time, eq_step(itteration +
     * 1)] = balance_soc(cluster, soc, mp, ep, 2200, 2000); */
    balance_soc(cluster_clt_res_cell, V, cluster_clt_max_count,
                cluster_noise_max, cluster_noise_min, varargout_3, ep,
                &blc_time, e_expl_temp, t3_destination_queue_cells,
                &f_expl_temp, &lg_inconsistency);
    varargout_2.data[itteration].source_target_soc_av.size[0] = cast(
        e_expl_temp, t3_destination_queue_cells, f_expl_temp, lg_inconsistency,
        varargout_2.data[itteration].source_queue_cells.data,
        varargout_2.data[itteration].source_queue_cells.size,
        varargout_2.data[itteration].destination_queue_cells.data,
        varargout_2.data[itteration].destination_queue_cells.size,
        varargout_2.data[itteration].source_target_soc_av.data,
        varargout_2.data[itteration].destination_target_soc_av.data,
        &varargout_2.data[itteration].destination_target_soc_av.size[0]);
    /*  store charge profile */
    /* 'balance_costF:87' soc_profile(itteration + 2, :) = soc; */
    for (i = 0; i < 9; i++) {
      soc_profile_data[(itteration + 100 * i) + 1] = varargout_3[i];
    }
    /*  clustering */
    /* 'balance_costF:90' [cluster] = pso_DBSCAN(soc, mp, ep); */
    OE = pso_DBSCAN(
        varargout_3, mp, ep, &f_expl_temp, expl_temp, cluster_clt_res_cell,
        b_expl_temp, V, &cluster_clt_max_count, c_expl_temp, d_expl_temp,
        cluster_noise_max, cluster_noise_min, e_expl_temp, &g_expl_temp);
    /* 'balance_costF:92' itteration = itteration + 1; */
    itteration++;
    /*  sorting cluster.clt_res_soc_av  */
    /* 'balance_costF:95' V = cluster.clt_res_soc_av; */
    /* 'balance_costF:96' V(V(:,2)==0,2) = Inf; */
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 9; i++) {
      b = (V[i + 9] == 0.0);
      if (b) {
        trueCount++;
        c_tmp_data[partialTrueCount] = (signed char)i;
        partialTrueCount++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      V[c_tmp_data[i] + 9] = rtInf;
    }
    /* 'balance_costF:97' cluster.clt_res_soc_av = sortrows(V, 2,'ascend'); */
    c_sortrows(V);
    /* 'balance_costF:98'
     * cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0; */
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 9; i++) {
      b = (V[i + 9] == rtInf);
      if (b) {
        trueCount++;
        d_tmp_data[partialTrueCount] = (signed char)i;
        partialTrueCount++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      V[d_tmp_data[i] + 9] = 0.0;
    }
    /* 'balance_costF:99' soc_transfered_total = soc_transfered_total +
     * soc_transfered; */
    /* 'balance_costF:100' blc_time_total = blc_time_total + blc_time; */
    *varargout_4 += blc_time;
    /* 'balance_costF:102' if itteration > 20 */
    if (itteration > 20) {
      /*  error("maximum itteration reached"); */
      /*  disp("maximum itteration reached"); */
      exitg1 = true;
    }
  }
  /* 'balance_costF:109' if coder.target('MATLAB') */
  /* 'balance_costF:113' soc_profile(any(isnan(soc_profile), 2), :) = []; */
  tmp_size[0] = 100;
  tmp_size[1] = 9;
  for (i = 0; i < 900; i++) {
    tmp_data[i] = rtIsNaN(soc_profile_data[i]);
  }
  partialTrueCount = any(tmp_data, tmp_size, b_tmp_data);
  nullAssignment(soc_profile_data, soc_profile_size, b_tmp_data,
                 partialTrueCount);
  /*  Remove any row with NaN */
  /* 'balance_costF:115' lg_time = blc_time_total; */
  /* 'balance_costF:116' lg_inconsistency = max(soc) - min(soc); */
  lg_inconsistency = f_maximum(varargout_3) - e_minimum(varargout_3);
  /* no_ovp_plot_flag = 0; */
  /*  summing equalization overlap value of each cell after balancing  */
  /* 'balance_costF:120' for n = 1:cluster.cell_cnt */
  partialTrueCount = soc_profile_size[0];
  b_soc_profile_size[0] = 1;
  b_soc_profile_size[1] = soc_profile_size[0];
  for (itteration = 0; itteration < 9; itteration++) {
    /* 'balance_costF:121' OE = calculate_overlap(soc_profile(:, n)'); */
    for (i = 0; i < partialTrueCount; i++) {
      b_soc_profile_data[i] =
          soc_profile_data[i + soc_profile_size[0] * itteration];
    }
    OE = calculate_overlap(b_soc_profile_data, b_soc_profile_size);
    /* 'balance_costF:122' lg_eq_overlap = lg_eq_overlap + OE; */
    *varargout_6 += OE;
  }
  /* no_ovp_plot_flag = 0; */
  /*  results */
  /* 'balance_costF:127' time = lg_time; */
  /* 'balance_costF:128' inconsistency = lg_inconsistency; */
  *varargout_5 = lg_inconsistency;
  /*  normalize each component */
  /*  maximum possible values */
  /* 'balance_costF:133' max_lg_inconsistency = 100; */
  /* 'balance_costF:134' max_lg_eq_overlap = 50; */
  /* 'balance_costF:135' if(lg_eq_overlap > max_lg_eq_overlap) */
  if (*varargout_6 > 50.0) {
    /* 'balance_costF:136' lg_eq_overlap = max_lg_eq_overlap; */
    *varargout_6 = 50.0;
  }
  /*  calculating maximum time just once */
  /* 'balance_costF:140' if isempty(max_t_res) */
  if (!max_t_res_not_empty) {
    /* 'balance_costF:141' ep = 0.1; */
    /* 'balance_costF:142' [max_t_res, ~, ~, ~] = log_clustering(soc_in, mp,
     * ep); */
    max_t_res = log_clustering(soc_in, mp, &OE, &f_expl_temp, soc_profile_data,
                               soc_profile_size);
    max_t_res_not_empty = true;
  }
  /* 'balance_costF:145' lg_time = lg_time / max_t_res; */
  /* 'balance_costF:146' lg_inconsistency = lg_inconsistency /
   * max_lg_inconsistency; */
  lg_inconsistency /= 100.0;
  /* 'balance_costF:147' lg_eq_overlap = lg_eq_overlap / max_lg_eq_overlap; */
  *varargout_6 /= 50.0;
  /* 'balance_costF:149' eq_overlap = lg_eq_overlap; */
  /*  combined cost */
  /* 'balance_costF:152' cost = w_time * lg_time + w_inconsistency *
   * lg_inconsistency + w_eq_overlap * lg_eq_overlap; */
  varargout_2_size[0] = 1;
  varargout_2_size[1] = 50;
  memcpy(&varargout_2_data[0], &varargout_2.data[0], 50U * sizeof(struct1_T));
  return (w_time * (*varargout_4 / max_t_res) +
          w_inconsistency * lg_inconsistency) +
         w_eq_overlap * *varargout_6;
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
  static struct_T particle[10];
  static const struct_T r = {
      0.0, /* position */
      0.0, /* cost */
      0.0, /* velocity */
      {
          0.0, /* position */
          0.0  /* cost */
      }        /* best */
  };
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
    particle[i].cost = pso_anonFcn1(
        soc_in, mp, w_time, w_inconsistency, w_eq_overlap, particle[i].position,
        eq_step_data, eq_step_size, stio->soc, &stio->time,
        &stio->inconsistency, &stio->eq_overlap);
    /* update the personal best */
    /* 'pso:56' if coder.target('MATLAB') */
    /* 'pso:58' else */
    /* 'pso:59' round(particle(i).position * 10) / 10; */
    /* 'pso:62' particle(i).best.cost = particle(i).cost; */
    particle[i].best.cost = particle[i].cost;
    /* update global best */
    /* 'pso:64' if(particle(i).best.cost < global_best.cost) */
    if (particle[i].best.cost < global_best->cost) {
      /* 'pso:65' global_best = particle(i).best; */
      *global_best = particle[i].best;
    }
  }
  /*  array to hold best costs */
  /* 'pso:70' best_costs = zeros(maxit, 1); */
  /*  main loop of PSO */
  /* 'pso:73' for it=1:maxit */
  for (it = 0; it < 20; it++) {
    /* 'pso:74' for i=1:npop */
    for (i = 0; i < 10; i++) {
      /*  update velocity */
      /* 'pso:77' particle(i).velocity = w*particle(i).velocity... */
      /* 'pso:78'             + c1*rand(varsize).*(particle(i).best.position -
       * particle(i).position)... */
      /* 'pso:79'             + c2*rand(varsize).*(global_best.position -
       * particle(i).position); */
      b_r = particle[i].position;
      particle[i].velocity =
          (w * particle[i].velocity +
           2.0 * b_rand() * (particle[i].best.position - b_r)) +
          2.0 * b_rand() * (global_best->position - b_r);
      /*  update position */
      /* 'pso:82' particle(i).position = particle(i).position +
       * particle(i).velocity; */
      particle[i].position = b_r + particle[i].velocity;
      /* 'pso:84' if coder.target('MATLAB') */
      /* 'pso:86' else */
      /* 'pso:87' particle(i).position = round(particle(i).position * 10) / 10;
       */
      particle[i].position = rt_roundd_snf(particle[i].position * 10.0) / 10.0;
      /*  limitation */
      /* 'pso:90' particle(i).position = max(particle(i).position, varmin); */
      particle[i].position = fmax(particle[i].position, 0.1);
      /* 'pso:91' particle(i).position = min(particle(i).position, varmax); */
      particle[i].position = fmin(particle[i].position, 20.0);
      /*  evaluation */
      /* 'pso:95' [particle(i).cost, eq_step, stio.soc, stio.time,
       * stio.inconsistency, stio.eq_overlap] =
       * costfunction(particle(i).position); */
      particle[i].cost = pso_anonFcn1(
          soc_in, mp, w_time, w_inconsistency, w_eq_overlap,
          particle[i].position, eq_step_data, eq_step_size, stio->soc,
          &stio->time, &stio->inconsistency, &stio->eq_overlap);
      /*  update personal best */
      /* 'pso:98' if(particle(i).cost < particle(i).best.cost) */
      if (particle[i].cost < particle[i].best.cost) {
        /* 'pso:100' particle(i).best.cost = particle(i).cost; */
        particle[i].best.cost = particle[i].cost;
        /* 'pso:102' if coder.target('MATLAB') */
        /* 'pso:104' else */
        /* 'pso:105' particle(i).best.position = round(particle(i).position *
         * 10) / 10; */
        particle[i].best.position =
            rt_roundd_snf(particle[i].position * 10.0) / 10.0;
        /* update global best */
        /* 'pso:108' if(particle(i).best.cost < global_best.cost) */
        if (particle[i].best.cost < global_best->cost) {
          /* 'pso:109' global_best = particle(i).best; */
          *global_best = particle[i].best;
        }
      }
    }
    /*  store the best cost value */
    /* 'pso:115' best_costs(it) = global_best.cost; */
    /* 'pso:117' if coder.target('MATLAB') */
    /* 'pso:122' w = w * wdamp; */
    w *= 0.99;
  }
  /*  results */
  /*  Font and line width settings */
  /* 'pso:127' font_name = 'Helvetica'; */
  /* 'pso:128' font_size = 22; */
  /* 'pso:129' line_width = 2.5; */
  /* 'pso:131' figure('Name', 'cost'); */
  /* 'pso:132' plot(best_costs,'LineWidth', line_width); */
  /* 'pso:134' ylabel('best cost', 'FontName', font_name, 'FontSize', font_size,
   * 'Color', 'k'); */
  /*  Set the color to black */
  /* 'pso:135' xlabel('iteration', 'FontName', font_name, 'FontSize', font_size,
   * 'Color', 'k'); */
  /*  Set x-axis color to black */
}

/*
 * File trailer for pso.c
 *
 * [EOF]
 */
