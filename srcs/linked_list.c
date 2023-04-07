/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:27:21 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/07 15:27:23 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_first	*init()
{
	t_first *first = malloc(sizeof(*first));
	t_list *content = malloc(sizeof(*content));
	if (first == NULL || content == NULL)
		exit(1);
	content->content = 0;
	content->next = NULL;
	first->first = content;
	return (first);
}

void	insertion(t_first *first, int new_nbr)
{
    t_list *new = malloc(sizeof(*new));
    if (first == NULL || new == NULL)
        exit(1);
    new->content = new_nbr;
    new->next = first->first;
    first->first = new;
}

void	destroy(t_first *first)
{
    if (first == NULL)
        exit(1);

    if (first->first != NULL)
    {
        t_list *to_del = first->first;
        first->first = first->first->next;
        free(to_del);
    }
}

void	display_list(t_first *first)
{
    if (first == NULL)
        exit(1);
    t_list *actual = first->first;
    while (actual != NULL)
    {
        ft_printf("%d -> ", actual->content);
        actual = actual->next;
    }
    ft_printf("NULL\n");
}