/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 20:15:59 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

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

void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char *dst;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		dst = img_data->mlx_img_addr + (y * img_data->line_len + x * (img_data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}

	
	// char	*dst;

	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int*)dst = color;
}

int x_close(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(1);
}
