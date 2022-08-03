# 42cursus-02-fract-ol
Discover 2D programming and the psychedelic universe of fractals in this project, using minilibX.

# MLX 

- https://harm-smits.github.io/42docs/libs/minilibx

> First of all, we should take into account that the `mlx_pixel_put` function is very, very slow. This is because it tries to push the pixel instantly to the window (without waiting for the frame to be entirely rendered). Because of this sole reason, we will have to buffer all of our pixels to a image, which we will then push to the window.


# Tips

- The [`minilibx-linux.tgz`](files/minilibx-linux.tgz) has some man pages that are not in the other provided compressed files.

## Converting from `man` to `pdf`
- In order to convert from `man` format to `pdf`, use command `man -Tpdf man > man.pdf` as suggested [here](https://unix.stackexchange.com/a/444769).

## Installing permanently the `mlx` man pages
- Use command `manpath` to list all the folders where `man` will look for files
- Copy the files into one of the folders listed
```shell
sudo cp minilibx-linux/man/man3/* /usr/local/man/man3
```
- Now just type `man mlx` to check the manual
```man
MiniLibX(3)                             Library Functions Manual                            MiniLibX(3)

NAME
       MiniLibX - Simple X-Window Interface Library for students

SYNOPSYS
       #include <mlx.h>

       void *
       mlx_init ();

DESCRIPTION
       MiniLibX  is  an  easy way to create graphical software, without any X-Window programming knowl‐
       edge. It provides simple window creation, a drawing tool, image and basic events management.
```


# Resources

- [MiniLibX - 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx.html)
- [X11 documentation about events](https://tronche.com/gui/x/xlib/events)
- [Some examples with MLX](https://github.com/terry-yes/mlx_example)
- [Image tutorials with MLX](https://github.com/keuhdall/images_example)
- [minilibx sources and ft_fractal links](https://qst0.github.io/ft_libgfx/#ft_fractal)
- [Smooth Zoom - stackoverflow](https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c)
