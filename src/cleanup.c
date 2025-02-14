#include "so_long.h"



void  ft_free_grid(char **matrix)
 {
int i;

  i = 0;
 while (matrix[i])
 free(matrix[i++]);
 free(matrix);
 }

static void	free_window(t_game *game)
{
	mlx_clear_window(game->id, game->win);
	mlx_destroy_window(game->id, game->win);
	mlx_destroy_display(game->id);
	free(game->id);
}





static void	free_images(t_game *game)
{
	void	*win;

	win = game->id;
	mlx_destroy_image(win, game->img.floor);
	mlx_destroy_image(win, game->img.wall);
	mlx_destroy_image(win, game->img.collect);
	mlx_destroy_image(win, game->img.r1);
	mlx_destroy_image(win, game->img.exit_open);
}

static void	free_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.n_row)
		free(game->map.grid[i++]);
	free(game->map.grid);
}


int	clean_before_exit(t_game *game)
{
	free_matrix(game);
	free_images(game);
	free_window(game);
	ft_printf("\n");
	exit(0);
	return (0);
}




