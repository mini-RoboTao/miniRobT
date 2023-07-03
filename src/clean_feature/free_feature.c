/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_feature.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:16:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/03 19:24:33 by dapaulin         ###   ########.fr       */
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
			while(x < c->width)
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
