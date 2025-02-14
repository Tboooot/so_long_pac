#include "so_long.h"


static void insert_sprite(char *spirte , t_game *game , int x, int y)
{
	void *mlx;
	void *win;

	x *= game->size;
	y *= game->size;
	win = game->win;
	mlx = game->id;
	mlx_put_image_to_window(mlx,win,spirte , x , y);
}



void	render_map(t_game *game)
{
	int (i) , (j);
	
	i = -1;
	while(++i < game->map.n_row)
	{
		j = -1;
		while(++j < game->map.n_col)
		{
			if(game->map.grid[i][j] == '1')
				insert_sprite(game->img.wall , game ,j,i);
			if(game->map.grid[i][j] == '0')	
				insert_sprite(game->img.floor , game ,j,i);	
			if(game->map.grid[i][j] == 'C')	
				insert_sprite(game->img.collect , game ,j,i);
			if(game->map.grid[i][j] == 'P')	
				insert_sprite(game->img.r1, game ,j,i);
			if(game->map.grid[i][j] == 'E')	
				insert_sprite(game->img.exit_open , game ,j,i);
		}
	}
}
