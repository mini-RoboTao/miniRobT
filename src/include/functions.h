/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:42:03 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 06:43:05 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minirt.h"

char	*float_to_hex(double dbl_value);
void	rev_str(char **str);
char	*join_rgb_colors(t_color color);
int		hex_to_int(char *hex);

void	swap_double(double *min, double *max);
double	min_three(double a, double b, double c);
double	max_three(double a, double b, double c);

#endif