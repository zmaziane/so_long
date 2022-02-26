/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:28:18 by zmaziane          #+#    #+#             */
/*   Updated: 2021/12/10 17:44:57 by zmaziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_press(char *s, va_list valist, int *len, int i)
{
	if (s[i] == 'c')
		ft_putchar(va_arg(valist, int), len);
	if (s[i] == 's')
		ft_putstr(va_arg(valist, char *), len);
	if (s[i] == 'i' || s[i] == 'd')
		ft_putnbr(va_arg(valist, int), len);
	if (s[i] == 'u')
		ft_putunb(va_arg(valist, unsigned int), len);
	if (s[i] == 'x')
		ft_putlowhex(va_arg(valist, unsigned int), len);
	if (s[i] == 'X')
		ft_putuphex(va_arg(valist, unsigned int), len);
	if (s[i] == '%')
		ft_putchar('%', len);
	if (s[i] == 'p')
	{
		write(1, "0x", 2);
		(*len)++;
		(*len)++;
		ft_putpointer(va_arg(valist, unsigned long), len);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	valist;
	int		len;

	i = 0;
	len = 0;
	va_start(valist, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_press((char *)s, valist, &len, i);
		}
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end(valist);
	return (len);
}
