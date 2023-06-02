/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:46 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:49:49 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_string(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static void	ft_alloc_mem(char **split_array, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				j++;
				s++;
			}
			split_array[i] = (char *)malloc(sizeof(char) * (j + 1));
			i++;
			j = 0;
		}
		else
			s++;
	}
}

static void	fill_array(char **result_array, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				result_array[i][j] = *s;
				s++;
				j++;
			}
			result_array[i][j] = '\0';
			i++;
			j = 0;
		}
		else
			s++;
	}
	result_array[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = ft_count_string(s, c);
	result = (char **)malloc(sizeof (char *) * (i + 1));
	if (!s || !result)
		return (0);
	ft_alloc_mem(result, s, c);
	fill_array(result, s, c);
	return (result);
}
