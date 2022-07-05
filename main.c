/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/05 17:58:53 by stena-he         ###   ########.fr       */
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
	if (key == 18)
		data->zoom -= 5;
	if (key == 19)
		data->zoom += 5;
	if (key == 15)
		data->angle += 0.1;
	if (key == 17)
		data->angle -= 0.1;
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

void	zoom_ini(fdf *data)
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

int	main(int argc, char **argv)
{
	fdf	*data;
	int	check;

	if (argc != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	data = (fdf *)malloc(sizeof(fdf));
	check = read_file(argv[1], data);
	if (check == -1)
	{
		ft_printf("Error\n");
		return (1);
	}			
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	zoom_ini (data);
	ft_printf("data->weight=%d\n", data->width);
	ft_printf("data->height=%d\n", data->height);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
