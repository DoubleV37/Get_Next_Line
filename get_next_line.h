/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:07:12 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/11 09:58:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
ssize_t	readfd(int fd, char **buffer, ssize_t *i);
void	ft_bzero(void *s, size_t n);
void	buffershift(size_t index, char **buffer);
char	*returnbuffer(char **buffer, int fd);
void	filterbuffer(char **outstr, char **buffer, size_t end);
char	*verifybuffer(char **buffer, char **str);

#endif
