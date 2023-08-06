/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:39:08 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 13:25:53 by dapaulin         ###   ########.fr       */
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

/*///////////////// Render Image //////////////////*/
typedef struct s_obj {
	double		x;
	double		y;
	double		z;
	double		w;
}	t_obj;

typedef struct s_matrix
{
	int		x;
	int		y;
	double	node[4][4];
}				t_matrix;

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
}	t_color;

typedef struct s_material
{
	t_color		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
}				t_material;

typedef struct s_ray
{
	t_obj		position;
	t_obj		direction;
}				t_ray;

/************* Objects *************/
typedef struct s_sphere
{
	double		x;
	double		y;
	double		z;
	double		radius;
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
}				t_sphere;

typedef struct s_plane
{
	double		x;
	double		y;
	double		z;
	double		radius;
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
}				t_plane;

typedef struct s_common_shape
{
	double		x;
	double		y;
	double		z;
	double		radius;
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
}				t_common_shape;

union u_shape
{
	t_sphere		*sphere;
	t_plane			*plane;
	t_common_shape	*any;
	void			*v;
};

typedef struct s_shape
{
	t_object_type			id;
	union {
		t_sphere			*sphere;
		t_plane				*plane;
		t_common_shape		*any;
		void				*v;
	};
}				t_shape;
/* ******************************** */

typedef struct s_intersection
{
	double					t;
	t_shape					shape;
	struct s_intersection	*next;
}				t_intersection;

typedef struct s_intersections
{
	int				amount;
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
	t_matrix	inverse;
	t_matrix	transpose;
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
	t_shape		shape;
	t_light		light;
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

typedef struct s_precomp
{
	double		t;
	t_shape		shape;
	t_obj		point;
	t_obj		over_point;
	t_obj		eyev;
	t_obj		normalv;
	t_obj		reflectv;
	int			inside;
}				t_precomp;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		field_of_view;
	t_matrix	transform;
}				t_camera;

typedef struct s_world
{
	int				amount_obj;
	t_shape			*shapes;
	t_camera		camera;
	t_light			light;
}					t_world;

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

t_shape		make_wall_right(t_shape *floor);
t_shape		make_wall_left(t_shape *floor);
t_shape		make_floor(void *v);
void		put_together(t_data *d);
int			ft_render_minirt(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif