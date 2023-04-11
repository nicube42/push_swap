/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:26 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/06 13:51:29 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_two_numbers(t_first *first)
{
	t_list	*stack = first->first;
	if (stack->content > stack->next->content)
	{
		ft_swap(first);
		ft_printf("sa\n");
	}
}

void	ft_three_numbers(t_first *first)
{
	t_list	*stack = first->first;
	if (stack->content < stack->next->content && stack->content
			> stack->next->next->content)
	{
		ft_reverse_rotate(first);
		ft_printf("rra\n");
	}
	else if (stack->content > stack->next->content && stack->next->content > stack->next->next->content)
	{
		ft_swap(first);
		ft_reverse_rotate(first);
		ft_printf("sa\nrra\n");
	}
	else if (stack->content < stack->next->next->content && stack->next->next->content < stack->next->content)
	{
		ft_swap(first);
		ft_rotate(first);
		ft_printf("sa\nra\n");
	}
	else if (stack->content > stack->next->content && stack->content < stack->next->next->content)
	{
		ft_swap(first);
		ft_printf("sa\n");
	}
	else if (stack->content > stack->next->next->content && stack->next->content < stack->next->next->content)
	{
		ft_rotate(first);	
		ft_printf("ra\n");
	}
}

void	ft_five_numbers()
{
	
}