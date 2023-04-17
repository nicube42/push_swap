/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasdiamantis <nicolasdiamantis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/17 19:37:09 by nicolasdiam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include "../libft_printf/includes/libft.h"
# include "../libft_printf/includes/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_first
{
	struct s_list	*first;
	struct s_list	*last;
	struct s_list	*biggest;
	int				count;
	int				size;
	int				max_shift;
}					t_first;

typedef struct s_glob
{
	int				content;
	int				count;
}				t_glob;

int		main(int argc, char **argv);
void	ft_fill_list(int ac, char **av, t_first *list);
void	ft_check_if_sorted(t_first *first);

void	ft_two_numbers(t_first *first, int selection);
void	ft_three_numbers(t_first *first, int selection);
void	ft_four_numbers(t_first *first_a, t_first *first_b);
void	ft_five_numbers(t_first *first_a, t_first *first_b);
void	ft_select_small(t_first *first_a, t_first *first_b, int argc);

int		ft_is_biggest(t_first *first);
int		ft_is_smallest(t_first *first);
void	ft_index(t_first *first);
void	ft_prepare_push(t_first *first, t_first *first_b);
void	ft_prepare_push_2(t_first *first_a, t_first *first_b, t_list *stack_a);

t_first	*ft_init_list(void);
void	ft_insert_before_list(t_first *first, int new_nbr);
void	ft_insert_list(t_first *first, int new_nbr);
void	ft_destroy_list(t_first *first);
void	ft_display_list(t_first *first);

void	ft_swap(t_first *list, int selection);
void	ft_reverse_rotate(t_first *first, int selection);
void	ft_rotate(t_first *first, int selection);
void	ft_rotate_2(t_list *stack, int tmp, int tmp2);
void	ft_push(t_first *first, t_first *first_b, int selection);

void	ft_find_max_shift(t_first *first);
void	ft_radix(t_first *first_a, t_first *first_b, int shift);

int		ft_parsing(int ac, char **av, t_first *list);
int		ft_check_if_duplicate(int ac, char **av, t_first *first);
void	ft_error(void);
void	ft_clean_exit(t_first *first_a);

#endif
