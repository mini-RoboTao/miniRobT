/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 20:12:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	set_rotate(t_shape *shape, char **pieces)
{
	double		xyz[3];

	xyz[0] = ft_atof(pieces[0]);
	xyz[1] = ft_atof(pieces[1]);
	xyz[2] = ft_atof(pieces[2]);
	if ((xyz[0] < 1 && xyz[0] > -1)
		|| (xyz[1] < 1 && xyz[1] > -1)
		|| (xyz[2] < 1 && xyz[2] > -1))
	{
		set_transform2(shape, rotation_x(xyz[0] * (M_PI * 2)));
		set_transform2(shape, rotation_y(xyz[1] * (M_PI * 2)));
		set_transform2(shape, rotation_z(xyz[2] * (M_PI * 2)));
		return (true);
	}
	return (false);
}

void	convert_normalize(char *str, t_shape *shape, t_world *world)
{
	int			i;
	size_t		size;
	char		**pieces;
	t_matrix	tmp;

	pieces = ft_split(str, ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_world(*world);
		exit (1);
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		if (set_rotate(shape, pieces))
			return ;
	}
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}

static t_obj	aux_normalize_cam(char **pieces)
{
	double	xyz[3];

	xyz[0] = ft_atof(pieces[0]);
	xyz[1] = ft_atof(pieces[1]);
	xyz[2] = ft_atof(pieces[2]);
	if ((xyz[0] < 1 && xyz[0] > -1)
		|| (xyz[1] < 1 && xyz[1] > -1)
		|| (xyz[2] < 1 && xyz[2] > -1))
		return (create_point(xyz[0], xyz[1], xyz[2]));
	return (create_point(42, 0, 0));
}

t_obj	convert_normalize_cam(char *str, t_world *world)
{
	int		i;
	size_t	size;
	char	**pieces;
	t_obj	res;

	pieces = ft_split(str, ',');
	size = ft_arraylen(pieces);
	if (size != 3)
	{
		clean_array(pieces);
		clean_world(*world);
		exit (1);
	}
	while (i < size && is_valid_float(pieces[i]))
		i++;
	if (i == size)
	{
		res = aux_normalize_cam(pieces);
		if (res.x < 1 && res.x > -1)
			return (res);
	}
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}
