/*
 * File: pso_DBSCAN.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

#ifndef PSO_DBSCAN_H
#define PSO_DBSCAN_H

/* Include Files */
#include "pso_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double
b_pso_DBSCAN(const double socs[9], double minPts, double *cluster_average,
             double cluster_dbscan_res[9], double cluster_clt_res_cell[81],
             double cluster_clt_res_soc[81], double cluster_clt_res_soc_av[18],
             double *cluster_clt_max_count, double cluster_clt_noise_soc[18],
             double cluster_clt_soc[18], double cluster_noise_max[2],
             double cluster_noise_min[2], double cluster_single_noise[2],
             e_noise_stat *cluster_noise_status);

double
pso_DBSCAN(const double socs[9], double minPts, double eps,
           double *cluster_average, double cluster_dbscan_res[9],
           double cluster_clt_res_cell[81], double cluster_clt_res_soc[81],
           double cluster_clt_res_soc_av[18], double *cluster_clt_max_count,
           double cluster_clt_noise_soc[18], double cluster_clt_soc[18],
           double cluster_noise_max[2], double cluster_noise_min[2],
           double cluster_single_noise[2], e_noise_stat *cluster_noise_status);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pso_DBSCAN.h
 *
 * [EOF]
 */
