/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:10 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/17 18:29:32 by tfedoren         ###   ########.fr       */
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
	default_state(data);	
	// check = read_file(argv[1], data);
	// if (check == -1)
	// {
	// 	ft_printf("Error\n");
	// 	return (1);
	// }	
	mlx_ini(data);
	draw (data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
