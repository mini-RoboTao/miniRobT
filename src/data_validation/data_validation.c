/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:37:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 03:48:40 by rotakesh         ###   ########.fr       */
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
	printf("LUZ, CAMERAAAA, ACAOOOO!!\n");
	printf("%f\n", data->world.light.position.x);
	printf("%f\n", data->world.light.position.y);
	printf("%f\n", data->world.light.position.z);
	data->world.light.position.y = 10;
	data->world.light.intensity = fill_color(1, 1, 1);
	printf("%f\n", data->world.lst->shape.any->x);
	printf("%f\n", data->world.lst->next->shape.id);
	/*
		set_ambient_light();
	*/
	// printf("a.light\n");
	// printf("%f\n", data->world.a_light.red);
	// printf("%f\n", data->world.a_light.green);
	// printf("%f\n", data->world.a_light.blue);
	// printf("camera\n");
	// printf("%f\n", data->world.camera.field_of_view);
	// data->canvas = generate_canvas(data->win_w, data->win_h);
	// put_together(data);
}
