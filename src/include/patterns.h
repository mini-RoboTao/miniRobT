/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:46:21 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 05:34:25 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "minirt.h"

t_pattern	stripe_pattern(t_color a, t_color b);
t_color		stripe_at(t_pattern pattern, t_obj point);
t_color		stripe_at_object(t_pattern *pattern, t_shape object,
				t_obj world_point);
void		set_pattern_transform(t_pattern *pattern, t_matrix t);

#endif