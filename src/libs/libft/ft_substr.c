/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:03 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 23:13:16 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	slen;

	i = 0;
	if (len >= ft_strlen(s))
		slen = ft_strlen(s) - start;
	else
		slen = len;
	if (start > ft_strlen(s))
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = 0;
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (slen + 1));
	if (!result)
		return (NULL);
	while (i < slen)
	{
		result[i++] = s[start];
		start++;
	}
	result[i] = '\0';
	return (result);
}
