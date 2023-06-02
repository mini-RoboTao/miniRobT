/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:17 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 15:27:14 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;
	int		len;

	result = (char *)str;
	len = (int)ft_strlen(result);
	while (len >= 0)
	{
		if (result[len] == (unsigned char)c)
			return (&result[len]);
		len--;
	}
	return (0);
}
