/*
    Copyright (C) 2011 Fredrik Johansson
    Copyright (C) 2014 Abhinav Baid

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpz_mat.h"
#include "ulong_extras.h"

int
main(void)
{
    int i;
    FLINT_TEST_INIT(state);


    flint_printf("is_one....");
    fflush(stdout);

    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        fmpz_mat_t A;
        slong rows = n_randint(state, 10);
        slong cols = n_randint(state, 10);

        fmpz_mat_init(A, rows, cols);
        fmpz_mat_one(A);

        if (!fmpz_mat_is_one(A))
        {
            flint_printf("FAIL!\n");
            fflush(stdout);
            flint_abort();
        }

        if (rows && cols)
        {
            fmpz_mat_randbits(A, state, 100);
            if (fmpz_mat_is_one(A))
            {
                flint_printf("FAIL!\n");
                fflush(stdout);
                flint_abort();
            }
        }

        fmpz_mat_clear(A);
    }



    FLINT_TEST_CLEANUP(state);
    flint_printf("PASS\n");
    return 0;
}
