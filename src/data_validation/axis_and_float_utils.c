/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_and_float_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/12 20:54:22 by dapaulin         ###   ########.fr       */
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

t_matrix	convert_xyz(char **str, t_world *world, int pos)
{
	int			i;
	size_t		size;
	char		**pieces;
	t_matrix	mtx;

	pieces = ft_split(str[pos], ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_parser_error(*world, str, "error code: 99 - invalid quantity params");
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{		
		mtx = translation(ft_atof(pieces[0]), \
			ft_atof(pieces[1]), ft_atof(pieces[2]));
		clean_array(pieces);
		return (mtx);
	}
	clean_array(pieces);
	clean_parser_error(*world, str, "error code: 97 - invalid params");
	return (mtx);
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
		clean_parser_error(*world, str, "error code: 21 - Invalid params format");
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		point = create_point(ft_atof(pieces[0]), \
			ft_atof(pieces[1]), ft_atof(pieces[2]));
		clean_array(pieces);
		return (point);
	}
	clean_array(pieces);
	clean_parser_error(*world, str, "error code: 22 - Invalid param");
	return ((t_obj){0});
}
