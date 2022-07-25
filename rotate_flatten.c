/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_flatten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:44 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 15:33:55 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	flatten(int *z, int *z1, t_fdf *data)
{
	*z *= data->scale_z;
	*z1 *= data->scale_z;
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(alpha) + *z * sin(alpha);
	*z = -temp_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(beta) + *z * sin(beta);
	*z = -temp_x * sin(beta) + *z * cos(beta);
}
