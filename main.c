#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    int color;
} t_data;

// Function for mlx_key_hook
//int key_simple(int keycode, t_data *data)
//{
//    printf("\n=== Simple Key Hook ===\n");
//    printf("Key pressed: %d\n", keycode);
//    if (keycode == XK_Escape)
//    {
//        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//        mlx_destroy_display(data->mlx_ptr);
//        free(data->mlx_ptr);
//        exit(0);
//    }
//    return (0);
//}

// Function for mlx_hook
//int key_advanced(int keycode, t_data *data)
//{
//    printf("\n=== Advanced Hook with Mask ===\n");
//    printf("Key pressed: %d\n", keycode);
//    if (keycode == XK_Escape)
//    {
//        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//        mlx_destroy_display(data->mlx_ptr);
//        free(data->mlx_ptr);
//        exit(0);
//    }
//    return (0); sf
//}
//
//int change_color(t_data *data)
//{
//    static int y_pos = 150;  // Static variable to move text vertically
//    
//    mlx_clear_window(data->mlx_ptr, data->win_ptr);
//    mlx_string_put(data->mlx_ptr, data->win_ptr, 150, y_pos, data->color, 
//                   "Color Changing Window!");
//    
//    // Change color
//    if (data->color == 0xFF0000)        // Red
//        data->color = 0x00FF00;         // to Green
//    else if (data->color == 0x00FF00)   // Green
//        data->color = 0x0000FF;         // to Blue
//    else
//        data->color = 0xFF0000;         // to Red
//    
//    return (0);
//}
//int f(int kysym ,t_data *data)
//{
//    printf("press %d\n",kysym);
//    sleep(1);
//    return 1;
//}
int main(void)
{
    VDFV,    
    "bsdgsdf");
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "key hook compare");

   // mlx_key_hook(data.win_ptr, key_simple, &data);

    // method 2: advanced hook (explicit mask)
    //mlx_hook(data.win_ptr, keypress, keypressmask, key_advanced, &data);
        data.color = 0xff0000;
    mlx_string_put(data.mlx_ptr , data.win_ptr , 400 ,400 ,0xffffff,"dada");
    
    //   mlx_key_hook(data.mlx_ptr , f, &data);
    //mlx_loop_hook(data.mlx_ptr ,change_color,&data); 
    mlx_loop(data.mlx_ptr);
    return (0);
}
