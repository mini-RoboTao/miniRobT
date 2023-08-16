/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:52:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 19:23:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	insert_obj_in_world(char **params, t_world *world)
{
	static int counter;

	if (check_file_params(params, world, 0))
		return ;
	else if (!ft_strncmp(*params, "sp", 3))
		fill_sphere(world, define_sphere(params, world));
	else if (!ft_strncmp(*params, "pl", 3))
		fill_plane(world, define_plane(params, world));
	else if (!ft_strncmp(*params, "cy", 3))
		fill_cylinder(world, define_cylinder(params, world));
	else if (!ft_strncmp(*params, "A", 2))
		fill_a_light(world, define_ambient_light(params, world));
	else if (!ft_strncmp(*params, "L", 2))
		fill_light(world, define_light(params, world));
	else if (!ft_strncmp(*params, "C", 2))
		world->camera = new_camera(define_camera(params, world));
	else
		clean_parser_error(*world, params, "error code: 99 - Invalid file");
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
	values = ft_split(line, ' ');
	if (line)
		free(line);
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
	}
	//check_file_params(params, world, 1);
	clean_array(params);	
	close (world->fd);
}
