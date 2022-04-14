/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:29:57 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:25:13 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i)
{
	if (i == -2147483648)
		ft_putstr("-2147483648");
	else if (i < 0)
	{
		ft_putchar('-');
		ft_putnbr(i * -1);
	}
	else if (i >= 0 && i <= 9)
		ft_putchar(i + '0');
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	return (ft_nbr_len(i));
}
