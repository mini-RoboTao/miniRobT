/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:52:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:27:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	insert_obj_in_world(char **params, t_world *world)
{
	if (!ft_strncmp(*params, "sp", 3))
		define_sphere(params, world);
	if (!ft_strncmp(*params, "pl", 3))
		define_plane(params, world);
	if (!ft_strncmp(*params, "cy", 3))
		define_cylinder(params, world);
	if (!ft_strncmp(*params, "A", 2))
		define_ambient_light(params, world);
	if (!ft_strncmp(*params, "L", 2))
		define_light(params, world);
	if (!ft_strncmp(*params, "C", 2))
		define_camera(params, world);
}

void	parser_file(char *file_name, t_world *world)
{
	int		i;
	int		fd;
	char	**params;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		clean_world(*world);
		perror("Fail to open file: ");
		exit(1);
	}
	i = 0;
	params = parser_line(fd);
	while (params && params[i])
	{
		insert_obj_in_world(params, world);
		params = parser_line(fd);
	}
	printf("%p\n", world->lst);
	close (fd);
}
