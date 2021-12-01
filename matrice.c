/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:02:25 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 15:56:46 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	matrice_size(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
		i++;
	return (i);
}

char	**get_matrice(int fd)
{
	char	*tmp;
	char	*str;
	int		i;
	char	**matrice;
	char	*fre;

	str = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!str)
			str = strdup(tmp);
		else
		{
			fre = str;
			str = ft_strjoin(str, tmp);
			free(fre);
		}	
	}
	close (fd);
	free(tmp);
	matrice = ft_split(str, '\n');
	return (matrice);
}

void	count_size(t_fdf **data)
{
	int	i;

	i = 0;
	(*data)->size = 0;
	while (i < (*data)->w)
	{
		if (ft_isdigit((*data)->char_matrice[0][i])
			&& ((*data)->char_matrice[0][i + 1] == ','
			|| (*data)->char_matrice[0][i + 1] == ' '))
			(*data)->size++;
		i++;
	}
}

void	conv_int(char **matrice, t_fdf *data)
{
	int		i;
	int		j;
	char	**split;

	count_size(&data);
	data->matrice = (int **)malloc(sizeof(int *) * data->h);
	i = 0;
	while (i < data->h)
	{
		split = ft_split(matrice[i], ' ');
		data->size = matrice_size(split);
		data->matrice[i] = (int *)malloc(sizeof(int) * data->size);
		j = 0;
		while (j < data->size)
		{
			data->matrice[i][j] = ft_atoi(split[j]) * data->high;
			data->color = get_color(split[j]);
			j++;
		}
		free(*split);
		i++;
	}
	free(split);
}
