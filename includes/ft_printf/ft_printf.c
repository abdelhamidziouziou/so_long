/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:54:01 by abziouzi          #+#    #+#             */
/*   Updated: 2022/04/14 01:57:20 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_converter(va_list args, const char userstr)
{
	int	count;

	count = 0;
	if (userstr == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (userstr == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (userstr == 'p')
		count += ft_put_ptr((unsigned long long)va_arg(args, void *));
	else if (userstr == 'd' || userstr == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (userstr == 'u')
		count += ft_put_uns_nbr(va_arg(args, unsigned int));
	else if (userstr == 'x')
		count += ft_put_hexa_l(va_arg(args, unsigned int));
	else if (userstr == 'X')
		count += ft_put_hexa_u(va_arg(args, unsigned int));
	else if (userstr == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *userstr, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, userstr);
	while (userstr[i])
	{
		if (userstr[i] == '%')
		{
			i++;
			count += ft_converter(args, userstr[i]);
		}
		else
			count += ft_putchar(userstr[i]);
	i++;
	}
	va_end(args);
	return (count);
}
