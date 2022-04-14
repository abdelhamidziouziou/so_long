/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:30:38 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:25:07 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_hexa_l(unsigned int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i < 16)
		ft_putchar(base[i]);
	else
	{
		ft_put_hexa_l(i / 16);
		ft_put_hexa_l(i % 16);
	}
	return (ft_hexa_len(i));
}

unsigned int	ft_put_hexa_u(unsigned int i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i < 16)
		ft_putchar(base[i]);
	else
	{
		ft_put_hexa_u(i / 16);
		ft_put_hexa_u(i % 16);
	}
	return (ft_hexa_len(i));
}

void	ft_put_hexa_ptr(unsigned long long i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i < 16)
		ft_putchar(base[i]);
	else
	{
		ft_put_hexa_ptr(i / 16);
		ft_put_hexa_ptr(i % 16);
	}
}
