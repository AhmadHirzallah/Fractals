#include "fractal.h"


char    *get_title_name(t_fractal *fractal)
{
    if (fractal->fractol_type == MANDELBROT)
        fractal->mlx_data.title_window = "Mandelbrot Fractal";
    else if (fractal->fractol_type == JULIA)
        fractal->mlx_data.title_window = "JULIA Fractal";
    else if (fractal->fractol_type == BURNING_SHIP)
        fractal->mlx_data.title_window = "Burning Ship Fractal";
    return (fractal->mlx_data.title_window);
}

int create_trgb(int t, int r, int g, int b)
{
    int color;

    color = (t << 24) | (r << 16) | (g << 8) | b;
    return (color);
}