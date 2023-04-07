/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/05 11:31:40 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft_printf/includes/libft.h"
# include "../libft_printf/includes/ft_printf.h"

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct		s_first
{
	struct s_list	*first;
}					t_first;

int		main(int argc, char **argv);
int		ft_parsing(int ac, char **av, int *stack_a);

void	ft_error(void);

void	ft_two_numbers(int *stack_a);
void	ft_three_numbers(int *stack_a);

t_first *init();
void	insertion(t_first *first, int new_nbr);
void	destroy(t_first *first);
void	display_list(t_first *first);

#endif
