/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:26 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/12 17:37:00 by nicolasdiam      ###   ########.fr       */
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

void	ft_4_5_numbers(t_first *first_a, t_first *first_b, int argc)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = first_a->first;
	stack_b = first_b->first;
	if (argc == 6)
		ft_push(first_a, first_b, 1);
	ft_push(first_a, first_b, 1);
	if (argc == 6)
	{
		ft_three_numbers(first_a, 0);
		ft_two_numbers(first_b, 1);
	}
	else
		ft_three_numbers(first_a, 0);
	while (argc >= 5)
	{
		i = 0;
		while (first_a->first->content < first_b->first->content && first_b != NULL)
		{
			ft_rotate(first_a, 0);
			i++;
		}
		ft_push(first_b, first_a, 0);
		if (i < 3)
		{
			while (--i >= 0)
				ft_reverse_rotate(first_a, 0);
		}
		else
		{
			while (++i <= 5)
				ft_rotate(first_a, 0);
		}
		argc--;
	}
}