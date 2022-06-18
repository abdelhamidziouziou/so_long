/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 05:45:20 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/18 22:18:08 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	is_valid_ext(char *filename, char *ext)
{
	char	*buff;

	if (!filename || !ext)
		return (false);
	buff = ft_strrchr(filename, '.');
	if (!buff)
		return (false);
	return (!ft_strncmp(buff, ext, ft_strlen(ext) + 1));
}

size_t	get_map_lines(char *filename)
{
	char	*line;
	int		fd;
	size_t	counter;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	counter = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line == '\n')
			return (0);
		free(line);
		counter++;
	}
	return (counter);
}

bool	check_fl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	trim_nl(char *line, int length)
{
	if (line[length - 1] == '\n')
		line[length - 1] = '\0';
}

bool	check_each_line(t_obj *obj, char *line, size_t length, int y)
{
	size_t	i;

	if (line[0] != '1' || line[length - 1] != '1')
		return (false);
	i = 1;
	while (i < length - 1)
	{
		if (!ft_strchr("1EPC0", line[i]))
			return (false);
		else if (line[i] == 'C')
			obj->map.collectibles++;
		else if (line[i] == 'P')
		{
			obj->map.players++;
			obj->player_pos.x = i;
			obj->player_pos.y = y;
		}
		else if (line[i] == 'E')
			obj->map.exits++;
		i++;
	}
	return (true);
}
