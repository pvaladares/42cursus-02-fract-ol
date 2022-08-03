
# Tutorial - Hooks


Homework regarding Hooks found [here](https://harm-smits.github.io/42docs/libs/minilibx/hooks.html#test-your-skills
)

> - a key is pressed, it will print the key code in the terminal.
- OK, implemented

> - the mouse if moved, it will print the current position of that mouse in the terminal.
 - OK, implemented
 - The 42docs mentions that the implementation for linux does not work well with mouse hooks, see reference [here](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_mouse_hook). After analysis of the mlx it could not be found any mlx function that already addressed this. Had to check the [documentation](https://tronche.com/gui/x/xlib/events/processing-overview.html) to find the right match for event and mask and implement using the `mlx_hook`:
```c
mlx_hook(app->win_ptr, MotionNotify, PointerMotionMaskcursor_moved, &app);
```

> - a mouse is pressed, it will print the angle at which it moved over the window to the terminal.
- OK, implemented

See the sources files for the implementation.

In order to test just type
```shell
make mlx ; make run
```
