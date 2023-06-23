/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:36:58 by rotakesh          #+#    #+#             */
/*   Updated: 2023/06/18 19:24:49 by dapaulin         ###   ########.fr       */
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
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.ptr);
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

void	ft_create_screen(t_data *data)
{
	int	i;

	i = 1;
	data->screen.passx = 3.0 / data->screen.zoom / 640.0;
	data->screen.x[0] = (data->screen.initx);
	data->screen.y[0] = (data->screen.inity);
	while (i < WIDTH)
	{
		data->screen.x[i] = data->screen.x[i - 1] + data->screen.passx;
		i++;
	}
	i = 1;
	while (i < HEIGHT)
	{
		data->screen.y[i] = data->screen.y[i - 1] - data->screen.passx;
		i++;
	}
}

// mlx_mouse_hook(data.win, &ft_mouse_hook, &data);
/* Add on before mlx_loop */
int	main(int ac, char **av)
{
	t_data	data;

	data.screen.initx = -2.0;
	data.screen.inity = 1.15;
	data.screen.zoom = 1.0;
	data.win_w = WIDTH;
	data.win_h = HEIGHT;
	data.win_name = "Mini-RobT";
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_w, data.win_h, data.win_name);
	data.img.ptr = mlx_new_image(data.mlx, data.win_w, data.win_h);
	data.img.addr = mlx_get_data_addr(data.img.ptr, &data.img.bits_per_pixel, \
	&data.img.line_lenght, &data.img.endian);
	mlx_loop_hook(data.mlx, &ft_render_minirt, &data);
	mlx_hook(data.win, 2, 1L << 0, &ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, &ft_close_win, &data);
	mlx_loop(data.mlx);
	printf("Look the Robotão!\n");
	return (0);
}
