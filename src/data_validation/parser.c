/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:52:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 06:59:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**parser_line(int fd)
{
	char	*line;
	int		i;
	char	**values;

	line = get_next_line(fd);
	printf("%s %d\n", line, fd);
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	values = ft_split(line, ' ');
	if (line)
		free(line);
	return (values);
}

t_color	convert_rgb(char *str, t_bool *is_valid)
{
	return (fill_color(0, 0, 1));
}

// t_bool	define_plane(char **params, t_lst **lst)
// {
// 	t_bool	is_valid;
// 	t_lst	*new_shape;
// 	t_obj	obj;
// 	t_color	color;

// 	is_valid = true;
// 	new_shape = ft_lstlast(*lst);
// 	if (!*lst)
// 	{
// 		*lst = ft_lstnew(new_plane());
// 		new_shape = *lst;
// 	}
// 	else
// 		new_shape = ft_lstnew(new_plane());
// 	new_shape->shape.id = plane;
// 	obj = convert_xyz(params[1], &is_valid);
// 	if (is_valid)
// 		return (false);
// 	if (is_valid)
// 		return (false);
// 	return (true);
// }

// t_bool	define_cylinder(char **params, t_lst **lst)
// {
// 	t_bool	is_valid;
// 	t_lst	*new_shape;
// 	t_obj	obj;
// 	t_color	color;

// 	is_valid = true;
// 	new_shape = ft_lstlast(*lst);
// 	if (!*lst)
// 	{
// 		*lst = ft_lstnew(new_sphere());
// 		new_shape = *lst;
// 	}
// 	else
// 		new_shape = ft_lstnew(new_sphere());
// 	new_shape->shape.id = sphere;
// 	obj = convert_xyz(params[1], &is_valid);
// 	if (is_valid)
// 		return (false);
// 	set_transform2(&new_shape->shape, translation(obj.x, obj.y, obj.z));
// 	new_shape->shape.any->material.color = convert_rgb(params[3], &is_valid);
// 	if (is_valid)
// 		return (false);
// 	return (true);
// }

t_bool	define_shape(int fd, t_lst **lst)
{
	char			**params;

	params = parser_line(fd);
	if (params)
	{
		if (params[0] == NULL || !ft_strncmp(params[0], "\n", 2))
		{
			clean_array(params);
			return (true);
		}
	}
	return (false);
}
		// if (ft_strncmp(params[0], "pl", 3) == 0)
		// 	return (define_plane(params, lst));
		// else if (ft_strncmp(params[0], "cy", 3) == 0)
		// 	return (define_cylinder(params, lst));
		// else if (ft_strncmp(params[0], "C", 2) == 0)
		// 	return (define_camera(params, lst));
		// else if (ft_strncmp(params[0], "A", 2) == 0)
		// 	return (define_ambient(params, lst));
		// else if (ft_strncmp(params[0], "L", 2) == 0)
		// 	return (define_light(params, lst));
		//else if (ft_strncmp(params[0], "sp", 3) == 0)
		//	return (define_sphere(params, lst));

void	parser_file(char *file_name, t_lst **lst)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	while (1)
	{
		if (define_shape(fd, lst))
			break ;
	}
	close (fd);
}
