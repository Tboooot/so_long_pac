
#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.grid[game->y - 1][game->x] == 'C')
		game->collect++;
	game->map.grid[game->y][game->x] = '0';
	game->map.grid[game->y - 1][game->x] = 'P';
	game->moves++;
}

void	move_down(t_game *game)
{
	if (game->map.grid[game->y + 1][game->x] == 'C')
		game->collect++;
	game->map.grid[game->y][game->x] = '0';
	game->map.grid[game->y + 1][game->x] = 'P';
	game->moves++;
}

void	move_left(t_game *game)
{
	if (game->map.grid[game->y][game->x - 1] == 'C')
		game->collect++;
	game->map.grid[game->y][game->x] = '0';
	game->map.grid[game->y][game->x - 1] = 'P';
	game->moves++;
}

void	move_right(t_game *game)
{
	if (game->map.grid[game->y][game->x + 1] == 'C')
		game->collect++;
	game->map.grid[game->y][game->x] = '0';
	game->map.grid[game->y][game->x + 1] = 'P';
	game->moves++;
}
