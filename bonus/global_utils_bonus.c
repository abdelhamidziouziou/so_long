/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:13:55 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/19 08:30:02 by abziouzi         ###   ########.fr       */
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
