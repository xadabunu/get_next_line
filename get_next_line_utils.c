/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:26:05 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/27 16:53:41 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t size, size_t count)
{
	char	*res;
	size_t	i;
	size_t	total;

	total = size * count;
	res = malloc(total);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total)
	{
		res[i] = '\0';
		++i;
	}
	return (res);
}

void	ft_strcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

char	*gnl_join(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	len1 = gnlen(s1);
	len2 = gnlen(s2);
	str = ft_calloc(sizeof(*str), (len1 + len2 + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (i < len1)
	{
		str[i] = s1[i];
		++i;
	}
	i = 0;
	while (i < len2)
	{
		str[len1 + i] = s2[i];
		++i;
	}
	free(s1);
	return (str);
}
