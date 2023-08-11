/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:18 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 07:06:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_VALIDATION_H
# define DATA_VALIDATION_H

# include "minirt.h"

char			**parser_line(int fd);
t_bool			define_shape(int fd, t_lst **lst);
t_obj			convert_xyz(char *str, t_bool *is_valid);
t_obj			convert_3d_normalized(char *str, t_bool *is_valid);
void			parser_file(char *file_name, t_lst **lst);
t_bool			define_cynlinder(char **params, t_lst **lst);
t_color			convert_to_rgb(char *input, t_bool *is_valid);

#endif