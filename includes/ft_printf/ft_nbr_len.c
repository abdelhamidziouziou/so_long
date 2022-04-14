/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:45:19 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:26:17 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(int i)
{
	int	nbrlen;

	nbrlen = 0;
	if (i == 0)
		nbrlen += 1;
	if (i < 0)
		nbrlen += 1;
	while (i != 0)
	{
		i = i / 10;
		nbrlen++;
	}
	return (nbrlen);
}

int	ft_hexa_len(unsigned long long i)
{
	int	nbrlen;

	nbrlen = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 16;
		nbrlen++;
	}
	return (nbrlen);
}
