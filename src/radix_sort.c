/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:30:07 by user              #+#    #+#             */
/*   Updated: 2024/09/01 23:07:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	ft_get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
int	*ft_stack_to_array(t_stack *stack)
{
	int		*array;
	int		i;
	t_list	*current;

	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i] = *(int *)(current->content);
		current = current->next;
		i++;
	}
	return (array);
}

void	ft_normalize_stack(t_stack *a)
{
	t_list	*current;
	int		*array;
	int		i;

	array = ft_stack_to_array(a);
	ft_sort_array(array, a->size);
	current = a->top;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (*(int *)(current->content) == array[i])
			{
				*(int *)(current->content) = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(array);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		num;
	int		max_bits;
	int		size;

	ft_normalize_stack(a);
	max_bits = ft_get_max_bits(a->size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a->size;
		while (j < size)
		{
			num = *(int *)(a->top->content);
			if (((num >> i) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			j++;
		}
		while (b->size > 0)
			ft_pa(a, b);
		i++;
	}
}