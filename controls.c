/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:03:46 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/05 17:59:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	b_zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void	b_translate(float *x, float *y, float *x1, float *y1, fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void	b_scale_z(int *z, int *z1, fdf *data)
{
	data->scale_z = 1;
	*z *= data->scale_z;
	*z1 *= data->scale_z;
}
