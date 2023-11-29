/*
 * File: pso_DBSCAN_types.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

#ifndef PSO_DBSCAN_TYPES_H
#define PSO_DBSCAN_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_e_noise_stat
#define enum_e_noise_stat
enum e_noise_stat
{
  noise_not_found = 0, /* Default value */
  noise_found,
  noise_single_found
};
#endif /* enum_e_noise_stat */
#ifndef typedef_e_noise_stat
#define typedef_e_noise_stat
typedef enum e_noise_stat e_noise_stat;
#endif /* typedef_e_noise_stat */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double cell_cnt;
  double average;
  double dbscan_res[9];
  double clt_res_cell[81];
  double clt_res_soc[81];
  double clt_res_soc_av[18];
  double clt_max_count;
  double clt_noise_soc[18];
  double clt_soc[18];
  double noise_max[2];
  double noise_min[2];
  double single_noise[2];
  e_noise_stat noise_status;
} struct0_T;
#endif /* typedef_struct0_T */

#endif
/*
 * File trailer for pso_DBSCAN_types.h
 *
 * [EOF]
 */
