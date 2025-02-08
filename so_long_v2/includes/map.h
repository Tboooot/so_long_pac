#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <stddef.h>

/* Error Messages */
# define ERR_READ "Memory allocation failed"
# define ERR_OPEN "Cannot open file"
# define ERR_MALLOC "Memory allocation failed"
# define ERR_EXTENSION "Invalid file extension"
# define ERR_EMPTY "Empty map"
# define ERR_RECTANGLE "Map is not rectangle"
# define ERR_WALL "Map is not surrounded by walls"
# define ERR_CHARS "Invalid characters in map"
# define ERR_PLAYER "Invalid number of players"
# define ERR_EXIT "Invalid number of exits"
# define ERR_COLLECT "No collectibles found"
# define ERR_PATH "No valid path exists"
# define ERR_NEWLINE "Invalid newline in map"

/* Structures */
typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     p_count;
    int     e_count;
    int     c_count;
    int     player_x;
    int     player_y;
}   t_map;

/* Map Functions */
void    flood_fill(char **grid, int x, int y, t_map *map);
int     check_path(t_map *map);
t_map   *parse_map(char *file);
char    *read_map(int fd);
int     process_map(t_map *map, char *map_str);
int     is_rectangle(t_map *map);
int     check_walls(t_map *map);
int     check_characters(t_map *map);
void    free_map(t_map *map);
void    ft_free_grid(char **grid, int height);
void    free_grid(char **grid, size_t height);
int     copy_grid(t_map *map, char ***temp);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_arrlen(char **arr);
void    print_error(char *msg);

#endif
