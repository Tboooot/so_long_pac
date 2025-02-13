/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:31:55 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/06 17:01:51 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;
	size_t				i;

	d = (unsigned char *)dst;
	i = 0;
	if (s < d)
	{
		s += len;
		d += len;
		while (len--)
			*--d = *--s;
	}
	else
	{
		while (i < len)
		{
			*d++ = *s++;
			i++;
		}
	}
	return (dst);
}
