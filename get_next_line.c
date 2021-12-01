/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:22:30 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/15 09:22:30 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_line(int fd, char *buf, char **result)
{
	int		line;
	char	*tmp;

	if (!*result || !ft_strchr(*result, '\n'))
	{
		line = read(fd, buf, BUFFER_SIZE);
		while (line > 0)
		{
			buf[line] = '\0';
			if (!*result)
				*result = ft_substr(buf, 0, line);
			else
			{
				tmp = *result;
				*result = ft_strjoin(*result, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			line = read(fd, buf, BUFFER_SIZE);
		}
	}
}

static char	*ft_read_line(char **result)
{
	int		size;
	int		remain_len;
	char	*ret;
	char	*tmp;

	if (!*result)
	{
		free(*result);
		return (NULL);
	}
	if (!ft_strchr(*result, '\n'))
	{
		ret = ft_substr(*result, 0, ft_strlen(*result));
		free(*result);
		*result = 0;
		return (ret);
	}
	size = ft_strlen(*result);
	remain_len = ft_strlen(ft_strchr(*result, '\n'));
	ret = ft_substr(*result, 0, size - remain_len + 1);
	tmp = *result;
	*result = ft_substr(ft_strchr(*result, '\n'), 1, remain_len);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*result;
	int			ret;

	ret = read(fd, buf, 0);
	if (BUFFER_SIZE <= 0 || ret < 0)
	{
		write (2, "Error! ENCONTRED_PROBLEM_WHILE_READING_FILE\n", 45);
		return (NULL);
	}
	ft_free_line(fd, buf, &result);
	return (ft_read_line(&result));
}
