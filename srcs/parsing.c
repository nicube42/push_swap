/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:56 by nicolasdiam       #+#    #+#             */
/*   Updated: 2023/04/19 09:40:08 by ndiamant         ###   ########.fr       */
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
		ft_error(first);
	i = 1;
	while ((int)i < ac)
	{
		stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret = ft_isduplicate(ac, stack);
	ft_fill_list(ac, av, first);
	if (stack)
		free(stack);
	return (ret);
}

void	ft_error(t_first *first)
{
	ft_printf("error\n");
	if (first)
		ft_free_stack(first);
	exit(1);
}

/*
 * Destroy and free all stack
*/

void	ft_clean_exit(t_first *first_a)
{
	ft_free_stack(first_a);
	exit(0);
}

int	ft_one_arg(int ac, char **av, t_first *first)
{
	char	**tmp;
	int		error;
	int		i;

	if (ac == 2)
	{
		i = 0;
		av[0] = ft_strjoin(av[0], " ");
		av[1] = ft_strjoin(av[0], av[1]);
		free(av[0]);
		tmp = ft_split(av[1], ' ');
		while (tmp[i])
			i++;
		error = ft_parsing(i, tmp, first);
		i = 0;
		while (tmp[++i])
			free(tmp[i]);
		free (tmp);
		ft_error_parsing(error, first);
		return (i);
	}
	error = ft_parsing(ac, av, first);
	ft_error_parsing(error, first);
	return (ac);
}
