/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 15:04:39 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_ini(t_fdf *data)
{
	if (data->height >= 500 || data->width >= 500)
		data->zoom = 1;
	else if ((data->height >= 250) || data->width >= 250)
		data->zoom = 2;
	else if ((data->height >= 150) || data->width >= 150)
		data->zoom = 3;
	else if ((data->height >= 100) || data->width >= 100)
		data->zoom = 6;
	else if (data->height <= 20 || data->width <= 20)
		data->zoom = 30;
}

void	default_state(t_fdf *data)
{
	data->scale_z = 1;
	// data->alpha =  0;
	// data->beta = 0;
	// data->gamma = 0;
	data->angle = 0.53;
	data->mlx_ptr = NULL;
	data->img.mlx_img_addr = NULL;
	data->img.img_ptr = NULL;
	data->win_ptr = NULL;
	data->img.bits_per_pixel = 0;
	data->img.line_len = 0;
	data->img.endian = 0;
	zoom_ini (data);
	data->x_offset = WIDTH / 2 - WIDTH / (2 * (int)data->zoom);
	data->y_offset = HEIGHT / 2 - HEIGHT / (2 * (int)data->zoom);
}

void mlx_ini(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	// printf("Whaaat Wid/th %d Height %d\n\n", WIDTH, HEIGHT);
	// perror("Zium");
}
