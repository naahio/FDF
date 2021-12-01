/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:10:59 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 18:20:58 by mbabela          ###   ########.fr       */
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
	data->move_x = 700;
	data->move_y = 200;
	data->scoop = 20;
	data->rotation = 0.4;
	return (data);
}

// int	key_handel_exit(int key, t_fdf *param)
// {
// 	if (key == 53)
// 	{
// 		mlx_destroy_window((param)->mlx_ptr, (param)->win_prt);
// 		exit(0);
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		fd;
	int		i; // rm
	t_fdf	*data;

	if (argc < 2) // !=
	{
		write(2, "Erreur! FILE_INDEFINED !\n", 26);
		return (0);
	}
	i = 0; // rm
	fd = open (argv[1], O_RDONLY);
	if (fd < 0) // || fd > MAX_FD (4096)
	{
		write(2, "Erreur! FILE_NAME_ERROR!\n", 26);
		return (0);
	}
	data = init_data(fd); // check NULL ret
	data->mlx_ptr = mlx_init();
	data->win_prt = mlx_new_window(data->mlx_ptr, 1000, 1000, "F_D_F");
	draw(data);
	mlx_key_hook(data->win_prt, key_event, &data);
	mlx_loop(data->mlx_ptr);
}
