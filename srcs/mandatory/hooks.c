#include "fractal.h"
#include <stdio.h>

static int press_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
		perform_zoom(fractal, x, y, ZOOM_IN);
	else if (button == 5)
		perform_zoom(fractal, x, y, ZOOM_OUT);
    paint_fractal(fractal);
	return (0);
}

static int press_keyboard_handler(int keycode, t_fractal *fractal)
{
    if (keycode == XK_Escape)
        terminate_fractal(&fractal, OK);
    else if (keycode == XK_Right)
		shift_any(fractal, SHIFT_TORIGHT);
	else if (keycode == XK_Left)
		shift_any(fractal, SHIFT_TOLEFT);
	else if (keycode == XK_Up)
		shift_any(fractal, SHIFT_UPWARD);
	else if (keycode == XK_Down)
		shift_any(fractal, SHIFT_DOWNWARD);
	// else if (keycode == XK_plus || keycode == XK_equal)
	// 	fractal->iter_ceil += 50;
	// else if (keycode == XK_minus)
	// 	fractal->iter_ceil -= 50;
	// else if (keycode == XK_s || keycode == XK_S)
	// {
	// 	if (fractal-> sharpness < 2048)
	// 		fractal->sharpness += 10;
	// }
	// else if (keycode == XK_d || keycode == XK_D)
	// 	if (fractal-> sharpness > 50)
	// 		fractal->sharpness -= 10;
	// fractal_render(data);
    paint_fractal(fractal);
	return (0);
}

static int exit_handler(t_fractal *fractal)
{
    terminate_fractal(&fractal, OK);
	return (0);
}


void define_hooks(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_data.window, KeyPress, KeyPressMask, press_keyboard_handler, fractal);
    mlx_hook(fractal->mlx_data.window, ButtonPress, ButtonPressMask, press_mouse_handler, fractal);
    mlx_hook(fractal->mlx_data.window, DestroyNotify, StructureNotifyMask, exit_handler, fractal);
}
