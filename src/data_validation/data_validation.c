/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:37:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/12 22:06:55 by dapaulin         ###   ########.fr       */
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
	// printf("a.light\n");
	// printf("%f\n", data->world.a_light.red);
	// printf("%f\n", data->world.a_light.green);
	// printf("%f\n", data->world.a_light.blue);
	// printf("camera\n");
	// printf("%f\n", data->world.camera.field_of_view);
	// data->canvas = generate_canvas(data->win_w, data->win_h);
	put_together(data);
}
