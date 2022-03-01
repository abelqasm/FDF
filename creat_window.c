/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:52:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/24 00:26:03 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	deal_key(int key, t_data *data)
{
	if (key == CLOSE_WINDOW)
		ft_exit();
	if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom(key, data);
	if (key == MOVE_LEFT || key == MOVE_DOWN
		|| key == MOVE_RIGHT || key == MOVE_UP)
		ft_move(key, data);
	if (key == ALTITUDE_UP || key == ALTITUDE_DOWN)
		ft_altitude(key, data);
	if (key == TRANSLATE)
		ft_translate(data);
	return (0);
}

static int	ft_get_zoom(t_data *data)
{
	if (data->height > 200 || data->width > 200)
		return (2);
	if (data->height > 150 || data->width > 150)
		return (3);
	if (data->height > 90 || data->width > 90)
		return (6);
	if (data->height > 50 || data->width > 50)
		return (10);
	if (data->height > 20 || data->width > 20)
		return (13);
	return (20);
}

static int	ft_get_altitude(t_data *data)
{
	if (data->height > 150 || data->width > 150)
		return (1);
	if (data->height > 90 || data->width > 90)
		return (2);
	if (data->height > 70 || data->width > 70)
		return (5);
	if (data->height > 50 || data->width > 50)
		return (7);
	if (data->height > 30 || data->width > 30)
		return (5);
	if (data->height > 10 || data->width > 10)
		return (2);
	return (1);
}

void	ft_creat_window(char *argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_get_data(argv, data);
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, 2200, 1200, "fdf");
	data->zoom = ft_get_zoom(data);
	data->alt = ft_get_altitude(data);
	data->start_x = 700;
	data->start_y = -100;
	data->translate = 0;
	ft_draw(data);
	printf("%d\n%d\n", data->height, data->width);
	mlx_key_hook(data->win, deal_key, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->ptr);
}
