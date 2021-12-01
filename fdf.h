/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:11:35 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 17:54:03 by mbabela          ###   ########.fr       */
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
# include "libft/libft.h"
# define BUFFER_SIZE 1000
typedef struct s_fdf
{
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
int		key_event(int key, t_fdf **param);
void	conv_int(char **matrice, t_fdf *data);
char	**get_matrice(int fd);
int		matrice_size(char **matrice);

#endif