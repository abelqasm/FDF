/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:50:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/10 15:40:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int	draw_line_down(t_draw draw, t_data *data)
{
	draw.dx = draw.x1 - draw.x0;
	draw.dy = draw.y1 - draw.y0;
	draw.next = 1;
	if (draw.dy < 0)
	{
		draw.next = -1;
		draw.dy = -draw.dy;
	}
	draw.index = 2 * draw.dy - draw.dx;
	while (draw.x0 <= draw.x1)
	{
		my_mlx_pixel_put(data->image, draw.x0, draw.y0, data->color);
		draw.x0++;
		if (draw.index > 0)
		{
			draw.y0 = draw.y0 + draw.next;
			draw.index = draw.index + 2 * (draw.dy - draw.dx);
		}
		else
			draw.index = draw.index + 2 * draw.dy;
	}
	return (0);
}

static int	draw_line_up(t_draw draw, t_data *data)
{
	draw.dx = draw.x1 - draw.x0;
	draw.dy = draw.y1 - draw.y0;
	draw.next = 1;
	if (draw.dx < 0)
	{
		draw.next = -1;
		draw.dx = -draw.dx;
	}
	draw.index = 2 * draw.dx - draw.dy;
	while (draw.y0 <= draw.y1)
	{
		my_mlx_pixel_put(data->image, draw.x0, draw.y0, data->color);
		draw.y0++;
		if (draw.index > 0)
		{
			draw.x0 = draw.x0 + draw.next;
			draw.index = draw.index + 2 * (draw.dx - draw.dy);
		}
		else
			draw.index = draw.index + 2 * draw.dx;
	}
	return (0);
}

void	draw_line(t_draw *tab, t_data *data, int z0, int z1)
{
	t_draw	*draw;

	draw = ft_isometri(tab, z0, z1, data);
	if (ft_abs(draw->y1 - draw->y0) < ft_abs(draw->x1 - draw->x0))
	{
		if (draw->x0 > draw->x1)
			draw_line_down(ft_change(draw), data);
		else
			draw_line_down(*draw, data);
	}
	else
	{
		if (draw->y0 > draw->y1)
			draw_line_up(ft_change(draw), data);
		else
			draw_line_up(*draw, data);
	}
	free(draw);
}
