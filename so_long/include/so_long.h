/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:53:51 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 19:58:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include <mlx.h>

typedef enum e_tiles
{
	PLAYER = 'P',
	WALL = '1',
	FLOOR = '0',
	OBJ = 'C',
	EXIT = 'E',
	TRAP = 'T',
	TILE_SIZE = 64,
	FREE_SPACE = 30
}				t_tiles;

typedef enum e_keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	WSL_LEFT = 65361,
	WSL_UP = 65362,
	WSL_RIGTH = 65363,
	WSL_DOWN = 65364,
	W_UP = 13,
	S_DOWN = 1,
	D_RIGHT = 2,
	A_LEFT = 0,
	END = 53,
	WSL_END = 65307
}				t_keys;

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}				t_events;

typedef struct s_display
{
	void		*mlx;
	void		*win;
}				t_display;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_imgs
{
	t_image		wall;
	t_image		floor;
	t_image		obj;
	t_image		exit;
	t_image		player;
	t_image		player_2;
	t_image		trap;
	t_image		blank;
}				t_imgs;

typedef struct s_game
{
	t_display	display;
	t_imgs		imgs;
	char		**map;
	int			y;
	int			x;
	int			moves;
	int			obj;
	int			width;
	int			height;
}				t_game;

// ft_get_map: read map from "*.ber" file

char			**ft_get_map(char *file);

// ft_check_map: check if map is valid

void			ft_check_map(char **map);
int				ft_check_content(char **map);
void			ft_check_path(char **map);

// ft_display: mlx part

void			ft_display(t_game *game);

// ft_hooks

void			ft_destroy_images(void *mlx, t_imgs imgs);
int				ft_process_input(int keycode, t_game *game);
int				ft_close(t_game *game);
int				ft_render_frame(t_game *game);

// ft_render_frame

void			ft_str_init(t_display *display, int x, int y, char *str);
void			ft_put_img(t_display *display, t_image *img, char **map,
					int tile);
void			ft_put_images(char **map, t_display *display, t_imgs *imgs);
void			ft_put_background(char **map, t_display *display, t_imgs *imgs);

// ft_move_player

void			ft_move_player(int keycode, t_game *game);

// ft_check_path

int				ft_count_collectibles(char **map);

// so_long -> ft_end_game

void			ft_end_game(t_game	*game);

// so_long_utils: later move to libft

void			ft_perror(const char *str);
void			ft_free_array(char **array);
char			**ft_array_dup(char **array);
int				ft_array_len(char **array);

#endif