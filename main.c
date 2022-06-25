/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/06/22 11:02:19 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void *data)
{
	ft_printf("%d", key);
	return(0);
}

int	main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));

	read_file(argv[1], data);
	
	int i;
	int j;


	i = 0;
	while(i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}


}