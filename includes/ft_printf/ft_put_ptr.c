/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:29:27 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:25:08 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_ptr(unsigned long long p)
{
	unsigned int	x;

	x = 0;
	x += write(1, "0x", 2);
	ft_put_hexa_ptr(p);
	x += ft_hexa_len(p);
	return (x);
}
