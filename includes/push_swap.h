/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:04:31 by user              #+#    #+#             */
/*   Updated: 2024/09/02 16:05:57 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

//Parsing
char	*ft_strjoined(char *s1, char const *s2);
int	    ft_is_valid_input(char *input_str);
int     ft_split_input_check(char **numbers);

//Utils
int	    ft_count_number(char **numbers);
void	ft_error_mess_print(void);
void	ft_free_chainedlst(t_list **lst);
void	ft_free_lst(t_list *lst);
t_list	*ft_before_last_lst(t_list *lst);
int		ft_stack_a_sort_check(t_stack *stack_a);


//Operations
int	ft_sa(t_stack *stack_a);
int	ft_sb(t_stack *stack_b);
int	ft_ss(t_stack *stack_a, t_stack *stack_b);
int 	ft_pa(t_stack *stack_a, t_stack *stack_b);
int 	ft_pb(t_stack *stack_a, t_stack *stack_b);
int 	ft_ra(t_stack *stack_a);
int 	ft_rb(t_stack *stack_b);
int 	ft_rr(t_stack *stack_a, t_stack *stack_b);
int 	ft_rra(t_stack *stack_a);
int 	ft_rrb(t_stack *stack_b);
int 	ft_rrr(t_stack *stack_a, t_stack *stack_b);

//sort
void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_three(t_stack *stack_a);
void	ft_move_min_to_b(t_stack *stack_a, t_stack *stack_b, int min_pos);
int		ft_find_min_position(t_stack *stack_a);

//radix
void	ft_radix_sort(t_stack *a, t_stack *b);
void	ft_normalize_stack(t_stack *a);
int		*ft_stack_to_array(t_stack *stack);
void	ft_sort_array(int *array, int size);
int		ft_get_max_bits(int max_num);


int	ft_push_swap(char **splitted_inpstr, int size);
t_list	*ft_create_chainedlst(char **splitted_inpstr, int size);


#endif