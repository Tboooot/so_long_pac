#include "so_long.h"

static char **create_map_copy(char **original, int rows, int cols)
{
    char    **copy;
    int     i;

    copy = (char **)malloc(sizeof(char *) * (rows + 1));
    if (!copy)
        return (NULL);
    copy[rows] = NULL;

    i = 0;
    while (i < rows)
    {
        copy[i] = (char *)malloc(sizeof(char) * (cols + 1));
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        ft_memcpy(copy[i], original[i], cols);
        copy[i][cols] = '\0';
        i++;
    }
    return (copy);
}

static void flood_fill(char **map, int row, int col, t_point *count)
{
    // Base cases: out of bounds or hit a wall or already visited
    if (row < 0 || col < 0 || !map[row] || !map[row][col] || 
        map[row][col] == '1' || map[row][col] == 'x')
        return;

    // Count collectibles and exit if found
    if (map[row][col] == 'C')
        count->c++;
    else if (map[row][col] == 'E')
        count->e = 1;

    // Mark as visited
    map[row][col] = 'x';

    // Recursively check all directions
    flood_fill(map, row - 1, col, count);    // Up
    flood_fill(map, row + 1, col, count);    // Down
    flood_fill(map, row, col - 1, count);    // Left
    flood_fill(map, row, col + 1, count);    // Right
}

static void find_player(char **map, t_point *player)
{
    int row;
    int col;

    row = 0;
    player->x = -1;
    player->y = -1;
    while (map[row])
    {
        col = 0;
        while (map[row][col])
        {
            if (map[row][col] == 'P')
            {
                player->y = row;
                player->x = col;
                return;
            }
            col++;
        }
        row++;
    }
}

int validate_flood(t_map *map)
{
    char    **temp_map;
    t_point player;
    t_point count;
    int     valid;

    // Create a copy of the map
    temp_map = create_map_copy(map->grid, map->n_row, map->n_col);
    if (!temp_map)
        return (0);

    // Find player position
    find_player(temp_map, &player);
    if (player.x == -1 || player.y == -1)
    {
        ft_free_grid(temp_map);
        return (0);
    }

    // Initialize counters
    count.c = 0;  // collectibles counter
    count.e = 0;  // exit found flag

    // Perform flood fill
    flood_fill(temp_map, player.y, player.x, &count);

    // Check if all collectibles are reachable and exit is accessible
    valid = (count.c == map->c && count.e == 1);

    // Free temporary map
    ft_free_grid(temp_map);

    if (!valid)
        ft_printf("Error\nInvalid path: Cannot reach all collectibles or exit\n");

    return (valid);
}
