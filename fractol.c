

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"
#include <X11/keysym.h> // ESC key defintion
#include <X11/Xlib.h> // XColor

int deal_click(int pressed_click, void *param)
{
    (void)param;
    (void)pressed_click;
    printf("click %d %c\n", pressed_click, pressed_click);
    return (0);
}

int deal_key(int pressed_key, void *param)
{
    (void)param;
    (void)pressed_key;
    printf("key %d %c\n", pressed_key, pressed_key);
    if (pressed_key == XK_Escape)
        exit(1);
    return (0);
}

int continue_function(void *param)
{
    (void)param;
    puts("Hi");
    return (0);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     x, y;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Hello World!");
    if (!win_ptr)
        return (2);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if ((x - WIDTH / 2) * (x - WIDTH / 2) + (y - HEIGHT / 2) * (y - HEIGHT / 2) < 500)
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
            x++;
        }
        y++;
    }
    mlx_key_hook(win_ptr, deal_key, NULL);
    mlx_mouse_hook(win_ptr, deal_click, NULL);
    //mlx_loop_hook(mlx_ptr, continue_function, NULL);
    mlx_loop(mlx_ptr);
  return (0);
}
