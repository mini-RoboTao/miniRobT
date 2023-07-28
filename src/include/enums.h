/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:13:42 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/22 15:56:09 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include "minirt.h"

enum	e_content_type {
	LIGHT,
	AMBIENT_LIGHT,
	CAMERA,
	SPHERE,
	CYLINDER,
	PLANE,
	CONE,
	CUBE,
	DONUT
};

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif