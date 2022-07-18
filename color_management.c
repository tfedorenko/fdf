/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:00:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 20:38:59 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void color_function(t_fdf *data, int z, int z1)
{
	int color1;
	int color2;
	// if 	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	if (data->color_flag == 0)
	{
		color1 = 0xe80c0c;
		color2 = 0xffffff;
	}
	else if (data->color_flag == 1)
	{
		color1 = 0x8A2BE2;
		color2 = 0xADFF2F;
	}
	else if (data->color_flag == 2)
	{
		color1 = 0xF08080;
		color2 = 0x00FA9A;
	}
	else if (data->color_flag == 3)
	{
		color1 = 0x800080;
		color2 = 0x87CEFA;
	}
	if (z || z1)
		data->color = color1;
	else 
		data->color = color2;
}
