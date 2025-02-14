#include "so_long.h"




void init_window(t_game *game)
{
		int (display_w),(display_h),(x),(y);
		
	x = game->map.n_col * game->size ;
	y = game->map.n_row * game->size ;
	game->id = mlx_init();
	mlx_get_screen_size(game->id , &display_w , &display_h);
	if(x > display_w || y > display_h )
	{
		x /= 2 ;
		y /= 2;
		game->size = 32;
		game->win = mlx_new_window(game->id , x , y , "so_long (mtarza");

	}
	else 
		game->win = mlx_new_window(game->id , x , y , "so_long (mtarza)");
}


void init_game(t_game *game)
{
	init_window(game);
}
