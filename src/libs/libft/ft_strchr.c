/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:43 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:51:37 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	result = (char *)str;
	len = ft_strlen(result);
	while (i <= len)
	{
		if (result[i] == (unsigned char)c)
			return (&result[i]);
		i++;
	}
	return (0);
}
