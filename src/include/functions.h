/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:42:03 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/02 02:11:00 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minirt.h"

char	*float_to_hex(double dbl_value);
void	rev_str(char **str);
char	*join_rgb_colors(t_color color);
int		hex_to_int(char *hex);

#endif