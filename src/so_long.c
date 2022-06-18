/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:27:36 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/18 06:19:16 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_obj	obj;

	if (argc != 2)
		return (_error(ERR_ARGS), 1);
	ft_bzero(&obj, sizeof(t_obj));
	ft_bzero(&obj.map, sizeof(t_map));
	if (!is_valid_ext(argv[1], ".ber"))
		return (_error(ERR_MAP_EXT), 1);
	else if (!map_checker(argv[1], &obj))
		return (_error(ERR_MAP_READ), free_all(&obj), 1);
	render(&obj);
	return (1);
}
