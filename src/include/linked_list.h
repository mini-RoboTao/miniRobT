/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:01:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/17 20:01:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "minirt.h"

typedef struct a_lst {
	t_object		*obj;
	struct a_lst	*next;
}				t_lst;

// list
t_lst			*ft_lstnew(t_object *obj);
int				ft_lstsize(t_lst *l);
t_lst			*ft_lstlast(t_lst *l);
void			ft_lstadd_back(t_lst **l, t_lst *new);
void			ft_lstclean(t_lst **l, void (*del)(t_object *));

// ray
int				ft_lstray_size(t_intersection *l);
t_intersection	*ft_lstray_last(t_intersection *l);
void			clean_intersection_lst(t_intersection **l);
void			ft_lstrayadd_back(t_intersection **l, t_intersection *new);

#endif