/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:04:35 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/13 23:07:46 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Print "error" and exit the program in case of an incorrect entry
*/

void	ft_error(void)
{
	ft_printf("error\n");
	exit(1);
}

int	ft_is_biggest(t_first *first)
{
	t_list	*stack;
	t_list	*tmp;

	stack = first->first;
	tmp = first->first;
	while (stack != NULL)
	{
		if (stack->content > tmp->content)
			tmp = stack;
		stack = stack->next;
	}
	first->biggest = tmp;
	return (tmp->content);
}

int	ft_is_smallest(t_first *first)
{
	t_list	*stack;
	t_list	*tmp;

	stack = first->first;
	tmp = first->first;
	while (stack != NULL)
	{
		if (stack->content < tmp->content)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp->content);
}

void	ft_index(t_first *first)
{
	t_list	*stack;
	t_list	*stack_smallest;
	int		i;

	i = 1;
	ft_is_biggest(first);
	while (i <= first->count)
	{
		stack_smallest = first->biggest;
		stack = first->first;
		while (stack != NULL)
		{
			if (stack->index < 1)
			{
				if (stack->content < stack_smallest->content)
					stack_smallest = stack;
			}
			stack = stack->next;
		}
		stack_smallest->index = i;
		i++;
	}
}

void	ft_push_back(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	while (stack_a != NULL)
	{
		ft_index(first_a);
		if (first_a->first->content < first_b->first->content)
		{
			if (stack_b->index <= 2)
			{
				while (first_a->first->content != ft_is_biggest(first_a))
					ft_rotate(first_a, 0);
			}
			else
			{
				while (first_a->first->content != ft_is_biggest(first_a))
					ft_reverse_rotate(first_a, 0);
			}
		}
		else
		{
			if (stack_b->index <= 2)
			{
				while (first_a->first->content != ft_is_smallest(first_a))
					ft_rotate(first_a, 0);
			}
			else
			{
				while (first_a->first->content != ft_is_smallest(first_a))
					ft_reverse_rotate(first_a, 0);
			}
		}
		stack_a = stack_a->next;
	}
}