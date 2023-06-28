/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_feature.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:17:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/28 16:31:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FEATURE_H
# define OBJECT_FEATURE_H

# include "structs.h"
# include "defines.h"

// Create objects
t_obj		*create_point(double x, double y, double z);
t_obj		*create_vector(double x, double y, double z);
t_obj		*create_object(double x, double y, double z, double w);

#endif