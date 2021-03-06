/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:30:41 by abziouzi          #+#    #+#             */
<<<<<<< HEAD:src_mandatory/render_utils.c
/*   Updated: 2022/06/20 13:52:54 by abziouzi         ###   ########.fr       */
=======
/*   Updated: 2022/06/21 00:31:33 by abziouzi         ###   ########.fr       */
>>>>>>> 2b85e6a41390796bf6e399dcc03c5b7002f9f4cc:src_mandatory/render_utils.c
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_img(t_obj *obj, int x, int y, t_img *img)
{
	mlx_put_image_to_window(obj->mlx, obj->win, img->data, x * 64, y * 64);
}

int	rendering(t_obj *obj)
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
				draw_img(obj, j, i, &obj->player_right);
			else if (obj->map.data[i][j] == 'E')
				draw_img(obj, j, i, &obj->exit);
			j++;
		}
		i++;
	}
	return (1);
}

t_img	img_init(t_obj *obj, char *filename)
{
	t_img	img;

	img.data = mlx_xpm_file_to_image(obj->mlx, filename, \
	&img.width, &img.height);
	return (img);
}
}

void	load_images(t_obj *obj)
{
	obj->collectible = img_init(obj, COLLECTIBLE);
	obj->exit = img_init(obj, EXIT);
	obj->floor = img_init(obj, EMPTY);
<<<<<<< HEAD:src_mandatory/render_utils.c
	obj->player_right = img_init(obj, PLAYER);
=======
	obj->player_right = img_init(obj, PLAYER_RIGHT);
>>>>>>> 2b85e6a41390796bf6e399dcc03c5b7002f9f4cc:src_mandatory/render_utils.c
	obj->wall = img_init(obj, WALL);
}
