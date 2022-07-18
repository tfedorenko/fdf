/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:15 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 20:40:54 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h" 

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 126)
		data->y_offset -= 10;
	else if (key == 125)
		data->y_offset += 10;
	else if (key == 123)
		data->x_offset -= 10;
	else if (key == 124)
		data->x_offset += 10;
	else if (key == 18)
		data->zoom -= 0.5;
	else if (key == 19)
		data->zoom += 0.5;
	else if (key == 1)
		data->scale_z -= 1.1;
	else if (key == 2)
		data->scale_z += 1.1;
	else if (key == 15)
		data->angle += 0.1;
	else if (key == 17)
		data->angle -= 0.1;
	else if (key == 32)
		data->color_flag = 1;
	else if (key == 34)
		data->color_flag = 2;
	else if (key == 35)
		data->color_flag = 3;
	else if (key == 31)
		data->color_flag = 0;
	draw(data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}
