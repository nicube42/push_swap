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

void	ft_two_numbers(t_first *list)
{
	if (list->first > list->first->next)
	{
		ft_swap(list);
		ft_printf("sa\n");
	}
}

/*void	ft_three_numbers(t_list *list)
{
	if (list[0] < stack_a[1] && list[0] > stack_a[2])
		ft_printf("rra\n");
	else if (list[0] > list[1] && list[1] > list[2])
		ft_printf("sa\nrra\n");
	else if (list[0] < list[2] && list[2] < list[1])
		ft_printf("sa\nra\n");
	else if (list[0] > list[1] && list[0] < list[2])
		ft_printf("sa\n");
	else if (list[0] > list[2] && list[1] < list[2])
		ft_printf("ra\n");
}*/

void	ft_five_numbers()
{
	
}