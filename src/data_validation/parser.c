/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:52:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/12 22:15:41 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	insert_obj_in_world(char **params, t_world *world)
{
	static int counter;
	printf("%s QUANTAS VEZES ELE PASSA AQUI?????? %s%d%s **********************************************\n", YELLOW, GREEN, counter++, RESET_COLORS);
	if (check_order_input(params, world))
		return ;
	// colocar o else
	if (!ft_strncmp(*params, "sp", 3))
		define_sphere(params, world);
	else if (!ft_strncmp(*params, "pl", 3))
		define_plane(params, world);
	else if (!ft_strncmp(*params, "cy", 3))
		define_cylinder(params, world);
	else if (!ft_strncmp(*params, "A", 2))
		define_ambient_light(params, world);
	else if (!ft_strncmp(*params, "L", 2))
		define_light(params, world);
	else if (!ft_strncmp(*params, "C", 2))
		define_camera(params, world);
	else
	{
		printf("%sAQUIIIIIII%s\n\n", GREEN, RESET_COLORS);
		clean_parser_error(*world, params, "Invalid file");
	}
}

char	**parser_line(int fd)
{
	char	*line;
	int		i;
	char	**values;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
		i++;
	}
	printf("'%s'\n", line);
	values = ft_split(line, ' ');
	if (line)
		free(line);
	printf("'%s'\n", *values);
	for (size_t j = 0; j < ft_arraylen(values); j++)
		printf("value[%zu]\t%s\n", j, values[j]);
	printf("\n");
	return (values);
}

void	parser_file(char *file_name, t_world *world)
{
	int		fd;
	char	**params;

	world->fd = open(file_name, O_RDONLY);
	if (world->fd == -1)
		clean_parser_error(*world, NULL, "Fail to open file: ");
	params = parser_line(world->fd);
	while (params)
	{
		insert_obj_in_world(params, world);
		clean_array(params);
		params = parser_line(world->fd);
		printf("%p\n", params);
	}
	printf("ta chegando aqui\n");
	printf("%p\n", params);
	clean_array(params);
	// t_lst *temp = world->lst;
	// while(temp)
	// {
	// 	printf("%s PRINTING OBJECTS\n\n%s", CYAN, RESET_COLORS);
	// 	printf("%d\n", temp->shape.id);
	// 	printf("%f\n", temp->shape.any->x);
	// 	printf("%f\n", temp->shape.any->y);
	// 	printf("%f\n", temp->shape.any->z);
	// 	printf("%f\n", temp->shape.any->material.ambient);
	// 	for (int k = 0; k < 4; k++)
	// 	{
	// 		printf("[");
	// 		for (int l = 0; l < 4; l++)	
	// 			printf("%.3f ", temp->shape.any->transform.node[k][l]);
	// 		printf("]\n");
	// 	}
	// 	printf("%d\n", temp->shape.any->transform.x);
	// 	printf("%d\n", temp->shape.any->transform.x);
	// 	printf("%f\n", temp->shape.any->material.color.red);
	// 	printf("%f\n", temp->shape.any->material.color.green);
	// 	printf("%f\n", temp->shape.any->material.color.blue);
	// 	temp = temp->next;
	// }
	
	close (world->fd);
}
