/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:58:51 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:35:59 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	result;

	result = 1;
	if (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z'))
		result = 1;
	else
		return (0);
	return (result);
}
