#include "../../includes/so_long.h"

static int load_image(t_game *game, t_img *img, char *path)
{
    img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
    if (!img->img)
    {
        ft_putstr_fd("Error\nFailed to load image: ", 2);
        ft_putendl_fd(path, 2);
        return (0);
    }
    return (1);
}

int load_images(t_game *game)
{
    // Load wall from map directory
    if (!load_image(game, &game->wall, "./assets/map/wall.xpm"))
        return (0);
    
    // Load player (Pacman) from pacman directory
    if (!load_image(game, &game->player, "./assets/pacman/pac_open_right.xpm"))
    {
        mlx_destroy_image(game->mlx, game->wall.img);
        return (0);
    }
    
    // Load collectible (item) from map directory
    if (!load_image(game, &game->collectible, "./assets/map/item.xpm"))
    {
        mlx_destroy_image(game->mlx, game->wall.img);
        mlx_destroy_image(game->mlx, game->player.img);
        return (0);
    }
    
    // Load exit from map directory
    if (!load_image(game, &game->exit, "./assets/map/exit.xpm"))
    {
        mlx_destroy_image(game->mlx, game->wall.img);
        mlx_destroy_image(game->mlx, game->player.img);
        mlx_destroy_image(game->mlx, game->collectible.img);
        return (0);
    }
    
    // Load floor (black) from map directory
    if (!load_image(game, &game->floor, "./assets/map/black.xpm"))
    {
        mlx_destroy_image(game->mlx, game->wall.img);
        mlx_destroy_image(game->mlx, game->player.img);
        mlx_destroy_image(game->mlx, game->collectible.img);
        mlx_destroy_image(game->mlx, game->exit.img);
        return (0);
    }
    
    return (1);
}

int init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        print_error("Failed to initialize MLX");
        return (0);
    }

    game->win = mlx_new_window(game->mlx, 
                              game->map->width * TILE_SIZE,
                              game->map->height * TILE_SIZE,
                              WINDOW_TITLE);
    if (!game->win)
    {
        print_error("Failed to create window");
        return (0);
    }

    game->moves = 0;
    game->collected = 0;

    if (!load_images(game))
    {
        mlx_destroy_window(game->mlx, game->win);
        return (0);
    }

    return (1);
}
