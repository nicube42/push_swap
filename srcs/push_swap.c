/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:41 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 19:19:33 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	{
		ft_printf("error\n");
		ft_clean_exit(first);
	}
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
	ft_clean_exit(first);
	return (0);
}
