/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:01:16 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/11 18:42:40 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_def.h"

void	img_clear(t_fdf *data)
{
	int	pixel;

	pixel = 0;
	data->buffer = mlx_get_data_addr(data->img_ptr,
			&data->pixel_bits, &data->line_bytes, &data->endian);
	while (pixel < WIDTH_F * data->line_bytes)
		data->buffer[pixel++] = 0;
}

void	pixel_put(t_fdf *data, int x, int y)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH_F) && (y >= 0 && y < HEIGHT_F))
	{
		data->buffer = mlx_get_data_addr(data->img_ptr,
				&data->pixel_bits, &data->line_bytes, &data->endian);
		dst = data->buffer + (y * data->line_bytes
				+ x * (data->pixel_bits / 8));
		*(unsigned int *)dst = data->color[data->i][data->j];
	}
}

int	mouse_event(int key, int x, int y, t_fdf *data)
{
	if (key == 1)
	{
		data->move_x = x;
		data->move_y = y;
	}
	if (key == 4)
		data->scoop -= 2;
	if (key == 5)
		data->scoop += 2;
	mlx_clear_window(data->mlx_ptr, data->win_prt);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH_F, HEIGHT_F);
	draw(data);
	load_info(data);
	return (0);
}
