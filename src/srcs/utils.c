/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:33:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/02 20:46:40 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rev_str(char **str)
{
	size_t	len;
	char	temp;
	size_t	i;

	i = 0;
	len = ft_strlen(*str);
	if (len == 1)
	{
		str[0][1] = 48;
		str[0][2] = '\0';
		len = 2;
	}
	while (i < len)
	{
		temp = str[0][i];
		str[0][i] = str[0][len - 1];
		str[0][len - 1] = temp;
		i++;
		len--;
	}
}

char	*float_to_hex(double dbl_value)
{
	char	*result;
	int		int_value;
	int		remain;
	int		i;

	result = malloc(sizeof(char) * 3);
	if (!result)
		return (NULL);
	int_value = dbl_value * 255;
	i = 0;
	if (int_value == 0)
		return ("00");
	while (int_value != 0)
	{
		remain = int_value % 16;
		if (remain < 10)
			result[i++] = remain + 48;
		else
			result[i++] = remain + 55;
		int_value = int_value / 16;
	}
	result[i] = '\0';
	rev_str(&result);
	return (result);
}

char	*join_rgb_colors(t_color color)
{
	char	*result;

	if (color.red > 1)
		result = ft_strjoin("", float_to_hex(1));
	else if (color.red < 0)
		result = ft_strjoin("", float_to_hex(0));
	else
		result = ft_strjoin("", float_to_hex(color.red));
	if (color.green > 1)
		result = ft_strjoin(result, float_to_hex(1));
	else if (color.green < 0)
		result = ft_strjoin(result, float_to_hex(0));
	else
		result = ft_strjoin(result, float_to_hex(color.green));
	if (color.blue > 1)
		result = ft_strjoin(result, float_to_hex(1));
	else if (color.blue < 0)
		result = ft_strjoin(result, float_to_hex(0));
	else
		result = ft_strjoin(result, float_to_hex(color.blue));
	return (result);
}

int	hex_to_int(char *hex)
{
	int	dec;
	int	base;
	int	i;

	dec = 0;
	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			dec += (hex[i] - '0') * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			dec += (hex[i] - 'A' + 10) * base;
			base *= 16;
		}
		i--;
	}
	return (dec);
}
