/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel_Bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:05:54 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/11 17:58:18 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_def.h"

void	movement(int key, t_fdf **param)
{
	if (key == MOVE_LEFT)
		(*param)->move_x -= (WIDTH_F / 2) - 500;
	if (key == MOVE_RIGHT)
		(*param)->move_x += (HEIGHT_F / 2) - 300;
	if (key == MOVE_UP)
		(*param)->move_y += (WIDTH_F / 2) - 500;
	if (key == MOVE_DOWN)
		(*param)->move_y -= (HEIGHT_F / 2) - 300;
}

void	exit_window(int key, t_fdf **param)
{
	if (key == EXIT)
	{
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_prt);
		free((*param)->mlx_ptr);
		exit(0);
	}
}

void	change_view(int key, t_fdf **param)
{
	if (key == ZOOM_OUT)
		(*param)->scoop -= 2;
	if (key == ZOOM_IN)
		(*param)->scoop += 2;
	if (key == UP)
		(*param)->high += 2;
	if (key == DOWN)
		(*param)->high -= 2;
	if (key == 2)
		(*param)->view = 0;
	if (key == 17)
		(*param)->view = 0;
	if (key == 2)
		(*param)->view = 1;
}

void	rotate(int key, t_fdf **param)
{
	if (key == REJECTION_X)
		(*param)->rotate_x += 0.2;
	if (key == REJECTION_Y)
		(*param)->rotate_y += 0.2;
}

int	key_event_bonus(int key, t_fdf **param)
{
	change_view(key, param);
	movement(key, param);
	rotate(key, param);
	exit_window(key, param);
	mlx_clear_window((*param)->mlx_ptr, (*param)->win_prt);
	mlx_destroy_image((*param)->mlx_ptr, (*param)->img_ptr);
	(*param)->img_ptr = mlx_new_image((*param)->mlx_ptr, WIDTH_F, HEIGHT_F);
	draw(*param);
	load_info(*param);
	return (0);
}
