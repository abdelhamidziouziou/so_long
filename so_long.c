/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/05/27 17:45:15 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	if (argc == 2)
	{
		if(check_extension(argv[1]))
		{
			ft_printf("Welcome to the game !!\n");
			ft_printf("Checking map dimensions...\n");
			if (check_shape(argv[1]))
			{
				ft_printf("Map loaded successfully!\n");
				ft_printf("Starting Game...\n");
				mlx = mlx_init();
				img.img = mlx_new_image(mlx, 1920, 1080);
				img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
				mlx_win = mlx_new_window(mlx, 1920, 1080, "abziouzi's So_long");
				mlx_loop(mlx);
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
