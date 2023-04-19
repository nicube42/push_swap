/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:33:55 by nicolasdiam       #+#    #+#             */
/*   Updated: 2023/04/19 19:37:36 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_better_isdigit(char **av, int i)
{
	size_t	j;

	j = 0;
	if ((av[i][0] == '-' || av[i][0] == '+') && av[i][1] == '\0')
		return (0);
	if (av[i][0] == '-' || av[i][0] == '+')
		j++;
	while (j < ft_strlen(av[i]))
	{
		if ((av[i][j]) < '0' || av[i][j] > '9')
		{
			return (0);
		}
		j++;
	}
	return (1);
}
