#include "../../includes/map.h"



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
