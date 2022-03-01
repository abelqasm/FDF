/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:51:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 16:14:27 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H
# include <mlx.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
// altitude
# define ALTITUDE_UP 126
# define ALTITUDE_DOWN 125
// zoom
# define ZOOM_IN 69
# define ZOOM_OUT 78
// moving
# define MOVE_UP 13
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define MOVE_LEFT 0
// close window
# define CLOSE_WINDOW 53
// translate
# define TRANSLATE 49
// rotation
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123

typedef struct s_draw
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dy;
	int		dx;
	int		index;
	int		next;
	int		i;
	int		j;
}	t_draw;
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;
typedef struct s_data
{
	t_image	*image;
	int		height;
	int		width;
	int		**matrice;
	void	*ptr;
	void	*win;
	int		zoom;
	int		color;
	int		start_x;
	int		start_y;
	int		alt;
	int		translate;
	int		**color_tab;
	float	angle;
}	t_data;
int			ft_atoi(const char *str);
int			word_count(char const *str, char sep);
void		ft_get_data(char *file, t_data *data);
char		**ft_split(char const *s, char c);
void		ft_draw(t_data *data);
int			ft_abs(int sum);
void		ft_dda(t_draw draw, t_data *data, int z0, int z1);
void		draw_line(t_draw *tab, t_data *data, int z0, int z1);
t_draw		ft_change(t_draw *draw);
t_draw		*ft_isometri(t_draw *tab, int z0, int z1, t_data *data);
void		ft_creat_window(char *argv);
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		ft_zoom(int key, t_data *data);
int			ft_exit(void);
void		ft_move(int key, t_data *data);
void		ft_altitude(int key, t_data *data);
void		ft_translate(t_data *data);
int			ft_hexa(char *str);
int			ft_check_fdf(char *str, char *check);
int			ft_height(char *file);
#endif