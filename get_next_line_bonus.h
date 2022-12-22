/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:32:05 by xadabunu          #+#    #+#             */
/*   Updated: 2022/12/19 17:32:29 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE < 0 || BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_calloc(size_t size, size_t count);
void	ft_strcpy(char *dest, char *src, int len);
size_t	gnlen(const char *str);
char	*gnl_join(char *s1, char *s2);

#endif
