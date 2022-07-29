
# Tutorial - Events


Homework regarding Events found [here](https://harm-smits.github.io/42docs/libs/minilibx/events.html#test-your-skills)

> - ESC key is pressed, your window should close.
- OK, implemented

> - window is resized, you should print something in your terminal.

- Regarindg window resize, this is not really possible just with MLX. 
- According to [here](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx#Minilibx-window-limitations) *"it is currently [impossible to resize a window](https://github.com/42Paris/minilibx-linux/blob/master/mlx_int_anti_resize_win.c): thus we're only allowed to deal with the original dimensions of the window."*

> - the red cross is clicked, your window should close.
- OK, implemented

> - you press a key longer than x seconds, you should print something in your terminal.
- OK, implemented

> - mouse enters the window, you should print Hello! in your terminal, when it leaves, you should print Bye!.
- OK, implemented


See the sources files for the implementation.

In order to test just type
```shell
make run
```
