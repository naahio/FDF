/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:17 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 16:57:08 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			if (x < data->size - 1)
			{
				data->x1 = x + 0.5;
				data->y1 = y;
				bresen(x, y, data);
			}
			if (y < data->h - 1)
			{
				data->x1 = x;
				data->y1 = y + 0.5;
				bresen(x, y, data);
			}
			if (x < data->size - 1)
			{
				data->x1 = x + 1;
				data->y1 = y;
				bresen(x, y, data);
			}
			if (y < data->h - 1)
			{
				data->x1 = x;
				data->y1 = y + 1;
				bresen(x, y, data);
			}
			x++;
		}
		y++;
	}
}
