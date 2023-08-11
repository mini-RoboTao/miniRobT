/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:18 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:18:12 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_VALIDATION_H
# define DATA_VALIDATION_H

# include "minirt.h"

// Shape defines
t_bool			define_sphere(char **params, t_world *world);
t_bool			define_plane(char **params, t_world *world);
t_bool			define_cylinder(char **params, t_world *world);

// RGB utils
t_color			convert_to_rgb(char *input, t_world *world);

// light and camera
t_obj			convert_point(char *str, t_world *world);
t_bool			define_ambient_light(char **params, t_world *world);
t_bool			define_light(char **params, t_world *world);
t_obj	convert_normalize_cam(char *str, t_world *world);
t_bool	define_camera(char **params, t_world *world);

// Axis and float utils
t_bool			is_valid_float(char *str);
t_matrix		convert_xyz(char *str, t_world *world);
void			convert_normalize(char *str, t_shape *shape, t_world *world);

// Parser 
char			**parser_line(int fd);
void			parser_file(char *file_name, t_world *world);









t_bool			define_shape(int fd, t_world *world);
t_obj			convert_3d_normalized(char *str, t_bool *is_valid);

#endif