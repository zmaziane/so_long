/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:19:04 by zmaziane          #+#    #+#             */
/*   Updated: 2021/12/09 15:34:18 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunb(unsigned int nbr, int *len)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0', len);
	else
	{
		ft_putunb(nbr / 10, len);
		ft_putunb(nbr % 10, len);
	}
	return (0);
}
