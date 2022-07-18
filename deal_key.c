/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:15 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 15:09:31 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h" 

int	deal_key(int key, t_fdf *data)
{
	// ft_printf("%d\n", key);
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
		data->scale_z -= 1.5;
	else if (key == 2)
		data->scale_z += 1.5;
	draw(data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}
