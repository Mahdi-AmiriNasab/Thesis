/*
 * File: pso_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/* Include Files */
#include "pso_initialize.h"
#include "balance_costF.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "pso_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_initialize(void)
{
  max_t_res_not_empty_init();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_pso = true;
}

/*
 * File trailer for pso_initialize.c
 *
 * [EOF]
 */
