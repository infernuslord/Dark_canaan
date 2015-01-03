// NON-LG: Rewrite of .asm file to C. Partially generated
// Original file name: cstring.asm

#include <assert.h>

void memcpy_cache_dst (void *d, void *s, int n)
{
	memcpy(d, s, n);
}

