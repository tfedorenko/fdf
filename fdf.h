/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:55:53 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/02 22:18:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <dlfcn.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

// include minilibx

typedef struct 
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	double	angle;
	int		scale_z;
}	fdf;

int		read_file(char *file_name, fdf *data);
void	draw(fdf *data);
int		get_width(char *file_name);
int		get_height(char *file_name);

int		ft_wdcounter(char const *str, char c);
int		deal_key(int key, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	default_location(float x, float y);

void	b_zoom(float *x, float *y, float *x1, float *y1, fdf *data);
void	b_translate(float *x, float *y, float *x1, float *y1, fdf *data);
void	b_scale_z(int *z, int *z1, fdf *data);
#endif