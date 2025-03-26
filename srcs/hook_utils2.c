/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:23:41 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:23:42 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/* Computes the shift factors for x and y axes. */
void	get_shift_factors(const t_fractal *fractal, double *shift_x,
		double *shift_y)
{
	*shift_x = (fractal->axises.x_pos_axis - fractal->axises.x_neg_axis)
		/ fractal->settings_fractal.shift_factor;
	*shift_y = (fractal->axises.y_pos_axis - fractal->axises.y_neg_axis)
		/ fractal->settings_fractal.shift_factor;
}

void	shift_axis(double *axis_min, double *axis_max, double delta)
{
	*axis_min += delta;
	*axis_max += delta;
}

void	update_axis_zoom_in(double *axis_min, double *axis_max, double center,
		double factor)
{
	*axis_min = center - (center - *axis_min) / factor;
	*axis_max = center + (*axis_max - center) / factor;
}

void	update_axis_zoom_out(double *axis_min, double *axis_max, double center,
		double factor)
{
	*axis_min = center - (center - *axis_min) * factor;
	*axis_max = center + (*axis_max - center) * factor;
}
