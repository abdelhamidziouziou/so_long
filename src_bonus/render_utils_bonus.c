/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:30:41 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/21 00:43:28 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	obj->floor = img_init(obj, EMPTY);
	obj->enemy = img_init(obj, ENEMY);
	obj->exit = img_init(obj, EXIT);
	obj->player_down = img_init(obj, PLAYER_DOWN);
	obj->player_left = img_init(obj, PLAYER_LEFT);
	obj->player_right = img_init(obj, PLAYER_RIGHT);
	obj->player_up = img_init(obj, PLAYER_UP);
	obj->wall = img_init(obj, WALL);
}
