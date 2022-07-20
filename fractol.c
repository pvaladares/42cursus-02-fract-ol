

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"
#include <X11/keysym.h> // ESC key defintion
#include <X11/Xlib.h> // XColor
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int deal_click(int pressed_click, void *param)
{
    (void)param;
    (void)pressed_click;
    printf("click %d %c\n", pressed_click, pressed_click);
    printf("%f\n", M_PI);
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
    puts("continue");
    return (0);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     x, y;
    //int     c;
    //char    buffer;
double MinRe = -2.0;
double MaxRe = 1.0;
double MinIm = -1.2;
double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
unsigned MaxIterations = 100;

    x = -2;
    read(x, 0, 0);
    //buffer = strerror(-1);
    //puts(buffer);
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Hello World!");
    if (!win_ptr)
        return (2);
    y = 0;
    //c = HEIGHT;
    while (y < HEIGHT)
    {
            double c_im = MaxIm - y*Im_factor;

        x = 0;
        while (x < WIDTH)
        {
            double c_re = MinRe + x*Re_factor;

        double Z_re = c_re, Z_im = c_im;
        bool isInside = true;
        for(unsigned n=0; n<MaxIterations; ++n)
        {
            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
            if(Z_re2 + Z_im2 > 4)
            {
                isInside = false;
                break;
            }
            Z_im = 2*Z_re*Z_im + c_im;
            Z_re = Z_re2 - Z_im2 + c_re;
        }
        if(isInside) { mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000); }

            // z = 0 ; c = 0
            // z_n+1 = zn * zn + c
            //if ()
            //if ((x - WIDTH / 2) * (x - WIDTH / 2) + (y - HEIGHT / 2) * (y - HEIGHT / 2) == 500)
                
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
