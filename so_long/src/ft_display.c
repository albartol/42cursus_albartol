/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:17:41 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 15:22:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* static void	ft_check_screen(void *mlx, int x_len, int y_len, char **map)
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
} */

/* static void	ft_win_init(char **map, t_display *display, int *x, int *y)
{
	*x = ft_strlen(*map) * TILE_SIZE;
	*y = ft_array_len(map) * TILE_SIZE + FREE_SPACE;
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_init\n");
	}
	ft_check_screen(display->mlx, *x, *y, map);
	display->win = mlx_new_window(display->mlx, *x, *y, "so_long");
	if (!display->win)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_new_window\n");
	}
} */

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
	display->win = mlx_new_window(display->mlx, *x_len, *y_len, "so_long");
	if (!display->win)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en mlx_new_window\n");
	}
}

static void	ft_images_init(t_game *game)
{
	ft_img_init(game, &game->imgs.wall, "./textures/wall.xpm");
	ft_img_init(game, &game->imgs.floor, "./textures/floor.xpm");
	ft_img_init(game, &game->imgs.obj, "./textures/egg.xpm");
	ft_img_init(game, &game->imgs.exit, "./textures/exit.xpm");
	ft_img_init(game, &game->imgs.exit_closed, "./textures/exit_closed.xpm");
	ft_img_init(game, &game->imgs.player, "./textures/rabbit_3.xpm");
	ft_img_init(game, &game->imgs.player_up, "./textures/rabbit_2.xpm");
	ft_img_init(game, &game->imgs.player_left, "./textures/rabbit.xpm");
	ft_img_init(game, &game->imgs.player_right, "./textures/rabbit_1.xpm");
	ft_img_init(game, &game->imgs.trap, "./textures/trap.xpm");
	ft_img_init(game, &game->imgs.trap_1, "./textures/trap_2.xpm");
	ft_img_init(game, &game->imgs.trap_2, "./textures/trap_3.xpm");
}

static void	ft_font_init(t_game *game)
{
	ft_img_init(game, &game->font.num_0, "./textures/num_0.xpm");
	ft_img_init(game, &game->font.num_1, "./textures/num_1.xpm");
	ft_img_init(game, &game->font.num_2, "./textures/num_2.xpm");
	ft_img_init(game, &game->font.num_3, "./textures/num_3.xpm");
	ft_img_init(game, &game->font.num_4, "./textures/num_4.xpm");
	ft_img_init(game, &game->font.num_5, "./textures/num_5.xpm");
	ft_img_init(game, &game->font.num_6, "./textures/num_6.xpm");
	ft_img_init(game, &game->font.num_7, "./textures/num_7.xpm");
	ft_img_init(game, &game->font.num_8, "./textures/num_8.xpm");
	ft_img_init(game, &game->font.num_9, "./textures/num_9.xpm");
}

void	ft_display(t_game *game)
{
	int	x;

	ft_win_init(game->map, &game->display, &game->width, &game->height);
	ft_images_init(game);
	x = game->width;
	game->imgs.blank.img = mlx_new_image(game->display.mlx, x, FREE_SPACE);
	if (!game->imgs.blank.img)
	{
		ft_end_game(game);
		ft_perror("Error\nFallo en mlx_new_image\n");
	}
	ft_font_init(game);
	ft_put_img(&game->display, &game->imgs.wall, game->map, WALL);
	ft_put_img(&game->display, &game->imgs.obj, game->map, OBJ);
	ft_put_img(&game->display, &game->imgs.exit_closed, game->map, EXIT);
	ft_put_img(&game->display, &game->imgs.floor, game->map, FLOOR);
	ft_put_player(&game->display, &game->imgs, game);
	ft_put_moves(game);
}
