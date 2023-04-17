/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:54 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 10:25:44 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_first *first, int	selection)
{
	int		tmp;
	t_list	*stack = first->first;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	if (selection == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_reverse_rotate(t_first *first, int selection)
{
	int		tmp;
	int		tmp2;
	t_list	*stack;

	stack = first->last;
	if (stack == NULL || stack->previous == NULL)
		return ;
	tmp = first->last->content;
	tmp2 = first->last->index;
	while (stack != NULL && stack->previous)
	{
		stack->content = stack->previous->content;
		stack->index = stack->previous->index;
		stack = stack->previous;
	}
	stack = first->first;
	stack->content = tmp;
	stack->index = tmp2;
	if (selection == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	ft_rotate(t_first *first, int selection)
{
	int		tmp;
	int		tmp2;
	t_list	*stack;

	stack = first->first;
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	tmp2 = stack->index;
	while (stack != NULL)
	{
		if (stack->next == NULL)
		{
			stack->content = tmp;
			stack->index = tmp2;
		}
		else
		{
			stack->content = stack->next->content;
			stack->index = stack->next->index;
		}
		stack = stack->next;
	}
	if (selection == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	ft_push(t_first *first, t_first *first_b, int selection)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = first->first;
	b = first_b->first;
	tmp = first->first;
	ft_insert_before_list(first_b, first->first->content);
	first_b->first->index = first->first->index;
	ft_destroy_list(first);
	if (selection == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}