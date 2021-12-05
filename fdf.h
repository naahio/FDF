/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:11:35 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/05 13:31:37 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# define BUFFER_SIZE 1000
# define WIDTH_F 1080
# define HEIGHT_F 768
# define DEF_ROTATION 0.523599
# define DEF_SCOOP 10
# define ZOOM_IN_ACT "*ZOOME IN    : i"
# define ZOOM_OUT_ACT "*ZOOME OUT   : o"
# define UP_ACT "*UP          : +"
# define DOWN_ACT "*DOWN        : -"
# define MOVE_LEFT_ACT "*MOVE_LEFT   : left_arrow"
# define MOVE_RIGHT_ACT "*MOVE_RIGHT  : right_arrow"
# define MOVE_UP_ACT "*MOVE_UP      : up_arrow"
# define MOVE_DOWN_ACT "*MOVE_DOWN   : down_arrow"
# define ROTATE_ACT "*ROTATE      : r"
# define EXIT_ACT "*EXIT        : esc"

typedef struct s_fdf
{
	void	*img_ptr;
	void	*mlx_ptr;
	void	*win_prt;
	int		color;
	int		scoop;
	int		**matrice;
	char	**char_matrice;
	float	rotation;
	int		size;
	int		h;
	int		w;
	int		high;
	int		move_x;
	int		move_y;
	int		x1;
	int		y1;
}t_fdf;

typedef struct s_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	z;
	int	z1;
}t_param;

void	draw(t_fdf *data);
void	isometric(int *x, int *y, int z, t_fdf *data);
void	bresen(int x0, int y0, t_fdf *data);
int		get_color(char *split);
void	conv_int(char **matrice, t_fdf *data);
char	**get_matrice(int fd);
int		matrice_size(char **matrice);
int		key_event_bonus(int key, t_fdf **param);
int		key_handel(int key, t_fdf **param);
t_fdf	*init_data(int fd);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
void	load_info(t_fdf *data);
#endif