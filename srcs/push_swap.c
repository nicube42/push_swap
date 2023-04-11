/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:41 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/05 14:56:44 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Test if only digits are entered in command line arguments, if the number 
enters in a int and if 2 numbers are the same
*/

int	ft_parsing(int ac, char **av, t_first *first)
{
	size_t	i;
	size_t	j;
	long	max_int;
	long	min_int;
	int		ret;
	int		*stack;

	stack = ft_calloc(ac, sizeof(int));
	if(!stack)
		ft_error();
	i = 1;
	max_int = 2147483647;
	min_int	= -2147483648;
	while (i < ft_strlen(av[i]))
	{
		if ((ft_atol(av[i]) > max_int) || (ft_atol(av[i]) < min_int))
			return (1);
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][0] != '-')
				return (1);
			j++;
		}
		i++;
	}
	i = 1;
	while ((int)i < ac)
	{
		stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret = ft_isduplicate(ac, stack);
	ft_fill_list(ac, av, first);
	return (ret);
}

void	ft_fill_list(int ac, char **av, t_first *first)
{
	int	i;

	i = 1;
	while ((int)i < ac)
	{
		ft_insert_list(first, ft_atoi(av[ac - i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		error;
	t_first	*first;

	first = ft_init_list();
	first = ft_calloc(argc, sizeof(int));
	if(!first)
		ft_error();
	error = ft_parsing(argc, argv, first);
	if (error == 1)
		ft_error();
	if (argc == 3)
		ft_two_numbers(first);
	if (argc == 4)
		ft_three_numbers(first);
    //ft_destroy_list(list);
    ft_display_list(first);
	return (0);
}
