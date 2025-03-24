#include "fractal.h"

void    terminate_mlx(t_fractal *fractal)
{
	if (fractal->mlx_data.image.img_pixels_ptr)
		mlx_destroy_image(fractal->mlx_data.conn_display,
                        fractal->mlx_data.image.img_pixels_ptr);
	if (fractal->mlx_data.window)
		mlx_destroy_window(fractal->mlx_data.conn_display, 
                        fractal->mlx_data.window);
	if (fractal->mlx_data.conn_display)
		mlx_destroy_display(fractal->mlx_data.conn_display);
}

void    terminate_fractal(t_fractal **fractal)
{
    terminate_mlx(*fractal);
    free(*fractal);
    (*fractal) = NULL;
    exit(ERR_MALLOC_FAIL);
}