/*
 * File: rand.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
#endif
#include <stdio.h>
#include "rand.h"
#include "pso_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
void seed_from_cryptgen(void);
void init_genrand(unsigned long s);  // Ensure this is declared if not already present

/* Static Variable to Track Initialization */
static int initialized = 0;

/* Function Definitions */

#ifdef _WIN32
/*
 * Seed the random number generator using CryptGenRandom
 */
void seed_from_cryptgen() {
    HCRYPTPROV hProvider;
    unsigned int seed;

    // Acquire a cryptographic provider context handle
    if (!CryptAcquireContext(&hProvider, NULL, NULL, PROV_RSA_FULL, 0)) {
        if (GetLastError() == NTE_BAD_KEYSET) {
            if (!CryptAcquireContext(&hProvider, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET)) {
                printf("CryptAcquireContext failed\n");
                exit(1);
            }
        } else {
            printf("CryptAcquireContext failed\n");
            exit(1);
        }
    }

    // Generate a random seed
    if (!CryptGenRandom(hProvider, sizeof(seed), (BYTE*)&seed)) {
        printf("CryptGenRandom failed\n");
        exit(1);
    }

    // Release the cryptographic provider context
    CryptReleaseContext(hProvider, 0);

    // Seed the Mersenne Twister
    init_genrand(seed);
    initialized = 1;  // Mark as initialized
}
#else
/*
 * Placeholder for other platforms
 */
void seed_from_cryptgen() {
    // Implementation for other platforms will go here
    printf("Seeding not implemented for this platform.\n");
    exit(1);
}
#endif

/*
 * Initialize the Mersenne Twister with a seed
 */
void init_genrand(unsigned long s) {
    state[0] = s & 0xffffffffUL;
    for (int mti = 1; mti < 624; mti++) {
        state[mti] = (1812433253UL * (state[mti - 1] ^ (state[mti - 1] >> 30)) + mti);
        state[mti] &= 0xffffffffUL;
    }
    state[624] = 624;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double b_rand(void) {
    if (!initialized) {
        seed_from_cryptgen();  // Seed if not already initialized
    }

    double r;
    unsigned int u[2];
    int j;
    int kk;
    unsigned int mti;
    unsigned int y;

    do {
        for (j = 0; j < 2; j++) {
            mti = state[624] + 1U;
            if (state[624] + 1U >= 625U) {
                for (kk = 0; kk < 227; kk++) {
                    y = (state[kk] & 2147483648U) | (state[kk + 1] & 2147483647U);
                    if ((y & 1U) == 0U) {
                        y >>= 1U;
                    } else {
                        y = y >> 1U ^ 2567483615U;
                    }
                    state[kk] = state[kk + 397] ^ y;
                }
                for (kk = 0; kk < 396; kk++) {
                    y = (state[kk + 227] & 2147483648U) | (state[kk + 228] & 2147483647U);
                    if ((y & 1U) == 0U) {
                        y >>= 1U;
                    } else {
                        y = y >> 1U ^ 2567483615U;
                    }
                    state[kk + 227] = state[kk] ^ y;
                }
                y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
                if ((y & 1U) == 0U) {
                    y >>= 1U;
                } else {
                    y = y >> 1U ^ 2567483615U;
                }
                state[623] = state[396] ^ y;
                mti = 1U;
            }
            y = state[(int)mti - 1];
            state[624] = mti;
            y ^= y >> 11U;
            y ^= y << 7U & 2636928640U;
            y ^= y << 15U & 4022730752U;
            u[j] = y ^ y >> 18U;
        }
        u[0] >>= 5U;
        u[1] >>= 6U;
        r = 1.1102230246251565E-16 * ((double)u[0] * 6.7108864E+7 + (double)u[1]);
    } while (r == 0.0);
    return r;
}

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
