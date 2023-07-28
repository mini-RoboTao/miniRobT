/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:01:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

// t_sphere	*middle_sphere(void *v)
// {
// 	t_sphere	*middle;

// 	middle = new_sphere();
// 	middle->transform = translation(-0.5, 1, 0.5);
// 	middle->material = new_material();
// 	middle->material.color = fill_color(0.1, 1, 0.5);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	return (middle);
// 	(void)v;
// }

// t_sphere	*right_sphere(void *v)
// {
// 	t_sphere	*middle;
// 	t_matrix	*tmp[2];

// 	middle = new_sphere();
// 	tmp[0] = translation(1.5, 0.5, -0.5);
// 	tmp[1] = scaling(0.5, 0.5, 0.5);
// 	middle->transform = multiply_matrix(tmp[0], tmp[1], 4, 4);
// 	middle->material = new_material();
// 	middle->material.color = fill_color(1, 0.1, 0.1);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	clean_matrix(tmp[0]);
// 	clean_matrix(tmp[1]);
// 	return (middle);
// 	(void)v;
// }

// t_sphere	*left_sphere(void *v)
// {
// 	t_sphere	*middle;
// 	t_matrix	*tmp[2];

// 	middle = new_sphere();
// 	tmp[0] = translation(-1.5, 0.33, -0.75);
// 	tmp[1] = scaling(0.33, 0.33, 0.33);
// 	middle->transform = multiply_matrix(tmp[0], tmp[1], 4, 4);
// 	middle->material = new_material();
// 	middle->material.color = fill_color(1, 0.8, 0.1);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	clean_matrix(tmp[0]);
// 	clean_matrix(tmp[1]);
// 	return (middle);
// 	(void)v;
// }

// void	put_together(t_data *d)
// {
// 	t_world		w;
// 	t_camera	c;

// 	w = (t_world){0};
// 	w.amount_obj = 6;
// 	w.sphere = malloc(sizeof(t_sphere) * w.amount_obj);
// 	w.sphere[0] = make_floor(NULL);
// 	w.sphere[1] = make_wall_left(w.sphere[0]);
// 	w.sphere[2] = make_wall_right(w.sphere[0]);
// 	w.sphere[3] = middle_sphere(NULL);
// 	w.sphere[4] = right_sphere(NULL);
// 	w.sphere[5] = left_sphere(NULL);
// 	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
// 	c = camera(1000, 500, M_PI / 3);
// 	clean_matrix(c.transform);
// 	c.transform = view_transformation(create_point(0, 1.5, -5), \
// 								create_point(0, 1, 0), \
// 								create_vector(0, 1, 1));
// 	d->canvas = render(&c, &w);
// }
