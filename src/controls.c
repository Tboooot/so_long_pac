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
            return (!ft_strchr("1", game->map.grid[game->y - 1][game->x]));
        if (dir == 'S' && game->y < game->map.n_row - 1)
            return (!ft_strchr("1", game->map.grid[game->y + 1][game->x]));
        if (dir == 'W' && game->x > 0)
            return (!ft_strchr("1", game->map.grid[game->y][game->x - 1]));
        if (dir == 'E' && game->x < game->map.n_col - 1)
            return (!ft_strchr("1", game->map.grid[game->y][game->x + 1]));
        return (0);
    }

    // If game is finished, check if player can exit
    if (is_exit(game, dir))
    {
        if (game->total_collect == 0)  // All collectibles collected
        {
            clean_before_exit(game);  // End the game
            return (0);
        }
        else
        {
            // Temporarily disable the exit by changing 'E' to '0'
            if (dir == 'N')
                game->map.grid[game->y - 1][game->x] = '0';
            else if (dir == 'S')
                game->map.grid[game->y + 1][game->x] = '0';
            else if (dir == 'W')
                game->map.grid[game->y][game->x - 1] = '0';
            else if (dir == 'E')
                game->map.grid[game->y][game->x + 1] = '0';
            return (1);  // Allow moving onto the exit
        }
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
    static int prev_exit_y = -1;  // Store the previous exit position
    static int prev_exit_x = -1;

    update_player_coordinates(game);

    // Restore the previous exit if the player moves away
    if (prev_exit_y != -1 && prev_exit_x != -1 &&
        (game->y != prev_exit_y || game->x != prev_exit_x))
    {
        game->map.grid[prev_exit_y][prev_exit_x] = 'E';  // Restore 'E'
        prev_exit_y = -1;
        prev_exit_x = -1;
    }

    if ((key == 'w' || key == UP) && is_valid_move(game, 'N'))
    {
        if (is_exit(game, 'N') && game->total_collect > 0)
        {
            prev_exit_y = game->y - 1;
            prev_exit_x = game->x;
        }
        move_up(game);
    }
    else if ((key == 's' || key == DOWN) && is_valid_move(game, 'S'))
    {
        if (is_exit(game, 'S') && game->total_collect > 0)
        {
            prev_exit_y = game->y + 1;
            prev_exit_x = game->x;
        }
        move_down(game);
    }
    else if ((key == 'a' || key == LEFT) && is_valid_move(game, 'W'))
    {
        if (is_exit(game, 'W') && game->total_collect > 0)
        {
            prev_exit_y = game->y;
            prev_exit_x = game->x - 1;
        }
        move_left(game);
    }
    else if ((key == 'd' || key == RIGHT) && is_valid_move(game, 'E'))
    {
        if (is_exit(game, 'E') && game->total_collect > 0)
        {
            prev_exit_y = game->y;
            prev_exit_x = game->x + 1;
        }
        move_right(game);
    }
}
