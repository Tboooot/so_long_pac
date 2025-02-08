#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "map.h"

# define TILE_SIZE 32
# define WINDOW_TITLE "so_long"
/* Add these event macros after your key definitions */
# define X_EVENT_KEY_PRESS        2
# define X_EVENT_KEY_RELEASE      3
# define X_EVENT_MOUSE_PRESS      4
# define X_EVENT_MOUSE_RELEASE    5
# define X_EVENT_MOUSE_MOVE       6
# define X_EVENT_EXIT            17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_img
{
    void    *img;
    int     width;
    int     height;
}   t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_img   wall;
    t_img   player;
    t_img   collectible;
    t_img   exit;
    t_img   floor;
    int     moves;
    int     collected;
}   t_game;

/* Function Prototypes */
// Game initialization
int     init_game(t_game *game);
int     load_images(t_game *game);

// Game loop and rendering
void    render_game(t_game *game);
int     game_loop(t_game *game);

// Input handling
int     key_handler(int keycode, t_game *game);
int     close_game(t_game *game);

// Movement
void    move_player(t_game *game, int new_x, int new_y);

#endif
