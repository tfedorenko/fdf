/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:15 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 18:01:16 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h" 

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 18)
		data->zoom -= 5;
	if (key == 19)
		data->zoom += 5;
	if (key == 1)
		data->scale_z -= 1.1;
	if (key == 2)
		data->scale_z += 1.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}