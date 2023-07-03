/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:41 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/02 21:36:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_canvas_with_black(t_canvas *canvas, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			canvas->canvas[i][j].red = 0;
			canvas->canvas[i][j].green = 0;
			canvas->canvas[i][j].blue = 0;
			j++;
		}
		i++;
	}
}

t_canvas	*generate_canvas(int width, int height)
{
	t_canvas	*canvas;
	int			i;
	int			j;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->width = width;
	canvas->height = height;
	i = 0;
	canvas->canvas = malloc(sizeof(t_color) * (width + 1));
	if (!canvas->canvas)
		return (NULL);
	while (i < width)
	{
		canvas->canvas[i] = malloc(sizeof(t_color) * (height + 1));
		if (!canvas->canvas[i])
			return (NULL);
		i++;
	}
	fill_canvas_with_black(canvas, width, height);
	return (canvas);
}

int	write_pixel(t_canvas *canvas, int x, int y, t_color color)
{
	if (x > canvas->width || y > canvas->height || x < 0 || y < 0)
		return (1);
	canvas->canvas[x][y] = color;
	return (0);
}
