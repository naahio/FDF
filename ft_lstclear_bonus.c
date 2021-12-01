/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:28:55 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/06 11:28:55 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pass;

	if (!*lst)
		return ;
	while (*lst)
	{
		pass = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = pass;
	}
	*lst = NULL;
}
