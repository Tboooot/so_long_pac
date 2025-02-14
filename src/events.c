#include "so_long.h"

static void check_win_condition(t_game *game)
{
    // Check if all collectibles are gathered
    if (game->collect == game->total_collect)
    {
        game->end = 1;
        ft_printf("\r\033[0;32mAll collectibles gathered! Head to the exit!\033[0m");
    }
}

static int is_arrow(int key)
{
    return (key == UP || key == DOWN || key == LEFT || key == RIGHT);
}

int key_hook(int key, t_game *game)
{
    if (key == 'q' || key == ESC)
        clean_before_exit(game);
    if (ft_strchr("wasd", key) || is_arrow(key))
    {
        move_player(key, game);
        ft_printf("\r\033[0;31mMoves:\033[0;33m %d\033[0m", game->moves);
        check_win_condition(game);
    }
    return (0);
}

int loop_hook(t_game *game)
{
    render_map(game);
    return (0);
}