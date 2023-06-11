/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:39:08 by rotakesh          #+#    #+#             */
/*   Updated: 2023/06/11 13:42:32 by rotakesh         ###   ########.fr       */
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



typedef struct s_input_data {
	void		*next;
	void		*content;
	int			content_type;
}	t_input_data;

#endif