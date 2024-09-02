/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:27:17 by user              #+#    #+#             */
/*   Updated: 2024/09/02 18:45:12 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_min_position(t_stack *stack_a)
{
	t_list	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	current = stack_a->top;
	min_value = *(int *)current->content;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (*(int *)(current->content) < min_value)
		{
			min_value = *(int *)(current->content);
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	ft_move_min_to_b(t_stack *stack_a, t_stack *stack_b, int min_pos)
{
	if (min_pos == 0)
		ft_pb(stack_a, stack_b);
	else if (min_pos <= stack_a->size / 2)
	{
		while (min_pos > 0)
		{
			ft_ra(stack_a);
			min_pos--;
		}
		ft_pb(stack_a, stack_b);
	}
	else
	{
		while (min_pos < stack_a->size)
		{
			ft_rra(stack_a);
			min_pos++;
		}
		ft_pb(stack_a, stack_b);
	}
}

static void	ft_apply_sort_action(t_stack *stack_a, int firstv, int secondv,
		int thirdv)
{
	if (firstv > secondv && firstv < thirdv)
		ft_sa(stack_a);
	else if (firstv > secondv && secondv > thirdv)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (firstv > secondv && firstv > thirdv)
		ft_ra(stack_a);
	else if (firstv < secondv && firstv > thirdv)
		ft_rra(stack_a);
	else if (firstv < secondv && secondv > thirdv)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

void	ft_sort_three(t_stack *stack_a)
{
	int	firstv;
	int	secondv;
	int	thirdv;

	if (stack_a->size < 3 || !stack_a || !stack_a->top || !stack_a->top->next
		|| !stack_a->top->next->next)
		return ;
	firstv = *(int *)(stack_a->top->content);
	secondv = *(int *)(stack_a->top->next->content);
	thirdv = *(int *)stack_a->top->next->next->content;
	ft_apply_sort_action(stack_a, firstv, secondv, thirdv);
}

void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	if (stack_a->size == 2)
		ft_sa(stack_a);
	while (stack_a->size > 3)
	{
		min_pos = ft_find_min_position(stack_a);
		ft_move_min_to_b(stack_a, stack_b, min_pos);
	}
	ft_sort_three(stack_a);
	while (stack_b->size > 0)
		ft_pa(stack_a, stack_b);
}
