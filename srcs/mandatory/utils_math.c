#include "fractal.h"

/*
 * square_complex:
 * Computes the square of a complex number.
 * z^2 = (x + i*y)^2 = (x^2 - y^2) + i*(2*x*y)
 */
t_complex_nbr square_complex(t_complex_nbr z)
{
    t_complex_nbr result;
    
    result.real_part = pow(z.real_part, 2) - pow(z.imgnry_part, 2);
    result.imgnry_part = 2.0 * z.real_part * z.imgnry_part;
    return result;
}

/*
 * sum_complex:
 * Returns the sum of two complex numbers:
 * z1 + z2 = (x1 + x2) + i*(y1 + y2)
 */
t_complex_nbr sum_complex(t_complex_nbr z1, t_complex_nbr z2)
{
    t_complex_nbr result;
    
    result.real_part = z1.real_part + z2.real_part;
    result.imgnry_part = z1.imgnry_part + z2.imgnry_part;
    return result;
}

/*
 * map_pixel_to_complex_plane:
 * Maps a pixel coordinate (x or y) to the corresponding complex plane value.
 */
double map_pixel_to_complex_plane(int pixel, int max_pixel, double min_val, double max_val)
{
    return min_val + ((max_val - min_val) * pixel) / (double)(max_pixel - 1);
}



/*
 * magnitude_squared_complex:
 * Returns the squared magnitude of a complex number:
 * |z|^2 = x^2 + y^2.
 * Using squared magnitude avoids an expensive sqrt() call.
 */
double magnitude_squared_complex(t_complex_nbr z)
{
    return pow(z.real_part, 2) + pow(z.imgnry_part, 2);
}


/*
 * fractal_iteration:
 * Performs one iteration of the fractal function:
 * z = z^2 + c.
 */
t_complex_nbr fractal_iteration(t_complex_nbr z, t_complex_nbr c)
{
    return sum_complex(square_complex(z), c);
}