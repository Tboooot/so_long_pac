#include "includes/so_long.h"

int close_game(t_game *game)
{
    if (game->mlx)
    {
        if (game->wall.img)
            mlx_destroy_image(game->mlx, game->wall.img);
        if (game->player.img)
            mlx_destroy_image(game->mlx, game->player.img);
        if (game->collectible.img)
            mlx_destroy_image(game->mlx, game->collectible.img);
        if (game->exit.img)
            mlx_destroy_image(game->mlx, game->exit.img);
        if (game->floor.img)
            mlx_destroy_image(game->mlx, game->floor.img);
        
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
    }

    if (game->map)
    {
        free_map(game->map);
        free(game->map);
    }

    exit(0);
    return (0);
}

int key_handler(int keycode, t_game *game)
{
    int x = game->map->player_x;
    int y = game->map->player_y;

    if (keycode == KEY_ESC)
        return (close_game(game));
    else if (keycode == KEY_W || keycode == KEY_UP)
        y--;
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        y++;
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        x--;
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        x++;

    if (x != game->map->player_x || y != game->map->player_y)
        move_player(game, x, y);
    return (0);
}

int main(int argc, char *argv[])
{
    t_game  *game;

    if (argc != 2)
    {
        ft_putendl_fd("Error\nUsage: ./so_long map.ber", 2);
        return (1);
    }

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        ft_putendl_fd("Error\nMemory allocation failed", 2);
        return (1);
    }


    game->map = parse_map(argv[1]);
    if (!game->map)
    {
        free(game);
        return (1);
    }

    if (!init_game(game))
    {
        free_map(game->map);
        free(game);
        return (1);
    }

    mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L<<0, key_handler, game);
    mlx_hook(game->win, X_EVENT_EXIT, 0, close_game, game);  // Handle window close button

    render_game(game);

    mlx_loop(game->mlx);

    return (0);
}
