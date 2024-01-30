/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:48:30 by albartol          #+#    #+#             */
/*   Updated: 2024/01/30 21:00:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	ft_img_init(t_game *game, t_image *img, char *str)
{
	img->img = mlx_xpm_file_to_image(game->display.mlx, str, &img->width,
			&img->height);
	if (!img->img)
	{
		ft_end_game(game);
		ft_perror("Error\nFallo en mlx_xpm_file_to_image\n");
	}
}

void	ft_destroy_images(void *mlx, t_imgs imgs)
{
	if (imgs.exit.img)
		mlx_destroy_image(mlx, imgs.exit.img);
	if (imgs.wall.img)
		mlx_destroy_image(mlx, imgs.wall.img);
	if (imgs.player.img)
		mlx_destroy_image(mlx, imgs.player.img);
	if (imgs.player_up.img)
		mlx_destroy_image(mlx, imgs.player_up.img);
	if (imgs.player_left.img)
		mlx_destroy_image(mlx, imgs.player_left.img);
	if (imgs.player_right.img)
		mlx_destroy_image(mlx, imgs.player_right.img);
	if (imgs.trap.img)
		mlx_destroy_image(mlx, imgs.trap.img);
	if (imgs.trap_1.img)
		mlx_destroy_image(mlx, imgs.trap_1.img);
	if (imgs.trap_2.img)
		mlx_destroy_image(mlx, imgs.trap_2.img);
	if (imgs.floor.img)
		mlx_destroy_image(mlx, imgs.floor.img);
	if (imgs.obj.img)
		mlx_destroy_image(mlx, imgs.obj.img);
	if (imgs.blank.img)
		mlx_destroy_image(mlx, imgs.blank.img);
}

void	ft_destroy_font(void *mlx, t_font font)
{
	if (font.num_0.img)
		mlx_destroy_image(mlx, font.num_0.img);
	if (font.num_1.img)
		mlx_destroy_image(mlx, font.num_1.img);
	if (font.num_2.img)
		mlx_destroy_image(mlx, font.num_2.img);
	if (font.num_3.img)
		mlx_destroy_image(mlx, font.num_3.img);
	if (font.num_4.img)
		mlx_destroy_image(mlx, font.num_4.img);
	if (font.num_5.img)
		mlx_destroy_image(mlx, font.num_5.img);
	if (font.num_6.img)
		mlx_destroy_image(mlx, font.num_6.img);
	if (font.num_7.img)
		mlx_destroy_image(mlx, font.num_7.img);
	if (font.num_8.img)
		mlx_destroy_image(mlx, font.num_8.img);
	if (font.num_9.img)
		mlx_destroy_image(mlx, font.num_9.img);
}
