/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:01:36 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/27 18:30:50 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresen(int x0, int y0, int x1, int y1, t_fdf *data)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	z;
	int	z1;
	
	z = data->matrice[y0][x0];
	z1 = data->matrice[y1][x1];
	x0 *= data->scoop;
	x1 *= data->scoop;
	y0 *= data->scoop;
	y1 *= data->scoop;
	x0 += data->move_x;
	x1 += data->move_x;
	y0 += data->move_y;
	y1 += data->move_y;
	// deb
	isometric(&x0, &y0, z, data);
	isometric(&x1, &y1, z1, data);
	dx = abs(x1 - x0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	dy = -abs(y1 - y0);
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr,data->win_prt, x0, y0, data->color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err+= dy;
			x0 += sx;
		}	
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}	
}