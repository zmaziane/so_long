/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:20:06 by zmaziane          #+#    #+#             */
/*   Updated: 2022/02/25 03:17:04 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

void	mlx_fun(t_data data)
{
	init(&data);
	check_rectangle(data);
	check_walls(data);
	if (!check_content(&data, 0, 0))
	{
		ft_printf("Error\nProblem in the contents of the map");
		exit (0);
	}
	open_wind(&data);
	mlx_hook(data.mlx_win, 17, 0, destroy_window, &data);
	mlx_hook(data.mlx_win, 2, (1L << 0), key_hook, &data);
	mlx_loop(data.mlx);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len)
	{
		free (data->stock[i]);
		i++;
	}
	free (data->stock);
}

void	put_img(void *txt, int i, int j, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		txt, j * 64, i * 64);
}

void	draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len)
	{
		j = 0;
		while (j < data->wit)
		{
			if (data->stock[i][j] == '1')
				put_img(data->walls, i, j, data);
			else
			{
				put_img(data->vide, i, j, data);
				if (data->stock[i][j] == 'P')
					put_img(data->alien, i, j, data);
				else if (data->stock[i][j] == 'C')
					put_img(data->human, i, j, data);
				else if (data->stock[i][j] == 'E')
					put_img(data->alien_flying, i, j, data);
			}
			j++;
		}
		i++;
	}
}

void	open_wind(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 64 * data->wit, \
		64 * data->len, "so_long");
	data->alien_flying = mlx_xpm_file_to_image(data->mlx, \
		"imag/alien_flying.xpm", &data->a, &data->b);
	data->human = mlx_xpm_file_to_image(data->mlx, \
		"imag/human.xpm", &data->a, &data->b);
	data->alien = mlx_xpm_file_to_image(data->mlx, \
		"imag/alien.xpm", &data->a, &data->b);
	data->walls = mlx_xpm_file_to_image(data->mlx, \
		"imag/walls.xpm", &data->a, &data->b);
	data->vide = mlx_xpm_file_to_image(data->mlx, \
		"imag/vide.xpm", &data->a, &data->b);
	if (!data->walls || !data->alien || !data->human || !data->alien_flying \
		|| !data->vide)
	{
		ft_printf("Error\nfor image");
		exit(0);
	}
	draw(data);
}
