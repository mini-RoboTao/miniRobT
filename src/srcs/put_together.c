/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:27:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_shape	middle_sphere(void *v)
// {
// 	t_shape		middle;
// 	t_matrix	tmp[2];
// 	t_pattern	pattern;

// 	middle = new_sphere();
// 	middle.any->transform = translation(-0.5, 1, 0.5);
// 	middle.any->material = new_material();
// 	middle.any->material.color = fill_color(0.8, 0.4, 1);
// 	middle.any->material.reflective = 0.5;
// 	middle.any->material.transparency = 0.5;
// 	middle.any->material.refractive_index = 1.5;
// 	middle.any->material.diffuse = 0.7;
// 	middle.any->material.specular = 0.3;
// 	middle.any->material.ambient = 0.5;
// 	pattern = gradient_pattern(fill_color(0, 1, 0), fill_color(1, 0, 0));
// 	tmp[0] = translation(1, 1, 0.5);
// 	tmp[1] = scaling(2, 2, 2);
// 	set_pattern_transform(&pattern, multiply_matrix(tmp[0], tmp[1], 4, 4));
// 	middle.any->material.pattern = pattern;
// 	return (middle);
// 	(void)v;
// }

t_shape	middle_sphere(void *v)
{
	t_shape		middle;
	t_matrix	tmp[2];
	t_pattern	pattern;

	middle = new_sphere();
	middle.any->transform = translation(0, 0, 20);
	middle.any->material = new_material();
	middle.any->material.color = fill_color(1, 0, 0);
	set_transform2(&middle, scaling(20, 20, 20));
	return (middle);
	(void)v;
}

t_shape	right_sphere(void *v)
{
	t_shape		middle;
	t_pattern	pattern;

	middle = new_cube();
	middle.any->transform = multiply_matrix(\
								translation(1.5, 0.5, -0.5), \
								scaling(0.5, 0.5, 0.5), 4, 4);
	middle.any->material = new_material();
	middle.any->material.color = fill_color(0.5, 0, 0.7);
	middle.any->material.reflective = 0.5;
	middle.any->material.diffuse = 0.7;
	middle.any->material.specular = 0.3;
	pattern = alt_checkers_pattern(fill_color(0, 1, 0), fill_color(1, 0, 0));
	set_pattern_transform(&pattern, scaling(0.2, 0.2, 0.2));
	middle.any->material.pattern = pattern;
	return (middle);
	(void)v;
}

t_shape	left_cube(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cube();
	s3.any->transform = multiply_matrix(\
									translation(-1.5, 0.33, -0.75), \
									scaling(0.33, 0.33, 0.33), 4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	pattern = stripe_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	s3.any->material.pattern = pattern;
	return (s3);
	(void)v;
}

t_shape	left_cylinder(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cylinder();
	s3.any->transform = multiply_matrix(\
									translation(0.33, 0.33, -1.5), \
									scaling(0.33, 0.33, 0.33), 4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	s3.any->maximum = 1;
	s3.any->minimum = -1;
	pattern = stripe_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	s3.any->material.pattern = pattern;
	return (s3);
	(void)v;
}

// void	put_together(t_data *d)
// {
// 	t_world		w;
// 	t_camera	c;

// 	w = (t_world){0};
// 	w.amount_obj = 8;
// 	w.shapes = malloc(sizeof(t_shape) * w.amount_obj);
// 	w.shapes[0] = make_floor(NULL);
// 	w.shapes[1] = middle_sphere(NULL);
// 	w.shapes[2] = right_sphere(NULL);
// 	w.shapes[3] = left_cylinder(NULL);
// 	w.shapes[4] = right_cube(NULL);
// 	w.shapes[5] = cap_cylinder(NULL);
// 	w.shapes[6] = left_cone(NULL);
// 	w.shapes[7] = left_cone_2(NULL);
// 	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
// 	c = camera(WIDTH, HEIGHT, M_PI / 3);
// 	c.transform = view_transformation(create_point(0, 1.5, -5), \
// 	create_point(0, 1, 0), create_vector(0, 1, 0));
// 	d->canvas = render(&c, &w);
// }

// void	put_together(t_data *d)
// {
// 	t_world		w;
// 	t_camera	c;
// 	t_lst		*lst = NULL;

// 	w = (t_world){0};
// 	parser_file("./test.rt", &w);
// 	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
// 	w.camera = camera(WIDTH, HEIGHT, M_PI / 3);
// 	w.camera.transform = view_transformation(create_point(0, 1.5, -5), \
//  	create_point(0, 1, 0), create_vector(0, 1, 0));
// 	printf("%sSPHERE %d %s\n", RED, w.lst->shape.id, RESET_COLORS);
// 	d->canvas = render(&w);
// }

// void	put_together(t_data *d)
// {
// 	t_world		w;

// 	w = (t_world){0};
// 	ft_lstadd_back(&w.lst, ft_lstnew(make_floor(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(middle_sphere(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(right_sphere(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(left_cylinder(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(right_cube(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(cap_cylinder(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(left_cone(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(left_cone_2(NULL)));
// 	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
// 	w.camera = camera(WIDTH, HEIGHT, M_PI / 3);
// 	w.camera.transform = view_transformation(create_point(0, 1.5, -5), \
// 	create_point(0, 1, 0), create_vector(0, 1, 0));
// 	d->canvas = render(&w);
// }

// void	put_together(t_data *d)
// {
// 	t_world		w;

// 	w = (t_world){0};
// 	ft_lstadd_back(&w.lst, ft_lstnew(make_floor(NULL)));
// 	ft_lstadd_back(&w.lst, ft_lstnew(middle_sphere(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(right_sphere(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(left_cylinder(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(right_cube(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(cap_cylinder(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(left_cone(NULL)));
// 	//ft_lstadd_back(&w.lst, ft_lstnew(left_cone_2(NULL)));
// 	w.light = point_light(create_point(-40, 0, 30), fill_color(0.7, 0.7, 0.7));
// 	w.camera = camera(WIDTH, HEIGHT, M_PI / 2);
// 	w.camera.transform = view_transformation(create_point(-50, 0, 20), \
// 	create_point(0, 0, 0), create_vector(0, 1, 0));
// 	d->canvas = render(&w);
// }

void	put_together(t_data *d)
{
	t_world		w;

	w = (t_world){0};
	//ft_lstadd_back(&w.lst, ft_lstnew(left_cylinder(NULL)));
	ft_lstadd_back(&w.lst, ft_lstnew(make_floor(NULL)));
	parser_file("test.rt", &w);
	//w.light = point_light(create_point(-10, 10, -10), fill_color(0.0, 0.0, 0.0));
	// w.camera = camera(WIDTH, HEIGHT, M_PI / 3);
	// w.camera.transform = view_transformation(create_point(0, 1.5, -5), \
	// create_point(0, 1, 0), create_vector(0, 1, 0));
	d->canvas = render(&w);
}