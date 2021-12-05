/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:58:59 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/02 12:08:27 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_DEF.h"

int	key_handel(int key, t_fdf **param)
{
	if (key == EXIT)
	{
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_prt);
		exit(0);
	}
	return (0);
}
