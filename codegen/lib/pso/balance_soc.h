/*
 * File: balance_soc.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

#ifndef BALANCE_SOC_H
#define BALANCE_SOC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double balance_soc(const double cluster_clt_res_cell[81],
                   const double cluster_clt_res_soc_av[18],
                   double cluster_clt_max_count,
                   const double cluster_noise_max[2],
                   const double cluster_noise_min[2], double soc_in[9],
                   double ep, double *blc_time,
                   double eq_step_source_queue_cells[2],
                   double eq_step_destination_queue_cells[2],
                   double *eq_step_source_target_soc_av,
                   double *c_eq_step_destination_target_so);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for balance_soc.h
 *
 * [EOF]
 */
