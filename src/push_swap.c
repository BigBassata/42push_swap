/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:49:44 by user              #+#    #+#             */
/*   Updated: 2024/09/01 17:51:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list *create_new_node(char *str)
{
    int *value;
    t_list *newlst;

    value = (int *)malloc(sizeof(int));
    if (!value)
        return (NULL);
    *value = ft_atoi(str);
    newlst = ft_lstnew(value);
    if (!newlst)
    {
        free(value);
        return (NULL);
    }
    return (newlst);
}

t_list *ft_create_chainedlst(char **splitted_inpstr, int size)
{
    t_list *beginlst;
    t_list *newlst;
    int i;

    beginlst = NULL;
    i = 0;
    while (splitted_inpstr[i] && i < size)
    {
        newlst = create_new_node(splitted_inpstr[i]);
        if (!newlst)
        {
            ft_free_chainedlst(&beginlst);
            return (NULL);
        }
        ft_lstadd_back(&beginlst, newlst);
        i++;
    }
    return (beginlst);
}

static int initialize_stacks(t_stack **stack_a, t_stack **stack_b, 
                             char **splitted_inpstr, int size)
{
    *stack_a = (t_stack *)malloc(sizeof(t_stack));
    if (!*stack_a)
        return (0);
    *stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (!*stack_b)
    {
        free(*stack_a);
        return (0);
    }
    (*stack_a)->top = ft_create_chainedlst(splitted_inpstr, size);
    (*stack_a)->size = size;
    (*stack_b)->top = NULL;
    (*stack_b)->size = 0;
    return (1);
}

static int process_sorting(t_stack *stack_a, t_stack *stack_b)
{
    int result = 0;

    if (ft_stack_a_sort_check(stack_a))
        result = 1;
    else if (stack_a->size <= 5)
        ft_insertion_sort(stack_a, stack_b);
    else
        ft_radix_sort(stack_a, stack_b);
    if (!ft_stack_a_sort_check(stack_a))
    {
        ft_printf("not sorted!\n");
        result = 0;
    }
    else
    {
        ft_printf("sorted!\n");
        result = 1;
    }
    return (result);
}

int ft_push_swap(char **splitted_inpstr, int size)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int result;

    if (!initialize_stacks(&stack_a, &stack_b, splitted_inpstr, size))
        return (0);
    
    result = process_sorting(stack_a, stack_b);
    
    ft_free_chainedlst(&(stack_a->top));
    ft_free_chainedlst(&(stack_b->top));
    free(stack_a);
    free(stack_b);
    
    return (result);
}
