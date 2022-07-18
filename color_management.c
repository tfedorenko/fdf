/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:00:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/18 20:30:14 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void color_function(t_fdf *data, int z, int z1)
{
	// if 	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	// if (color_flag)
	if (z || z1)
		data->color = 0xe80c0c;
	else 
		data->color = 0xffffff;
}
