/*
 * File: rand.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "rand.h"
#include "pso_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : double
 */
double b_rand(void)
{
  double r;
  int j;
  int kk;
  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  unsigned long u[2];
  do {
    for (j = 0; j < 2; j++) {
      unsigned long mti;
      unsigned long y;
      mti = state[624] + 1UL;
      if (state[624] + 1UL >= 625UL) {
        for (kk = 0; kk < 227; kk++) {
          y = (state[kk] & 2147483648UL) | (state[kk + 1] & 2147483647UL);
          if ((unsigned int)((int)y & 1) == 0U) {
            y >>= 1;
          } else {
            y = y >> 1 ^ 2567483615UL;
          }
          state[kk] = state[kk + 397] ^ y;
        }
        for (kk = 0; kk < 396; kk++) {
          y = (state[kk + 227] & 2147483648UL) |
              (state[kk + 228] & 2147483647UL);
          if ((unsigned int)((int)y & 1) == 0U) {
            y >>= 1;
          } else {
            y = y >> 1 ^ 2567483615UL;
          }
          state[kk + 227] = state[kk] ^ y;
        }
        y = (state[623] & 2147483648UL) | (state[0] & 2147483647UL);
        if ((unsigned int)((int)y & 1) == 0U) {
          y >>= 1;
        } else {
          y = y >> 1 ^ 2567483615UL;
        }
        state[623] = state[396] ^ y;
        mti = 1UL;
      }
      y = state[(int)mti - 1];
      state[624] = mti;
      y ^= y >> 11;
      y ^= y << 7UL & 2636928640UL;
      y ^= y << 15UL & 4022730752UL;
      u[j] = y ^ y >> 18;
    }
    u[0] >>= 5;
    u[1] >>= 6;
    r = 1.1102230246251565E-16 * ((double)u[0] * 6.7108864E+7 + (double)u[1]);
  } while (r == 0.0);
  return r;
}

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
