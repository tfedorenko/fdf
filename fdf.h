/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:02 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/15 18:02:03 by tfedoren         ###   ########.fr       */
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

typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
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
	int		scale_z;
	int		angle_thingy;
	double	alpha;
	double	gamma;
	double	beta;

}	t_fdf;

int		find_max(int a, int b);
int		find_mod(int a);
void	default_state(t_fdf *data);
int		read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
int		get_width(char *file_name);
int		get_height(char *file_name);

int		ft_wdcounter(char const *str, char c);
int		deal_key(int key, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	default_location(float x, float y);

void	b_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data);
void	b_translate(float *x, float *y, float *x1, float *y1, t_fdf *data);
void	b_scale_z(int *z, int *z1, t_fdf *data);
#endif