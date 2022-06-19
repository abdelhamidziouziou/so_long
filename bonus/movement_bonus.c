/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:01:29 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/19 08:38:58 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(int keycode, t_obj *obj)
{
	if (keycode == KEY_LEFT && \
	obj->map.data[obj->player_pos.y][obj->player_pos.x - 1] != '1')
		obj->player_pos.x--;
	else if (keycode == KEY_RIGHT && \
	obj->map.data[obj->player_pos.y][obj->player_pos.x + 1] != '1')
		obj->player_pos.x++;
	else if (keycode == KEY_UP && \
	obj->map.data[obj->player_pos.y - 1][obj->player_pos.x] != '1')
		obj->player_pos.y--;
	else if (keycode == KEY_DOWN && \
	obj->map.data[obj->player_pos.y + 1][obj->player_pos.x] != '1')
		obj->player_pos.y++;
}

void	check_enemy(t_obj *obj)
{
	if (obj->map.data[obj->player_pos.y][obj->player_pos.x] == 'J')
	{
		ft_msg("Ser a khoya 3awed lwdo hhhh.");
		destroy_window(obj);
	}
}

void	end_game(t_obj	*obj)
{
	if (obj->map.collectibles == 0)
	{
		write(1, "Game Ended!", 11);
		exit(0);
	}
}

void	show_moves(t_obj *obj, t_point player)
{
	if (obj->player_pos.x != player.x || obj->player_pos.y != player.y)
	{
		obj->moves++;
	}
}

void	movement(int keycode, t_obj *obj)
{
	t_point	tmp_p;
	bool	replace;

	replace = false;
	tmp_p = obj->player_pos;
	move(keycode, obj);
	if (obj->map.data[obj->player_pos.y][obj->player_pos.x] == 'C')
	{
		obj->map.collectibles--;
		replace = true;
	}
	else if (obj->map.data[obj->player_pos.y][obj->player_pos.x] == 'E')
		end_game(obj);
	else if (obj->map.data[obj->player_pos.y][obj->player_pos.x] == 'J')
		check_enemy(obj);
	else
		replace = true;
	if (replace)
	{
		show_moves(obj, tmp_p);
		obj->map.data[tmp_p.y][tmp_p.x] = '0';
		obj->map.data[obj->player_pos.y][obj->player_pos.x] = 'P';
	}
	else
		obj->player_pos = tmp_p;
	rendering(obj);
}
