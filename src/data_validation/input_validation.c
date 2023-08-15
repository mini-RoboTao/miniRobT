/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:39:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/14 11:27:00 by rotakesh         ###   ########.fr       */
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

int	check_label(char *label, char *tag, int *flag, t_world *w)
{
	if (ft_strncmp(label, tag, 2) && !*flag)
		clean_parser_error(*w, NULL, "Order of objectos incorrect in file");
	*flag = 1;
	return (1);
}

int	check_order_input(char **params, t_world *world)
{
	static int	A;
	static int	C;
	static int	L;

	if (!*params || *params[0] == '#')
		return (1);
	if (A && C && L)
		return (0);
	if (check_label(*params, "A", &A, world))
		return (0);
	if (check_label(*params, "C", &C, world))
		return (0); 
	if (check_label(*params, "L", &L, world))
		return (0);
	return (0);
}

void	check_input_file(t_data *data, int ac, char **av)
{
	if (ac == 2 && !check_extension(av[1], ".rt"))
	{
		data->file_name = av[1];
		return ;
	}
	// perror(RED"Error\n");

	// char *str = "\001\e[31m\002 Error\n";
	// write(1, str, ft_strlen(str));
	// perror(YELLOW"Invalid file"RESET_COLORS);
	print_error("error code: 1 - Invalid file");
	exit (-1);
}