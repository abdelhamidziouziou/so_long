/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:14:20 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/19 08:29:28 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	map_validator(int fd, t_obj *obj)
{
	size_t	i;
	char	*line;

	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trim_nl(line, ft_strlen(line));
		if (i == 0)
			obj->width = ft_strlen(line);
		if (ft_strlen(line) != obj->width)
			return (false);
		if ((i == 0 || i == obj->height - 1) && !check_fl(line))
			return (false);
		else if (!check_each_line(obj, line, obj->width, i))
			return (false);
		obj->map.data[i++] = line;
	}
	if (obj->map.collectibles == 0 \
	|| obj->map.exits == 0 || obj->map.players == 0 || obj->map.players > 1 \
	|| obj->map.enemies == 0)
		return (false);
	return (true);
}

bool	map_checker(char *filename, t_obj *obj)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	obj->height = get_map_lines(filename);
	if (obj->height < 3)
		return (false);
	obj->map.data = malloc(sizeof(char *) * (obj->height + 1));
	if (!obj->map.data)
		return (false);
	obj->map.data[obj->height] = NULL;
	return (map_validator(fd, obj));
}
