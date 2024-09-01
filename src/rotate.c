/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:13:40 by user              #+#    #+#             */
/*   Updated: 2024/09/01 16:16:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int rotate(t_stack *stack)
{
    t_list *first;

    if (stack == NULL || stack->size <= 1)
        return (-1);

    first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    ft_lstadd_back(&stack->top, first);

    return (0);
}

int ft_ra(t_stack *stack_a)
{
    if (rotate(stack_a) == -1)
        return (-1);
    ft_printf("ra\n");
    return (0);
}

int ft_rb(t_stack *stack_b)
{
    if (rotate(stack_b) == -1)
        return (-1);
    ft_printf("rb\n");
    return (0);
}

int ft_rr(t_stack *stack_a, t_stack *stack_b)
{
    if (rotate(stack_a) == -1 || rotate(stack_b) == -1)
        return (-1);
    ft_printf("rr\n");
    return (0);
}
