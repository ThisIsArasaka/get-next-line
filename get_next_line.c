/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:30 by olardeux          #+#    #+#             */
/*   Updated: 2023/11/30 11:48:36 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nlinstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i++])
		if (s[i] == '\n')
			return (1);
	return (0);
}
char	*reset_read(char *readed)
{
}

void	*get_next_read(char *readed, int fd)
{
	char	*BUFFER;
	size_t	bytes;

	BUFFER = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!BUFFER)
		return (NULL);
	BUFFER[BUFFER_SIZE] = '\0';
	bytes = read(fd, BUFFER, BUFFER_SIZE);
	if (bytes == -1)
		return (free(BUFFER), NULL);
	readed = ft_strjoin(readed, BUFFER);
	if (!readed)
		return (free(BUFFER), NULL);
	free(BUFFER);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char *readed;
	char *nl;

	while (!nlinstr(readed))
		get_next_read(readed, fd);
}