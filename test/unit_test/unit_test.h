#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "minirt.h"
# include "criterion.h"
# include "new/assert.h"

int cr_object_eq(t_obj *a, t_obj *b)
{
    return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			a->w == b->w);
}

#endif