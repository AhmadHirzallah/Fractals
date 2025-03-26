/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:31:39 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:31:40 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/* Initializes the fractal settings. */
void	init_settings(t_fractal *fractal)
{
	fractal->settings_fractal.iterations_depth = ITER_DEPTH;
	fractal->settings_fractal.escape_val = ESCAPE_RADIUS;
	fractal->settings_fractal.zoom_factor = ZOOM_FACTOR;
	fractal->settings_fractal.shift_factor = SHIFT_FACTOR;
}

/* Initializes the axis ranges based on the aspect ratio.
   For non-BURNING_SHIP, y-axis is centered; for BURNING_SHIP,
	it is inverted. */
void	init_axes(t_fractal *fractal)
{
	double	aspect_ratio;
	double	x_range;
	double	y_range;

	fractal->axises.x_neg_axis = -2.0;
	fractal->axises.x_pos_axis = 2.0;
	aspect_ratio = (double)HEIGHT / WIDTH;
	x_range = fractal->axises.x_pos_axis - fractal->axises.x_neg_axis;
	y_range = x_range * aspect_ratio;
	if (fractal->fractol_type != BURNING_SHIP)
	{
		fractal->axises.y_neg_axis = -y_range / 2.0;
		fractal->axises.y_pos_axis = y_range / 2.0;
	}
	else
	{
		fractal->axises.y_neg_axis = y_range / 2.0;
		fractal->axises.y_pos_axis = -y_range / 2.0;
	}
}

/* Initializes the default complex number z. */
void	init_complex_numbers(t_fractal *fractal)
{
	fractal->z.real_part = 0.0;
	fractal->z.imgnry_part = 0.0;
}

/* For JULIA fractals,
	reset axes and initialize c from command-line arguments. */
void	init_julia_params(t_fractal *fractal, char **argv)
{
	fractal->axises.x_neg_axis = -2.0;
	fractal->axises.x_pos_axis = 2.0;
	fractal->axises.y_neg_axis = -2.0;
	fractal->axises.y_pos_axis = 2.0;
	fractal->c.real_part = ft_atodbl(argv[2]);
	fractal->c.imgnry_part = ft_atodbl(argv[3]);
}
