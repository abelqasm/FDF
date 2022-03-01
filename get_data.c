/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:47:15 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/15 15:08:06 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int	ft_get_color(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != 'x')
		str++;
	if (*str == '\0')
		return (0);
	str++;
	return (ft_hexa(str));
}

static int	ft_width(char *file)
{
	int		width_count;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	width_count = 0;
	line = get_next_line(fd);
	width_count = word_count(line, ' ');
	free(line);
	close(fd);
	return (width_count);
}

int	ft_height(char *file)
{
	int		height_count;
	char	*read_file;
	int		fd;

	fd = open(file, O_RDONLY);
	height_count = 0;
	read_file = get_next_line(fd);
	while (read_file)
	{
		height_count++;
		free(read_file);
		read_file = get_next_line(fd);
	}
	free(read_file);
	close(fd);
	return (height_count);
}

static void	ft_fill(int *matrice_line, char	*line, int *color_tab, int width)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(line, ' ');
	while (split[++i] && i < width)
	{
		matrice_line[i] = ft_atoi(split[i]);
		color_tab[i] = ft_get_color(split[i]);
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_get_data(char *file, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = ft_height(file);
	data->width = ft_width(file);
	data->matrice = (int **)malloc(sizeof(int *) * data->height);
	data->color_tab = (int **)malloc(sizeof(int *) * data->height);
	i = -1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->matrice[++i] = malloc(sizeof(int) * data->width);
		data->color_tab[i] = malloc(sizeof(int) * data->width);
		ft_fill(data->matrice[i], line, data->color_tab[i], data->width);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
