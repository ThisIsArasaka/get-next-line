/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:34 by olardeux          #+#    #+#             */
/*   Updated: 2023/12/05 15:34:31 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*sjoin;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (free(s1), NULL);
	i = 0;
	sjoin = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!sjoin)
		return (free(sjoin), NULL);
	while (s1[i] != 0)
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)] != 0)
	{
		sjoin[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	sjoin[i] = '\0';
	return (free(s1), sjoin);
}

char	*get_last_line(char *readed)
{
	int i;
	char* new_line;

	i = 0;
	new_line = (char *)malloc((ft_strlen(readed) + 1) * sizeof(char));
	if (!new_line)
		return (free(new_line), NULL);
	while (readed[i] != 0)
	{
		new_line[i] = readed[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
