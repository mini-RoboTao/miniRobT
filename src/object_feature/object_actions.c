/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:41:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:17:19 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_feature.h"

// The second param is a normalize vector.
t_projectile	*create_proj(t_obj point_p, t_obj vector_v)
{
	t_projectile	*p;

	p = malloc(sizeof(t_projectile));
	if (!p)
		return (NULL);
	p->position = point_p;
	p->velocity = vector_v;
	return (p);
}

t_environment	*create_env(t_obj vector_g, t_obj vector_w)
{
	t_environment	*e;

	e = malloc(sizeof(t_environment));
	if (!e)
		return (NULL);
	e->gravity = vector_g;
	e->wind = vector_w;
	return (e);
}

t_projectile	*tick(t_environment *e, t_projectile *p)
{
	t_projectile	*new_p;
	t_obj			tmp;
	t_obj			position;
	t_obj			velocity;

	position = sum_objects(p->position, p->velocity);
	tmp = sum_objects(p->velocity, e->gravity);
	velocity = sum_objects(tmp, e->wind);
	new_p = create_proj(position, velocity);
	return (new_p);
}
