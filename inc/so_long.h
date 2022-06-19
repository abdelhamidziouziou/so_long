/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:08:49 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/19 07:46:46 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include 						"libft.h"
# include 						<mlx.h>

// Keys
# define KEY_LEFT 				0
# define KEY_DOWN 				1
# define KEY_RIGHT 				2
# define KEY_UP 				13
# define KEY_ESC 				53

// Errors & Messages
# define ERR_ARGS				"ERROR : Invalid arguments. Use : ./so_long [*.ber] map."
# define ERR_MAP_EXT			"ERROR : Invalid file extension. Only [*.ber] files allowed."
# define ERR_MAP_EXIT			"ERROR : Exit."
# define ERR_MAP_READ			"ERROR : Could not read map."
# define ERR_MAP_COLLECTIBLES	"ERROR : Collectibles."
# define ERR_MAP_PLAYER			"ERROR : Player."
# define ERR_MAP_WALLS			"ERROR : Walls."
# define ERR_MLX				"ERROR : MLX error."
# define EXIT_GAME				"Closing game..."
# define GAME_SUCCESS			"ALLAH Y TA9ABAL :)"
# define LINES_1				"\n--------------------------------------------\n"

// XPMs
# define COLLECTIBLE			"./img/collectible.xpm"
# define EMPTY					"./img/empty.xpm"
# define ENEMY					"./img/satan.xpm"
# define EXIT					"./img/exit.xpm"
# define PLAYER					"./img/player.xpm"
# define WALL					"./img/wall.xpm"

// Structs

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_map
{
	char		**data;
	size_t		collectibles;
	size_t		exits;
	size_t		players;
	size_t		starting_position;
}				t_map;

typedef struct	s_img
{
	void		*data;
	int			height;
	int			width;
}				t_img;

typedef struct	s_obj
{
	size_t		height;
	size_t		width;
	size_t		moves;

	t_img		collectible;
	t_img		enemy;
	t_img		exit;
	t_img		floor;
	t_img		player;
	t_img		wall;

	t_map		map;

	t_point		enemy_pos;
	t_point		player_pos;

	void		*mlx;
	void		*win;
}				t_obj;

bool			check_each_line(t_obj *obj, char *line, size_t length, int y);
bool			check_fl(char *str);
bool			is_valid_ext(char *filename, char *ext);
bool			map_checker(char *filename, t_obj *obj);

size_t			get_map_lines(char *filename);

void			_error(char *str);
void			free_all(t_obj *obj);
void			load_images(t_obj *obj);
void			movement(int keycode, t_obj *obj);
void			render(t_obj *obj);
void			rendering(t_obj *obj);
void			trim_nl(char *line, int length);

#endif
