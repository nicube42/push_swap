/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:58:42 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/14 15:16:11 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_max_shift(t_first *first)
{
	t_list	*stack;

	stack = first->first;
	while ((first->count >> first->max_shift) != 0)
	{
		first->max_shift++;
	}
}

void	ft_radix(t_first *first_a, t_first *first_b, int shift)
{
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = first_a->first;
	stack_b = first_b->first;
	if (shift >= first_a->max_shift)
		return ;
	len = 0;
	while (len < first_a->count)
	{
		//ft_test_index(first_a);
		if ((stack_a->index >> shift) & 1)
		{
			ft_printf("%d", stack_a->index);
			ft_rotate(first_a, 0);
		}
		else
			ft_push(first_a, first_b, 1);
		len ++;
	}
	while (first_b->first)
	{
		ft_push(first_b, first_a, 0);
	}
	ft_radix(first_a, first_b, shift + 1);
}