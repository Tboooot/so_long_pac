#include "../../includes/so_long.h"

void move_player(t_game *game, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= game->map->width || 
        new_y < 0 || new_y >= game->map->height || 
        game->map->grid[new_y][new_x] == '1')
        return;

    game->moves++;
    ft_putstr_fd("Moves: ", 1);
    ft_putnbr_fd(game->moves, 1);
    ft_putchar_fd('\n', 1);

    if (game->map->grid[new_y][new_x] == 'C')
    {
        game->collected++;
        game->map->grid[new_y][new_x] = '0';
    }
    else if (game->map->grid[new_y][new_x] == 'E')
    {
        if (game->collected == game->map->c_count)
        {
            ft_putendl_fd("You won!", 1);
            close_game(game);
        }
        return;
    }

    game->map->grid[game->map->player_y][game->map->player_x] = '0';
    game->map->grid[new_y][new_x] = 'P';
    game->map->player_x = new_x;
    game->map->player_y = new_y;

    render_game(game);
}
