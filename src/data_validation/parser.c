/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:52:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 01:27:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**parser_line(int fd)
{
	char	*line;
	int		i;
	char	**values;

	line = get_next_line(fd);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	values = ft_split(line, ' ');
	if (line)
		free(line);
	if (values && !values[0])
	{
		clean_array(values);
		return (NULL);
	}
	return (values);
}

t_any_input	define_shape(int fd)
{
	int				i;
	char			**params;
	t_any_input		shape;

	shape = (t_any_input){0};
	params = parser_line(fd);
	if (ft_strncmp(params[0], "pl", 3) == 0)
		shape.type = plane;
	i = 0;
	while (params[i])
		i++;
	if (params[0])
		free(params[0]);
	if (params)
		free(params);
	return (shape);
}
	// shape.params = malloc(sizeof(char *) * i);
	// if (1) // valid_xyz(params[1])
	// 	shape.params[0] = params[1];
	// if (1) // valid_xyz(params[2])
	// 	shape.params[1] = params[2];
	// if (1) // valid_rgb(params[3])
	// 	shape.params[2] = params[3];
	// shape.params[3] = NULL;
