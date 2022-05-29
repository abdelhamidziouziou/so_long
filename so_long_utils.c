/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:32:17 by abziouzi          #+#    #+#             */
/*   Updated: 2022/05/28 15:19:16 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_extension(char *map)
{
	int		map_len;
	char	*map_str;

	map_len = ft_strlen(map);
	map_str = map + map_len - 4;
	if (!ft_strncmp(map_str, ".ber", 4))
		return (1);
	else
		return (0);
}

int		check_shape(char *map)
{
	int		map_fd;

	map_fd = open(map, O_RDONLY);
	if (map_fd)
		return (1);
	else
		return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

///

int key_handler(int keycode, t_obj *obj)
{

	if (keycode == ESC)
		exit(1);
	else if (keycode == 49)
		mlx_put_image_to_window(obj->mlx, obj->win, obj->img.img, (rand() % (800 / 30)) * obj->img.w, (rand() % (600 / 30))* obj->img.h);
	if (keycode <= 126 && keycode >= 123)
	{
		keycode -= 123;
		if (keycode == LEFT)
			obj->pos.x--;
		else if (keycode == RIGHT)
			obj->pos.x++;
		else if (keycode == DOWN)
			obj->pos.y++;
		else
			obj->pos.y--;
		mlx_clear_window(obj->mlx, obj->win);
		mlx_put_image_to_window(obj->mlx, obj->win, obj->img.img, obj->pos.x * obj->img.w, obj->pos.y * obj->img.h);
	}
	return (1);
}
