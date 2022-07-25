/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:51:16 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 15:42:47 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	x_isometric(float x, float y)
{
	int	x_iso;

	x_iso = (int)((x - y) * cos(0.523599));
	return (x_iso);
}

static int	y_isometric(float x, float y, int z)
{
	int	y_iso;

	y_iso = (int)((x + y) * sin(0.523599) - z);
	return (y_iso);
}

void	x_y_isometric_helper(int x, int y, int z, t_fdf *data)
{
	data->iso_x = x_isometric(x, y);
	data->iso_y = y_isometric(data->iso_x, y, z);
}

void	x1_y1_isometric_helper(int x1, int y1, int z1, t_fdf *data)
{
	
	data->iso_x1 = x_isometric(x1, y1);
	data->iso_y1 = y_isometric(data->iso_x1, y1, z1);
}
