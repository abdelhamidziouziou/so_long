/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/04/14 01:12:08 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if(check_extension(argv[1]))
		{
			printf("Welcome to the game !!\n");
			exit (0);
		}
		else
		{
			printf("Not a .ber map!\n");
			exit (1);
		}
	}
	else
	{
		printf("Invalid arguments !!\n");
		exit (1);
	}
}
