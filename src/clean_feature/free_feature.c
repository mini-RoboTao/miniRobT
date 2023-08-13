/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_feature.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/13 00:24:42 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_canvas(t_canvas *c)
{
	int	x;

	x = 0;
	if (c)
	{
		if (c->canvas)
		{
			while (x < c->width)
			{
				if (c->canvas[x])
					free(c->canvas[x]);
				x++;
			}
			free(c->canvas);
		}
		free(c);
	}
}

void	clean_shape(t_shape *obj)
{
	if (obj->any)
		free(obj->any);
}

void	clean_world(t_world w)
{
	int	i;

	i = 0;
	ft_lstclean(&w.lst, free);
}

void	clean_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
}

void	clean_parser_error(t_world world, char **params, char *errormsg)
{
	char *line;

	clean_array(params);
	line = get_next_line(world.fd);
	while (line)
	{
		free(line);
		line = get_next_line(world.fd);
	}
	if (line)
		free(line);
	close(world.fd);
	clean_world(world);
	print_error(errormsg);
	exit(42);
}
