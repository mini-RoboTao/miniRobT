/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:01:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 17:00:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "minirt.h"

typedef struct a_lst {
	t_obj			*obj;
	struct a_lst	*next;
}				t_lst;

// list
t_lst			*ft_lstnew(t_obj *obj);
int				ft_lstsize(t_lst *l);
t_lst			*ft_lstlast(t_lst *l);
void			ft_lstadd_back(t_lst **l, t_lst *new);
void			ft_lstclean(t_lst **l, void (*del)(t_obj *));

// ray
int				ft_lstray_size(t_intersection *l);
t_intersection	*ft_lstray_last(t_intersection *l);
void			clean_intersection_lst(t_intersection **l);
void			ft_lstrayadd_back(t_intersection **l, t_intersection *new);
void			ft_lst_ray_sort_add(t_intersection **l, t_intersection *new);

#endif