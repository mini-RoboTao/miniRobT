/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:17:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/12 16:36:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_FEATURE_H
# define CLEAN_FEATURE_H

# include "minirt.h"

void	clean_canvas(t_canvas *c);
void	clean_shape(t_shape *obj);
void	clean_world(t_world w);
void	clean_array(char **array);
void	clean_parser_error(t_world world, char **params, char *errormsg);

#endif