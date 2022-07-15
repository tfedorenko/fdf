/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 17:31:13 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	printf("i'm here\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	default_state(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
