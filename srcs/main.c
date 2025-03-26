/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:26:20 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 17:26:32 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	init_data(argc, argv, &fractal);
	paint_fractal(fractal);
	return (0);
}
