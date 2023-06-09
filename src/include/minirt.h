/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:38:20 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/11 12:08:01 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define VERSION "0.0.1"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifdef __APPLE__
#  include "mlx.h"// delete before close the project
# elif __linux__
#  include "mlx.h"
// # include <mlx.h>// needed to run in 42's linux
#  include <X11/X.h>// needed to run in 42's linux
#  include <X11/keysym.h>// needed to run in 42's linux
# endif
# include <math.h>
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "enums.h"
# include "clean_feature.h"
# include "object_feature.h"
# include "object_colors.h"
# include "canvas.h"
# include "functions.h"
# include "matrix_feature.h"
# include "matrix_transformations.h"
#endif
