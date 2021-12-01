/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:00 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/08 09:19:51 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*k;

	k = (unsigned char *)b;
	i = 0;
	if (len <= 0)
		return (b);
	while (i < len)
	{
		k[i] = (unsigned char)c;
		i++;
	}
	return (k);
}
