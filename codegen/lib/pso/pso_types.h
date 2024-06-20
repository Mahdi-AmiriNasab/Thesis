/*
 * File: pso_types.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

#ifndef PSO_TYPES_H
#define PSO_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double position;
  double cost;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  double soc[9];
  double time;
  double inconsistency;
  double eq_overlap;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef struct_emxArray_real_T_1x2
#define struct_emxArray_real_T_1x2
struct emxArray_real_T_1x2 {
  double data[2];
  int size[2];
};
#endif /* struct_emxArray_real_T_1x2 */
#ifndef typedef_emxArray_real_T_1x2
#define typedef_emxArray_real_T_1x2
typedef struct emxArray_real_T_1x2 emxArray_real_T_1x2;
#endif /* typedef_emxArray_real_T_1x2 */

#ifndef struct_emxArray_real_T_1
#define struct_emxArray_real_T_1
struct emxArray_real_T_1 {
  double data[1];
  int size[1];
};
#endif /* struct_emxArray_real_T_1 */
#ifndef typedef_emxArray_real_T_1
#define typedef_emxArray_real_T_1
typedef struct emxArray_real_T_1 emxArray_real_T_1;
#endif /* typedef_emxArray_real_T_1 */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  emxArray_real_T_1x2 source_queue_cells;
  emxArray_real_T_1x2 destination_queue_cells;
  emxArray_real_T_1 source_target_soc_av;
  emxArray_real_T_1 destination_target_soc_av;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#endif
/*
 * File trailer for pso_types.h
 *
 * [EOF]
 */
