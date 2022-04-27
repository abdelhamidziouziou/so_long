/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:45 by abziouzi          #+#    #+#             */
/*   Updated: 2022/04/27 21:02:10 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../inc/ft_printf.h"

int		ft_printf(const char *userstr, ...);
char	*get_next_line(int fd);

// Functions
int		check_extension(char *map);
int		check_shape(char *map);


int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(char *s);

// Structs

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
