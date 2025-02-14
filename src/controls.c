#include "so_long.h"

static int is_exit(t_game *game, char dir)
{
    if (dir == 'N')
        return (game->map.grid[game->y - 1][game->x] == 'E');
    if (dir == 'S')
        return (game->map.grid[game->y + 1][game->x] == 'E');
    if (dir == 'W')
        return (game->map.grid[game->y][game->x - 1] == 'E');
    if (dir == 'E')
        return (game->map.grid[game->y][game->x + 1] == 'E');
    return (0);
}

static void update_player_coordinates(t_game *game)
{
    int i;
    int j;
    
    i = -1;
    while (++i < game->map.n_row)
    {
        j = -1;
        while (++j < game->map.n_col)
        {
            if (game->map.grid[i][j] == 'P')
            {
                game->y = i;
                game->x = j;
                return;
            }
        }
    }
}

static int is_valid_move(t_game *game, char dir)
{
    // First check if game is not in end state
    if (!game->end)
    {
        // Check for walls and exit when game is not finished
        if (dir == 'N' && game->y > 0)
            return (!ft_strchr("1E", game->map.grid[game->y - 1][game->x]));
        if (dir == 'S' && game->y < game->map.n_row - 1)
            return (!ft_strchr("1E", game->map.grid[game->y + 1][game->x]));
        if (dir == 'W' && game->x > 0)
            return (!ft_strchr("1E", game->map.grid[game->y][game->x - 1]));
        if (dir == 'E' && game->x < game->map.n_col - 1)
            return (!ft_strchr("1E", game->map.grid[game->y][game->x + 1]));
        return (0);
    }

    // If game is finished, check if player can exit
    if (is_exit(game, dir))
    {
        clean_before_exit(game);
        return (0);
    }

    // Only check for walls when game is finished
    if (dir == 'N' && game->y > 0)
        return (!ft_strchr("1", game->map.grid[game->y - 1][game->x]));
    if (dir == 'S' && game->y < game->map.n_row - 1)
        return (!ft_strchr("1", game->map.grid[game->y + 1][game->x]));
    if (dir == 'W' && game->x > 0)
        return (!ft_strchr("1", game->map.grid[game->y][game->x - 1]));
    if (dir == 'E' && game->x < game->map.n_col - 1)
        return (!ft_strchr("1", game->map.grid[game->y][game->x + 1]));
    return (0);
}

void move_player(int key, t_game *game)
{
    update_player_coordinates(game);

    if ((key == 'w' || key == UP) && is_valid_move(game, 'N'))
        move_up(game);
    else if ((key == 's' || key == DOWN) && is_valid_move(game, 'S'))
        move_down(game);
    else if ((key == 'a' || key == LEFT) && is_valid_move(game, 'W'))
        move_left(game);
    else if ((key == 'd' || key == RIGHT) && is_valid_move(game, 'E'))
        move_right(game);
}