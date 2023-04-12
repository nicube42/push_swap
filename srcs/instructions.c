/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:54 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/12 10:49:08 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_first *first)
{
	int		tmp;
	t_list	*stack = first->first;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	ft_reverse_rotate(t_first *first)
{
	int		tmp;
	t_list	*stack;

	stack = first->last;
	if (stack == NULL || stack->previous == NULL)
		return ;
	tmp = first->last->content;
	while (stack != NULL && stack->previous)
	{
		stack->content = stack->previous->content;
		stack = stack->previous;
	}
	stack = first->first;
	stack->content = tmp;
}

void	ft_rotate(t_first *first)
{
	int		tmp;
	t_list	*stack;

	stack = first->first;
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	while (stack != NULL)
	{
		if (stack->next == NULL)
				stack->content = tmp;
		else
			stack->content = stack->next->content;
		stack = stack->next;
	}
	}

void	ft_push(t_first *first, t_first *first_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	ft_insert_before_list(first_b, 10);
	a = first->first;
	b = first_b->first;
	tmp = first->first;
	ft_insert_before_list(first_b, first->first->content);
	ft_destroy_list(first);
}
