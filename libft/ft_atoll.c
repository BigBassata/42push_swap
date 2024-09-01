/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:25:24 by user              #+#    #+#             */
/*   Updated: 2024/09/01 02:43:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	sum;
	long long	sign;
	int			i;

	sign = 1;
	sum = 0;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		sum = sum * 10 + (nptr[i] - 48);
		i++;
	}
	return (sum * sign);
}

// long long   ft_atoll(const char *nptr)
// {
//     long long sum = 0;
//     int sign = 1;
//     int i = 0;

//     while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
//         i++;
//     if (nptr[i] == '-' || nptr[i] == '+')
//     {
//         sign = (nptr[i] == '-') ? -1 : 1;
//         i++;
//     }
//     // Conversion et vérification du dépassement
//     while (nptr[i] >= '0' && nptr[i] <= '9')
//     {
//         // Vérifier le dépassement avant d'ajouter le chiffre suivant
//         if (sign == 1 && (sum > LLONG_MAX / 10 || (sum == LLONG_MAX / 10 && nptr[i] - '0' > LLONG_MAX % 10)))
//             return LLONG_MAX;
//         if (sign == -1 && (sum < LLONG_MIN / 10 || (sum == LLONG_MIN / 10 && nptr[i] - '0' > -(LLONG_MIN % 10))))
//             return LLONG_MIN;

//         sum = sum * 10 + (nptr[i] - '0');
//         i++;
//     }

//     return sum * sign;
// }
