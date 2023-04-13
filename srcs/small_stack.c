/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:26 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/13 15:07:04 by ndiamant         ###   ########.fr       */
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
	//int		i;

	stack_a = first_a->first;
	stack_b = first_b->first;
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	while (stack_a != NULL)
	{
		if (stack_b->index <= 2)
		{
			while (first_a->last->content != ft_is_biggest(first_a))
				ft_rotate(first_a, 0);
		}
		else
		{
			while (first_a->last->content != ft_is_biggest(first_a))
				ft_reverse_rotate(first_a, 0);
		}
		stack_a = stack_a->next;
	}
}

/*void	ft_4_5_numbers(t_first *first_a, t_first *first_b, int argc)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = first_a->first;
	stack_b = first_b->first;
	if (argc == 6)
		ft_push(first_a, first_b, 1);
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	while (argc >= 5)
	{
		i = 0;
		while (first_a->first->content < first_b->first->content && first_a->first->content != ft_is_biggest(first_a))
		{
			ft_rotate(first_a, 0);
			i++;
		}
		if (first_a->first->content < first_b->first->content)
		{
			ft_rotate(first_a, 0);
			i++;
		}
		ft_push(first_b, first_a, 0);
		argc--;
	}
	while (first_a->last->content != ft_is_biggest(first_a))
	{
		if (i >= 3)
			ft_reverse_rotate(first_a, 0);
		else
			ft_rotate(first_a, 0);
	}
}*/