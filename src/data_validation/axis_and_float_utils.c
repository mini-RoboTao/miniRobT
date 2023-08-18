/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_and_float_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/18 06:12:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_valid_float(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (true);
	return (false);
}

t_bool	check_vector_normalize(t_obj vector)
{
	if ((vector.x <= 1 && vector.x >= -1)
		&& (vector.y <= 1 && vector.y >= -1)
		&& (vector.z <= 1 && vector.z >= -1))
	{
		return (true);
	}
	return (false);
}

t_obj	convert_point(char **str, t_world *world, int pos)
{
	int		i;
	size_t	size;
	t_obj	point;
	char	**pieces;

	pieces = ft_split(str[pos], ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_parser_error(*world, str, \
		"error code: 21 - Invalid params format");
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		point = create_point(ft_atof(pieces[0]), ft_atof(pieces[1]), \
		-ft_atof(pieces[2]));
		clean_array(pieces);
		return (point);
	}
	clean_array(pieces);
	clean_parser_error(*world, str, "error code: 22 - Invalid param");
	return ((t_obj){0});
}

t_obj	convert_vector(char **str, t_world *world, int pos)
{
	int		i;
	size_t	size;
	t_obj	vector;
	char	**pieces;

	pieces = ft_split(str[pos], ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_parser_error(*world, str, "error code: 05 - \
		Invalid params format");
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		vector = create_vector(ft_atof(pieces[0]), \
			ft_atof(pieces[1]), ft_atof(pieces[2]));
		clean_array(pieces);
		return (vector);
	}
	clean_array(pieces);
	clean_parser_error(*world, str, "error code: 06 - Invalid param");
	return ((t_obj){0});
}
