/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:34:08 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:42:55 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define ITER_DEPTH 30
# define ZOOM_FACTOR 1.30
# define SHIFT_FACTOR 5.30
# define ESCAPE_RADIUS 2.0
// # define WIDTH 1000
// # define HEIGHT 800
# define WIDTH 500
# define HEIGHT 500

// # define WIDTH 1400
// # define HEIGHT 1200
// # define X_MIN -2.5
// # define X_MAX 1.0
// # define Y_MIN -1.5
// # define Y_MAX 1.5

# define NUM_COLORS 10

enum					e_shifting_director
{
	SHIFT_UPWARD,
	SHIFT_DOWNWARD,
	SHIFT_TORIGHT,
	SHIFT_TOLEFT,
	ZOOM_IN,
	ZOOM_OUT
};

enum					e_fract_rtrns
{
	OK,
	ERR_WRNG_ARGV,
	ERR_MALLOC_FAIL
};

typedef struct s_img
{
	void				*img_ptr;
	char				*img_pixels_ptr;
	int					bits_per_pixel;
	int					endian;
	int					size_line;
}						t_img;

typedef struct s_complex_nbr
{
	double				real_part;
	double				imgnry_part;
}						t_complex_nbr;

typedef struct s_axises
{
	double				x_pos_axis;
	double				x_neg_axis;
	double				y_pos_axis;
	double				y_neg_axis;
}						t_axises;

enum					e_fractal_type
{
	JULIA,
	MANDELBROT,
	BURNING_SHIP
};

typedef struct s_mlx_data
{
	void				*conn_display;
	void				*window;
	char				*title_window;
	t_img				image;

}						t_mlx_data;

typedef struct s_fractal_settings
{
	double				escape_val;
	double				zoom_factor;
	int					iterations_depth;
	double				shift_factor;
}						t_fractal_settings;

typedef struct s_fractal
{
	t_mlx_data			mlx_data;
	t_complex_nbr		z;
	t_complex_nbr		c;
	enum e_fractal_type	fractol_type;
	t_axises			axises;
	t_fractal_settings	settings_fractal;
}						t_fractal;

int						init_data(int argc, char **argv, t_fractal **fractal);
char					*get_title_name(t_fractal *fractal);
void					terminate_mlx(t_fractal *fractal);
void					define_hooks(t_fractal *fractal);
double					magnitude_squared_complex(t_complex_nbr z);
double					magnitude_squared_complex(t_complex_nbr z);
double					map_pixel_to_complex_plane(int pixel, int max_pixel,
							double min_val, double max_val);
t_complex_nbr			sum_complex(t_complex_nbr z1, t_complex_nbr z2);
t_complex_nbr			square_complex(t_complex_nbr z);
int						create_trgb(int t, int r, int g, int b);
void					put_pixel(int x, int y, t_img *img, int color);
int						paint_fractal(t_fractal *fractal);
double					normalized_iteration(double iteration,
							double maxIteration);
unsigned int			interpolate_color(double t, unsigned int color1,
							unsigned int color2);
unsigned int			*get_plasma_palette(void);
int						render_a_fractal(t_fractal *fractal, int x, int y,
							const unsigned int *palette);
unsigned int			generate_color(double iteration, double max_iteration,
							const unsigned int palette[], int num_colors);
void					terminate_fractal(t_fractal **fractal,
							enum e_fract_rtrns exit_code);
void					how_to_use(void);
t_complex_nbr			fractal_iteration(t_complex_nbr z, t_complex_nbr c,
							enum e_fractal_type fractol_type);
void					define_hooks(t_fractal *fractal);
void					shift_any(t_fractal *fractal,
							enum e_shifting_director shift);
void					perform_zoom(t_fractal *fractal, int x, int y,
							enum e_shifting_director zoom);
void					get_shift_factors(const t_fractal *fractal,
							double *shift_x, double *shift_y);
void					shift_axis(double *axis_min, double *axis_max,
							double delta);
void					update_axis_zoom_in(double *axis_min, double *axis_max,
							double center, double factor);
void					update_axis_zoom_out(double *axis_min, double *axis_max,
							double center, double factor);
void					get_shift_factors(const t_fractal *fractal,
							double *shift_x, double *shift_y);
void					shift_axis(double *axis_min, double *axis_max,
							double delta);
void					update_axis_zoom_in(double *axis_min, double *axis_max,
							double center, double factor);
void					update_axis_zoom_out(double *axis_min, double *axis_max,
							double center, double factor);
void					init_settings(t_fractal *fractal);
void					init_axes(t_fractal *fractal);
void					init_complex_numbers(t_fractal *fractal);
void					init_julia_params(t_fractal *fractal, char **argv);
#endif
