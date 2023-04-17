/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:56 by nicolasdiam       #+#    #+#             */
/*   Updated: 2023/04/17 19:49:49 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Test if only digits are entered in command line arguments, if the number 
 * enters in a int and if 2 numbers are the same
*/

int	ft_parsing(int ac, char **av, t_first *first)
{
	size_t	i;
	size_t	j;
	int		ret;

	i = 1;
	while (i < ft_strlen(av[i]))
	{
		if ((ft_atol(av[i]) > MAX_INT) || (ft_atol(av[i]) < MIN_INT))
			return (1);
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][0] != '-')
				return (1);
			j++;
		}
		i++;
	}
	ret = ft_check_if_duplicate(ac, av, first);
	return (ret);
}

/*
 * Test if 2 numbers are the same
*/

int	ft_check_if_duplicate(int ac, char **av, t_first *first)
{
	int	i;
	int	ret;
	int	*stack;

	stack = ft_calloc(ac, sizeof(int));
	if (!stack)
		ft_error();
	i = 1;
	while ((int)i < ac)
	{
		stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret = ft_isduplicate(ac, stack);
	ft_fill_list(ac, av, first);
	return (ret);
}

void	ft_error(void)
{
	ft_printf("error\n");
	exit(1);
}

/*
 * Destroy and free all stack
*/

void	ft_clean_exit(t_first *first_a)
{
	while (first_a)
	{
		ft_destroy_list(first_a);
	}
	exit(0);
}
