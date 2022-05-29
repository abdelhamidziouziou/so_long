/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:31:45 by abziouzi          #+#    #+#             */
/*   Updated: 2022/05/28 15:20:59 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define LEFT 0
# define RIGHT 1
# define DOWN 2
# define UP 3
# define ESC 53

// Includes
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <time.h>

// Structs
typedef struct s_img
{
	void *img;
	int w;
	int h;
}	t_img;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_obj
{
	void *mlx;
	void *win;
	t_img img;
	t_point pos;
}	t_obj;

// Functions
int		check_extension(char *map);
int		check_shape(char *map);
int		ft_printf(const char *userstr, ...);
char	*get_next_line(int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(char *s);

int key_handler(int keycode, t_obj *obj);

#endif
