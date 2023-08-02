/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_feature.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:17:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:17:48 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FEATURE_H
# define OBJECT_FEATURE_H

# include "minirt.h"

// Create objects
t_obj			create_point(double x, double y, double z);
t_obj			create_vector(double x, double y, double z);
t_obj			create_object(double x, double y, double z, double w);

// Arithmetic operations
t_obj			sum_objects(t_obj o_one, t_obj o_two);
t_obj			subtract_objects(t_obj o_one, t_obj o_two);
t_obj			negating_object(t_obj vector);
t_obj			multiply_object(t_obj o, double value);
t_obj			divide_object(t_obj o, double value);

// Handle object
double			object_magnitude(t_obj o);
t_obj			object_normalize(t_obj o);
double			object_dot(t_obj o_one, t_obj o_two);
t_obj			object_cross_product(t_obj o_one, t_obj o_two);

// Objects Actions
t_projectile	*create_proj(t_obj point_p, t_obj vector_v);
t_environment	*create_env(t_obj vector_g, t_obj vector_w);
t_projectile	*tick(t_environment *e, t_projectile *p);

#endif