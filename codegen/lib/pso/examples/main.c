/*
 * File: main.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
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

/* Function Declarations */
static void argInit_1x9_real_T(double result[9]);

static double argInit_real_T(void);

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
  main_pso();
  /* Terminate the application.
You do not need to do this more than one time. */
  pso_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
int main(int argc, char *argv[])
{

  static emxArray_struct1_T_1x50 eq_step;
  static struct2_T stio;
  static double dv[9];
  struct0_T global_best;
  double mp_tmp;
  /* Initialize function 'pso' input arguments. */
  /* Initialize function input argument 'soc_in'. */
  mp_tmp = argInit_real_T();
  /* Call the entry-point 'pso'. */
  argInit_1x9_real_T(dv);
  pso(dv, mp_tmp, mp_tmp, mp_tmp, mp_tmp, &global_best, eq_step.data,
      eq_step.size, &stio);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
