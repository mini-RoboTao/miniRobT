/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:13:42 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 17:38:02 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include "minirt.h"

typedef enum e_object_type {
	any,
	sphere,
	plane,
	cylinder,
	cube,
	triangle,
	csg
}				t_object_type;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_pattern_type
{
	test,
	stripe,
	gradient,
	ring,
	checker,
	checker_3d
}	t_pattern_type;

#endif