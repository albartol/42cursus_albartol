/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:09:21 by albartol          #+#    #+#             */
/*   Updated: 2024/01/30 22:17:06 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* void	ft_anim_trap(t_display *display, t_imgs *imgs, char **map)
{
	static int	i;

	if (i == 0)
		ft_put_img(display, &imgs->trap_2, map, TRAP);
	else if (i == 240)
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	else if (i == 480)
		ft_put_img(display, &imgs->trap, map, TRAP);
	else if (i == 720)
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	i++;
	if (i >= 960)
		i = 0;
} */

void	ft_anim_trap(t_display *display, t_imgs *imgs, char **map)
{
	static int	i;

	if (i == 0)
		ft_put_img(display, &imgs->trap_2, map, TRAP);
	else if (i == 30)
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	else if (i == 60)
		ft_put_img(display, &imgs->trap, map, TRAP);
	else if (i == 90)
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	i++;
	if (i >= 120)
		i = 0;
}

void	ft_put_player(t_display *d, t_imgs *imgs, t_game *game)
{
	int	x;
	int	y;

	x = game->x * TILE_SIZE;
	y = game->y * TILE_SIZE + FREE_SPACE;
	if (!game->pos)
		mlx_put_image_to_window(d->mlx, d->win, imgs->player.img, x, y);
	else if (game->pos == 1)
		mlx_put_image_to_window(d->mlx, d->win, imgs->player_up.img, x, y);
	else if (game->pos == 2)
		mlx_put_image_to_window(d->mlx, d->win, imgs->player_left.img, x, y);
	else
		mlx_put_image_to_window(d->mlx, d->win, imgs->player_right.img, x, y);
}

/* void	ft_put_floor(t_display *display, t_image *img, t_game *game)
{
	int	x;
	int	y;

	x = game->x * TILE_SIZE;
	y = game->y * TILE_SIZE + FREE_SPACE;
	if (!game->pos)
		y = (game->y - 1) * TILE_SIZE + FREE_SPACE;
	else if (game->pos == 1)
		y = (game->y + 1) * TILE_SIZE + FREE_SPACE;
	else if (game->pos == 2)
		x = (game->x + 1) * TILE_SIZE;
	else
		x = (game->x - 1) * TILE_SIZE;
	mlx_put_image_to_window(display->mlx, display->win, img->img, x, y);
} */

void	ft_put_floor(t_display *display, t_image *img, t_game *game)
{
	if (game->map[game->y - 1][game->x - 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x - 1) * TILE_SIZE, (game->y - 1) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y - 1][game->x] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x) * TILE_SIZE, (game->y - 1) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y - 1][game->x + 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x + 1) * TILE_SIZE, (game->y - 1) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y][game->x - 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x - 1) * TILE_SIZE, (game->y) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y][game->x + 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x + 1) * TILE_SIZE, (game->y) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y + 1][game->x - 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x - 1) * TILE_SIZE, (game->y + 1) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y + 1][game->x] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x) * TILE_SIZE, (game->y + 1) * TILE_SIZE + FREE_SPACE);
	if (game->map[game->y + 1][game->x + 1] == FLOOR)
		mlx_put_image_to_window(display->mlx, display->win, img->img, \
		(game->x + 1) * TILE_SIZE, (game->y + 1) * TILE_SIZE + FREE_SPACE);
}

void	ft_put_font_num(t_display *d, t_font *font, char c, int i)
{
	if (c == '1')
		mlx_put_image_to_window(d->mlx, d->win, font->num_1.img, i * 16, 8);
	else if (c == '2')
		mlx_put_image_to_window(d->mlx, d->win, font->num_2.img, i * 16, 8);
	else if (c == '3')
		mlx_put_image_to_window(d->mlx, d->win, font->num_3.img, i * 16, 8);
	else if (c == '4')
		mlx_put_image_to_window(d->mlx, d->win, font->num_4.img, i * 16, 8);
	else if (c == '5')
		mlx_put_image_to_window(d->mlx, d->win, font->num_5.img, i * 16, 8);
	else if (c == '6')
		mlx_put_image_to_window(d->mlx, d->win, font->num_6.img, i * 16, 8);
	else if (c == '7')
		mlx_put_image_to_window(d->mlx, d->win, font->num_7.img, i * 16, 8);
	else if (c == '8')
		mlx_put_image_to_window(d->mlx, d->win, font->num_8.img, i * 16, 8);
	else if (c == '9')
		mlx_put_image_to_window(d->mlx, d->win, font->num_9.img, i * 16, 8);
	else if (c == '0')
		mlx_put_image_to_window(d->mlx, d->win, font->num_0.img, i * 16, 8);
}
