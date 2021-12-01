/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:10:56 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/08 13:12:08 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*psrc;
	unsigned char		*pdst;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (psrc > pdst)
	{
		i = -1;
		while (++i < len)
			pdst[i] = psrc[i];
	}
	else
	{
		i = len;
		while (i-- > 0)
			pdst[i] = psrc[i];
	}
	return (dst);
}
