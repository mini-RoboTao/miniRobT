/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:46:21 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/07 14:51:17 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "minirt.h"

// Striped Pattern
t_pattern	stripe_pattern(t_color a, t_color b);
t_color		stripe_at(t_pattern pattern, t_obj point);
// t_color		stripe_at_object(t_pattern *pattern, t_shape object,
//				t_obj world_point);

// Transforming Patterns
void		set_pattern_transform(t_pattern *pattern, t_matrix t);

// Generalizing Patterns
t_pattern	test_pattern(void);
t_color		pattern_at_shape(t_pattern *pattern, t_shape shape,
				t_obj world_point);
t_color		pattern_at(t_pattern pattern, t_obj point);

// Gradient Pattern
t_pattern	gradient_pattern(t_color a, t_color b);
t_color		gradient_at(t_pattern pattern, t_obj point);

// Ring Pattern
t_pattern	ring_pattern(t_color a, t_color b);
t_color		ring_at(t_pattern pattern, t_obj point);
#endif