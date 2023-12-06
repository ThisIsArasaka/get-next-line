/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:40:22 by olardeux          #+#    #+#             */
/*   Updated: 2023/12/06 11:09:55 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	nlinstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*del_line(char *readed)
{
	int		i;
	int		j;
	char	*read_del;

	i = nlinstr(readed);
	j = 0;
	if (!nlinstr(readed) || !readed)
		return (free(readed), NULL);
	read_del = (char *)malloc((ft_strlen(readed) - i + 1) * sizeof(char));
	if (!read_del)
		return (free(readed), NULL);
	while (readed[i] != 0)
	{
		read_del[j] = readed[i];
		i++;
		j++;
	}
	read_del[j] = '\0';
	free(readed);
	return (read_del);
}

char	*get_new_line(char *readed)
{
	int		i;
	char	*new_line;

	i = 0;
	if (nlinstr(readed))
	{
		new_line = (char *)malloc((nlinstr(readed) + 1) * sizeof(char));
		if (!new_line)
			return (free(new_line), NULL);
		while (readed[i] != 0 && i < nlinstr(readed))
		{
			new_line[i] = readed[i];
			i++;
		}
	}
	else
		return (get_last_line(readed));
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_get_next_read(char *readed, int fd)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (!nlinstr(readed) && bytes != 0)
	{
		if (!buffer || bytes == -1)
			return (free(buffer), NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == BUFFER_SIZE)
		{
			buffer[BUFFER_SIZE] = '\0';
			readed = ft_strjoin(readed, buffer);
		}
		else if (bytes > 0)
		{
			buffer[bytes] = '\0';
			readed = ft_strjoin(readed, buffer);
		}
	}
	if (!readed)
		return (free(buffer), NULL);
	free(buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed[1024];
	char		*nl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	readed[fd] = ft_get_next_read(readed[fd], fd);
	if (!readed[fd] || !readed[fd][0])
		return (free(readed[fd]), NULL);
	nl = get_new_line(readed[fd]);
	if (!nl)
		return (free(nl), NULL);
	readed[fd] = del_line(readed[fd]);
	return (nl);
}
