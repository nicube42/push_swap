/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:41 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/05 14:56:44 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Test if only digits are entered in command line arguments, if the number 
enters in a int and if 2 numbers are the same
*/

int	ft_parsing(int ac, char **av, int *pile_a)
{
	size_t	i;
	size_t	j;
	long	max_int;
	long	min_int;
	int		ret;

	i = 1;
	max_int = 2147483647;
	min_int	= -2147483648;
	while (i < ft_strlen(av[i]))
	{
		if ((ft_atol(av[i]) > max_int) || (ft_atol(av[i]) < min_int))
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
	i = 1;
	while ((int)i < ac)
	{
		pile_a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret = ft_isduplicate(ac, pile_a);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		*pile_a;
	int		error;

	t_first *list = init();
	pile_a = ft_calloc(argc, sizeof(int));
	if(!pile_a)
		ft_error();
	error = ft_parsing(argc, argv, pile_a);
	if (error == 1)
		ft_error();
	if (argc == 3)
		ft_two_numbers(pile_a);
	if (argc == 4)
		ft_three_numbers(pile_a);
	insertion(list, 4);
    insertion(list, 8);
    insertion(list, 15);
    destroy(list);
    display_list(list);
	return (0);
}
