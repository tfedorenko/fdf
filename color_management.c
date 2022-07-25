/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:00:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 15:34:48 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color1_helper(t_fdf *data)
{
	int	color1;

	color1 = 0xe80c0c;
	if (data->color_flag == 0)
		color1 = 0xe80c0c;
	else if (data->color_flag == 1)
		color1 = 0x8A2BE2;
	else if (data->color_flag == 2)
		color1 = 0xF08080;
	else if (data->color_flag == 3)
		color1 = 0x800080;
	return (color1);
}

static int	color2_helper(t_fdf *data)
{
	int	color2;

	color2 = 0xffffff;
	if (data->color_flag == 0)
		color2 = 0xffffff;
	else if (data->color_flag == 1)
		color2 = 0xADFF2F;
	else if (data->color_flag == 2)
		color2 = 0x00FA9A;
	else if (data->color_flag == 3)
		color2 = 0x87CEFA;
	return (color2);
}

void	color_function(t_fdf *data, int z, int z1)
{
	if (z || z1)
		data->color = color1_helper(data);
	else
		data->color = color2_helper(data);
}
