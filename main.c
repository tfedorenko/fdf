/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:10 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 20:26:05 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		check;

	
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	check = read_file(argv[1], data);
	if (check == -1)
	{
		ft_printf("Error\n");
		return (1);
	}			
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	// data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, data->x, data->y);
	// printf("i'm here\n");
	// data->mlx_img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->width-1, 0);
	printf("i'm here\n");
	default_state(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
