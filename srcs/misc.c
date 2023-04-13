/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:04:35 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/13 15:07:04 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Print "error" and exit the program in case of an incorrect entry
*/

void	ft_error(void)
{
	ft_printf("error\n");
	exit(1);
}

int	ft_is_biggest(t_first *first)
{
	t_list	*stack;
	t_list	*tmp;

	stack = first->first;
	tmp = first->first;
	while (stack != NULL)
	{
		if (stack->content > tmp->content)
			tmp = stack;
		stack = stack->next;
	}
	first->biggest = tmp;
	return (tmp->content);
}

void	ft_index(t_first *first)
{
	t_list	*tmp;
	t_list	*tmp_smallest;
	int		i;

	i = 1;
	ft_is_biggest(first);
	while (i <= first->count)
	{
		tmp_smallest = first->biggest;
		tmp = first->first;
		while (tmp != NULL)
		{
			if (tmp->index < 1)
			{
				if (tmp->content < tmp_smallest->content)
					tmp_smallest = tmp;
			}
			tmp = tmp->next;
		}
		tmp_smallest->index = i;
		i++;
	}
}