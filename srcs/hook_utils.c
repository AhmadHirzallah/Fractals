/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:22:48 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:29:16 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	shift_any(t_fractal *fractal, enum e_shifting_director shift)
{
	double	shift_x;
	double	shift_y;

	get_shift_factors(fractal, &shift_x, &shift_y);
	if (shift == SHIFT_DOWNWARD)
		shift_axis(&fractal->axises.y_neg_axis, &fractal->axises.y_pos_axis,
			-shift_y);
	else if (shift == SHIFT_UPWARD)
		shift_axis(&fractal->axises.y_neg_axis, &fractal->axises.y_pos_axis,
			shift_y);
	else if (shift == SHIFT_TOLEFT)
		shift_axis(&fractal->axises.x_neg_axis, &fractal->axises.x_pos_axis,
			-shift_x);
	else if (shift == SHIFT_TORIGHT)
		shift_axis(&fractal->axises.x_neg_axis, &fractal->axises.x_pos_axis,
			shift_x);
}

/*
 * Performs zoom based on a mouse event.
 * Maps the pixel (x,y) to the complex plane.

	* The y-axis mapping is reversed so that the top
		of the screen remains at the top.
 * Depending on zoom_dir (ZOOM_IN or ZOOM_OUT),
	the appropriate helper is called.
 */
void	perform_zoom(t_fractal *fractal, int x, int y,
		enum e_shifting_director zoom_dir)
{
	double	x_new;
	double	y_new;

	x_new = map_pixel_to_complex_plane(x, WIDTH, fractal->axises.x_neg_axis,
			fractal->axises.x_pos_axis);
	y_new = map_pixel_to_complex_plane(y, HEIGHT, fractal->axises.y_pos_axis,
			fractal->axises.y_neg_axis);
	if (zoom_dir == ZOOM_IN)
	{
		update_axis_zoom_in(&fractal->axises.x_neg_axis,
			&fractal->axises.x_pos_axis, x_new, ZOOM_FACTOR);
		update_axis_zoom_in(&fractal->axises.y_neg_axis,
			&fractal->axises.y_pos_axis, y_new, ZOOM_FACTOR);
	}
	else if (zoom_dir == ZOOM_OUT)
	{
		update_axis_zoom_out(&fractal->axises.x_neg_axis,
			&fractal->axises.x_pos_axis, x_new, ZOOM_FACTOR);
		update_axis_zoom_out(&fractal->axises.y_neg_axis,
			&fractal->axises.y_pos_axis, y_new, ZOOM_FACTOR);
	}
}
