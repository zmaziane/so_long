/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:46:07 by zmaziane          #+#    #+#             */
/*   Updated: 2022/02/25 03:16:33 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_data
{
	int		len;
	int		wit;
	int		exit;
	int		player;
	int		collectible;
	int		space;
	int		p_x;
	int		p_y;
	int		wall;
	int		*mlx_win;
	int		*mlx;
	int		*walls;
	int		*vide;
	int		*alien;
	int		*human;
	int		*alien_flying;
	int		a;
	int		b;
	int		moves;
	char	**stock;
}			t_data;

int		check_ext(char *map);
void	check_rectangle(t_data data);
void	check_walls(t_data data);
void	ft_free(t_data *data);
void	draw(t_data *data);
void	open_wind(t_data *data);
void	mlx_fun(t_data data);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init(t_data *dita);
int		check_content(t_data *dita, int i, int j);
int		destroy_window(t_data *data);
int		key_hook(int key_code, t_data *data);
#endif
