/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:35:06 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/14 11:44:13 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(char *msg)
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error\n", 6);
	write(2, YELLOW, ft_strlen(YELLOW));
	perror(msg);
	write(2, RESET_COLORS, ft_strlen(RESET_COLORS));
}
