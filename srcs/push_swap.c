/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:41 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 16:34:26 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Test if only digits are entered in command line arguments, if the number 
 * enters in a int and if 2 numbers are the same
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
	if (!stack)
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

/*
 * Fill list with numbers from argv
*/

void	ft_fill_list(int ac, char **av, t_first *first)
{
	int	i;

	i = 1;
	while ((int)i < ac)
	{
		ft_insert_list(first, ft_atoi(av[i]));
		i++;
	}
}

/*
 * Check if numbers are in order
*/

void	ft_check_if_sorted(t_first *first)
{
	t_list	*stack;

	stack = first->first;
	ft_index(first);
	while (stack != NULL)
	{
		if (stack->next != NULL && stack->index > stack->next->index)
			return ;
		stack = stack->next;
	}
	exit (0);
}

int	main(int argc, char **argv)
{
	int		error;
	t_first	*first;
	t_first	*first_b;

	first = ft_init_list();
	first_b = ft_init_list();
	error = ft_parsing(argc, argv, first);
	if (error == 1)
		ft_error();
	ft_check_if_sorted(first);
	ft_index(first);
	if (argc <= 6)
		ft_select_small(first, first_b, argc);
	else
	{
		ft_find_max_shift(first);
		ft_radix(first, first_b, 0);
	}

	ft_display_list(first);
	ft_display_list(first_b);
	
	free(first);
	free(first->first);
	free(first->last);
	return (0);
}
