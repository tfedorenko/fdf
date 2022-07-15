/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_translate_flatten.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:44 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 18:02:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

void	b_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void	b_translate(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void	b_scale_z(int *z, int *z1, t_fdf *data)
{
	*z *= data->scale_z;
	*z1 *= data->scale_z;
}
