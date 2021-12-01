/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:17 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 17:44:55 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_draw_x(int x, int y, int comp, t_fdf *data)
{
	if (x < comp - 1)
	{
		data->x1 = x + 1;
		data->y1 = y;
		bresen(x, y, data);
	}
}

void	set_draw_y(int x, int y, int comp, t_fdf *data)
{
	if (y < comp - 1)
	{
		data->x1 = x;
		data->y1 = y + 1;
		bresen(x, y, data);
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->size)
		{
			if (!data->matrice[y][x])
				data->color = 0xFFFFFF;
			else
				data->color = 0xFF00FF;
			set_draw_x(x, y, data->size, data);
			set_draw_y(x, y, data->h, data);
			x++;
		}
		y++;
	}
}
