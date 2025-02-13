/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:37:11 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/06 20:37:22 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			indx;
	unsigned char	*buffer;

	c = (unsigned char)c;
	buffer = (unsigned char *)dest;
	indx = 0;
	while (indx < n)
	{
		buffer[indx] = c;
		indx++;
	}
	return (dest);
}
