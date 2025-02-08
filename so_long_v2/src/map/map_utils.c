#include "../../includes/map.h"
void ft_free_grid(char **grid, int height)
{
    int i;

    if (!grid)
        return;
    i = 0;
    while (i < height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}
void free_map(t_map *map)
{
    if (!map)
        return;
    if (map->grid)
        ft_free_grid(map->grid, map->height);
    free(map);
}

void print_error(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(msg, 2);
}

int ft_arrlen(char **arr)
{
    int i;

    if (!arr)
        return (0);
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

 char *join_line(char *map_str, char *line)
{
    char *tmp;

    tmp = ft_strjoin(map_str, line);
    free(map_str);
    return (tmp);
}
