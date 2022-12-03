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

static int	gnl_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

static char	*ft_read_to_n(char *str)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = gnl_len(str)
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = str[i];
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	long		ret;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	// if (ret > 0)
	// {
	// }
	next_line = ft_read_to_n(buffer);
	if (!next_line)
		return (NULL);
	return (next_line);
}

