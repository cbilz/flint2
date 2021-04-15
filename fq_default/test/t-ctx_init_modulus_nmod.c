/*
    Copyright (C) 2021 William Hart

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "fq_default.h"

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include "flint.h"
#include "nmod_poly.h"
#include "ulong_extras.h"

int
main(void)
{
    int i;
    FLINT_TEST_INIT(state);


    flint_printf("ctx_init_modulus_nmod....");
    fflush(stdout);

    for (i = 0; i < 100 * flint_test_multiplier(); i++)
    {
        fq_default_ctx_t ctx;
        fq_default_t fq;
        ulong p;
	slong len;
	nmod_poly_t mod;

        p = 3;

        nmod_poly_init(mod, p);

        len = n_randint(state, 16) + 2;
	nmod_poly_randtest_irreducible(mod, state, len);

        fq_default_ctx_init_modulus_nmod(ctx, mod, "x");

        fq_default_init(fq, ctx);

        fq_default_clear(fq, ctx);

        fq_default_ctx_clear(ctx);
    }

    for (i = 0; i < 100 * flint_test_multiplier(); i++)
    {
        fq_default_ctx_t ctx;
        fq_default_t fq;
        ulong p;
        slong len;
        nmod_poly_t mod;

        p = 3;

        nmod_poly_init(mod, p);

        len = n_randint(state, 16) + 2;
        nmod_poly_randtest_irreducible(mod, state, len);

        fq_default_ctx_init_modulus_nmod_type(ctx, mod, "x", 3);

        fq_default_init(fq, ctx);

        fq_default_clear(fq, ctx);

        fq_default_ctx_clear(ctx);
    }
    
    FLINT_TEST_CLEANUP(state);

    flint_printf("PASS\n");
        return 0;
}
