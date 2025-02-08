#include "../../includes/map.h"



static int parse_grid_characters(t_map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            char c = map->grid[y][x];
            if (c == 'P')
            {
                map->p_count++;
                map->player_x = x;
                map->player_y = y;
            }
            else if (c == 'E')
                map->e_count++;
            else if (c == 'C')
                map->c_count++;
            else if (c != '0' && c != '1')
                return (print_error(ERR_CHARS), 0);
        }
    }
    return 1;
}

int check_characters(t_map *map)
{
    if (!parse_grid_characters(map))
        return 0;
    if (map->p_count != 1)
        return (print_error(ERR_PLAYER), 0);
    if (map->e_count != 1)
        return (print_error(ERR_EXIT), 0);
    if (map->c_count < 1)
        return (print_error(ERR_COLLECT), 0);
    if (!check_path(map))
        return (print_error(ERR_PATH), 0);
    return 1;
}
