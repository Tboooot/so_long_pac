#include "includes/so_long.h"

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

     return (0);
}
