/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:05:54 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 15:50:14 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_DEF.h"

void	movement(int key, t_fdf **param)
{
	if (key == MOVE_LEFT)
	{
		(*param)->move_x -= 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == MOVE_RIGHT)
	{
		(*param)->move_x += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == MOVE_UP)
	{
		(*param)->move_y += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == MOVE_DOWN)
	{
		(*param)->move_y -= 5;
		conv_int((*param)->char_matrice, *param);
	}
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
		(*param)->scoop -= 5;
	if (key == ZOOM_IN)
		(*param)->scoop += 5;
	if (key == UP)
	{
		(*param)->high += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == DOWN)
	{
		(*param)->high -= 5;
		conv_int((*param)->char_matrice, *param);
	}
}

int	key_event(int key, t_fdf **param)
{
	change_view(key, param);
	movement(key, param);
	if (key == REJECTION)
	{
		if ((*param)->rotation == 1)
			(*param)->rotation = 0;
		(*param)->rotation += 0.1;
		conv_int((*param)->char_matrice, *param);
	}
	exit_window(key, param);
	mlx_clear_window((*param)->mlx_ptr, (*param)->win_prt);
	draw(*param);
	return (0);
}
