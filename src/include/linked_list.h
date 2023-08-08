/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:01:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 22:28:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "minirt.h"

// list
t_lst			*ft_lstnew(t_shape shape);
int				ft_lstsize(t_lst *l);
t_lst			*ft_lstlast(t_lst *l);
void			ft_lstadd_back(t_lst **l, t_lst *new);
void			ft_lstremove(t_lst **l, t_shape rm);
void			ft_only_lstclean(t_lst **l);
void			ft_lstclean(t_lst **l, void (*del)(void *));

// ray
t_intersection	*ft_lstnew_ray(double t, t_shape shape, size_t id);
int				ft_lstray_size(t_intersection *l);
t_intersection	*ft_lstray_last(t_intersection *l);
void			clean_intersection_lst(t_intersection **l);
void			ft_lstrayadd_back(t_intersection **l, t_intersection *new);
void			ft_lst_ray_sort_add(t_intersection **l, t_intersection *new);

#endif