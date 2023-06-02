/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:23 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 15:22:29 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		count;
	const char	*str1;
	const char	*str2;

	count = 0;
	str1 = s1;
	str2 = s2;
	while (count < n && (str1[count] != '\0' || str2[count] != '\0'))
	{
		if (str1[count] == str2[count])
			count++;
		else if (str1[count] != str2[count])
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
	}
	return (0);
}
