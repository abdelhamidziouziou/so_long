/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:22 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/02 18:03:12 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(int argc, char *argv[])
int main()
{
	void *mlx_ptr;
	void *mlx_window;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 800, 600, "abziouzi's So Long");
	printf("Hello\n");
	mlx_loop(mlx_ptr);
}
