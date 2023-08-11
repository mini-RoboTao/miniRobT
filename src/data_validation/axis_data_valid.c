/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_data_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:53 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 01:52:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	is_valid_float(char *str)
{
	int	i;

	i = 0;
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

static int	set_float(double *res, char **array, int i, t_bool *is_valid)
{
	if (!is_valid_float(array[i]))
	{
		clean_array(array);
		*is_valid = false;
		return (0);
	}
	*res = ft_atof(array[i]);
	return (1);
}

t_obj	convert_xyz(char *str, t_bool *is_valid)
{
	size_t	size;
	t_obj	point;
	char	**comma;

	*is_valid = true;
	point = create_point(0, 0, 0);
	comma = ft_split(str, ',');
	size = ft_arraylen(comma);
	if (size != 3)
	{
		*is_valid = false;
		clean_array(comma);
		return (point);
	}
	if (!set_float(&point.x, comma, 0, is_valid))
		return (point);
	if (!set_float(&point.y, comma, 1, is_valid))
		return (point);
	if (!set_float(&point.z, comma, 2, is_valid))
		return (point);
	clean_array(comma);
	return (point);
}

t_obj	convert_3d_normalized(char *str, t_bool *is_valid)
{
	t_obj	vector;

	vector = convert_xyz(str, is_valid);
	if (!*is_valid)
		return (vector);
	if (vector.x < -1 || vector.x > 1
		|| vector.y < -1 || vector.y > 1
		|| vector.z < -1 || vector.z > 1)
	{
		*is_valid = false;
		return (create_vector(0, 0, 0));
	}
	vector.w = 0;
	return (vector);
}
