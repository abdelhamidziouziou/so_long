/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:30:41 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/19 09:23:41 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_img(t_obj *obj, int x, int y, t_img *img)
{
	mlx_put_image_to_window(obj->mlx, obj->win, img->data, x * 48, y * 48);
}

void	rendering(t_obj *obj)
{
	size_t	i;
	size_t	j;

	i = 0;
	mlx_clear_window(obj->mlx, obj->win);
	while (i < obj->height)
	{
		j = 0;
		while (j < obj->width)
		{
			if (obj->map.data[i][j] == 'C')
				draw_img(obj, j, i, &obj->collectible);
			else if (obj->map.data[i][j] == '0')
				draw_img(obj, j, i, &obj->floor);
			else if (obj->map.data[i][j] == '1')
				draw_img(obj, j, i, &obj->wall);
			else if (obj->map.data[i][j] == 'P')
				draw_img(obj, j, i, &obj->player);
			else if (obj->map.data[i][j] == 'E')
				draw_img(obj, j, i, &obj->exit);
			else if (obj->map.data[i][j] == 'J')
				draw_img(obj, j, i, &obj->enemy);
			j++;
		}
		i++;
	}
}

t_img	img_init(t_obj *obj, char *filename)
{
	t_img	img;

	img.data = mlx_xpm_file_to_image(obj->mlx, filename, \
	&img.width, &img.height);
	return (img);
}

void	load_images(t_obj *obj)
{
	obj->collectible = img_init(obj, COLLECTIBLE);
	obj->enemy = img_init(obj, ENEMY);
	obj->exit = img_init(obj, EXIT);
	obj->floor = img_init(obj, EMPTY);
	obj->player = img_init(obj, PLAYER);
	obj->wall = img_init(obj, WALL);
}
