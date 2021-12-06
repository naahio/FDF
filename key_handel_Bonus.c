/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel_Bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:05:54 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/06 11:57:46 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_DEF.h"

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
	load_info((*param));
}

void	exit_window(int key, t_fdf **param)
{
	if (key == EXIT)
	{
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_prt);
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
	load_info((*param));
}

int	key_event_bonus(int key, t_fdf **param)
{
	change_view(key, param);
	movement(key, param);
	if (key == REJECTION)
	{
		if ((*param)->rotation == 1)
			(*param)->rotation = 0;
		(*param)->rotation += 0.1;
	}
	exit_window(key, param);
	mlx_clear_window((*param)->mlx_ptr, (*param)->win_prt);
	load_info(*param);
	draw(*param);
	return (0);
}
