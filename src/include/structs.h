/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:39:08 by rotakesh          #+#    #+#             */
/*   Updated: 2023/06/27 19:04:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_img
{
	void	*ptr;
	void	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct s_screen
{
	double	x[WIDTH];
	double	y[HEIGHT];
	double	initx;
	double	inity;
	double	zoom;
	double	passx;
	double	passy;
}	t_screen;

typedef struct s_data {
	void		*mlx;
	void		*win;
	char		*win_name;
	int			win_w;
	int			win_h;
	t_img		img;
	t_screen	screen;
}	t_data;

typedef struct s_object {
	void		*content;
	int			content_type;
}	t_object;

typedef struct s_obj {
	double		x;
	double		y;
	double		z;
	double		w;
}	t_obj;

void	ft_draw_letter_m(t_data *data, int *x, int *y);
void	ft_draw_letter_i(t_data *data, int x);
void	ft_draw_letter_n(t_data *data, int *x, int *y);
int		ft_render_minirt(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif