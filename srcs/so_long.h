/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:22:51 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 17:40:13 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>

enum e_errors
{
	INVALID_MAP = 1,
	INVALID_MAP_PATH = 2,
	INVALID_ARGS = 3,
};

enum e_keys
{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	ESC_KEY = 53
};

// Structs
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_vector	pos;
	t_vector	size;
}	t_vars;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bits_ppx;
	int			l_size;
	int			endian;
	t_vector	size;
}	t_img;

typedef struct s_map
{
	char		**map;
	t_vector	size;
	int			col_count;
	t_vector	*col_pos;
	t_vector	exit_pos;
	t_vector	start_pos;
}	t_map;

typedef struct s_sprites
{
	t_img	bg;
	t_img	wall;
	t_img	col;
	t_img	exit;
	t_img	player;
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			move_count;
	t_vector	p_pos;
	t_vector	size;
	t_map		map;
	t_sprites	sprites;
	t_img		base_map;
}	t_game;

// so_long_utils.c
int		trgb(int t, int r, int g, int b);
void	my_pixel_put(t_img *img, int x, int y, unsigned int colour);
void	fill_vect(t_vector *vect, int x, int y);

// game.c
void	fill_game(t_game *game, int argc, char **argv);

// map checks
// map_parse.c map_parse_col.c map_parse_exit.c
t_map	map_parse(int argc, char **argv);
void	check_walls(t_map *map);
void	col_read(t_map *map);
void	exit_location(t_map *map);
void	start_location(t_map *map);

// error_exit.c
void	error_and_exit(int code);

// sprites / images
// sprites.c put_sprite.c
void	make_sprites(t_game *game);
void	put_sprite(t_img *dst, t_img sprite, int x, int y);

#endif