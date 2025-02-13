/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:31:33 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/06 17:13:57 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*two;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	two = *lst;
	while (two->next)
		two = two->next;
	two->next = new;
}
