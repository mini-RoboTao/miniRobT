/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:02:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/03 17:13:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_draw_letter_m(t_data *data, int *x, int *y)
{
	int	i;

	i = 190;
	while (i < 290)
		ft_mlx_pixel_put(data, 30, i++, 0x00FF0000);
	*x = 30;
	*y = 190;
	while (*y < 240)
	{
		ft_mlx_pixel_put(data, *x, *y, 0x00FF0000);
		*x += 1;
		*y += 1;
	}
	while (*y > 190)
	{
		ft_mlx_pixel_put(data, *x, *y, 0x00FF0000);
		*x += 1;
		*y -= 1;
	}
	i = 190;
	while (i < 290)
		ft_mlx_pixel_put(data, *x, i++, 0x00FF0000);
}

void	ft_draw_letter_i(t_data *data, int x)
{
	int	i;

	i = 190;
	while (i < 290)
		ft_mlx_pixel_put(data, x + 20, i++, 0x00FF0000);
}

void	ft_draw_letter_n(t_data *data, int *x, int *y)
{
	int	i;

	i = 190;
	while (i < 290)
		ft_mlx_pixel_put(data, *x + 40, i++, 0x00FF0000);
	*x = 170;
	while (*y < 290)
	{
		ft_mlx_pixel_put(data, *x, *y, 0x00FF0000);
		*y += 1;
		ft_mlx_pixel_put(data, *x, *y, 0x00FF0000);
		*x += 1;
		*y += 1;
	}
	i = 190;
	while (i < 290)
		ft_mlx_pixel_put(data, *x, i++, 0x00FF0000);
}

int	ft_render_minirt(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			ft_mlx_pixel_put(data, i, j,
				hex_to_int(join_rgb_colors(data->canvas->canvas[i][j])));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}

// int	ft_render_minirt(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	ft_draw_letter_m(data, &x, &y);
// 	ft_draw_letter_i(data, x);
// 	ft_draw_letter_n(data, &x, &y);
// 	ft_draw_letter_i(data, x);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
// 	return (0);
// }
