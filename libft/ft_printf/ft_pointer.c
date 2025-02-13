/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:15:56 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:15:59 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	count += ft_putnbr_hexa_lower(address);
	return (count + 2);
}
