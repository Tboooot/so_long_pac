
/* get_next_line.h */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

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

t_list	*ft_lstnew(char *data);
void	ft_lstclean_up(t_list **list, t_list *new_node, char *new_data);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*found_newline(t_list *list);
void	add_line_to_list(t_list **list, int fd);
char	*construct_line(t_list *list);
int		get_line_length(t_list *list);
void	next_line(t_list **list);
char	*get_next_line(int fd);

#endif
