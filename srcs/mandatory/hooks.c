#include "fractal.h"

// static int press_mouse_handler(int button, int x, int y, t_fractal *fractal)
// {
//     if (button == 5)
// 		zoom_in(fractal, x, y);
// 	else if (button == 4)
// 		zoom_out(fractal, x, y);
// 	if (button == 1)
// 	{
// 		if (fractal->pallet == RAINBOW)
// 			fractal->pallet = MAGMA;
// 		else
// 			fractal->pallet = RAINBOW;
// 	}
// 	fractal_render(fractal);
// 	return (0);
// }

// static int press_keyboard_handler(int keycode, t_fractal *fractal)
// {
//     if (keycode == XK_Escape)
//         terminate_fractal(&fractal);
//     else if (keycode == XK_Right)
// 		shift_x(fractal, 1);
// 	else if (keycode == XK_Left)
// 		shift_x(fractal, -1);
// 	else if (keycode == XK_Up)
// 		shift_y(fractal, -1);
// 	else if (keycode == XK_Down)
// 		shift_y(fractal, 1);
// 	// else if (keycode == XK_plus || keycode == XK_equal)
// 	// 	fractal->iter_ceil += 50;
// 	// else if (keycode == XK_minus)
// 	// 	fractal->iter_ceil -= 50;
// 	// else if (keycode == XK_s || keycode == XK_S)
// 	// {
// 	// 	if (fractal-> sharpness < 2048)
// 	// 		fractal->sharpness += 10;
// 	// }
// 	// else if (keycode == XK_d || keycode == XK_D)
// 	// 	if (fractal-> sharpness > 50)
// 	// 		fractal->sharpness -= 10;
// 	// fractal_render(data);
// 	return (0);
// }

// static int exit_handler(t_fractal *fractal)
// {
//     terminate_fractal(&fractal);
//     exit(0);
// }


// void define_hooks(t_fractal *fractal)
// {
//     mlx_hook(fractal->mlx_data.window, KeyPress, KeyPressMask, press_keyboard_handler, fractal);
//     mlx_hook(fractal->mlx_data.window, ButtonPress, ButtonPressMask, press_mouse_handler, fractal);
//     mlx_hook(fractal->mlx_data.window, DestroyNotify, StructureNotifyMask, exit_handler, fractal);
// }
