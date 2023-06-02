/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:07 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 15:14:03 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_string(char const *str, char const *verify)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(verify))
	{
		if (str[i] == verify[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static size_t	end_string(char const *str, char const *verify)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (j < ft_strlen(verify))
	{
		if (str[i] == verify[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	char	*result;
	size_t	start;
	size_t	finish;

	count = 0;
	start = start_string(s1, set);
	finish = end_string(s1, set);
	if (start == ft_strlen(s1) || !s1 || !set)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (finish - start + 2));
	if (result == NULL)
		return (NULL);
	while (start <= finish)
	{
		result[count] = s1[start];
		count++;
		start++;
	}
	result[count] = '\0';
	return (result);
}
