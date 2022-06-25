/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:55:53 by tfedoren          #+#    #+#             */
/*   Updated: 2022/06/22 10:55:53 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <fcntl.h>
#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>


// include minilibx

typedef struct
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int collor;

    void *mlx_ptr;
    void *win_ptr;
}   fdf;

void read_file(char *file_name, fdf *data);

#endif