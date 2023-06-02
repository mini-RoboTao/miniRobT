/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:20 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 22:55:15 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	count1;
	size_t	count2;

	if ((int)len < 0)
		len = ft_strlen(str);
	count1 = 0;
	if (to_find[count1] == '\0')
		return ((char *)str);
	while (count1 < len && str[count1] != '\0')
	{
		count2 = 0;
		while (str[count1 + count2] == to_find[count2])
		{
			count2++;
			if ((count1 + count2 < len + 1) && (to_find[count2] == '\0'))
				return ((char *)&str[count1]);
		}
		count1++;
	}
	return (NULL);
}
