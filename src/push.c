/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:14:14 by user              #+#    #+#             */
/*   Updated: 2024/09/01 16:18:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int push(t_stack *stack_dst, t_stack *stack_src)
{
    t_list *first;

    if (stack_src == NULL || stack_src->top == NULL)
        return (-1);

    first = stack_src->top;
    stack_src->top = first->next;
    
    if (stack_dst->top == NULL)
    {
        stack_dst->top = first;
        stack_dst->top->next = NULL;
    }
    else
        ft_lstadd_front(&stack_dst->top, first);

    stack_dst->size++;
    stack_src->size--;

    return (0);
}

int ft_pa(t_stack *stack_a, t_stack *stack_b)
{
    if (push(stack_a, stack_b) == -1)
        return (-1);
    ft_printf("pa\n");
    return (0);
}

int ft_pb(t_stack *stack_a, t_stack *stack_b)
{
    if (push(stack_b, stack_a) == -1)
        return (-1);
    ft_printf("pb\n");
    return (0);
}