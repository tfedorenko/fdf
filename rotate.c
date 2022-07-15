/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:22:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/15 17:23:07 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, int *z, double alpha)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(alpha) + *z * sin(alpha);
	*z = -temp_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, int *z, double beta)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(beta) + *z * sin(beta);
	*z = -temp_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(gamma) - temp_y * sin(gamma);
	*y = temp_x * sin(gamma) + temp_y * cos(gamma);
}
