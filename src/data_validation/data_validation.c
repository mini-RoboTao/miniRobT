/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:37:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/18 17:02:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	apply_ambient_light(t_world *world)
{
	t_lst	*l;
	t_color	new;

	l = world->lst;
	while (l)
	{
		l->shape.any->material.ambient = world->a_light.intensity;
		l = l->next;
	}
}

void	data_validation(t_data *data, int ac, char **av)
{
	data->win_w = WIDTH;
	data->win_h = HEIGHT;
	data->win_name = "Mini-RobT";
	//check_input_file(data, ac, av);
	//parser_file(data->file_name, &data->world);
	//apply_ambient_light(&data->world);
	put_together(data);
}
