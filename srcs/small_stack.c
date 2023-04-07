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

void	ft_two_numbers(int *stack_a)
{
	if (stack_a[0] > stack_a[1])
		ft_printf("sa\n");
}

void	ft_three_numbers(int *stack_a)
{
	if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		ft_printf("rra\n");
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
		ft_printf("sa\nrra\n");
	else if (stack_a[0] < stack_a[2] && stack_a[2] < stack_a[1])
		ft_printf("sa\nra\n");
	else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		ft_printf("sa\n");
	else if (stack_a[0] > stack_a[2] && stack_a[1] < stack_a[2])
		ft_printf("ra\n");
}

void	ft_five_numbers()
{
	
}