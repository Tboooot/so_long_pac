#include "../../includes/so_long.h"

void render_game(t_game *game)
{
    int x;
    int y;

    mlx_clear_window(game->mlx, game->win);
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            mlx_put_image_to_window(game->mlx, game->win, 
                                  game->floor.img, 
                                  x * TILE_SIZE, y * TILE_SIZE);

            char current = game->map->grid[y][x];
            if (current == '1')
                mlx_put_image_to_window(game->mlx, game->win, 
                                      game->wall.img, 
                                      x * TILE_SIZE, y * TILE_SIZE);
            else if (current == 'C')
                mlx_put_image_to_window(game->mlx, game->win, 
                                      game->collectible.img, 
                                      x * TILE_SIZE, y * TILE_SIZE);
            else if (current == 'E')
                mlx_put_image_to_window(game->mlx, game->win, 
                                      game->exit.img, 
                                      x * TILE_SIZE, y * TILE_SIZE);
            else if (current == 'P')
                mlx_put_image_to_window(game->mlx, game->win, 
                                      game->player.img, 
                                      x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
