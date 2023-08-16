/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:18 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 19:19:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_VALIDATION_H
# define DATA_VALIDATION_H

# include "minirt.h"

// Input Validation
int					check_file_params(char **params, t_world *world, int check_end);
int					check_extension(char const *s1, char const *set);
void				check_input_file(t_data *data, int ac, char **av);

// Data Validation
void				data_validation(t_data *data, int ac, char **av);

// Shape defines
t_define_sphere		define_sphere(char **params, t_world *world);
t_define_plane		define_plane(char **params, t_world *world);
t_define_cylinder	define_cylinder(char **params, t_world *world);

// RGB utils
t_color				convert_to_rgb(char **input, t_world *world, int pos);

// light and camera
t_define_a_light	define_ambient_light(char **params, t_world *world);
t_define_light		define_light(char **params, t_world *world);
t_obj				convert_normalize_cam(char **str, t_world *world, int pos);
t_define_cam		define_camera(char **params, t_world *world);

// Axis and float utils
t_bool				is_valid_float(char *str);
t_obj				convert_point(char **str, t_world *world, int pos);
t_obj				convert_vector(char **str, t_world *world, int pos);
t_bool				check_vector_normalize(t_obj vector);

// Parser 
char				**parser_line(int fd);
void				parser_file(char *file_name, t_world *world);

#endif