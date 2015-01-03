// NON-LG: Rewrite of .asm file to C. Partially generated
// Original file name: fixdiv.asm

#include <assert.h>
#include "fix.h"

fix fix_mul_div_safe (fix m0, fix m1, fix d)
{
    // STUB: Needs code
    assert(0);
}

fix fix_div_safe (fix a, fix b)
{
	// Not very fast replacement, I'm afraid :)
	float r;

	if (b == 0)
		return a < 0 ? FIX_MIN : FIX_MAX;

	r = fix_float(a) / fix_float(b);

	if (r > fix_float(FIX_MAX))
		return FIX_MAX;

	if (r < fix_float(FIX_MIN))
		return FIX_MIN;

	return fix_from_float(r);
}

