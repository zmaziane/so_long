/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:27:01 by zmaziane          #+#    #+#             */
/*   Updated: 2022/02/24 21:27:31 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_lecture(int fd, char *buffers);
char	*ft_ft_strchr(char *s, int c);
size_t	ft_ft_strlen(char *s);
char	*ft_ft_strjoin(char *s1, char *s2);
void	*ft_ft_memcpy(void *dst, void *src, size_t n);
char	*lire_ligne(char *buffers);
char	*chyata(char *buffers);
char	*get_next_line(int fd);

#endif
