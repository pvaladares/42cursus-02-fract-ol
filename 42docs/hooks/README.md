
# Tutorial - Hooks


Homework regarding Hooks found [here](https://harm-smits.github.io/42docs/libs/minilibx/hooks.html#test-your-skills
)

> - a key is pressed, it will print the key code in the terminal.
- OK, implemented

> - the mouse if moved, it will print the current position of that mouse in the terminal.
 - Not working... seems that mlx implementation for linux does not work well with mouse hooks, see reference [here](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_mouse_hook)
 - *"`mlx_mouse_hook`
Hook into mouse events. This will trigger every time you click somewhere in the given screen. Do mind that currently these mouse events barely work, it is therefore suggested to not use them.*"

> - a mouse is pressed, it will print the angle at which it moved over the window to the terminal.
- Mouse hook implemented, angle calculation is failing due to calculation of deltas. Issue with the linux version as well?

See the sources files for the implementation.

In order to test just type
```shell
make run
```
