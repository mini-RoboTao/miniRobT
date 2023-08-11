/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:18 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 04:18:43 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_VALIDATION_H
# define DATA_VALIDATION_H

# include "minirt.h"

char			**parser_line(int fd);
t_any_input		define_shape(int fd);
t_obj			convert_xyz(char *str, t_bool *is_valid);
t_obj			convert_3d_normalized(char *str, t_bool *is_valid);
t_color			convert_to_rgb(char *input, t_bool *is_valid);

#endif