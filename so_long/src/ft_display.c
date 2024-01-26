/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:17:41 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 18:40:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_display_init(char **map, t_display *display)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(*map) * TILE_SIZE;
	y_len = ft_array_len(map) * TILE_SIZE;
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_init\n");
	}
	display->win = mlx_new_window(display->mlx, x_len, y_len, "so_long");
	if (!display->win)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_new_window\n");
	}
}

static void	ft_img_init(t_display *d, t_image *img, char *str, char **map)
{
	img->img = mlx_xpm_file_to_image(d->mlx, str, &img->width, &img->height);
	if (!img->img)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_xpm_file_to_image\n");
	}
}

static void	ft_images_init(char **map, t_display *display, t_imgs *imgs)
{
	ft_img_init(display, &imgs->wall, "./textures/wall.xpm", map);
	ft_img_init(display, &imgs->floor, "./textures/floor.xpm", map);
	ft_img_init(display, &imgs->obj, "./textures/egg.xpm", map);
	ft_img_init(display, &imgs->exit, "./textures/exit.xpm", map);
	ft_img_init(display, &imgs->player, "./textures/rabbit.xpm", map);
	ft_img_init(display, &imgs->trap, "./textures/trap.xpm", map);
}

void	ft_display(char **map, t_display *display, t_imgs *imgs)
{
	ft_display_init(map, display);
	ft_images_init(map, display, imgs);
}
