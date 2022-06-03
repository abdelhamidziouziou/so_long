/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/03 20:54:21 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int		i;
	void	*mlx_ptr;
	void	*mlx_window;

	i = 0;
	if (argc == 2 && argv[i])
	{
		mlx_ptr = mlx_init();
		mlx_window = mlx_new_window(mlx_ptr, 800, 600, "abziouzi's So Long");
		ft_putstr("Welcome to So_long!\nStarting Game...");
		mlx_loop(mlx_ptr);
	}
	else
	{
		ft_putstr("Invalid arguments!\n");
		exit(1);
	}
}
