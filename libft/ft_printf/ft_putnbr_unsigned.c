/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:17:05 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:17:07 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	n = n % 10 + '0';
	count++;
	write(1, &n, 1);
	return (count);
}
