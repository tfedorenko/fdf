/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:19:30 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/15 17:25:21 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	find_mod(int a)
{
	if (a < 0)
		return (a * (-1));
	else
		return (a);
}
