#include "fractal.h"

static int	init_mlx(t_fractal **fractal)
{
	(*fractal)->mlx_data.conn_display = mlx_init();
	if ((*fractal)->mlx_data.conn_display == NULL)
		terminate_fractal(fractal);
	(*fractal)->mlx_data.window = mlx_new_window((*fractal)->mlx_data.conn_display,
													WIDTH,
													HEIGHT,
													get_title_name(*fractal));
	if ((*fractal)->mlx_data.window == NULL)
		terminate_fractal(fractal);
	(*fractal)->mlx_data.image.img_ptr = mlx_new_image((*fractal)->mlx_data.conn_display, 
														WIDTH, HEIGHT);
	if ((*fractal)->mlx_data.image.img_ptr == NULL)
		terminate_fractal(fractal);
	(*fractal)->mlx_data.image.img_pixels_ptr = mlx_get_data_addr((*fractal)->mlx_data.image.img_ptr,
																	&(*fractal)->mlx_data.image.bits_per_pixel,
																	&(*fractal)->mlx_data.image.size_line,
																	&(*fractal)->mlx_data.image.endian);
	if ((*fractal)->mlx_data.image.img_ptr == NULL)
		terminate_fractal(fractal);
	return (0);
}
// static int	init_fractal(char **argv, t_fractal **fractal)
// {

	


// 	(*fractal)->settings_fractal.iterations_depth = ITER_DEPTH;
// 	(*fractal)->settings_fractal.escape_val = ESCAPE_RADIUS;
// 	(*fractal)->axises.x_neg_axis = -2.5;
// 	(*fractal)->axises.x_pos_axis = 1;

// 	// (*fractal)->axises.y_neg_axis = -y_range / 2.0;
// 	// (*fractal)->axises.y_pos_axis = y_range / 2.0;

// 	// (*fractal)->axises.y_neg_axis = -1.5;
// 	// (*fractal)->axises.y_pos_axis = 1.5;

	
// 	double y_range = (1 - -2.5) * (HEIGHT / (double)WIDTH);
// 	(*fractal)->axises.y_neg_axis = -y_range / 2.0;
// 	(*fractal)->axises.y_pos_axis = y_range / 2.0;

// 	(*fractal)->z.real_part = 0.0;
// 	(*fractal)->z.imgnry_part = 0.0;
// 	if ((*fractal)->fractol_type == JULIA)
// 	{
// 		(*fractal)->c.real_part = ft_atodbl(argv[2]);
// 		(*fractal)->c.imgnry_part = ft_atodbl(argv[3]);
// 	}
// 	return (0);
// }


// static int	init_fractal(char **argv, t_fractal **fractal)
// {
// 	(*fractal)->settings_fractal.iterations_depth = ITER_DEPTH;
// 	(*fractal)->settings_fractal.escape_val = ESCAPE_RADIUS;
// 	(*fractal)->axises.x_neg_axis = -2.5;
// 	(*fractal)->axises.x_pos_axis = 1;

// 	// (*fractal)->axises.y_neg_axis = -y_range / 2.0;
// 	// (*fractal)->axises.y_pos_axis = y_range / 2.0;

// 	// (*fractal)->axises.y_neg_axis = -1.5;
// 	// (*fractal)->axises.y_pos_axis = 1.5;

	
// 	double y_range = (1 - -2.5) * (HEIGHT / (double)WIDTH);
// 	(*fractal)->axises.y_neg_axis = -y_range / 2.0;
// 	(*fractal)->axises.y_pos_axis = y_range / 2.0;

// 	(*fractal)->z.real_part = 0.0;
// 	(*fractal)->z.imgnry_part = 0.0;
// 	if ((*fractal)->fractol_type == JULIA)
// 	{
// 		(*fractal)->c.real_part = ft_atodbl(argv[2]);
// 		(*fractal)->c.imgnry_part = ft_atodbl(argv[3]);
// 	}
// 	return (0);
// }
		
static int init_fractal(char **argv, t_fractal **fractal) {
    (*fractal)->settings_fractal.iterations_depth = ITER_DEPTH;
    (*fractal)->settings_fractal.escape_val = ESCAPE_RADIUS;

    // Define X-Axis range
    (*fractal)->axises.x_neg_axis = -2.0;
    (*fractal)->axises.x_pos_axis = 2.0;

    // Maintain Aspect Ratio for Y-Axis
    double aspect_ratio = (double)HEIGHT / WIDTH;
    double x_range = (*fractal)->axises.x_pos_axis - (*fractal)->axises.x_neg_axis;
    double y_range = x_range * aspect_ratio;

    (*fractal)->axises.y_neg_axis = -y_range / 2.0;
    (*fractal)->axises.y_pos_axis = y_range / 2.0;

    (*fractal)->z.real_part = 0.0;
    (*fractal)->z.imgnry_part = 0.0;

    if ((*fractal)->fractol_type == JULIA) {
        (*fractal)->axises.x_neg_axis = -2.0;
        (*fractal)->axises.x_pos_axis = 2.0;

        // Ensure proper Y-Axis scaling
        (*fractal)->axises.y_neg_axis = -2.0;
        (*fractal)->axises.y_pos_axis = 2.0;  

        // Get Julia set complex constant from input
        (*fractal)->c.real_part = ft_atodbl(argv[2]);
        (*fractal)->c.imgnry_part = ft_atodbl(argv[3]);
    }
    return (0);
}

int     init_data(int argc, char **argv, t_fractal **fractal)
{
	char	*cmpr_str;

	(*fractal) = ft_calloc(1, sizeof(t_fractal));
	if (*fractal == NULL)
		exit(ERR_MALLOC_FAIL);
	cmpr_str = str_to_lower(argv[1]);
	if ((argc == 2 || str_cmpr(cmpr_str, "mandelbrot") == 0))
		(*fractal)->fractol_type = MANDELBROT;
	else if ((argc == 4) && str_cmpr(cmpr_str, "julia") == 0)
		(*fractal)->fractol_type = JULIA;
	else if (argc == 2 && str_cmpr(cmpr_str, "burning_ship") == 0)
		(*fractal)->fractol_type = BURNING_SHIP;
	else
	{
		ft_putstr_fd("Wronge Input.\n", 2);
		ft_putstr_fd("Usage:\n\n\t./fractol mandelbrot\n", 2);
		ft_putstr_fd("\t./fractol julia <real> <imaginary>\n", 2);
		ft_putstr_fd("\t./fractol third_fractal\n", 2);
		free(cmpr_str);
		exit(ERR_WRNG_ARGV);
	}
	free(cmpr_str);
	init_fractal(argv, fractal);
	init_mlx(fractal);
	// define_hooks(*fractal);
	return (OK);
}
