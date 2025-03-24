#include "fractal.h"

int main(int argc, char **argv)
{
    t_fractal   *fractal;

    init_data(argc, argv, &fractal);

    paint_fractal(fractal);
    
    
}