/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:36:58 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 06:02:41 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// mlx_destroy_display(data->mlx);
/* 
comment when run in mac, because this function doesn't
exist in mlx for mac. Also this function is used to
clean display and memory on linux.
*/

int	ft_close_win(t_data *data)
{
	printf("Look the Robotão!\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.ptr);
	clean_canvas(data->canvas);
	free(data->mlx);
	exit(0);
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_win(data);
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

// mlx_mouse_hook(data.win, &ft_mouse_hook, &data);
/* Add on before mlx_loop */
// put_together(&data);
int	main(int ac, char **av)
{
	t_data	data;

	data.win_w = WIDTH;
	data.win_h = HEIGHT;
	data.win_name = "Mini-RobT";
	data.canvas = generate_canvas(WIDTH, HEIGHT);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_w, data.win_h, data.win_name);
	data.img.ptr = mlx_new_image(data.mlx, data.win_w, data.win_h);
	data.img.addr = mlx_get_data_addr(data.img.ptr, &data.img.bits_per_pixel, \
	&data.img.line_lenght, &data.img.endian);
	mlx_loop_hook(data.mlx, &ft_render_minirt, &data);
	mlx_hook(data.win, 2, 1L << 0, &ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, &ft_close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
