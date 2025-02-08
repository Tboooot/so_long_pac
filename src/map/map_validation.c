#include "../../includes/map.h"

 void flood_fill(char **grid, int x, int y, t_map *map)
{
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return;
    if (grid[y][x] == '1' || grid[y][x] == 'F')
        return;
    if (grid[y][x] == 'C')
        map->c_count--;
    if (grid[y][x] == 'E')
        map->e_count--;
    grid[y][x] = 'F';

    flood_fill(grid, x + 1, y, map);  // right
    flood_fill(grid, x - 1, y, map);  // left
    flood_fill(grid, x, y + 1, map);  // down
    flood_fill(grid, x, y - 1, map);  // up
}

int copy_grid(t_map *map, char ***temp)
{
    int i;

    i = 0;
    *temp = malloc(sizeof(char *) * (map->height + 1));
    if (!*temp)
        return (print_error(ERR_MALLOC), 0);
    while (i < map->height)
    {
        (*temp)[i] = ft_strdup(map->grid[i]);
        if (!(*temp)[i])
        {
            while (--i >= 0)
                free((*temp)[i]);
            free(*temp);
            return (print_error(ERR_MALLOC), 0);
        }
        i++;
    }
    (*temp)[i] = NULL;
    return (1);
}

 int check_path(t_map *map)
{
    char    **temp;
    int     original_c;
    int     original_e;
    int     result;

    original_c = map->c_count;
    original_e = map->e_count;
    if (!copy_grid(map, &temp))
        return (0);
    flood_fill(temp, map->player_x, map->player_y, map);
    result = (map->c_count == 0 && map->e_count == 0);
    map->c_count = original_c;
    map->e_count = original_e;
    ft_free_grid(temp, map->height);
    return (result);
}

int is_rectangle(t_map *map)
{
    size_t width = ft_strlen(map->grid[0]);
    int i = 1;

    while (i < map->height)
    {
        if (ft_strlen(map->grid[i]) != width)
            return (print_error(ERR_RECTANGLE), 0);
        i++;
    }
    map->width = width;
    return 1;
}

int check_walls(t_map *map)
{
    int i = 0;

    while (i < map->width)
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
            return (print_error(ERR_WALL), 0);
        i++;
    }
    i = 0;
    while (i < map->height)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
            return (print_error(ERR_WALL), 0);
        i++;
    }
    return 1;
}
