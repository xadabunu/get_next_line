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

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	long	ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret > 0)
	{
		buffer = malloc(sizeof(*buffer) * (ret + 1));
		assign(res, buffer);
	}
	return (res);
}

