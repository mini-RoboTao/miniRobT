#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "../../src/include/minirt.h"
# include "../criterion-2.4.2/include/criterion/criterion.h"
# include "../criterion-2.4.2/include/criterion/new/assert.h"

void	clean_obj(t_obj *o)
{
	if (o)
	{
		free(o);
		o = NULL;
	}
}

int cr_object_eq(t_obj *a, t_obj *b)
{
    return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			a->w == b->w);
}

#endif