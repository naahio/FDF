/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:01:36 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/11 17:18:46 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param	*init_param(int *x0, int *y0, t_fdf *data)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->z = data->matrice[*y0][*x0] * data->high;
	param->z1 = data->matrice[data->y1][data->x1] * data->high;
	*x0 *= data->scoop;
	data->x1 *= data->scoop;
	*y0 *= data->scoop;
	data->y1 *= data->scoop;
	if (data->view)
	{
		isometric(x0, y0, param->z, data);
		isometric(&data->x1, &data->y1, param->z1, data);
	}
	data->y1 += data->move_y;
	*x0 += data->move_x;
	data->x1 += data->move_x;
	*y0 += data->move_y;
	param->dx = abs(data->x1 - *x0);
	return (param);
}

int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

void	bresen(int x0, int y0, t_fdf *data)
{
	t_param	*param;
	
	param = init_param(&x0, &y0, data);
	param->sx = compare(x0, data->x1);
	param->dy = -abs(data->y1 - y0);
	param->sy = compare(y0, data->y1);
	param->err = param->dx + param->dy;
	while (1)
	{
		pixel_put(data, x0, y0);
		if (x0 == data->x1 && y0 == data->y1)
			break ;
		param->e2 = 2 * param->err;
		if (param->e2 >= param->dy)
		{
			param->err += param->dy;
			x0 += param->sx;
		}	
		if (param->e2 <= param->dx)
		{
			param->err += param->dx;
			y0 += param->sy;
		}
	}
}
