/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:34 by olardeux          #+#    #+#             */
/*   Updated: 2023/11/30 11:43:58 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*sjoin;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sjoin = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!sjoin)
		return (0);
	while (s1[i++] != 0)
		sjoin[i] = s1[i];
	while (s2[i++ - ft_strlen(s1)] != 0)
		sjoin[i] = s2[i - ft_strlen(s1)];
	sjoin[i] = '\0';
	return (sjoin);
}
