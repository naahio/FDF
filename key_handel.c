/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:05:54 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 09:06:22 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_event(int key, t_fdf **param)
{
	if (key == 31)
		(*param)->scoop -= 5;
	if (key == 34)
		(*param)->scoop += 5;
	if (key == 69)
	{
		(*param)->high += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 78)
	{
		(*param)->high -= 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 123)
	{
		(*param)->move_x -= 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 124)
	{
		(*param)->move_x += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 125)
	{
		(*param)->move_y += 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 126)
	{
		(*param)->move_y -= 5;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 15)
	{
		if ((*param)->rotation == 1)
			(*param)->rotation = 0;
		(*param)->rotation += 0.1;
		conv_int((*param)->char_matrice, *param);
	}
	if (key == 53)
	{
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_prt);
		exit(0);
	}
	mlx_clear_window((*param)->mlx_ptr, (*param)->win_prt);
	draw(*param);
	return (0);
	// + : 69
	// - : 78
	//z + i (zoom in) : 6 + 34
	//z + o (zoom out) : 6 + 31
	//rotation auto r : 15
	//left flesh : 123
	//right flesh : 124	
}

// int	Mouse_event(int key, t_fdf **param)
// {
// 	printf("%d\n",key);
// 	if (key == 5)
// 	{
// 		(*param)->high += 2;
// 		conv_int((*param)->char_matrice, *param);
// 	}
// 	if (key == 4)
// 	{
// 		(*param)->high -= 2;
// 		conv_int((*param)->char_matrice, *param);
// 	}
// 	mlx_clear_window((*param)->mlx_ptr, (*param)->win_prt);
// 	draw(*param);
// 	return (0);
// }