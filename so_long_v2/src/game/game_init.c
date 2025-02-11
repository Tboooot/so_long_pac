#include "../../includes/so_long.h"

int main(int argc , char *argv[])
{
				t_game *game;

				game->mlx = init_game();
				if(!game->mlx)
				{
								print_error("faild instialize mlx");
								return (0);
				}
				
				game->win = mlx_new_window(game->mlx, game->map->width,game->map->height, WINDOW_TITLE );
				if(!game->win)
				{
								print_error("faild to creat window");
								return (0); 
				}
				


