/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:46:30 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/04 05:54:50 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	if (src_len + 1 < size)
		len = src_len;
	else
		len = size - 1;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = 0;
	return (src_len);
}
