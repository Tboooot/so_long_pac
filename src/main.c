#include "so_long.h"




static void define_game(t_game *game)
{
				game->x = 0;
				game->y = 0;
				game->end = 0;
				game->collect = 0;
				game->total_collect = 0;
				game->moves = 0;
				game->map.c = 0;
				game->map.e = 0;
				game->map.p = 0;
				game->map.n_row = 0;
				game->map.n_col = 0;
				game->size = 64;
}
int is_valid_argemnt(char *str)
{
				size_t offset;

				offset = ft_strlen(str) - 4;

				if(ft_strncmp(".ber",str + offset , 5 ) == 0)
				{
								return(1);
				}
				return(0);
}

int main(int ac , char *av[])
{
				t_game game;

				if( ac != 2)
				{
								ft_printf("Error \n Invalid number of argemnt\n");
								exit(1);
								return(1);
				}
				if(!is_valid_argemnt(av[1]))
				{
								ft_printf("Error\n Invalid name of agr .ber");
								exit(1);
								return(1);
				}
				define_game(&game);
				init_map(av[1],&game);

}
