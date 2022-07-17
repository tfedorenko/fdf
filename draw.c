/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:51 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/17 18:44:56 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

void	isometric_iso(float *x, float *y, int z)
{
	float	*temp;

	temp = x;
	*x = (int)(*x - *y)*cos(0.523599);
	*y = (int)(*temp + *y)*sin(0.525599) - z;
}

void drawing_line (t_fdf *data)
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
		// my_mlx_pixel_put(data, ((int)x_float + data->x_offset),((int)y_float + data->y_offset), data->color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, ((int)x_float + data->x_offset), ((int)y_float + data->y_offset), data->color);
		x_float += x_step;
		y_float += y_step;
	}
}

int x_isometric(float x, float y, t_fdf *data)
{
	int x_iso;
	
	x_iso = (int)((x-y) * cos(data->angle));
	return(x_iso);
}

int y_isometric(float x, float y, int z, t_fdf *data)
{
	int y_iso;
	
	y_iso = (int)((x+y) * sin(data->angle)- z);
	return (y_iso);
}

void make_x_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;

	x1 = x + 1;
	y1 = y;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	b_zoom(&x, &y, &x1, &y1, data);
	b_scale_z(&z, &z1, data);
	data->iso_x = x_isometric(x, y, data);
	data->iso_y = y_isometric(data->iso_x, y, z, data);
	data->iso_x1 = x_isometric(x1, y1, data);
	data->iso_y1 = y_isometric(data->iso_x1, y1, z1, data);
	drawing_line(data);
}

void make_y_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;

	x1 = x;
	y1 = y + 1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	b_zoom(&x, &y, &x1, &y1, data);
	b_scale_z(&z, &z1, data);
	data->iso_x = x_isometric(x, y, data);
	data->iso_y = y_isometric(data->iso_x, y, z, data);
	data->iso_x1 = x_isometric(x1, y1, data);
	data->iso_y1 = y_isometric(data->iso_x1, y1, z1, data);
	drawing_line(data);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	if (data->img_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	}
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, x, y);
}


// void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
// {
// 	float	x_step;
// 	float	y_step;
// 	int		max;
// 	int		z;
// 	int		z1;

// 	z = data->z_matrix[(int)y][(int)x];
// 	z1 = data->z_matrix[(int)y1][(int)x1];

// 	b_zoom(&x, &y, &x1, &y1, data);
// 	b_translate(&x, &y, &x1, &y1, data);
// 	b_scale_z(&z, &z1, data);
// 	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
// 	isometric_iso(&x, &y, z);
// 	isometric_iso(&x1, &y1, z1);
// 	x_step = (int)x1 - x;
// 	y_step = (int)y1 - y;
// 	max = find_max(find_mod(x_step), find_mod(y_step));

// 	x_step /= max;
// 	y_step /= max;

// 	while ((int)(x - x1) || (int)(y - y1))
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x + 450, (int)y + 350, data->color);
// 		// my_mlx_pixel_put(data, (int)x + 450, (int)y + 350, data->color);
// 		x += x_step;
// 		y += y_step;
// 		printf("after pixel put x = %f, y = %f\n", x, y);
// 		// if (x < 0 || y < 0)
// 		// if (x > WIDTH || y > HEIGHT || y < 0)
// 		// 	break;
			
// 		// printf("ami getting out? \n");
// 	}
// }



// void	draw(t_fdf *data)
// {
// 	int	x;
// 	int	y;


// 	// printf("h = %i w = %i\n", data->height, data->width);
// 	if(data->img_ptr)
// 	{
// 		mlx_clear_window(data->mlx_ptr, data->win_ptr);
// 		data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
// 	}
// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			if (x < data->width - 1)
// 				bresenham(x, y, x + 1, y, data);
// 			if (y < data->height - 1)
// 				bresenham(x, y, x, y + 1, data);
// 			x++;
// 			// printf("end of it h = %i  w= %i\n", y, x);
			
// 		}
// 		// printf("im here as well h = %i  w= %i\n", y, x);
// 		y++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, x, y);
// }
