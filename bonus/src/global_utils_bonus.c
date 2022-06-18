/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:13:55 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/18 22:18:09 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_obj *obj)
{
	if (obj->map.data)
	{
		while (*obj->map.data)
			free(*obj->map.data++);
		free(obj->map.data);
	}
}

void	_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
