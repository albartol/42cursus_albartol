/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:23:30 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 19:57:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_str_init(t_display *display, int x, int y, char *str)
{
	mlx_string_put(display->mlx, display->win, x, y, 0x00FFFFFF, str);
}

void	ft_put_img(t_display *display, t_image *img, char **map, int tile)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == tile)
			{
				mlx_put_image_to_window(display->mlx, display->win, img->img, x
					* TILE_SIZE, y * TILE_SIZE + FREE_SPACE);
			}
			x++;
		}
		y++;
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

void	ft_put_images(char **map, t_display *display, t_imgs *imgs)
{
	mlx_put_image_to_window(display->mlx, display->win, imgs->blank.img, 0, 0);
	ft_put_img(display, &imgs->wall, map, WALL);
	ft_put_img(display, &imgs->floor, map, FLOOR);
	ft_put_img(display, &imgs->obj, map, OBJ);
	ft_put_img(display, &imgs->trap, map, TRAP);
	ft_put_img(display, &imgs->exit, map, EXIT);
	ft_put_img(display, &imgs->player, map, PLAYER);
}
