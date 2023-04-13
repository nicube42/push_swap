/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:26 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/13 21:54:05 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_two_numbers(t_first *first, int selection)
{
	t_list	*stack;
	stack = first->first;
	if (stack->content > stack->next->content)
		ft_swap(first, selection);
}

void	ft_three_numbers(t_first *first, int selection)
{
	t_list	*stack;
	
	stack = first->first;
	if (stack->content < stack->next->content && stack->content
			> stack->next->next->content)
		ft_reverse_rotate(first, selection);
	else if (stack->content > stack->next->content && stack->next->content > stack->next->next->content)
	{
		ft_swap(first, selection);
		ft_reverse_rotate(first, selection);
	}
	else if (stack->content < stack->next->next->content && stack->next->next->content < stack->next->content)
	{
		ft_swap(first, selection);
		ft_rotate(first, selection);
	}
	else if (stack->content > stack->next->content && stack->content < stack->next->next->content)
		ft_swap(first, selection);
	else if (stack->content > stack->next->next->content && stack->next->content < stack->next->next->content)
		ft_rotate(first, selection);
}

void	ft_four_numbers(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	ft_push_back(first_a, first_b);
	if (first_a->first->content < first_b->first->content)
		ft_rotate(first_a, 0);
	ft_push(first_b, first_a, 0);
	ft_rotate(first_a, 0);
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

void	ft_five_numbers(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	ft_push(first_a, first_b, 1);
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	ft_push_back(first_a, first_b);
	ft_push(first_b, first_a, 0);
	ft_push_back(first_a, first_b);		
	ft_push(first_b, first_a, 0);

	// a refaire
	/*if (first_a->first->content < first_b->first->content)
		ft_rotate(first_a, 0);
	ft_push(first_b, first_a, 0);
	if (first_a->first->content < first_b->first->content)
		ft_rotate(first_a, 0);
	ft_push(first_b, first_a, 0);
	ft_rotate(first_a, 0);
	ft_rotate(first_a, 0);*/
}