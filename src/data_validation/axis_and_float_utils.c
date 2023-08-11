/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_and_float_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:21:03 by dapaulin         ###   ########.fr       */
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

t_matrix	convert_xyz(char *str, t_world *world)
{
	int		i;
	size_t	size;
	char	**pieces;

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
		return (translation(ft_atof(pieces[0]), ft_atof(pieces[1]), ft_atof(pieces[2])));
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}

t_obj	convert_point(char *str, t_world *world)
{
	int		i;
	size_t	size;
	char	**pieces;

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
		return (create_point(ft_atof(pieces[0]), ft_atof(pieces[1]), ft_atof(pieces[2])));
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}

void	convert_normalize(char *str, t_shape *shape, t_world *world)
{
	int		i;
	size_t	size;
	char	**pieces;
	t_matrix	tmp;
	double	xyz[3];

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
			return ;
		}
	}
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}


t_obj	convert_normalize_cam(char *str, t_world *world)
{
	int		i;
	size_t	size;
	char	**pieces;
	double	xyz[3];

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
		xyz[0] = ft_atof(pieces[0]);
		xyz[1] = ft_atof(pieces[1]);
		xyz[2] = ft_atof(pieces[2]);
		if ((xyz[0] < 1 && xyz[0] > -1)
			|| (xyz[1] < 1 && xyz[1] > -1)
			|| (xyz[2] < 1 && xyz[2] > -1))
		{
			return (create_point(xyz[0], xyz[1], xyz[2]));
		}
	}
	clean_array(pieces);
	clean_world(*world);
	exit (1);
}
