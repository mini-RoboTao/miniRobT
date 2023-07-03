/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:31:14 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/02 21:51:18 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "minirt.h"

t_canvas	*generate_canvas(int width, int height);
int			write_pixel(t_canvas *canvas, int x, int y, t_color color);

#endif