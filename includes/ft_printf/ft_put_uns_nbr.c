/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:30:23 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:25:09 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_uns_nbr(unsigned int i)
{
	unsigned int	c;

	c = 0;
	if (i >= 0 && i < 10)
		c += ft_putchar(i + '0');
	else
	{
		c += ft_put_uns_nbr(i / 10);
		c += ft_put_uns_nbr(i % 10);
	}
	return (c);
}
