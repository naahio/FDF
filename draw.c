/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:17 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/27 17:58:30 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->size)
		{
			if (data->matrice[y][x])
				data->color = 0xff00ff;
			else
				data->color = 0xffFFff;
			if (x < data->size - 1)
				bresen(x, y, x + 1, y ,data);
			if (y < data->h - 1)
				bresen(x, y, x , y + 1,data);
			x++;
		}
		y++;
	}
		
}