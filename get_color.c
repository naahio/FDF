/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:54:36 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/06 17:24:53 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *split)
{
	int	color;

	if (!ft_strchr(split, ',') && split[0] == '0')
		color = 0xFFFFFF;
	else if (ft_strchr(split, ','))
		color = ft_atoi_conv(ft_strchr(split, 'x') + 1);
	else
		color = 0x0226b2;
	return (color);
}
