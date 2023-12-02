/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:30 by olardeux          #+#    #+#             */
/*   Updated: 2023/12/02 11:59:17 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		return (NULL); // rajoute peut etre un free sur readed ici
	while (readed[i] != 0)
	{
		read_del[j] = readed[i];
		i++;
		j++;
	}
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
			return (NULL);
		while (readed[i] != 0 && i < nlinstr(readed))
		{
			new_line[i] = readed[i];
			i++;
		}
	}
	else
		return(get_last_line(readed));
	new_line[i] = '\0';
	return (new_line);
		
}

char	*get_next_read(char *readed, int fd)
{
	char	*BUFFER;
	ssize_t	bytes;

	bytes = 1;
	BUFFER = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!BUFFER)
		return (NULL);
	while (!nlinstr(readed) && bytes != 0)
	{
		bytes = read(fd, BUFFER, BUFFER_SIZE);
		if (bytes == -1)
			return (free(BUFFER), NULL);
		BUFFER[BUFFER_SIZE] = '\0';
		readed = ft_strjoin(readed, BUFFER);
	}
	if (!readed)
		return (free(BUFFER), NULL);
	free(BUFFER);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char *readed;
	char *nl;

	if (fd <= 0)
		return (NULL);
	readed = get_next_read(readed, fd);
	if (!readed)
		return(NULL);
	nl = get_new_line(readed);
	readed = del_line(readed);
	return (nl);
}