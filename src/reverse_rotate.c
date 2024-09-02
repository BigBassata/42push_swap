/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:14:39 by user              #+#    #+#             */
/*   Updated: 2024/09/02 16:04:16 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int reverse_rotate(t_stack *stack)
{
    t_list *last;
    t_list *before_last;

    if (stack == NULL || stack->size <= 1)
        return (-1);

    last = ft_lstlast(stack->top);
    before_last = ft_before_last_lst(stack->top);
    last->next = stack->top;
    stack->top = last;
    before_last->next = NULL;

    return (0);
}

int ft_rra(t_stack *stack_a)
{
    if (reverse_rotate(stack_a) == -1)
        return (-1);
    ft_printf("rra\n");
    return (0);
}

int ft_rrb(t_stack *stack_b)
{
    if (reverse_rotate(stack_b) == -1)
        return (-1);
    ft_printf("rrb\n");
    return (0);
}

int ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (reverse_rotate(stack_a) == -1 || reverse_rotate(stack_b) == -1)
        return (-1);
    ft_printf("rrr\n");
    return (0);
}
