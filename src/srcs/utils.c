/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:33:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/03 20:19:21 by dapaulin         ###   ########.fr       */
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

	int_value = dbl_value * 255;
	if (int_value == 0)
		return (ft_strdup("00"));
	i = 0;
	result = malloc(sizeof(char) * 3);
	if (!result)
		return (NULL);
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

char	*generate_color_string(double color, char *str)
{
	char	*rgb;
	char	*hex;

	rgb = NULL;
	hex = NULL;
	if (color > 1)
		hex = float_to_hex(1);
	else if (color < 0)
		hex = float_to_hex(0);
	else
		hex = float_to_hex(color);
	rgb = ft_strjoin(str, hex);
	if (hex)
		free(hex);
	if (str)
		free(str);
	return (rgb);
}

char	*join_rgb_colors(t_color color)
{
	char	*rgb;

	rgb = NULL;
	rgb = generate_color_string(color.red, ft_strdup(""));
	rgb = generate_color_string(color.green, rgb);
	rgb = generate_color_string(color.blue, rgb);
	return (rgb);
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
	if (hex)
		free(hex);
	return (dec);
}
