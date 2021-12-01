/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:11:35 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 09:07:18 by mbabela          ###   ########.fr       */
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

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
#define deb printf("===={ here }====\n");

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
}t_fdf;

void	bresenham(int x0, int y0, int x1, int y1, t_fdf *data);
void	draw(t_fdf *data);
void	isometric(int *x, int *y, int z, t_fdf *data);
void	bresen(int x0, int y0, int x1, int y1, t_fdf *data);
void	get_color(int x, int y, char **matrice, t_fdf *data);
void	clean(int x0, int y0, int x1, int y1, t_fdf *data);
int		key_event(int key, t_fdf **param);
void	conv_int(char **matrice, t_fdf *data);
char	**get_matrice(int fd);
int		matrice_size(char **matrice);

#endif