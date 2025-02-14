#include "so_long.h"


static int is_exit(t_game *game, char dir)
{
    if (dir == 'A') return (game->map.grid[game->y - 1][game->x] == 'E');
    if (dir == 'L') return (game->map.grid[game->y + 1][game->x] == 'E');
    if (dir == 'D') return (game->map.grid[game->y][game->x - 1] == 'E');
    if (dir == 'R') return (game->map.grid[game->y][game->x + 1] == 'E');
    return (0);
}
static void update_player_coordinates(t_game *game)
{
	int (i),(j);
	
	i = -1;
	while(++i < game->map.n_row)
	{
		j = -1;
		while(++j < game->map.n_col)
		{
			if(game->map.grid[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
		}
	}
}
static int is_valid(t_game *game, char dir)
{
    if (!game->end)
    {
        if (dir == 'A') return (!ft_strchr("1E", game->map.grid[game->y - 1][game->x]));
        if (dir == 'L') return (!ft_strchr("1E", game->map.grid[game->y + 1][game->x]));
        if (dir == 'D') return (!ft_strchr("1E", game->map.grid[game->y][game->x - 1]));
        if (dir == 'R') return (!ft_strchr("1E", game->map.grid[game->y][game->x + 1]));
    }
    if (is_exit(game, dir))
    {
        clean_before_exit(game);
        return (0);
    }
    if (dir == 'A') return (!ft_strchr("1", game->map.grid[game->y - 1][game->x]));
    if (dir == 'L') return (!ft_strchr("1", game->map.grid[game->y + 1][game->x]));
    if (dir == 'D') return (!ft_strchr("1", game->map.grid[game->y][game->x - 1]));
    if (dir == 'R') return (!ft_strchr("1", game->map.grid[game->y][game->x + 1]));
    return (0);
}
void move_player(int key, t_game *game)
{
    update_player_coordinates(game);
    if ((key == 'w' || key == UP) && is_valid(game, 'A'))
        move_up(game);
    if ((key == 'a' || key == LEFT) && is_valid(game, 'L'))
        move_left(game);
    if ((key == 's' || key == DOWN) && is_valid(game, 'D'))
        move_down(game);
    if ((key == 'd' || key == RIGHT) && is_valid(game, 'R'))
        move_right(game);
}
