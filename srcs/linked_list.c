/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:27:21 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/12 16:51:02 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_first	*ft_init_list()
{
	t_first *first = malloc(sizeof(*first));
    t_first *previous = malloc(sizeof(*previous));
	t_list *content = malloc(sizeof(*content));
	if (first == NULL || content == NULL || previous == NULL)
		exit(1);
	content->content = 0;
	content->next = NULL;
    content->previous = NULL;
	first->first = NULL;
    first->last = NULL;
	return (first);
}

void	ft_insert_before_list(t_first *first, int new_nbr)
{
    t_list *new = malloc(sizeof(*new));
    if (first == NULL || new == NULL)
        exit(1);
    new->content = new_nbr;
    new->next = first->first;
    new->previous = NULL;
    first->first = new;
    if (new->next)
        new->next->previous = new;
    if (first->last == NULL)
        first->last = new;
}

void	ft_insert_list(t_first *first, int new_nbr)
{
	t_list *new = malloc(sizeof(*new));
	new->previous = first->last;
	new->next = NULL;
	new->content = new_nbr;
	if (first->first == NULL)
		first->first = new;
	if (first->last != NULL)
		first->last->next = new;
	first->last = new;
}


void	ft_destroy_list(t_first *first)
{
    t_list  *to_del;

    to_del = first->first;
    if (to_del == first->first)
    {
        if(to_del->next != NULL)
            to_del->next->previous = NULL;
			
        first->first = to_del->next;
	}
    else
        to_del->previous->next = to_del->next;

    if (to_del == first->last)
    {
        first->last = to_del->previous;

        if (to_del->previous != NULL)
            to_del->previous->next = NULL;
    }
    else
        to_del->next->previous = to_del->previous;

    free(to_del);
}

void	ft_display_list(t_first *first)
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