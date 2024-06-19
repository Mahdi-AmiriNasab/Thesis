/*
 * File: balance_costF.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "balance_costF.h"
#include "pso_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * function [cost, eq_step, soc, time, inconsistency, eq_overlap] =
 * balance_costF(soc_in, mp, ep, w_time, w_inconsistency, w_eq_overlap)
 *
 * no_ovp_plot_flag = 0;
 * global no_ovp_plot_flag;
 * if isempty(no_ovp_plot_flag)
 *  no_ovp_plot_flag = 0;
 * end
 *
 * Arguments    : void
 * Return Type  : void
 */
void balance_costF_init(void)
{
  max_t_res_not_empty = false;
}

/*
 * File trailer for balance_costF.c
 *
 * [EOF]
 */
