/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:13:42 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/10 20:11:53 by dapaulin         ###   ########.fr       */
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
	cone,
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
	checkers,
	alt_checkers
}	t_pattern_type;

#endif