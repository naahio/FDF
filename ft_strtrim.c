/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:44 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/09 10:15:20 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (set[j] && i <= end)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		if (s1[end] == set[j])
		{
			end--;
			j = 0;
		}
		else if (s1[i] != set[j] && s1[end] != set[j])
			j++;
	}
	return (ft_substr(s1, i, end - i + 1));
}
