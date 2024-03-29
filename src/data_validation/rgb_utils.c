/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:11:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/11 04:40:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	check_char(char **str_array)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < ft_strlen(str_array[i]))
		{
			if (str_array[i][j] < '0' || str_array[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static t_bool	validate_rgb(char *input)
{
	char	**str_array;

	str_array = ft_split(input, ',');
	if (ft_arraylen(str_array) != 3)
	{
		clean_array(str_array);
		return (false);
	}
	if (ft_strlen(str_array[0]) > 3 || ft_strlen(str_array[1]) > 3
		|| ft_strlen(str_array[2]) > 3)
	{
		clean_array(str_array);
		return (false);
	}
	if (!check_char(str_array))
	{
		clean_array(str_array);
		return (false);
	}
	clean_array(str_array);
	return (true);
}

static double	convert_each_rgb(char *input)
{
	double	res;

	res = ft_atof(input);
	if (res < 0 || res > 255)
		return (-1);
	return (1.0 / 255.0 * res);
}

t_color	convert_to_rgb(char *input, t_bool *is_valid)
{
	t_color	rgb;
	char	**input_array;

	*is_valid = false;
	rgb = (t_color){0};
	if (!validate_rgb(input))
		return (rgb);
	input_array = ft_split(input, ',');
	rgb.red = convert_each_rgb(input_array[0]);
	rgb.green = convert_each_rgb(input_array[1]);
	rgb.blue = convert_each_rgb(input_array[2]);
	if (rgb.red < 0 || rgb.green < 0 || rgb.blue < 0)
	{
		clean_array(input_array);
		return (rgb);
	}
	clean_array(input_array);
	*is_valid = true;
	return (rgb);
}
