/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:39:08 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/20 19:34:32 by dapaulin         ###   ########.fr       */
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

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
}	t_color;

typedef struct s_canvas
{
	int			width;
	int			height;
	t_color		**canvas;
}	t_canvas;

typedef struct s_data {
	void		*mlx;
	void		*win;
	char		*win_name;
	int			win_w;
	int			win_h;
	t_img		img;
	t_screen	screen;
	t_canvas	*canvas;
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

typedef struct s_projectile
{
	t_obj		*position;
	t_obj		*velocity;
}				t_projectile;

typedef struct s_environment
{
	t_obj		*gravity;
	t_obj		*wind;
}				t_environment;

typedef struct s_matrix
{
	int		x;
	int		y;
	double	**node;
}				t_matrix;

///// Ray intersection structs
typedef struct s_ray
{
	t_obj		*position;
	t_obj		*direction;
}				t_ray;

typedef struct s_sphere
{
	double		x;
	double		y;
	double		z;
	double		radius;
	t_matrix	*transform;
}				t_sphere;

typedef struct s_intersect
{
	int			amount;
	double		collision[2];
}				t_intersect;

typedef struct s_intersection
{
	double					t;
	union {
		t_sphere			*sphere;
		void				*v;
	};
	struct s_intersection	*next;
}				t_intersection;

typedef struct s_intersections
{
	int				amount;
	void			*shape;
	t_intersection	*i;
}				t_intersections;
////////////////////////////////

typedef struct s_shearing
{
	double	x_to_y;
	double	x_to_z;
	double	y_to_x;
	double	y_to_z;
	double	z_to_x;
	double	z_to_y;
}				t_shearing;

typedef struct s_put_together
{
	double			wall_size;
	double			pixel_size;
	double			half;
	double			w_y;
	double			w_x;
	double			w_z;
	t_color			color;
	t_obj			*ray_origin;
	t_sphere		*s;
	t_obj			*position;
	t_ray			*ray;
	int				x;
	int				y;
	t_intersections	xs;
}				t_put_together;

void	put_together(t_data *d);
void	ft_draw_letter_m(t_data *data, int *x, int *y);
void	ft_draw_letter_i(t_data *data, int x);
void	ft_draw_letter_n(t_data *data, int *x, int *y);
int		ft_render_minirt(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif