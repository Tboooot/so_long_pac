#include "so_long.h"

static char **create_map_copy(char **original, int rows)
{
    char **copy;
    int i;

    copy = (char **)malloc(sizeof(char *) * (rows + 1));
    if (!copy)
        return (NULL);
    copy[rows] = NULL;

    i = 0;
    while (i < rows)
    {
        copy[i] = ft_strdup(original[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    return (copy);
}

static void flood_fill(char **map, int x, int y, int *collectibles)
{
    // Check boundaries and walls
    if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1' || map[y][x] == 'V')
        return;

    // Mark collectible as reachable
    if (map[y][x] == 'C')
        (*collectibles)++;

    // Mark current position as visited
    map[y][x] = 'V';

    // Recursively fill in all directions
    flood_fill(map, x + 1, y, collectibles);  // right
    flood_fill(map, x - 1, y, collectibles);  // left
    flood_fill(map, x, y + 1, collectibles);  // down
    flood_fill(map, x, y - 1, collectibles);  // up
}

static void find_player_pos(char **map, int *px, int *py)
{
    int y;
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                *px = x;
                *py = y;
                return;
            }
            x++;
        }
        y++;
    }
}

static int can_reach_exit(char **map)
{
    int y;
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'E')
            {
                // Check if any adjacent cell is visited ('V')
                if ((y > 0 && map[y-1][x] == 'V') ||           // up
                    (y < map[y][x] && map[y+1][x] == 'V') ||   // down
                    (x > 0 && map[y][x-1] == 'V') ||           // left
                    map[y][x+1] == 'V')                        // right
                    return (1);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int validate_flood(t_map *map)
{
    char **map_copy;
    int player_x;
    int player_y;
    int collectibles;
    int result;

    // Create a copy of the map for flood fill
    map_copy = create_map_copy(map->grid, map->n_row);
    if (!map_copy)
    {
        ft_printf("Error\nMemory allocation failed\n");
        return (0);
    }

    // Find player position
    find_player_pos(map_copy, &player_x, &player_y);

    // Count reachable collectibles
    collectibles = 0;
    flood_fill(map_copy, player_x, player_y, &collectibles);

    // Check if all collectibles are reachable and exit is accessible
    result = (collectibles == map->c && can_reach_exit(map_copy));

    // Free the map copy
    int i = 0;
    while (map_copy[i])
        free(map_copy[i++]);
    free(map_copy);

    if (!result)
        ft_printf("Error\nInvalid path: Cannot reach all collectibles or exit\n");

    return (result);
}