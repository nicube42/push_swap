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

void    ft_swap(t_first *list)
{
    t_list tmp;

    if (list == NULL || list->first->next == NULL)
        return ;
    tmp = *list->first;
    list->first = list->first->next;
    list->first->next = &tmp;
}

/*void    ft_rra_or_rrb(int *stack, int quantity)
{
    int    tmp;

    tmp = stack[quantity - 1];
    while (quantity - 1 > 0)
    {
        stack[quantity - 1] = stack[quantity - 2];
        quantity--;
    }
    stack[0] = tmp;
}

void    ft_ra_or_rb(int *stack, int quantity)
{
    int    tmp;
    int    i;

    i = 1;
    tmp = stack[0];
    while (i < quantity)
    {
        stack[i - 1] = stack[i];
        i++;
    }
    stack[quantity - 1] = tmp;
}

void    ft_pa_or_pb(int *stack_start, int *stack_dest, int quantity)
{
	ft_rra_or_rrb(stack_dest, quantity);
    stack_dest[0] = stack_start[0];
	ft_ra_or_rb(stack_start, quantity);
}*/
