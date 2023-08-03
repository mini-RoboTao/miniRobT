/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:13:42 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/03 03:46:20 by dapaulin         ###   ########.fr       */
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

#endif