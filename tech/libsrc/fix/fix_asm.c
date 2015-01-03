// NON-LG: Rewrite of .asm file to C. Partially generated
// Original file name: fix_asm.asm

//#include <windows.h>
//#include <lg.h>

#include <assert.h>
#include <math.h>
#include "fix.h"

ushort long_sqrt(long x)
{
    // STUB: Needs code
    assert(0);
    return 0;
}

fix fix_sqrt(fix x)
{
    if ( x < 0 )
        return 0;

    // TODO: Could be optimized via a lookup table...
    return fix_from_float(sqrt(fix_float(x)));
}

fix fix_sloppy_sqrt(fix x)
{
    // STUB: Needs code
    assert(0);
    return 0;
}

fix24 fix24_sqrt(fix24 x)
{
    // STUB: Needs code
    assert(0);
    return 0;
}

