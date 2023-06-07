/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:38:20 by rotakesh          #+#    #+#             */
/*   Updated: 2023/06/07 16:30:23 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define VERSION "0.0.1"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifdef __APPLE__
# include "mlx.h" // delete before close the project
# elif __linux__
# include <mlx.h> // needed to run in 42's linux
# include <X11/X.h> // needed to run in 42's linux
# include <X11/keysym.h> // needed to run in 42's linux
# endif
# include <math.h>
# include "defines.h"
# include "structs.h"

#endif
