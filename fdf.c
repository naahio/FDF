/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:10:59 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 09:06:08 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;
	int		i;
	char	**matrice_char;

	if (argc < 2)
	{
		printf("Erreur! File indefined\n");
		return (0);
	}
	i = 0;
	fd = open (argv[1],O_RDONLY);
	matrice_char = get_matrice(fd);
	data = (t_fdf*)malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	data->h = matrice_size(matrice_char);
	data->w = 0;
	while (matrice_char[0][data->w])
		data->w++;
	data->high = 1;
	conv_int(matrice_char, data);
	data->char_matrice = matrice_char;
	data->mlx_ptr = mlx_init();
	data->win_prt = mlx_new_window(data->mlx_ptr, 1000, 1000, "F_D_F");
	data->move_x = 900;
	data->move_y = 200;
	data->scoop = 1;
	data->rotation = 0.4;
	draw(data);
	// mlx_mouse_hook(data->win_prt, Mouse_event, &data);
	mlx_key_hook(data->win_prt, key_event, &data);
	mlx_loop(data->mlx_ptr);
}
