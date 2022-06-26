/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/06/26 19:37:57 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf *data)
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

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	// ft_printf("I'm here0\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	draw(data);
	// bresenham(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	// int i;
	// int j;


	// i = 0;
	// while(i < data->height)
	// {
	// 	j = 0;
	// 	while (j < data->width)
	// 	{
	// 		ft_printf("%d ", data->z_matrix[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
}
