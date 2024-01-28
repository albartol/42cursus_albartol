/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:17:41 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 19:59:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_screen(void *mlx, int	x_len, int	y_len, char **map)
{
	int	size_x;
	int	size_y;

	mlx_get_screen_size(mlx, &size_x, &size_y);
	if (size_x < x_len || size_y < y_len)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		ft_free_array(map);
		ft_printf("x: %d/%d - y: %d/%d\n", x_len, size_x, y_len, size_y);
		ft_perror("Error\nMapa demasiado grande\n");
	}
}

static void	ft_win_init(char **map, t_display *display, int *x_len, int *y_len)
{
	*x_len = ft_strlen(*map) * TILE_SIZE;
	*y_len = ft_array_len(map) * TILE_SIZE + FREE_SPACE;
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_init\n");
	}
	ft_check_screen(display->mlx, *x_len, *y_len, map);
	display->win = mlx_new_window(display->mlx, *x_len, *y_len, "so_long");
	if (!display->win)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_new_window\n");
	}
}

static void	ft_img_init(t_game *game, t_image *img, char *str)
{
	img->img = mlx_xpm_file_to_image(game->display.mlx, str, &img->width, &img->height);
	if (!img->img)
	{
		ft_end_game(game);
		ft_perror("Error\nFallo en mlx_xpm_file_to_image\n");
	}
}

static void	ft_images_init(t_game *game)
{
	ft_img_init(game, &game->imgs.wall, "./textures/wall.xpm");
	ft_img_init(game, &game->imgs.floor, "./textures/floor.xpm");
	ft_img_init(game, &game->imgs.obj, "./textures/egg.xpm");
	ft_img_init(game, &game->imgs.exit, "./textures/exit.xpm");
	ft_img_init(game, &game->imgs.player, "./textures/rabbit.xpm");
	ft_img_init(game, &game->imgs.player_2, "./textures/rabbit_1.xpm");
	ft_img_init(game, &game->imgs.trap, "./textures/trap.xpm");
}

void	ft_display(t_game *game)
{
	int x;

	ft_win_init(game->map, &game->display, &game->width, &game->height);
	ft_images_init(game);
	x = game->width;
	game->imgs.blank.img = mlx_new_image(game->display.mlx, x, FREE_SPACE);
	if (!game->imgs.blank.img)
	{
		ft_end_game(game);
		ft_perror("Error\nFallo en mlx_new_image\n");
	}
}
