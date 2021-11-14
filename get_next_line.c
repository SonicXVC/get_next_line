/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:56:51 by ameteori          #+#    #+#             */
/*   Updated: 2021/11/14 15:40:58 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>



char *read_ostatok(int fd, char *ostatok)
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
	static char		*ostatok;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatok = read_ostatok(fd, ostatok);
	if (!ostatok)
		return (NULL);
	line = ft_dup_line(ostatok);
	ostatok = new_ost(ostatok);
	return (line);
}

/*int main()
{
	int fd;
	
	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}*/