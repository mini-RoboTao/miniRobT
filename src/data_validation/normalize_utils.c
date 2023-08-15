/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/15 15:14:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	set_rotate(t_shape *shape, char **pieces)
{
	double		xyz[3];

	xyz[0] = ft_atof(pieces[0]);
	xyz[1] = ft_atof(pieces[1]);
	xyz[2] = ft_atof(pieces[2]);
	if ((xyz[0] <= 1 && xyz[0] >= -1)
		|| (xyz[1] <= 1 && xyz[1] >= -1)
		|| (xyz[2] <= 1 && xyz[2] >= -1))
	{
		set_transform2(shape, rotation_x(xyz[0] * (M_PI)));
		set_transform2(shape, rotation_y(xyz[1] * (M_PI)));
		set_transform2(shape, rotation_z(xyz[2] * (M_PI)));
		return (true);
	}
	return (false);
}

void	convert_normalize(char **str, t_shape *shape, t_world *world, int pos)
{
	int			i;
	size_t		size;
	char		**pieces;
	t_matrix	tmp;

	pieces = ft_split(str[pos], ',');
	size = ft_arraylen(pieces);
	if (size != 3)
		clean_parser_error(*world, str, "error code: 17 - Invalid params format");
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		if (set_rotate(shape, pieces))
		{
			clean_array(pieces);
			return ;
		}
	}
	clean_parser_error(*world, str, "error code: 13 - Invalid param");
}

static t_obj	aux_normalize_cam(char **pieces)
{
	double	xyz[3];

	xyz[0] = ft_atof(pieces[0]);
	xyz[1] = ft_atof(pieces[1]);
	xyz[2] = ft_atof(pieces[2]);
	if ((xyz[0] <= 1 && xyz[0] >= -1)
		&& (xyz[1] <= 1 && xyz[1] >= -1)
		&& (xyz[2] <= 1 && xyz[2] >= -1))
		return (create_vector(xyz[0], xyz[1], xyz[2]));
	return (create_vector(42, 0, 0));
}

t_obj	convert_normalize_cam(char **str, t_world *world, int pos)
{
	int		i;
	size_t	size;
	char	**pieces;
	t_obj	res;

	pieces = ft_split(str[pos], ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_parser_error(*world, str, "error code: 11 - Invalid params format");
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		res = aux_normalize_cam(pieces);
		if (res.x <= 1 && res.x >= -1)
		{
			clean_array(pieces);
			return (res); 
		}
	}
	clean_array(pieces);
	clean_parser_error(*world, str, "error code: 10 - Invalid param");
	return (res);
}
