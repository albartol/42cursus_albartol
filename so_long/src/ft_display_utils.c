/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:49:50 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 16:27:00 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_init(char **map, t_display *display)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(*map) * TILE_SIZE;
	y_len = ft_array_len(map) * TILE_SIZE;
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_init");
	}
	display->win = mlx_new_window(display->mlx, x_len, y_len, "so_long");
	if (!display->win)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_new_window");
	}
}

void	ft_str_init(t_display *display, int x, int y, char *str)
{
	mlx_string_put(display->mlx, display->win, x, y, 0x00FF0000, str);
}

void	ft_img_init(t_display *d, t_image *img, char *str, char **map)
{
	img->img = mlx_xpm_file_to_image(d->mlx, str, &img->width, &img->height);
	if (!img->img)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_xpm_file_to_image");
	}
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
					* TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
