// NON-LG: Rewrite of .asm file to C. Partially generated
// Original file name: n88il.asm

#include <assert.h>
#include <plyparam.h>

void opaque_nowrap_8to8_il(g2s_raster *r, g2s_poly_params *p)
{
    // STUB: Needs code
    assert(0);
}

void trans_nowrap_8to8_il(g2s_raster *r, g2s_poly_params *tp)
{
    // Used by ss2 minimap
	// transparency via zero pixels skipping
	int n;
	uchar *tbits = r->p + r->x;
	uchar *bits = tp->bm->bits;
	int row = tp->bm->row;

	fix du, dv, u, v;

	n = r->n;
    u = r->u;
    v = r->v;

	du = tp->dux;
	dv = tp->dvx;
	
	while (n--) {
		uint offset = (uint)(fix_int(v)*row + fix_int(u));
		unsigned char col = bits[offset];

		if (col)
			*tbits = col;

		++tbits;
		u += du;
		v += dv;
	}
}

void opaque_clut_nowrap_8to8_il(g2s_raster *r, g2s_poly_params *p)
{
    // STUB: Needs code
    assert(0);
}

void opaque_clut_nowrap_8to8_il_init(ulong clut)
{
    // STUB: Needs code
    assert(0);
}

void trans_clut_nowrap_8to8_il(g2s_raster *r, g2s_poly_params *p)
{
    // STUB: Needs code
    assert(0);
}

void trans_clut_nowrap_8to8_il_init(ulong clut)
{
    // STUB: Needs code
    assert(0);
}

