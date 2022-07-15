/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:15:00 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 15:28:15 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a <  0) ? -a : a)

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	find_mod(int a)
{
	if (a < 0)
		return (a * (-1));
	else
		return (a);
}


void	isometric(float *x, float *y, int z)
{
	float	*temp;

	temp = x;
	*x = (int)(*x - *y)*cos(0.523599);
	*y = (int)(*temp + *y)*sin(0.525599) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	b_zoom(&x, &y, &x1, &y1, data);
	// b_translate(&x, &y, &x1, &y1, data);
	// b_scale_z(&z, &z1, data);
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x_step = (int)x1 - x;
	y_step = (int)y1 - y;
	// max = find_max(find_mod(x_step), find_mod(y_step));
	max = MAX1(MOD(x_step), MOD(y_step));

	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + 450, y + 350, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	data->img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, x, y);
}
