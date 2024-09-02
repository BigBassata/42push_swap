/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:44:32 by licohen           #+#    #+#             */
/*   Updated: 2024/09/02 18:44:33 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_handlconver(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), *format));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		templen;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			templen = ft_handlconver(++format, args);
			if (templen == -1)
				return (-1);
			len += templen;
			format++;
		}
		else
			len += ft_putchar(*format++);
	}
	va_end(args);
	return (len);
}
