/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:34:45 by xadabunu          #+#    #+#             */
/*   Updated: 2022/12/19 17:34:47 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = -1;
	len1 = gnlen(s1);
	len2 = gnlen(s2);
	str = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[len1 + i] = s2[i];
	free(s1);
	return (str);
}
