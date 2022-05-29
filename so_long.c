/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/05/28 15:21:20 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	t_img img;
	t_obj obj;
	srand(time(NULL));
	obj.mlx = mlx_init();
	img.h = img.w = -1;
	img.img = mlx_xpm_file_to_image(obj.mlx, "./meme.xpm", &img.w, &img.h);
	if (img.h == -1 || img.w == -1)
		return (printf("can't load the image"), 1);
	obj.img = img;
	t_point point;
	point.x = rand() % (800 / img.w);
	point.y = rand() % (600 / img.h);
	printf("%d %d\n", point.x, point.y);
	obj.pos = point;
	obj.win = mlx_new_window(obj.mlx, 800, 600, "Game");
	mlx_put_image_to_window(obj.mlx, obj.win, obj.img.img, point.x * img.w, point.y * img.h);
	mlx_hook(obj.win, 2, 0, key_handler, &obj);
	// mlx_key_hook(obj.win, key_handler, &obj);
	mlx_loop(obj.mlx);

	if (argc == 2)
	{
		if (check_extension(argv[1]))
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
				exit(0);
			}
		}
		else
		{
			ft_printf("Not a .ber map!\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Invalid arguments !!\n");
		exit(1);
	}
}
