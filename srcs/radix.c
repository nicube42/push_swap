/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:58:42 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/18 11:39:35 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Stock numbers of shifts needed in first->max_shift
*/

void	ft_find_max_shift(t_first *first)
{
	while (((first->count) >> first->max_shift) != 0)
		first->max_shift++;
	first->size = first->count;
}

/*
 * Apply radix to index in binary to fit a 2 stacks sort
*/

void	ft_radix(t_first *first_a, t_first *first_b, int shift)
{
	int		len;

	if (shift >= first_a->max_shift)
		return ;
	len = 0;
	while (len < first_a->size)
	{
		if (((first_a->first->index >> shift) & 1))
			ft_rotate(first_a, 0);
		else
			ft_push(first_a, first_b, 1);
		len++;
	}
	while (first_b->first)
		ft_push(first_b, first_a, 0);
	ft_radix(first_a, first_b, shift + 1);
}
