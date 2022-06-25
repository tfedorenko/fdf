/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:15:00 by tfedoren          #+#    #+#             */
/*   Updated: 2022/06/25 12:15:00 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a <  0) ? -a : a)

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    int max;

    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
       // mlx_pixel_put(data->mlx_ptr, data->win_prt, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
}

void draw(fdf *data)
{
    int x;
    int y;
    
}