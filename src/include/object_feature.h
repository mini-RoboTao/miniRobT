/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_feature.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:17:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/29 10:43:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FEATURE_H
# define OBJECT_FEATURE_H

# include "minirt.h"

// Create objects
t_obj		*create_point(double x, double y, double z);
t_obj		*create_vector(double x, double y, double z);
t_obj		*create_object(double x, double y, double z, double w);

// Arithmetic operations
t_obj		*sum_objects(t_obj *o_one, t_obj *o_two);
t_obj		*subtract_objects(t_obj *o_one, t_obj *o_two);
t_obj		*negating_object(t_obj *vector);
t_obj		*multiply_object(t_obj *o, double value);
t_obj		*divide_object(t_obj *o, double value);

#endif