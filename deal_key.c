/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:36:42 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/12 21:36:49 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_zoom(int key, t_data *data)
{
	if (key == ZOOM_IN)
	{
		data->zoom++;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	if (key == ZOOM_OUT)
	{
		data->zoom--;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
}

void	ft_move(int key, t_data *data)
{
	if (key == MOVE_LEFT)
	{
		data->start_x -= 100;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	if (key == MOVE_RIGHT)
	{
		data->start_x += 100;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	if (key == MOVE_UP)
	{
		data->start_y -= 100;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	if (key == MOVE_DOWN)
	{
		data->start_y += 100;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
}

void	ft_altitude(int key, t_data *data)
{
	if (key == ALTITUDE_UP)
	{
		data->alt++;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	if (key == ALTITUDE_DOWN)
	{
		data->alt--;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
}

void	ft_translate(t_data *data)
{
	if (data->translate == 0)
	{
		data->translate = 1;
		data->start_x = 700;
		data->start_y = 150;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
	else
	{
		data->translate = 0;
		data->start_x = 700;
		data->start_y = -100;
		mlx_clear_window(data->ptr, data->win);
		ft_draw(data);
	}
}
