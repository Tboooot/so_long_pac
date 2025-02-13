/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:16:15 by mtarza            #+#    #+#             */
/*   Updated: 2024/12/19 07:16:17 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_hexa_lower(unsigned long n);
int	ft_putnbr_hexa_upper(unsigned long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_pointer(void *ptr);
int	ft_printf(const char *format, ...);

#endif
