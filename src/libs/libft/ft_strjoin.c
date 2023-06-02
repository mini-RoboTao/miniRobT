/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:35 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 23:17:27 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		iresult;
	int		i;

	i = 0;
	iresult = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i] != '\0')
	{
		result[iresult] = s1[i];
		iresult++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[iresult] = s2[i];
		iresult++;
		i++;
	}
	result[iresult] = '\0';
	return (result);
}
