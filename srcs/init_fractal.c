/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:24:31 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:52:14 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	init_mlx(t_fractal **fractal)
{
	(*fractal)->mlx_data.conn_display = mlx_init();
	if ((*fractal)->mlx_data.conn_display == NULL)
		terminate_fractal(fractal, ERR_MALLOC_FAIL);
	(*fractal)->mlx_data.window = mlx_new_window((
				*fractal)->mlx_data.conn_display,
			WIDTH, HEIGHT,
			get_title_name(*fractal));
	if ((*fractal)->mlx_data.window == NULL)
		terminate_fractal(fractal, ERR_MALLOC_FAIL);
	(*fractal)->mlx_data.image.img_ptr = mlx_new_image((
				*fractal)->mlx_data.conn_display, WIDTH, HEIGHT);
	if ((*fractal)->mlx_data.image.img_ptr == NULL)
		terminate_fractal(fractal, ERR_MALLOC_FAIL);
	(*fractal)->mlx_data.image.img_pixels_ptr = mlx_get_data_addr((
				*fractal)->mlx_data.image.img_ptr,
			&(*fractal)->mlx_data.image.bits_per_pixel,
			&(*fractal)->mlx_data.image.size_line,
			&(*fractal)->mlx_data.image.endian);
	if ((*fractal)->mlx_data.image.img_ptr == NULL)
		terminate_fractal(fractal, ERR_MALLOC_FAIL);
	return (0);
}

static int	init_fractal(char **argv, t_fractal **fractal)
{
	init_settings(*fractal);
	init_axes(*fractal);
	init_complex_numbers(*fractal);
	if ((*fractal)->fractol_type == JULIA)
		init_julia_params(*fractal, argv);
	return (0);
}

static enum e_fractal_type	get_fractal_type(int argc, char **argv,
		t_fractal **fractal)
{
	char				*cmpr_str;
	enum e_fractal_type	fractol_type;

	if (argc < 2)
	{
		how_to_use();
		terminate_fractal(fractal, ERR_WRNG_ARGV);
	}
	fractol_type = 0;
	cmpr_str = str_to_lower(argv[1]);
	if (argc == 2 && (str_cmpr(cmpr_str, "mandelbrot") == 0))
		fractol_type = MANDELBROT;
	else if (argc == 2 && (str_cmpr(cmpr_str, "burning_ship") == 0))
		fractol_type = BURNING_SHIP;
	else if ((argc == 4) && (str_cmpr(cmpr_str, "julia") == 0))
		fractol_type = JULIA;
	else
	{
		how_to_use();
		free(cmpr_str);
		terminate_fractal(fractal, ERR_WRNG_ARGV);
	}
	free(cmpr_str);
	return (fractol_type);
}

int	init_data(int argc, char **argv, t_fractal **fractal)
{
	(*fractal) = ft_calloc(1, sizeof(t_fractal));
	if (*fractal == NULL)
		exit(ERR_MALLOC_FAIL);
	(*fractal)->fractol_type = get_fractal_type(argc, argv, fractal);
	init_fractal(argv, fractal);
	init_mlx(fractal);
	define_hooks(*fractal);
	return (OK);
}
