/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:50:22 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/13 17:58:45 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_check_fdf(argv[1], ".fdf") == 0
		|| ft_height(argv[1]) == 0 || fd == -1)
	{
		close(fd);
		perror("the argument is invalid");
	}
	else
		ft_creat_window(argv[1]);
	return (0);
}
