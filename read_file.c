/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:21 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 18:20:54 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	wd_counter(char *line)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != 32 && (line[i + 1] == 32 || \
			line[i + 1] == '\0' || line[i + 1] == '\n'))
			counter++;
		i++;
	}
	return (counter);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	width = wd_counter(line);
	while (line)
	{	
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	printf("\n");
	free(nums);
}

int	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height <= 1 || data->width <= 1)
		return (-1);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * \
			(data->width));
	//z_matirx[0][] = width * height
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}
