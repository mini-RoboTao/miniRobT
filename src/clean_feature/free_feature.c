/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_feature.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 09:48:46 by dapaulin         ###   ########.fr       */
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
