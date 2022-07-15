/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:01:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 18:01:44 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "fdf.h"

void	zoom_ini(t_fdf *data)
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

void	default_state(t_fdf *data)
{
	data->scale_z = 1;
	// data->alpha =  0;
	// data->beta = 0;
	// data->gamma = 0;
	zoom_ini (data);
}
