#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "fractal.h"

/*
 * Sets the initial complex numbers for the current pixel.
 * For Mandelbrot, the constant c is derived from the pixel coordinates,
 * and z is set to 0.
 * For Julia, c is constant (already set during initialization),
 * and z is mapped from the pixel coordinates.
 */
// static void set_initial_complex_nbrs(t_fractal *fractal, int x, int y)
// {
//     if (fractal->fractol_type == JULIA)
//     {
//         fractal->z.real_part = map_pixel_to_complex_plane(x, WIDTH,
//                                     fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
//         fractal->z.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
//                                     fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
//     }
//     else if(fractal->fractol_type == MANDELBROT)
//     {
//         fractal->c.real_part = map_pixel_to_complex_plane(x, WIDTH,
//                                     fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
//         fractal->c.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
//                                     fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
//         fractal->z.real_part = 0.0;
//         fractal->z.imgnry_part = 0.0;
//     }
// 	else if (fractal->fractol_type == BURNING_SHIP)
// 	{
// 		fractal->c.real_part = fabs(fractal->c.real_part);
//         fractal->c.imgnry_part = fabs(fractal->c.imgnry_part);
// 	}
// }


/*
 * Sets the initial complex numbers for the current pixel.
 * For JULIA, z is mapped from the pixel; for Mandelbrot/Burning Ship, c is derived
 * from the pixel coordinates and z is set to 0.
 * In Burning Ship, c is made positive.
 */
static void set_initial_complex_nbrs(t_fractal *fractal, int x, int y)
{
    if (fractal->fractol_type == JULIA)
    {
        fractal->z.real_part = map_pixel_to_complex_plane(x, WIDTH,
                                    fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
        fractal->z.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
                                    fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
    }
    else  // Mandelbrot or Burning Ship
    {
        fractal->c.real_part = map_pixel_to_complex_plane(x, WIDTH,
                                    fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
        fractal->c.imgnry_part = map_pixel_to_complex_plane(y, HEIGHT,
                                    fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
        fractal->z.real_part = 0.0;
        fractal->z.imgnry_part = 0.0;
        if (fractal->fractol_type == BURNING_SHIP)
        {
            fractal->c.real_part = fabs(fractal->c.real_part);
            fractal->c.imgnry_part = fabs(fractal->c.imgnry_part);
        }
    }
}


/*
 * Render the fractal for a given pixel.
 * Uses pow() from <math.h> for squaring operations.
 */
int render_a_fractal(t_fractal *fractal, int x, int y, const unsigned int *palette)
{
    long int	i;
	long double	escape_limit_sq;
    t_complex_nbr z;

    set_initial_complex_nbrs(fractal, x, y);
	z = fractal->z;
	escape_limit_sq = pow(fractal->settings_fractal.escape_val, 2);
	i = 0;
    while (i < fractal->settings_fractal.iterations_depth)
    {
		z = fractal_iteration(z, fractal->c);
		if (magnitude_squared_complex(z) > escape_limit_sq)
		{
			put_pixel(x, y, &fractal->mlx_data.image,
                         generate_color((double)i, fractal->settings_fractal.iterations_depth,
						 				palette, 7));
            return 0;
		}
        i++;
    }
	put_pixel(x, y, &fractal->mlx_data.image,
					create_trgb(0, 0, 0, 0));
    return (0);
}

/*
 * Main painting loop: iterates over every pixel.
 */
int paint_fractal(t_fractal *fractal)
{
    int y;
    int x;
	unsigned int *palette;

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
	mlx_put_image_to_window(fractal->mlx_data.conn_display, fractal->mlx_data.window,
							fractal->mlx_data.image.img_ptr, 0, 0);

    mlx_loop(fractal->mlx_data.conn_display);
    return (0);
}
