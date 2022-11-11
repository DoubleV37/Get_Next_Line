/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:06:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/11 09:50:15 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*res;

	res = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
}

ssize_t	readfd(int fd, char **buffer, ssize_t *i)
{
	ssize_t	valread;
	char	*str;

	*i = 0;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (-1);
	ft_bzero(str, (BUFFER_SIZE + 1));
	valread = read(fd, str, BUFFER_SIZE);
	*buffer = ft_strjoin(*buffer, str);
	free(str);
	return (valread);
}

void	buffershift(size_t index, char **buffer)
{
	size_t	i;

	i = 0;
	index++;
	while ((*buffer)[index + i] != '\0')
	{
		(*buffer)[i] = (*buffer)[index + i];
		i++;
	}
	(*buffer)[i] = '\0';
}
