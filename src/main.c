/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:10:28 by user              #+#    #+#             */
/*   Updated: 2024/09/02 16:04:02 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_number(char **numbers)
{ 
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}

static int process_input(int argc, char **argv, char **input_str)
{
    int i;
    char *temp;

    *input_str = ft_strdup(argv[1]);
    if (!*input_str)
        return (-1);
    i = 2;
    while (i < argc)
    {
        temp = ft_strjoined(*input_str, argv[i]);
        if (!temp)
        {
            free(*input_str);
            return (-1);
        }
        *input_str = temp;
        i++;
    }
    return (0);
}

static int validate_and_split(char *input_str, char ***numbers)
{
    if (!ft_is_valid_input(input_str))
    {
        free(input_str);
        return (-1);
    }
    *numbers = ft_split(input_str, ' ');
    free(input_str);
    if (!*numbers)
        return (-1);
    if (!ft_split_input_check(*numbers))
    {
        ft_free_split(*numbers);
        return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    char *input_str;
    char **numbers;
    int size;

    if (argc < 2)
        return (-1);
    if (process_input(argc, argv, &input_str) == -1)
        return (-1);
    if (validate_and_split(input_str, &numbers) == -1)
        return (-1);
    size = ft_count_number(numbers);
    ft_push_swap(numbers, size);
    ft_free_split(numbers);
    return (0);
}
