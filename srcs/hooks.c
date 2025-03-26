/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:24:18 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 17:24:19 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

static int	press_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		perform_zoom(fractal, x, y, ZOOM_IN);
	else if (button == 5)
		perform_zoom(fractal, x, y, ZOOM_OUT);
	paint_fractal(fractal);
	return (0);
}

static int	press_keyboard_handler(int keycode, t_fractal *fractal)
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
	paint_fractal(fractal);
	return (0);
}

static int	exit_handler(t_fractal *fractal)
{
	terminate_fractal(&fractal, OK);
	return (0);
}

void	define_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_data.window, KeyPress, KeyPressMask,
		press_keyboard_handler, fractal);
	mlx_hook(fractal->mlx_data.window, ButtonPress, ButtonPressMask,
		press_mouse_handler, fractal);
	mlx_hook(fractal->mlx_data.window, DestroyNotify, StructureNotifyMask,
		exit_handler, fractal);
}
