/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:10:59 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/11 17:41:02 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_info(t_fdf *data)
{
	int	color;

	color = 0x0f8ede;
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 0, color, ZOOM_IN_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 15, color, ZOOM_OUT_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 30, color, UP_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 45, color, DOWN_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 60, color, MOVE_LEFT_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 75, color, MOVE_RIGHT_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 90, color, MOVE_UP_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 105, color, MOVE_DOWN_ACT);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 120, color, ROTATE_ACT_X);
	mlx_string_put (data->mlx_ptr, data->win_prt, 0, 135, color, ROTATE_ACT_Y);
	mlx_string_put (data->mlx_ptr, data->win_prt, 930, 0, color, BY);
	mlx_string_put (data->mlx_ptr, data->win_prt, 980, 15, color, LOGIN);
}

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
	if (data->w >= 4000)
		data->scoop = 1;
	else if (data->w >= 200)
		data->scoop = 5;
	else
		data->scoop = 10;
	data->move_x = (WIDTH_F / 2) - (data->size / 2);
	data->move_y = (HEIGHT_F / 2) - (data->h / 2);
	data->rotate_x = DEF_ROTATION;
	data->rotate_y = DEF_ROTATION;
	data->view = 1;
	return (data);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;

	if (argc != 2)
	{
		write(2, "Erreur! FILE_UNDEFINED !\n", 26);
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
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH_F, HEIGHT_F);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_prt, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_prt, key_handel, &data);
	mlx_loop(data->mlx_ptr);
}

