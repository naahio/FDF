/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:54:36 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/01 15:54:53 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *split)
{
	int	color;

	if (!ft_strchr(split, ',') && split[0] == '0')
		color = 0xFFFFFF;
	else
		color = 0x00FFFF;
	return (color);
}
