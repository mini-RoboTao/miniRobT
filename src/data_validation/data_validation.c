/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:37:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/17 23:14:22 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	data_validation(t_data *data, int ac, char **av)
{
	data->win_w = WIDTH;
	data->win_h = HEIGHT;
	data->win_name = "Mini-RobT";
	check_input_file(data, ac, av);
	parser_file(data->file_name, &data->world);
}
