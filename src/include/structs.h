/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:39:08 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 05:31:23 by rotakesh         ###   ########.fr       */
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
	t_obj		position;
	t_obj		velocity;
}				t_projectile;

typedef struct s_environment
{
	t_obj		gravity;
	t_obj		wind;
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
	t_obj		position;
	t_obj		direction;
}				t_ray;

typedef struct s_material
{
	t_color		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

typedef struct s_sphere
{
	double		x;
	double		y;
	double		z;
	double		radius;
	t_matrix	*transform;
	t_material	material;
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
	void			**shape;
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

typedef struct s_normal_at
{
	t_obj		object_point;
	t_obj		object_normal;
	t_obj		world_normal;
	t_matrix	*inverse;
	t_matrix	*transpose;
	t_obj		point;
}				t_normal_at;

typedef struct s_light
{
	t_color		intensity;
	t_obj		position;
}				t_light;

typedef struct s_lighting
{
	t_material	material;
	t_light		*light;
	t_obj		point;
	t_obj		eyev;
	t_obj		normalv;
	t_bool		in_shadow;
}				t_lighting;

typedef struct s_lighting_data
{
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;
	t_color	eff_color;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
}				t_lighting_data;

typedef struct s_world
{
	int			amount_obj;
	t_sphere	**sphere;
	t_light		*light;
}				t_world;

typedef struct s_precomp
{
	double		t;
	union {
		t_sphere			*sphere;
		void				*shape;
	};
	t_obj		point;
	t_obj		over_point;
	t_obj		eyev;
	t_obj		normalv;
	int			inside;
}				t_precomp;

typedef struct s_put_together
{
	double			wall_size;
	double			pixel_size;
	double			half;
	double			w_y;
	double			w_x;
	double			w_z;
	t_color			color;
	t_obj			ray_origin;
	t_sphere		*s;
	t_obj			position;
	t_ray			*ray;
	int				x;
	int				y;
	t_intersections	xs;
	t_light			*light;
	t_lighting		lig;
	t_intersection	*hit;
}				t_put_together;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		field_of_view;
	t_matrix	*transform;
}				t_camera;

t_sphere	*make_wall_right(void *v);
t_sphere	*make_wall_left(void *v);
t_sphere	*make_floor(void *v);
void		put_together(t_data *d);
int			ft_render_minirt(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif