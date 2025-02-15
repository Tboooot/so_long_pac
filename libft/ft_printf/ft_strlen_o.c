/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:17:21 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:17:22 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen_o(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
