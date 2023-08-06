/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:17:34 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/06 13:44:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_AND_REFRACTION_H
# define REFLECTION_AND_REFRACTION_H

# include "minirt.h"

t_color	reflected_color(t_world w, t_precomp c, int remaining);

#endif