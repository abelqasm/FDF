/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:08:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/12 22:28:46 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int	ft_color(int color, int z)
{
	if (color != 0)
		return (color);
	if (z != 0)
		return (0x0000FF00);
	return (0x000000FF);
}

static void	ft_draw_height(t_data *data)
{
	t_draw	*tab;

	tab = malloc(sizeof(t_draw));
	tab->i = 0;
	tab->y0 = data->start_y;
	while (tab->y0 < data->height * data->zoom + data->start_y)
	{
		tab->j = 0;
		tab->x0 = data->start_x;
		tab->y1 = tab->y0;
		while (tab->x0 + data->zoom < data->width * data->zoom + data->start_x)
		{
			data->color = ft_color(data->color_tab[tab->i][tab->j],
					data->matrice[tab->i][tab->j]);
			tab->x1 = tab->x0 + data->zoom;
			draw_line(tab, data,
				data->matrice[tab->i][tab->j],
				data->matrice[tab->i][tab->j + 1]);
			tab->x0 += data->zoom;
			tab->j++;
		}
		tab->i++;
		tab->y0 += data->zoom;
	}
	free(tab);
}

static void	ft_draw_width(t_data *data)
{
	t_draw	*tab;

	tab = malloc(sizeof(t_draw));
	tab->j = 0;
	tab->x0 = data->start_x;
	while (tab->x0 < data->width * data->zoom + data->start_x)
	{
		tab->i = 0;
		tab->y0 = data->start_y;
		tab->x1 = tab->x0;
		while (tab->y0 + data->zoom < data->height * data->zoom + data->start_y)
		{
			data->color = ft_color(data->color_tab[tab->i][tab->j],
					data->matrice[tab->i][tab->j]);
			tab->y1 = tab->y0 + data->zoom;
			draw_line(tab, data,
				data->matrice[tab->i][tab->j],
				data->matrice[tab->i + 1][tab->j]);
			tab->y0 += data->zoom;
			tab->i++;
		}
		tab->j++;
		tab->x0 += data->zoom;
	}
	free(tab);
}

static void	ft_string_put(t_data *data)
{
	mlx_string_put(data->ptr, data->win, 10, 10, 0x00FF0000,
		"Move through : A,D,W,S");
	mlx_string_put(data->ptr, data->win, 10, 40, 0x00FF0000,
		"Zoom : + / -");
	mlx_string_put(data->ptr, data->win, 10, 70, 0x00FF0000,
		"Altitude : Up / Down");
	mlx_string_put(data->ptr, data->win, 10, 100, 0x00FF0000,
		"Translate map : Space");
}

void	ft_draw(t_data *data)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->img = mlx_new_image(data->ptr, 2200, 1200);
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	data->image = image;
	ft_draw_height(data);
	ft_draw_width(data);
	mlx_put_image_to_window(data->ptr, data->win, image->img, 0, 0);
	ft_string_put(data);
	free(image);
}
