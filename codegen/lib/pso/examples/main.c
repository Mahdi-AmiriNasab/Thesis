/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "pso.h"
#include "pso_internal_types.h"
#include "pso_terminate.h"
#include "pso_types.h"
#include "rt_nonfinite.h"

#ifndef typedef_emxArray_struct1_T_1x100
#define typedef_emxArray_struct1_T_1x100
typedef struct {
  struct1_T data[100];
  int size[2];
} emxArray_struct1_T_1x100;
#endif /* typedef_emxArray_struct1_T_1x100 */

/* Function Declarations */
static void argInit_1x9_real_T(double result[9]);

static double argInit_real_T(void);

static void main_pso(void);

/* Function Definitions */
/*
 * Arguments    : double result[9]
 * Return Type  : void
 */
static void argInit_1x9_real_T(double result[9])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 9; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_pso(void)
{
  emxArray_struct1_T_1x100 eq_step;
  struct0_T global_best;
  struct2_T stio;

//	double eps = 16.3130;
//	double cluster_dbscan_res		[100];
//	double cluster_clt_res_cell		[100];
//	double cluster_clt_res_soc		[100];
//	double cluster_res_soc_av		[100];
//	double cluster_clt_noise_soc	[100];
//	double cluster_clt_soc			[100];
//	double cluster_noise_max		[100];
//	double cluster_noise_min		[100];
//	double cluster_single_noise 	[100];
//  	double average;
//	double cluster_clt_max_count;
//	e_noise_stat cluster_noise_status;


  double dv[9];
  double mp_tmp;
  /* Initialize function 'pso' input arguments. */
  /* Initialize function input argument 'soc_in'. */
  mp_tmp = argInit_real_T();
  /* Call the entry-point 'pso'. */
  argInit_1x9_real_T(dv);
  double w_time = 0.5;
  double w_inc = 0.5;

  
  double soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};
  pso(soc, 2, w_time, w_inc, 0, &global_best, eq_step.data, eq_step.size, &stio);


	// pso_DBSCAN clustering test
	
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  while(1)
	  main_pso();
  /* Terminate the application.
You do not need to do this more than one time. */
  pso_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
