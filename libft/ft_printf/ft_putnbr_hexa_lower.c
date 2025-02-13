/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:16:51 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:16:52 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_lower(unsigned long n)
{
	int		count;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_putnbr_hexa_lower(n / 16);
	count += ft_putchar(hexa[n % 16]);
	return (count);
}
