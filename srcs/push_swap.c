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
Print "error" and exit the program in case of an incorrect entry
*/

void	ft_error(int error)
{
	ft_printf("error\n");
	exit(1);
}

/*
Test if only digits are entered in command line arguments, if the number 
enters in a int and if 2 numbers are the same
*/

int	ft_parsing(int ac, char **av)
{
	int		i;
	int		j;
	long	max_int;
	long	min_int;
	int		ret;
	int		*pile_a;

	pile_a = ft_calloc(ac, sizeof(int));
	if(!pile_a)
		ft_error(1);
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
	while (i < ac)
	{
		pile_a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret = ft_isduplicate(ac, pile_a);
	return (ret);
}

int	main(int argc, char **argv)
{
	int error;

	error = ft_parsing(argc, argv);
	if (error == 1)
	{
		ft_error(error);
	}

}
