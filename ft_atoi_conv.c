/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:56:11 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/06 17:26:06 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fk_pow(int i)
{
	int	a;

	a = 1;
	while (i > 0)
	{	
		a = a * 16;
		i--;
	}
	return (a);
}

int	check_pos(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	if (c == 'b' || c == 'B')
		return (11);
	if (c == 'c' || c == 'C')
		return (12);
	if (c == 'd' || c == 'D')
		return (13);
	if (c == 'e' || c == 'E')
		return (14);
	if (c == 'f' || c == 'F')
		return (15);
	return (c - '0');
}

int	ft_atoi_conv(const char *str)
{
	int	result;
	int	add;
	int	i;
	int	j;

	add = 0;
	result = 0;
	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (str[i])
	{
		add = check_pos(str[i]);
		result = result + (add * fk_pow(j));
		i ++;
		j--;
	}
	return (result);
}
