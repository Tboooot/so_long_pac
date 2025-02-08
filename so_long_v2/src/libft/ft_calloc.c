/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:10:14 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/04 23:26:46 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
    void			*ptr;
    size_t			total;
    unsigned char	*temp;

    total = count * size;
    if (count != 0 && total / count != size)
        return (NULL);
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    temp = (unsigned char *)ptr;
    while (total--)
        *temp++ = 0;
    return (ptr);
}
