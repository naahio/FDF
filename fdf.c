/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:10:59 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/05 16:56:49 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_data(int fd)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->char_matrice = get_matrice(fd);
	data->h = matrice_size(data->char_matrice);
	data->w = 0;
	while (data->char_matrice[0][data->w])
		data->w++;
	data->high = 1;
	conv_int(data->char_matrice, data);
	data->move_x = WIDTH_F - 100;
	data->move_y = HEIGHT_F - 500;
	if (data->w >= 200)
		data->scoop = 4;
	else
		data->scoop = 20;
	data->rotation = DEF_ROTATION;
	return (data);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;

	if (argc != 2)
	{
		write(2, "Erreur! FILE_INDEFINED !\n", 26);
		return (0);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd < 0 || fd > 4096)
	{
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, ": ", 2);
		perror("");
		return (0);
	}
	data = init_data(fd);
	if (!data)
		return (0);
	data->mlx_ptr = mlx_init();
	data->win_prt = mlx_new_window(data->mlx_ptr, WIDTH_F, HEIGHT_F, "F_D_F");
	draw(data);
	mlx_key_hook(data->win_prt, key_handel, &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
