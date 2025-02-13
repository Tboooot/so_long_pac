/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:16:11 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/06 16:56:10 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
	return (res);
}
