
#include "includes/map.h"

int	main(int argc, char *argv[])
{
    t_map	*map;

    if (argc != 2)
    {
        ft_putendl_fd("Error\nUsage: ./so_long map.ber", 2);
        return (1);
    }
    map = parse_map(argv[1]);
    if (!map)
    {
        free_map(map);
        free(map);
        return (1);
    }
    free_map(map);
    return (0);
}
