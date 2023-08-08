/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming_patterns.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:47:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 16:48:01 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_pattern_transform(t_pattern *pattern, t_matrix t)
{
	pattern->transform = t;
}
