#include "so_long.h"


static void	set_game_objective(t_game *game)
{
	int	(i),(j);
	
	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
			if (game->map.grid[i][j] == 'C')
				game->total_collect++;
	}
}

static void	*get_sprite(char *path, t_game *game)
{
	int		(width),(height);

	width = game->size;
	height = game->size;
	return (mlx_xpm_file_to_image(game->id, path, &width, &height));
}

static void init_sprites(t_game *game)
{
    if (!game || !game->id)
        return;

    if (game->size == 32)
    {
        game->img.floor = get_sprite("assets/32/floor.xpm", game);
        game->img.wall = get_sprite("assets/32/wall.xpm", game);
        game->img.collect = get_sprite("assets/32/fruit.xpm", game);
        game->img.r1 = get_sprite("assets/32/r1.xpm", game);
        game->img.exit_open = get_sprite("assets/32/exit4.xpm", game);
    }
    else
    {
        game->img.floor = get_sprite("assets/64/floor.xpm", game);
        game->img.wall = get_sprite("assets/64/wall.xpm", game);
        game->img.collect = get_sprite("assets/64/fruit.xpm", game);
        game->img.r1 = get_sprite("assets/64/r1.xpm", game);
        game->img.exit_open = get_sprite("assets/64/exit4.xpm", game);
    }
}
//void init_window(t_game *game)
//{
//		int (display_w),(display_h),(x),(y);
//		
//	x = game->map.n_col * game->size ;
//	y = game->map.n_row * game->size ;
//	game->id = mlx_init();
//	mlx_get_screen_size(game->id , &display_w , &display_h);
//	if(x > display_w || y > display_h )
//	{
//		x /= 2 ;
//		y /= 2;
//		game->size = 32;
//		game->win = mlx_new_window(game->id , x , y , "so_long (mtarza");
//
//	}
//	else 
//		game->win = mlx_new_window(game->id , x , y , "so_long (mtarza)");
//	set_game_objective(game);
//}
//
static void	init_window(t_game *game)
{
	int		display_w;
	int		display_h;
	int		x;
	int		y;

	x = game->map.n_col * game->size;
	y = game->map.n_row * game->size;
	game->id = mlx_init();
	mlx_get_screen_size(game->id, &display_w, &display_h);
	if (x > display_w || y > display_h)
	{
		x /= 2;
		y /= 2;
		game->size = 32;
		game->win = mlx_new_window(game->id, x, y, "so_long (frosa-ma)");
	}
	else
		game->win = mlx_new_window(game->id, x, y, "so_long (frosa-ma)");
	set_game_objective(game);
}
void init_game(t_game *game)
{
	init_window(game);
	ft_printf("\r\033[0;31mMoves:\033[0;33m %d\033[0m", game->moves);
	init_sprites(game);
	mlx_loop_hook(game->id , loop_hook, game);
	mlx_key_hook(game->win, key_hook , game);
	mlx_hook(game->win , 17 , 0,clean_before_exit,game);
	mlx_loop(game->id);	
}
