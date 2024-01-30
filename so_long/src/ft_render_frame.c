/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:23:30 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 17:37:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_str_init(t_display *display, int x, int y, char *str)
{
	mlx_string_put(display->mlx, display->win, x, y, 0x00FFFFFF, str);
}

void	ft_put_img(t_display *display, t_image *img, char **map, int tile)
{
	int	y;
	int	x;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == tile)
			{
				mlx_put_image_to_window(display->mlx, display->win, img->img, y
					* TILE_SIZE, x * TILE_SIZE + FREE_SPACE);
			}
			y++;
		}
		x++;
	}
}

// void	ft_put_background(char **map, t_display *display, t_imgs *imgs)
// {
// 	int	x;
// 	int	y;

// 	y = 1;
// 	while (map[y + 1])
// 	{
// 		x = 1;
// 		while (map[y][x + 1])
// 		{
// 			mlx_put_image_to_window(display->mlx, display->win, imgs->floor.img,
// 				x * TILE_SIZE, y * TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// }

static void	ft_anim_trap(t_display *display, t_imgs *imgs, char **map)
{
	static int	i;

	if (i++ < 30) // 240
		ft_put_img(display, &imgs->trap_2, map, TRAP);
	else if (i++ < 60) // 480
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	else if (i++ < 90) // 720
		ft_put_img(display, &imgs->trap, map, TRAP);
	else if (i++ < 120) // 960
		ft_put_img(display, &imgs->trap_1, map, TRAP);
	if (i >= 120) // 960
		i = 0;
}

static void	ft_put_player(t_display *display, t_imgs *imgs, char **map, int pos)
{
	if (!pos)
		ft_put_img(display, &imgs->player, map, PLAYER);
	else if(pos == 1)
		ft_put_img(display, &imgs->player_up, map, PLAYER);
	else if(pos == 2)
		ft_put_img(display, &imgs->player_left, map, PLAYER);
	else
		ft_put_img(display, &imgs->player_right, map, PLAYER);
}

void	ft_put_images(char **map, t_display *display, t_imgs *imgs, t_game *g)
{

	// usleep(10000); // justify usage
	mlx_put_image_to_window(display->mlx, display->win, imgs->blank.img, 0, 0);
	// ft_put_img(display, &imgs->wall, map, WALL);
	// ft_put_img(display, &imgs->obj, map, OBJ);
	ft_put_img(display, &imgs->floor, map, FLOOR);
	// if (!g->obj)
	// 	ft_put_img(display, &imgs->exit_closed, map, EXIT);
	// else
	// 	ft_put_img(display, &imgs->exit, map, EXIT);
	if (g->obj == 0)
	{
		ft_put_img(display, &imgs->exit, map, EXIT);
		g->obj = -1;
	}
	ft_put_player(display, imgs, map, g->pos);
	ft_anim_trap(display, imgs, map);
}
