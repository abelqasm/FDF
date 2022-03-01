/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:16:13 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/10 22:40:54 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 2200 && y < 1200 && y >= 0)
	{
		dst = image->addr + (y * image->line_length
				+ x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
