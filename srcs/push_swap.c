/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:41 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/18 11:39:03 by ndiamant         ###   ########.fr       */
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
 * Free all compenents of linked list
*/

void	ft_free_stack(t_first *first)
{
	t_list	*stack;
	t_list	*tmp;

	stack = first->first;
	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

/*
 * Free first and print error if parsing error
*/

void	ft_error_parsing(int error, t_first *first)
{
	if (error == 1)
	{
		ft_printf("error\n");
		ft_clean_exit(first);
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
	ft_free_stack(first);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_first	*first;
	t_first	*first_b;

	first = ft_init_list();
	first_b = ft_init_list();
	argc = ft_one_arg(argc, argv, first);
	ft_check_if_sorted(first);
	ft_index(first);
	if (argc <= 6)
		ft_select_small(first, first_b, argc);
	else
	{
		ft_find_max_shift(first);
		ft_radix(first, first_b, 0);
	}
	ft_clean_exit(first);
	return (0);
}
