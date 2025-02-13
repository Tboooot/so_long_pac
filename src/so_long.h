#ifndef SO_LONG
#define SO_LONG

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

#include <fcntl.h>

typedef struct s_img 
{
				void *exit_open;
				void *r1;
				void *floor;
				void *wall;
				void *collect;
}t_img;


typedef struct s_map
{
				char **grid;
				int n_row;
				int n_col;
				int p;
				int c;
				int e
}t_map;


typedef struct s_game
{
				void *id;
				void *win;
				t_map map;
				t_img img;
				int x;
				int y;
				int collect;
				int total_collect;
				int moves;
				int end;
				int size;
}t_game;


void init_map(char *filename ,t_game *game);
void validate_map_sides(t_map *map);
void validate_map_attributes(t_map *map);
void init_game(t_game *game);
int loop_game(t_game *game);
void render_map(t_game *game);
int key_hook(int key , t_game *game);
void move_player(int key , t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);


#endif
