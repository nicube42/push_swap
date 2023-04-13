/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/13 21:33:43 by nicolasdiam      ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct		s_first
{
	struct s_list	*first;
	struct s_list	*last;
	struct s_list	*biggest;
	int				count;

}					t_first;

int		main(int argc, char **argv);
int		ft_parsing(int ac, char **av, t_first *list);
void	ft_fill_list(int ac, char **av, t_first *list);

void	ft_two_numbers(t_first *first, int selection);
void	ft_three_numbers(t_first *first, int selection);
void	ft_four_numbers(t_first *first_a, t_first *first_b);
void	ft_five_numbers(t_first *first_a, t_first *first_b);

void	ft_error(void);
int		ft_is_biggest(t_first *first);
int	ft_is_smallest(t_first *first);
void	ft_index(t_first *first);

t_first	*ft_init_list();
void	ft_insert_before_list(t_first *first, int new_nbr);
void	ft_insert_list(t_first *first, int new_nbr);
void	ft_destroy_list(t_first *first);
void	ft_display_list(t_first *first);

void    ft_swap(t_first *list, int selection);
void    ft_reverse_rotate(t_first *first, int selection);
void    ft_rotate(t_first *first, int selection);
void    ft_push(t_first *first, t_first *first_b, int selection);

#endif
