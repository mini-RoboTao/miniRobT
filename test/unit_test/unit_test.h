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

int cr_sphere_eq(t_sphere *a, t_sphere *b)
{
    return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			fabs(a->radius - b->radius) < EPSILON);
}

// cast items for a char []
# define STRITEM(I1, I2, I3, I4) (char []){I1}, (char []){I2}, (char []){I3}, (char []){I4}

int cr_matrix_eq(t_matrix *a, t_matrix *b)
{
	int	i = 0;
	int	j = 0;

	while (i < a->y && i < b->y)
	{
		j = 0;
		while (j < a->x && j < b->x)
		{
			if (fabs(a->node[i][j] - b->node[i][j]) > EPSILON)
				return (0);
			j++;
		}
		i++;
	}
	if (a->y == i && a->x == j && b->y == i && b->x == j)
		return (1);
	return (0);
}

#endif