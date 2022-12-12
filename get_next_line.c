/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:25:39 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/27 16:50:59 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	return (i);
}

static char	*gnl_copy(char *src, long fd, char *buffer)
{
	char	*dest;
	size_t	len;
	long	ret;

	ret = 1;
	len = gnlen(src);
	dest = ft_calloc(sizeof(*dest), len + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src, len);
	src += len;
	while (dest[len - 1] != '\n' && ret > 0)
	{
		len = gnlen(src);
		ret = read(fd, buffer, BUFFER_SIZE);
		ft_strcpy(src, buffer, BUFFER_SIZE);
		dest = gnl_join(dest, src);
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	nl[BUFFER_SIZE + 1] = "\0";
	char		buffer[BUFFER_SIZE];
	long		ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (nl[0] == '\0')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			return (NULL);
		ft_strcpy(nl, buffer, BUFFER_SIZE);
	}
	return (gnl_copy(nl, fd, buffer));
}
