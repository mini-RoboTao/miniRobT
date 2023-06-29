/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:01:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/28 21:21:52 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "minirt.h"

typedef struct a_lst {
	t_object		*obj;
	struct a_lst	*next;
}				t_lst;

t_lst			*ft_lstnew(t_object *obj);
int				ft_lstsize(t_lst *l);
t_lst			*ft_lstlast(t_lst *l);
void			ft_lstadd_back(t_lst **l, t_lst *new);
void			ft_lstclean(t_lst **l, void (*del)(t_object *));

#endif