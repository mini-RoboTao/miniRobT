/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_feature.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/06 00:55:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_obj(t_obj *o)
{
	if (o)
	{
		free(o);
		o = NULL;
	}
}

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

void	clean_env(t_environment *c)
{
	if (c)
	{
		if (c->gravity)
			free(c->gravity);
		if (c->wind)
			free(c->wind);
		free(c);
	}
}

void	clean_proj(t_projectile *c)
{
	if (c)
	{
		if (c->position)
			free(c->position);
		if (c->velocity)
			free(c->velocity);
		free(c);
	}
}

void	*clean_matrix(t_matrix *m)
{
	int	i;

	i = 0;
	if (m)
	{
		if (m->node)
		{
			while (i < m->y)
			{
				if (m->node[i])
					free(m->node[i]);
				i++;
			}
			free(m->node);
		}
		free(m);
	}
	return (NULL);
}
