/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:07:07 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/11 10:44:39 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	filterbuffer(char **outstr, char **buffer, size_t end)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(*buffer))
		return ;
	str = malloc(sizeof(char) * (end + 2));
	if (!str)
	{
		free(*outstr);
		return ;
	}
	while (i <= end)
	{
		str[i] = (*buffer)[i];
		i++;
	}
	str[i] = '\0';
	buffershift(end, buffer);
	*outstr = ft_strjoin(*outstr, str);
	free(str);
}

char	*verifybuffer(char **buffer, char **str)
{
	if (ft_strlen(*str) > 0)
		return (*str);
	free(*buffer);
	free(*str);
	*buffer = NULL;
	return (NULL);
}

char	*returnbuffer(char **buffer, int fd)
{
	ssize_t	nbread;
	ssize_t	i;
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	i = 1;
	while ((*buffer)[i - 1] != '\n')
	{
		if (!(*buffer)[0])
		{
			nbread = readfd(fd, buffer, &i);
			if ((nbread == -1 || nbread == 0))
				return (verifybuffer(buffer, &str));
		}
		if ((*buffer)[i] == '\0')
		{
			str = ft_strjoin(str, *buffer);
			(*buffer)[0] = '\0';
		}
		i++;
	}
	if ((*buffer)[i - 1] == '\n')
		filterbuffer(&str, buffer, i - 1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
	}
	str = returnbuffer(&buffer, fd);
	return (str);
}
