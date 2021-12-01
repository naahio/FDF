/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:10:32 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/06 18:07:02 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			size;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_size(n) + (n < 0);
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	result[size] = '\0';
	while (n)
	{
		result[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (result);
}
