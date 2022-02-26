/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:23:51 by zmaziane          #+#    #+#             */
/*   Updated: 2021/12/10 00:46:20 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putlowhex(unsigned int nbr, int *len)
{
	char	*s;

	s = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(s[nbr], len);
	else
	{
		ft_putlowhex(nbr / 16, len);
		ft_putlowhex(nbr % 16, len);
	}
	return (0);
}

unsigned int	ft_putuphex(unsigned int nbr, int *len)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(s[nbr], len);
	else
	{
		ft_putuphex(nbr / 16, len);
		ft_putuphex(nbr % 16, len);
	}
	return (0);
}

unsigned long	ft_putpointer(unsigned long nbr, int *len)
{
	char	*s;

	s = "0123456789abcdef";
	if (nbr < 16)
	{
		ft_putchar(s[nbr], len);
	}
	else
	{
		ft_putpointer(nbr / 16, len);
		ft_putpointer(nbr % 16, len);
	}
	return (0);
}
