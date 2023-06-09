/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:26 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 16:49:51 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Sort two numbers
*/

void	ft_two_numbers(t_first *first, int selection)
{
	t_list	*stack;

	stack = first->first;
	if (stack->content > stack->next->content)
		ft_swap(first, selection);
}

/*
 * Sort three numbers
*/

void	ft_three_numbers(t_first *first, int selection)
{
	t_list	*stack;

	stack = first->first;
	if (stack->content < stack->next->content && stack->content
		> stack->next->next->content)
		ft_reverse_rotate(first, selection);
	else if (stack->content > stack->next->content && stack->next->content
		> stack->next->next->content)
	{
		ft_swap(first, selection);
		ft_reverse_rotate(first, selection);
	}
	else if (stack->content < stack->next->next->content
		&& stack->next->next->content < stack->next->content)
	{
		ft_swap(first, selection);
		ft_rotate(first, selection);
	}
	else if (stack->content > stack->next->content
		&& stack->content < stack->next->next->content)
		ft_swap(first, selection);
	else if (stack->content > stack->next->next->content
		&& stack->next->content < stack->next->next->content)
		ft_rotate(first, selection);
}

/*
 * Sort four numbers
*/

void	ft_four_numbers(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	ft_prepare_push(first_a, first_b);
	ft_push(first_b, first_a, 0);
	if (first_a->first->content != ft_is_smallest(first_a))
		ft_rotate(first_a, 0);
}

/*
 * Sort five numbers
*/

void	ft_five_numbers(t_first *first_a, t_first *first_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	ft_push(first_a, first_b, 1);
	ft_push(first_a, first_b, 1);
	ft_three_numbers(first_a, 0);
	ft_prepare_push(first_a, first_b);
	ft_push(first_b, first_a, 0);
	ft_prepare_push(first_a, first_b);
	ft_push(first_b, first_a, 0);
	while (first_a->first->content != ft_is_smallest(first_a))
		ft_rotate(first_a, 0);
}

/*
 * Select algo for 2 to 5 numbers sorting
*/

void	ft_select_small(t_first *first_a, t_first *first_b, int argc)
{
	if (argc == 3)
		ft_two_numbers(first_a, 0);
	if (argc == 4)
		ft_three_numbers(first_a, 0);
	if (argc == 5)
		ft_four_numbers(first_a, first_b);
	if (argc == 6)
		ft_five_numbers(first_a, first_b);
}
