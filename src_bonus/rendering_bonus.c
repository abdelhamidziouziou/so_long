/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:39:00 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/21 01:12:24 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_img(t_obj *obj, int x, int y, t_img *img)
{
	mlx_put_image_to_window(obj->mlx, obj->win, img->data, x * 48, y * 48);
}

void	render_player(t_obj *obj, int x, int y)
{
	if (obj->player_pos.pos == KEY_RIGHT)
		draw_img(obj, x, y, &obj->player_right);
	else if (obj->player_pos.pos == KEY_LEFT)
		draw_img(obj, x, y, &obj->player_left);
	else if (obj->player_pos.pos == KEY_UP)
		draw_img(obj, x, y, &obj->player_up);
	else if (obj->player_pos.pos == KEY_DOWN)
		draw_img(obj, x, y, &obj->player_down);
}

void	render_enemy(t_obj *obj, int x, int y)
{
	int	i;
	int	d;

	d = rand() % 2;
	i = x;
	if (d == 0)
		i++;
	else
		i--;
	if (ft_strchr("0P", obj->map.data[y][i]) && rand() % 29 == 0)
	{
		if (obj->map.data[y][i] == 'P')
		{
			ft_printf("9asek chaytan, go and renew lwodo2 3afak.\n");
			free_all(obj);
			exit(1);
		}
		obj->map.data[y][x] = '0';
		obj->map.data[y][i] = 'J';
		draw_img(obj, i, y, &obj->enemy);
	}
	else
		draw_img(obj, x, y, &obj->enemy);
}

void	show_moves(t_obj *obj)
{
	char	*buff;

	buff = ft_itoa(obj->moves);
	mlx_string_put(obj->mlx, obj->win, 0, 0, 0, "Steps: ");
	mlx_string_put(obj->mlx, obj->win, 100, 0, 0, buff);
	free(buff);
	buff = ft_itoa(obj->stacks);
	mlx_string_put(obj->mlx, obj->win, 0, 20, 0, "Tawaf: ");
	mlx_string_put(obj->mlx, obj->win, 100, 20, 0, buff);
	free(buff);
}

int	rendering(t_obj *obj)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < obj->height)
	{
		j = -1;
		while (++j < obj->width)
		{
			if (obj->map.data[i][j] == 'C')
				draw_img(obj, j, i, &obj->collectible);
			else if (obj->map.data[i][j] == '0')
				draw_img(obj, j, i, &obj->floor);
			else if (obj->map.data[i][j] == '1')
				draw_img(obj, j, i, &obj->wall);
			else if (obj->map.data[i][j] == 'P')
				render_player(obj, j, i);
			else if (obj->map.data[i][j] == 'E')
				draw_img(obj, j, i, &obj->exit);
			else if (obj->map.data[i][j] == 'J')
				render_enemy(obj, j, i);
		}
	}
	show_moves(obj);
	return (1);
}
