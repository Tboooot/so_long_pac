/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:16:06 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:16:08 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sub_func(char **format, va_list args, int *count)
{
	if (**format == '%')
	{
		(*format)++;
		if (**format == 'c')
			*count += ft_putchar(va_arg(args, int));
		if (**format == 's')
			*count += ft_putstr(va_arg(args, char *));
		if (**format == 'i' || **format == 'd')
			*count += ft_putnbr(va_arg(args, int));
		if (**format == 'u')
			*count += ft_putnbr_unsigned(va_arg(args, unsigned int));
		if (**format == 'x')
			*count += ft_putnbr_hexa_lower(va_arg(args, unsigned int));
		if (**format == 'X')
			*count += ft_putnbr_hexa_upper(va_arg(args, unsigned int));
		if (**format == '%')
			*count += ft_putchar('%');
		if (**format == 'p')
			*count += ft_pointer(va_arg(args, void *));
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%' && *(format + 1) == '\0'))
			return (-1);
		if (*format == '%')
			sub_func((char **)&format, args, &count);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
