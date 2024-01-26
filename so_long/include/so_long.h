/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:53:51 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 16:26:36 by albartol         ###   ########.fr       */
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
	TILE_SIZE = 64
}			t_tiles;

typedef struct s_display
{
	void	*mlx;
	void	*win;
}			t_display;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_imgs
{
	t_image	wall;
	t_image	floor;
	t_image	obj;
	t_image	exit;
	t_image	player;
	t_image	trap;
}			t_imgs;

// ft_get_map: read map from "*.ber" file

char		**ft_get_map(char *file);

// ft_check_map: check if map is valid

void		ft_check_map(char **map);
int			ft_check_content(char **map);
void		ft_check_path(char **map);

// ft_display: mlx part

void		ft_display(char **map, t_display *display, t_imgs *imgs);
void		ft_display_init(char **map, t_display *display);
void		ft_str_init(t_display *display, int x, int y, char *str);
void		ft_img_init(t_display *display, t_image *img, char *str,
				char **map);
void		ft_put_img(t_display *display, t_image *img, char **map, int tile);

// so_long_utils: later move to libft

void		ft_perror(const char *str);
void		ft_free_array(char **array);
char		**ft_array_dup(char **array);
int			ft_array_len(char **array);

#endif