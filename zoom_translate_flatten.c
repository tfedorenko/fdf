/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_translate_flatten.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:44 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/17 18:50:50 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

// void	b_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
void	b_zoom(int *x, int *y, int *x1, int *y1, t_fdf *data)
{
	*x = (int)(*x * data->zoom);
	*y = (int)(*y * data->zoom);
	*x1 = (int)(*x1 * data->zoom);
	*y1 = (int)(*y1 * data->zoom);
	// *y *= data->zoom;
	// *x1 *= data->zoom;
	// *y1 *= data->zoom;
}

// void	b_translate(float *x, float *y, float *x1, float *y1, t_fdf *data)
// void	b_translate(int *x, int *y, int *x1, int *y1, t_fdf *data)
// {
// 	*x += data->x_offset;
// 	*y += data->y_offset;
// 	*x1 += data->x_offset;
// 	*y1 += data->y_offset;
// }

void	b_scale_z(int *z, int *z1, t_fdf *data)
{
	*z *= data->scale_z;
	*z1 *= data->scale_z;
}
