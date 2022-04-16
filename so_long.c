/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/04/14 02:29:04 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if(check_extension(argv[1]))
		{
			ft_printf("Welcome to the game !!\n");
			ft_printf("Checking map dimensions...\n");
			if (check_shape(argv[1]))
			{
				ft_printf("Starting Game...\n");
				return (0);
			}
			else
			{
				ft_printf("Not a valid shape !!\n");
				exit (0);
			}
		}
		else
		{
			ft_printf("Not a .ber map!\n");
			exit (1);
		}
	}
	else
	{
		ft_printf("Invalid arguments !!\n");
		exit (1);
	}
}
