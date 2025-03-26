/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:26:39 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 17:26:40 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

static void	set_initial_complex_nbrs(t_fractal *fractal, int x, int y)
{
	fractal->z.real_part = 0.0;
	fractal->z.imgnry_part = 0.0;
	if (fractal->fractol_type == JULIA)
	{
		fractal->z.real_part = map_pixel_to_complex_plane(x, WIDTH,
				fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
		fractal->z.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
				fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
		return ;
	}
	else
	{
		fractal->c.real_part = map_pixel_to_complex_plane(x, WIDTH,
				fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
		fractal->c.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
				fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
	}
}

/*
 * Render the fractal for a given pixel.
 * Uses pow() from <math.h> for squaring operations.
 */
int	render_a_fractal(t_fractal *fractal, int x, int y,
		const unsigned int *palette)
{
	long int		i;
	long double		escape_limit_sq;
	t_complex_nbr	z;

	set_initial_complex_nbrs(fractal, x, y);
	z = fractal->z;
	escape_limit_sq = pow(fractal->settings_fractal.escape_val, 2);
	i = 0;
	while (i < fractal->settings_fractal.iterations_depth)
	{
		z = fractal_iteration(z, fractal->c, fractal->fractol_type);
		if (magnitude_squared_complex(z) > escape_limit_sq)
		{
			put_pixel(x, y, &fractal->mlx_data.image, generate_color((double)i,
					fractal->settings_fractal.iterations_depth, palette, 7));
			return (0);
		}
		i++;
	}
	put_pixel(x, y, &fractal->mlx_data.image, create_trgb(0, 0, 0, 0));
	return (0);
}

/*
 * Main painting loop: iterates over every pixel.
 */
int	paint_fractal(t_fractal *fractal)
{
	int				y;
	int				x;
	unsigned int	*palette;

	palette = get_plasma_palette();
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_a_fractal(fractal, x, y, palette);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx_data.conn_display,
		fractal->mlx_data.window, fractal->mlx_data.image.img_ptr, 0, 0);
	mlx_loop(fractal->mlx_data.conn_display);
	return (0);
}
