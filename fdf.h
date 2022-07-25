/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:02 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 15:35:32 by tfedoren         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000

// include minilibx
typedef struct s_img_data
{
	void	*img_ptr;
	char	*mlx_img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img_data;

typedef struct s_fdf
{
	float		x;
	float		y;
	float		z;
	int			width;
	int			height;
	int			**z_matrix;
	float		zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	void		*mlx_ptr;
	void		*win_ptr;
	int			scale_z;
	double		angle;
	double		alpha;
	double		gamma;
	double		beta;
	int			x_offset;
	int			y_offset;
	int			iso_x;
	int			iso_y;
	int			iso_x1;
	int			iso_y1;
	int			color_flag;
	int			color1;
	int			color2;
	int			isometric_flag;
	t_img_data	img;
}	t_fdf;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	mlx_ini(t_fdf *data);
int		find_max(int a, int b);
int		find_mod(int a);
void	default_state(t_fdf *data);
int		read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
int		get_width(char *file_name);
int		get_height(char *file_name);
int		ft_wdcounter(char const *str, char c);
int		deal_key(int key, t_fdf *data);
void	flatten(int *z, int *z1, t_fdf *data);
int		x_close(t_fdf *data);
void	color_function(t_fdf *data, int z, int z1);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	x_y_isometric_helper(int x, int y, int z, t_fdf *data);
void	x1_y1_isometric_helper(int x1, int y1, int z1, t_fdf *data);
#endif