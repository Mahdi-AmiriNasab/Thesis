/*
 * File: pso_internal_types.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

#ifndef PSO_INTERNAL_TYPES_H
#define PSO_INTERNAL_TYPES_H

/* Include Files */
#include "pso_types.h"
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

#ifndef typedef_captured_var
#define typedef_captured_var
typedef struct {
  double contents;
} captured_var;
#endif /* typedef_captured_var */

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  double contents[9];
} b_captured_var;
#endif /* typedef_b_captured_var */

#ifndef typedef_c_captured_var
#define typedef_c_captured_var
typedef struct {
  boolean_T contents[9];
} c_captured_var;
#endif /* typedef_c_captured_var */

#ifndef typedef_d_captured_var
#define typedef_d_captured_var
typedef struct {
  double contents[81];
} d_captured_var;
#endif /* typedef_d_captured_var */

#endif
/*
 * File trailer for pso_internal_types.h
 *
 * [EOF]
 */
