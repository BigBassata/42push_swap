/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:51:13 by user              #+#    #+#             */
/*   Updated: 2024/09/01 02:43:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strjoined(char *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*str;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 2));
	if (!str)
		return (NULL);
	while (i < s1len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	while (i - s1len - 1 < s2len)
	{
		str[i] = s2[i - s1len - 1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_is_valid_input(char *input_str)
{
	int	i;

	i = 0;
	while (input_str[i])
	{
		if (!ft_isdigit(input_str[i]) && input_str[i] != ' ' && input_str[i] != '-' && input_str[i] != '+')
		{
			ft_error_mess_print();
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_split_input_check(char **numbers)
{
	int	i;
	int	j;
	long	atoied_str;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		atoied_str = ft_atoll(numbers[i]);
		if (atoied_str > 2147483647 || atoied_str < -2147483648)
			return (ft_error_mess_print(), 0);
		while (j < i)
		{
			if (ft_atoll(numbers[i]) == ft_atoll(numbers[j]))
				return (ft_error_mess_print(), 0);
			j++;
		}
		i++;
	}
	return (1);
}
