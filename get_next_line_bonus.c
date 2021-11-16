/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:56:51 by ameteori          #+#    #+#             */
/*   Updated: 2021/11/16 15:26:30 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
# include <limits.h>

char	*read_ostatok(int fd, char *ostatok)
{
	char	*buff;
	int		chars_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	chars_read = 1;
	while (!ft_strchr(ostatok, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[chars_read] = '\0';
		ostatok = ft_strjoin(ostatok, buff);
	}
	free(buff);
	return (ostatok);
}

char	*get_next_line(int fd)
{
	static char		*ostatok[MAX_OPEM];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatok[fd] = read_ostatok(fd, ostatok[fd]);
	if (!ostatok[fd])
		return (NULL);
	line = ft_dup_line(ostatok[fd]);
	ostatok[fd] = new_ost(ostatok[fd]);
	return (line);
}
