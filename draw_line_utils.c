/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:50:49 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/15 15:24:46 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_draw	ft_change(t_draw *draw)
{
	t_draw	temp;

	temp.x0 = draw->x1;
	temp.x1 = draw->x0;
	temp.y0 = draw->y1;
	temp.y1 = draw->y0;
	return (temp);
}

int	ft_isox(int x, int y)
{
	return (x - y);
}

int	ft_isoy(int x, int y, int z)
{
	return ((x + y) / 2 - z);
}

int	ft_abs(int sum)
{
	if (sum < 0)
		return (-sum);
	return (sum);
}

t_draw	*ft_isometri(t_draw *tab, int z0, int z1, t_data *data)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	if (!draw)
		return (NULL);
	if (data->translate == 1)
	{
		draw->x0 = tab->x0;
		draw->x1 = tab->x1;
		draw->y0 = tab->y0;
		draw->y1 = tab->y1;
		return (draw);
	}
	draw->x0 = ft_isox(tab->x0, tab->y0);
	draw->x1 = ft_isox(tab->x1, tab->y1);
	draw->y0 = ft_isoy(tab->x0, tab->y0, z0 * data->alt);
	draw->y1 = ft_isoy(tab->x1, tab->y1, z1 * data->alt);
	return (draw);
}
