/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:59:56 by zmaziane          #+#    #+#             */
/*   Updated: 2021/12/09 21:29:50 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int				ft_printf(const char *s, ...);
int				ft_putnbr(int nb, int *len);
void			ft_press(char *s, va_list valist, int *len, int i);
int				ft_putchar(const char c, int *len);
void			ft_putstr(char *str, int *len);
unsigned int	ft_putunb(unsigned int nbr, int *len);
unsigned int	ft_putlowhex(unsigned int nbr, int *len);
unsigned int	ft_putuphex(unsigned int nbr, int *len);
unsigned long	ft_putpointer(unsigned long nbr, int *len);

#endif
