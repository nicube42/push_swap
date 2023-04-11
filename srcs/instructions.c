/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:01:29 by ndiamant          #+#    #+#             */
/*   Updated: 2022/12/20 15:48:36 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void    ft_swap(t_first *first)
{
    int tmp;
    t_list	*stack = first->first;

    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = tmp;
}

void    ft_reverse_rotate(t_first *first)
{
    int		tmp;
    t_list	*stack;
    
    stack = first->first;
    if (stack == NULL || stack->next == NULL)
        return ;
    while (stack != NULL)
    {
        if (stack->next == NULL)
            tmp = stack->content;
        stack = stack->next;
    }
	stack = first->first;
    while (stack != NULL)
    {
		if (stack->next != NULL)
		{
        	stack->next->content = stack->content;
		}
		else
		{
			stack->content = stack->previous->content;
		}
        stack = stack->next;
    }
	stack = first->first;
	stack->content = tmp;
}

void    ft_rotate(t_first *first)
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

/*void    ft_pa_or_pb(int *stack_start, int *stack_dest, int quantity)
{
	ft_rra_or_rrb(stack_dest, quantity);
    stack_dest[0] = stack_start[0];
	ft_ra_or_rb(stack_start, quantity);
}*/
