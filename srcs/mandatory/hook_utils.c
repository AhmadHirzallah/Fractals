#include "fractal.h"

void	shift_any(t_fractal *fractal, enum	e_shifting_director shift)
{
	double	shift_of_x;
	double	shift_of_y;

	shift_of_x = (fractal->axises.x_pos_axis - fractal->axises.x_neg_axis) / fractal->settings_fractal.shift_factor;
	shift_of_y = (fractal->axises.y_pos_axis - fractal->axises.y_neg_axis) / fractal->settings_fractal.shift_factor;
	if (shift == SHIFT_DOWNWARD)
	{
		fractal->axises.y_neg_axis -= shift_of_y;
		fractal->axises.y_pos_axis -= shift_of_y;
	}
	else if(shift == SHIFT_UPWARD)
	{
		fractal->axises.y_neg_axis += shift_of_y;
		fractal->axises.y_pos_axis += shift_of_y;
	}
	else if (shift == SHIFT_TOLEFT)
	{
		fractal->axises.x_pos_axis -= shift_of_x;
		fractal->axises.x_neg_axis -= shift_of_x;
	}
	else if (shift == SHIFT_TORIGHT)
	{
		fractal->axises.x_pos_axis += shift_of_x;
		fractal->axises.x_neg_axis += shift_of_x;
	}
}


/*
 * ft_perform_zoom:
 * Adjusts the fractal's axis ranges (zooming in or out) based on a mouse click.
 * - (x, y) are the pixel coordinates of the mouse event.
 * - zoom_dir indicates whether we are zooming in or out.
 * - The function maps the pixel to the complex plane (x_new, y_new),
 *   then updates x_neg_axis, x_pos_axis, y_neg_axis, and y_pos_axis accordingly.
 */
void perform_zoom(t_fractal *fractal, int x, int y, enum e_shifting_director zoom_dir)
{
    double x_new;
    double y_new;

    x_new = map_pixel_to_complex_plane(x, WIDTH,
                                       fractal->axises.x_neg_axis, fractal->axises.x_pos_axis);
    y_new = map_pixel_to_complex_plane(y, HEIGHT,
                                       fractal->axises.y_pos_axis, fractal->axises.y_neg_axis);
    if (zoom_dir == ZOOM_IN)
    {
        fractal->axises.x_neg_axis = x_new - (x_new - fractal->axises.x_neg_axis) / ZOOM_FACTOR;
        fractal->axises.x_pos_axis = x_new + (fractal->axises.x_pos_axis - x_new) / ZOOM_FACTOR;
        fractal->axises.y_neg_axis = y_new - (y_new - fractal->axises.y_neg_axis) / ZOOM_FACTOR;
        fractal->axises.y_pos_axis = y_new + (fractal->axises.y_pos_axis - y_new) / ZOOM_FACTOR;
    }
    else if (zoom_dir == ZOOM_OUT)
    {
        fractal->axises.x_neg_axis = x_new - (x_new - fractal->axises.x_neg_axis) * ZOOM_FACTOR;
        fractal->axises.x_pos_axis = x_new + (fractal->axises.x_pos_axis - x_new) * ZOOM_FACTOR;
        fractal->axises.y_neg_axis = y_new - (y_new - fractal->axises.y_neg_axis) * ZOOM_FACTOR;
        fractal->axises.y_pos_axis = y_new + (fractal->axises.y_pos_axis - y_new) * ZOOM_FACTOR;
    }
}


// void	zoom_in(t_fractal *fractal, int dir)
// {
// 	double	mouse_x;
// 	double	mouse_y;

// 	mouse_x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
// 	mouse_y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
// 	data->xl1 = mouse_x - (mouse_x - data->xl1) / ZOOM;
// 	data->xl2 = mouse_x + (data->xl2 - mouse_x) / ZOOM;
// 	data->yl1 = mouse_y - (mouse_y - data->yl1) / ZOOM;
// 	data->yl2 = mouse_y + (data->yl2 - mouse_y) / ZOOM;
// }

// void	zoom_out(t_fractal *fractal, int dir)
// {
// 	double	mouse_x;
// 	double	mouse_y;

// 	mouse_x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
// 	mouse_y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
// 	data->xl1 = mouse_x - (mouse_x - data->xl1) * ZOOM;
// 	data->xl2 = mouse_x + (data->xl2 - mouse_x) * ZOOM;
// 	data->yl1 = mouse_y - (mouse_y - data->yl1) * ZOOM;
// 	data->yl2 = mouse_y + (data->yl2 - mouse_y) * ZOOM;
// }
