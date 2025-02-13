/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:05:23 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/06 13:00:41 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*pos;

	pos = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pos = s;
		s++;
	}
	if ((char)c == '\0')
		pos = s;
	return ((char *)pos);
}
