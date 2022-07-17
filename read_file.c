/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:21 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/17 17:11:47 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */









#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	height = 0;
	while (get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return (height);
}

int	wd_counter(char *line)
{
	// int	count;
	// int	i;
	// int	flag;

	// count = 0;
	// i = 0;
	// flag = 0;
	// while (line[i])
	// {
	// 	if ((line[i] >= '0' && line[i] <= '9') && flag == 0)
	// 	{
	// 		count++;
	// 		flag = 1;
	// 	}
	// 	else
	// 		flag = 0;
	// 	i++;
	// }
	// return (count);

	int counter;
	int	i;
	
	counter = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != 32 && (line[i+1] == 32 || line[i+1] == '\0' || line[i+1] == '\n'))
			counter++;
		i++;
	}
	return(counter);
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
	ft_strtrim(line, " ");
	width = wd_counter(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
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
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + data->width));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	// data->z_matrix[i] = NULL;
	return (0);
}
