/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:41:12 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/05 05:15:33 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif



typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;


int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *nptr);
void				*ft_memset(void *dest, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);



//get_next_line
t_list				*ft_lstnew(char *data);
void				ft_lstclean_up(struct s_list **list,
						struct s_list *new_node, char *new_data);
void				ft_lstadd_back(struct s_list **lst, struct s_list *new);
char				*ft_strdup_o(const char *s);
char				*found_newline(struct s_list *list);
void				add_line_to_list(struct s_list **list, int fd);
char				*construct_line(struct s_list *list);
int					get_line_length(struct s_list *list);
void				next_line(struct s_list **list);
char				*get_next_line(int fd);




// ft_printf
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_hexa_lower(unsigned long n);
int	ft_putnbr_hexa_upper(unsigned long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *str);
int	ft_strlen_o(char *str);
int	ft_pointer(void *ptr);
int	ft_printf(const char *format, ...);


#endif
