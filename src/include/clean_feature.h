/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:17:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/04 17:06:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_FEATURE_H
# define CLEAN_FEATURE_H

# include "minirt.h"

// free feature
void	clean_obj(t_obj *o);
void	clean_canvas(t_canvas *c);
void	clean_env(t_environment *c);
void	clean_proj(t_projectile *c);

#endif