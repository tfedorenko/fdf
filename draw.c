/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:51 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 17:35:37 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawing_line(t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	x_float;
	float	y_float;
	int		max;

	x_float = (float) data->iso_x;
	y_float = (float) data->iso_y;
	x_step = data->iso_x1 - x_float;
	y_step = data->iso_y1 - y_float;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= (float)max;
	y_step /= (float)max;
	while ((int)(x_float - data->iso_x1) || (int)(y_float - data->iso_y1))
	{
		my_mlx_pixel_put(&data->img, ((int)x_float + data->x_offset), \
			((int)y_float + data->y_offset), data->color);
		x_float += x_step;
		y_float += y_step;
	}
}

static void	make_x_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;

	x1 = x + 1;
	y1 = y;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	color_function(data, z, z1);
	x = (int)(x * data->zoom);
	y = (int)(y * data->zoom);
	x1 = (int)(x1 * data->zoom);
	y1 = (int)(y1 * data->zoom);
	flatten(&z, &z1, data);
	rotate_x(&y, &z, data->alpha);
	rotate_x(&y1, &z1, data->alpha);
	rotate_y(&x, &y, data->beta);
	rotate_y(&x1, &y1, data->beta);
	x_y_isometric_helper(x, y, z, data);
	x1_y1_isometric_helper(x1, y1, z1, data);
	drawing_line(data);
}

static void	make_y_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;

	x1 = x;
	y1 = y + 1;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	color_function(data, z, z1);
	x = (int)(x * data->zoom);
	y = (int)(y * data->zoom);
	x1 = (int)(x1 * data->zoom);
	y1 = (int)(y1 * data->zoom);
	flatten(&z, &z1, data);
	rotate_x(&y, &z, data->alpha);
	rotate_x(&y1, &z1, data->alpha);
	rotate_y(&x, &y, data->beta);
	rotate_y(&x1, &y1, data->beta);
	x_y_isometric_helper(x, y, z, data);
	x1_y1_isometric_helper(x1, y1, z1, data);
	drawing_line(data);
}

static void	draw_helper(t_fdf *data)
{
	if (data->img.img_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.mlx_img_addr = mlx_get_data_addr(data->img.img_ptr, \
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	draw_helper(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				make_x_isometric(x, y, data);
			if (y < data->height - 1)
				make_y_isometric(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.img_ptr, 0, 0);
}
