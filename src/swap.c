/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:13:11 by user              #+#    #+#             */
/*   Updated: 2024/09/01 16:14:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int swap(t_stack *stack)
{
    t_list *first;
    t_list *second;

    if (stack == NULL || stack->size <= 1)
        return (-1);

    first = stack->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;

    return (0);
}

int ft_sa(t_stack *stack_a)
{
    if (swap(stack_a) == -1)
        return (-1);
    ft_printf("sa\n");
    return (0);
}

int ft_sb(t_stack *stack_b)
{
    if (swap(stack_b) == -1)
        return (-1);
    ft_printf("sb\n");
    return (0);
}

int ft_ss(t_stack *stack_a, t_stack *stack_b)
{
    if (swap(stack_a) == -1 || swap(stack_b) == -1)
        return (-1);
    ft_printf("ss\n");
    return (0);
}
