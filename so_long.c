/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 05:02:32 by zmaziane          #+#    #+#             */
/*   Updated: 2022/02/24 21:13:36 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*b2;

	i = 0;
	a1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a1[i] != '\0' && b2[i] != '\0' && a1[i] == b2[i] && i < n - 1)
	{
		i++;
	}
	return (a1[i] - b2[i]);
}

void	init(t_data *dita)
{
	dita->exit = 0;
	dita->player = 0;
	dita->collectible = 0;
	dita->space = 0;
}

void	check(int fd, t_data data, char **av, int i)
{
	char	*line;

	data.len = 0;
	line = get_next_line(fd);
	while (line)
	{
		data.len++;
		free (line);
		line = get_next_line(fd);
	}
	data.stock = (char **)malloc(sizeof(char *) * (data.len + 1));
	if (!data.stock || !data.len)
		exit (1);
	if (close (fd) == -1)
	{
		perror ("Error\n");
		exit (1);
	}
	fd = open (av[1], O_RDWR);
	while (i < data.len)
		data.stock[i++] = get_next_line(fd);
	close (fd);
	data.wit = ft_strlen(data.stock[0]) - 1;
	mlx_fun(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.len = 0;
	if (ac != 2)
	{
		ft_printf("Error\nfor number of arguments");
		return (0);
	}
	if (check_ext(av[1]) == 0)
	{
		ft_printf("Error\nextention");
		return (0);
	}
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		perror("Error\n");
		return (0);
	}
	check(fd, data, av, 0);
	free (data.mlx);
	return (0);
}
