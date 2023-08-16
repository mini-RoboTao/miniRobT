/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:39:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 19:22:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_extension(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1 || !set)
		return (0);
	j = ft_strlen(set);
	s = ft_strrchr(s1, '/');
	if (!s)
		s = (char *)s1;
	else
		s++;
	i = ft_strlen(s);
	if (i <= 4)
		return (1);
	while (j > 0 && s[i - 1] == set[j - 1])
	{
		i--;
		j--;
	}
	if (j != 0)
		return (1);
	return (0);
}

int	check_file_params(char **params, t_world *world, int check_end)
{
	static int	A;
	static int	C;
	static int	L;

	// if (check_end && (!A || !C || !L))
	// 	clean_parser_error(*world, params, "One needed param don't exist");
	if (!*params || *params[0] == '#')
		return (1);
	if (!ft_strncmp(*params, "A", 2) && !A)
		A += 42;
	else if (!ft_strncmp(*params, "A", 2) && A)
		clean_parser_error(*world, params, "Duplicate Ambient Light");
	if (!ft_strncmp(*params, "C", 2) && !C)
		C += 42;
	else if (!ft_strncmp(*params, "C", 2) && C)
		clean_parser_error(*world, params, "Duplicate Camera");
	if (!ft_strncmp(*params, "L", 2) && !L)
		L += 42;
	else if (!ft_strncmp(*params, "L", 2) && L)
		clean_parser_error(*world, params, "Duplicate Light");
	return (0);
}

void	check_input_file(t_data *data, int ac, char **av)
{
	if (ac == 2 && !check_extension(av[1], ".rt"))
	{
		data->file_name = av[1];
		return ;
	}
	print_error("error code: 1 - Invalid file");
	exit (-1);
}