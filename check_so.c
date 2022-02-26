/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:15 by zmaziane          #+#    #+#             */
/*   Updated: 2022/02/24 21:14:26 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	check_ext(char *map)
{
	int		i;
	char	*str;

	i = ft_strlen(map);
	str = map + i - 4;
	if (!ft_strncmp(str, ".ber", 4))
		return (1);
	else
		return (0);
}

void	check_rectangle(t_data data)
{
	int		a;
	int		i;
	int		b;

	a = 0;
	i = 0;
	b = 1;
	while (b <= data.len)
	{
		if (i == data.len - 1)
			a = ft_strlen(data.stock[i]);
		else
			a = ft_strlen(data.stock[i]) - 1;
		if (data.wit != a)
		{
			ft_printf("Error\nmap is not rectangle");
			exit(1);
		}
		b++;
		i++;
	}
}

void	check_walls(t_data data)
{
	int	i;

	i = 0;
	while (i < data.wit)
	{
		if (data.stock[0][i] != '1' || data.stock[data.len - 1][i] != '1')
		{
			ft_printf("Error\nprobleme fo walls");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data.len)
	{
		if (data.stock[i][0] != '1' || data.stock[i][data.wit - 1] != '1')
		{
			ft_printf("Error\nproblem for walls");
			exit(1);
		}
		i++;
	}
}

void	check_character(t_data *dita, int i, int j)
{
	if (dita->stock[i][j] == 'P')
	{
		dita->player++;
		dita->p_x = i;
		dita->p_y = j;
	}
	else if (dita->stock[i][j] == 'C')
		dita->collectible++;
	else if (dita->stock[i][j] == 'E')
		dita->exit++;
	else if (dita->stock[i][j] == '0')
		dita->space++;
	else if (dita->stock[i][j] == '1')
		dita->wall++;
	else
	{
		ft_printf("Error\nundefined character");
		exit (1);
	}
}

int	check_content(t_data *dita, int i, int j)
{
	while (i < dita->len)
	{
		j = 0;
		while (j < dita->wit)
		{
			check_character(dita, i, j);
			j++;
		}
		i++;
	}
	if (dita->collectible > 0 && dita->exit > 0 && dita->player == 1 \
		&& dita->space > 0 && dita->wall > 0)
		return (1);
	return (0);
}
