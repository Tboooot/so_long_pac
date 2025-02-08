
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data {
  void *mlx_ptr;
  void *win_ptr;
  int color;
  int x_pos;
  int y_pos;
  char *img;

} t_data;

int key_handler(int botton, t_data *data) {
  int move = 10;
  int old_x = data->x_pos;
  int old_y = data->y_pos;


  if (botton == XK_Left || botton == XK_a) {
    printf("moving left\n");
    data->x_pos -= move;
  }

  if (botton == XK_Right || botton == XK_d) {
    printf("moving right\n");
    data->x_pos += move;
  }
    
  if (botton == XK_Up  || botton == XK_w) {
    printf("moving up\n");
    data->y_pos -= move;
  }

  if (botton == XK_Down || botton == XK_s) {
    printf("moving down\n");
    data->y_pos += move;
  }
    
  if (old_x != data->x_pos || old_y != data->y_pos) {
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img,
                            data->x_pos, data->y_pos);
  }
  return 0;
}

int main() {
  t_data data;
  char *path = "./img/pac.xpm";
  int hight, width;
  data.mlx_ptr = mlx_init();
  data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 500, "new");
  data.x_pos = 300 / 2;
  data.y_pos = 500 / 2;
  data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &hight, &width);
  mlx_key_hook(data.win_ptr, key_handler, &data);
  mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, data.x_pos,
                          data.y_pos);
  
  mlx_loop(data.mlx_ptr);
}

