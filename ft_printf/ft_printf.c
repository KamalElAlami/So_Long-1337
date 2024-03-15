/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:02:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/14 20:54:55 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	setter(char format, va_list elp)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(elp, int));
	else if (format == 's')
		count += ft_putstr(va_arg(elp, char *));
	else if (format == 'p')
		count += ft_putaddress(va_arg(elp, void *));
	else if (format == 'd')
		count += ft_putnbr(va_arg(elp, int));
	else if (format == 'i')
		count += ft_putnbr(va_arg(elp, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(elp, unsigned int));
	else if (format == 'x')
		count += ft_putexa(va_arg(elp, unsigned int));
	else if (format == 'X')
		count += ft_putexa_upper(va_arg(elp, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	elp;
	int		count;

	count = 0;
	va_start(elp, format);
	if (write(1, 0, 0) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += setter(*format, elp);
			if (*format)
				format++;
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(elp);
	return (count);
}
