/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:13:55 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/21 00:35:28 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_obj *obj)
{
	int	i;

	if (obj->map.data)
	{
		i = 0;
		while (obj->map.data[i])
		{
			free(obj->map.data[i]);
			obj->map.data[i] = NULL;
			i++;
		}
		free(obj->map.data);
		obj->map.data = NULL;
	}
}
