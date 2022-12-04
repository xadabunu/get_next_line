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
	char		buffer[BUFFER_SIZE];
	long		read;
	static char	next_line[BUFFER_SIZE + 1] = "\0";

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (*next_line == 0)
	{
		// soit premier appel soit appel après lecture complète => read retournera 0
		// init tout à 0 par sécurité ?
		read = read(fd, buffer, BUFFER_SIZE);
		if (read < 1)
			return (NULL);
	}
	// read_to_n doit copier en incrémentant le pointeur up to \n et s'il tombe 
	// sur un /0, lire dans le fichier pour vérifier qu'il s'agit bien de
	// la fin du fichier avant de return la string
	return (ft_read_to_n(next_line););
}

