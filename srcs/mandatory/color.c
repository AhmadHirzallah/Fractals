#include <math.h>
#include "fractal.h"   // Contains t_fractal, t_complex_nbr, etc.
#include "mlx.h"       // Your MLX library header
#include <stdlib.h>

/*
 * get_plasma_palette
 *
 * Dynamically allocates and returns a pointer to a plasma-style palette.
 * The palette contains 7 colors and each color is initialized on its own line.
 * The caller must free the returned memory.
 */
unsigned int *get_plasma_palette(void)
{
    static unsigned int palette[7];
    
    palette[0] = 0x0D0887;  /* dark indigo */
    palette[1] = 0x5B02A3;  /* deep violet */
    palette[2] = 0x9E02B8;  /* rich magenta */
    palette[3] = 0xD1308F;  /* vibrant fuchsia */
    palette[4] = 0xF17560;  /* warm orange */
    palette[5] = 0xF9B12F;  /* golden yellow */
    palette[6] = 0xF0F921;  /* pale cream */
    
    return (palette);
}


/*
 * normalized_iteration
 *
 * Normalize the iteration count using logarithmic scaling.
 */
double normalized_iteration(double iteration, double max_iteration)
{
    double t;

    t = iteration / max_iteration;
    t = log1p(t * 9.0) / log1p(9.0);
    return (t);
}

/*
 * interpolate_color
 *
 * Interpolates between two 0xRRGGBB colors using parameter t in [0,1].
 */
unsigned int interpolate_color(double t, unsigned int color1, unsigned int color2)
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int result;

    r = (unsigned int)(((1.0 - t) * ((color1 >> 16) & 0xFF))
         + (t * ((color2 >> 16) & 0xFF)));
    g = (unsigned int)(((1.0 - t) * ((color1 >> 8) & 0xFF))
         + (t * ((color2 >> 8) & 0xFF)));
    b = (unsigned int)(((1.0 - t) * (color1 & 0xFF))
         + (t * (color2 & 0xFF)));
    result = (r << 16) | (g << 8) | b;
    return (result);
}

/*
 * generate_color
 *
 * Generates a color using the given palette.
 * The iteration count is normalized (with fixed sharpness = 256) and mapped to a palette index.
 */
unsigned int generate_color(double iteration, double max_iteration,
                            const unsigned int palette[], int num_colors)
{
    double norm;
    double palette_pos;
    int idx;
    double frac;
    unsigned int result;

    norm = normalized_iteration(iteration, max_iteration);
    palette_pos = norm * (num_colors - 1);
    idx = (int) palette_pos;
    if (idx >= num_colors - 1)
    {
        result = palette[num_colors - 1];
    }
    else
    {
        frac = palette_pos - idx;
        result = interpolate_color(frac, palette[idx], palette[idx + 1]);
    }
    return (result);
}


/*
 * put_pixel
 *
 * Draws a pixel at coordinates (x, y) on the given image with the specified color.
 * The function assumes that the image's data address, line length, and bits per pixel
 * have been set up by a prior call to mlx_get_data_addr.
 * - If the point does not escape within the maximum number of iterations (i.e., i reaches iterations_depth),
 *      it is considered inside the fractal and is colored black (or the default color):
 * - Once a point is determined to have escaped (i.e., the magnitude exceeds the escape threshold),
 *      the corresponding pixel is colored. The number of iterations (i) it took for z to escape is used to generate the color.

c
Copy

 */
void put_pixel(int x, int y, t_img *img, int color)
{
    char *dst;

    dst = img->img_pixels_ptr + y * img->size_line + x * (img->bits_per_pixel / 8);
    *(unsigned int *)dst = color;
}
