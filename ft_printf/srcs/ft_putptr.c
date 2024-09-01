/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:54:27 by niarefi           #+#    #+#             */
/*   Updated: 2024/06/06 17:33:32 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr_recursive(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_putptr_recursive(ptr / 16);
	len += ft_putchar("0123456789abcdef"[ptr % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_putptr_recursive(ptr);
	return (len);
}
