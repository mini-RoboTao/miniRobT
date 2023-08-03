#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "minirt.h"
# include "criterion.h"
# include "new/assert.h"

# define T (t_bool)true
# define F (t_bool)false

int	cr_color_eq(t_color a, t_color b)
{
	return	(fabs(a.blue - b.blue) < EPSILON && \
			fabs(a.green - b.green) < EPSILON && \
			fabs(a.red - b.red) < EPSILON);
}

int	cr_material_eq(t_material a, t_material b)
{
	if (!cr_color_eq(a.color, b.color))
		return (0);
	return	(fabs(a.ambient - b.ambient) < EPSILON && \
			fabs(a.diffuse - b.diffuse) < EPSILON && \
			fabs(a.shininess - b.shininess) < EPSILON && \
			fabs(a.specular - b.specular) < EPSILON);
}

int cr_object_eq(t_obj a, t_obj b)
{
	return	(fabs(a.x - b.x) < EPSILON && \
			fabs(a.y - b.y) < EPSILON && \
			fabs(a.z - b.z) < EPSILON && \
			a.w == b.w);
}

int cr_sphere_eq(t_sphere *a, t_sphere *b)
{
	return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			fabs(a->radius - b->radius) < EPSILON);
}

int cr_light_eq(t_light a, t_light b)
{
	return	(cr_color_eq(a.intensity, b.intensity) && \
			cr_object_eq(a.position, b.position));
}

int cr_sphere_check_material_eq(t_sphere *a, t_sphere *b)
{
	return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			fabs(a->radius - b->radius) < EPSILON && \
			cr_material_eq(a->material, b->material));
}

int cr_intersection_eq(t_intersection *a, t_intersection *b)
{
	return	(fabs(a->sphere->x - b->sphere->x) < EPSILON && \
			fabs(a->sphere->y - b->sphere->y) < EPSILON && \
			fabs(a->sphere->z - b->sphere->z) < EPSILON && \
			fabs(a->sphere->radius - b->sphere->radius) < EPSILON &&
			fabs(a->t - b->t) < EPSILON);
}

// cast items for a char []
# define STRITEM(I1, I2, I3, I4) (char []){I1}, (char []){I2}, (char []){I3}, (char []){I4}

int cr_matrix_eq(t_matrix a, t_matrix b)
{
	int	i = 0;
	int	j = 0;

	while (i < a.y && i < b.y)
	{
		j = 0;
		while (j < a.x && j < b.x)
		{
			if (fabs(a.node[i][j] - b.node[i][j]) > EPSILON)
				return (0);
			j++;
		}
		i++;
	}
	if (a.y == i && a.x == j && b.y == i && b.x == j)
		return (1);
	return (0);
}

#endif