/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:04:35 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 19:37:54 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Find biggest number and return it
 * Also stock it in first->biggest
*/

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

/*
 * Find smallest number and return it
*/

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

/*
 * Index all numbers from 0 to size -1
*/

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

/*
 * Check if it's quicker to reverse rotate or rotate
*/

void	ft_prepare_push(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	while (stack_a != NULL)
	{
		ft_index(first_a);
		ft_prepare_push_2(first_a, first_b, stack_a);
		stack_a = stack_a->next;
	}
}

void	ft_prepare_push_2(t_first *first_a, t_first *first_b, t_list *stack_a)
{
	if (first_b->first->content > ft_is_biggest(first_a)
		|| first_b->first->content < ft_is_smallest(first_a))
	{
		while (first_a->first->content != ft_is_smallest(first_a))
		{
			if (first_a->count / 2 <= stack_a->index)
				ft_rotate(first_a, 0);
			else
				ft_reverse_rotate(first_a, 0);
		}
	}
	else
	{
		while (first_b->first->content > first_a->first->content
			|| first_b->first->content < first_a->last->content)
		{
			if (first_a->count / 2 <= stack_a->index)
				ft_rotate(first_a, 0);
			else
				ft_reverse_rotate(first_a, 0);
		}
	}
}
