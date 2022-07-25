/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:15 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 17:33:25 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

static void	offset_key(int key, t_fdf *data)
{
	if (key == 126)
		data->y_offset -= 10;
	else if (key == 125)
		data->y_offset += 10;
	else if (key == 123)
		data->x_offset -= 10;
	else if (key == 124)
		data->x_offset += 10;
}

static void	rotation_key(int key, t_fdf *data)
{
	if (key == 15)
		data->alpha += 0.1;
	else if (key == 17)
		data->alpha -= 0.1;
	else if (key == 3)
		data->beta += 0.1;
	else if (key == 5)
		data->beta -= 0.1;
}

static void	color_key(int key, t_fdf *data)
{
	if (key == 32)
		data->color_flag = 1;
	else if (key == 34)
		data->color_flag = 2;
	else if (key == 35)
		data->color_flag = 3;
	else if (key == 31)
		data->color_flag = 0;
}

static void	zoom_flatten_key(int key, t_fdf *data)
{
	if (key == 18)
		data->zoom -= 0.5;
	else if (key == 19)
		data->zoom += 0.5;
	else if (key == 1)
		data->scale_z -= 1.1;
	else if (key == 2)
		data->scale_z += 1.1;
}

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	offset_key(key, data);
	rotation_key(key, data);
	color_key(key, data);
	zoom_flatten_key(key, data);
	draw(data);
	if (key == 29)
		data->isometric_flag *= 0;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}
