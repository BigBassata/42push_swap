/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:38 by niarefi           #+#    #+#             */
/*   Updated: 2024/06/06 15:46:56 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
