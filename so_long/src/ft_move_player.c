/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:28:34 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 20:04:01 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] == WALL)
		return ;
	if (game->map[game->y - 1][game->x] == FLOOR || game->map[game->y
		- 1][game->x] == OBJ)
	{
		if (game->map[game->y - 1][game->x] == OBJ)
			game->obj--;
		game->map[game->y - 1][game->x] = PLAYER;
		game->map[game->y][game->x] = FLOOR;
		game->y--;
		game->moves++;
	}
	else if (game->map[game->y - 1][game->x] == TRAP || game->map[game->y
		- 1][game->x] == EXIT)
	{
		if (game->map[game->y - 1][game->x] == EXIT && game->obj)
			return ;
		mlx_destroy_window(game->display.mlx, game->display.win);
		ft_destroy_images(game->display.mlx, game->imgs);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] == WALL)
		return ;
	if (game->map[game->y + 1][game->x] == FLOOR || game->map[game->y
		+ 1][game->x] == OBJ)
	{
		if (game->map[game->y + 1][game->x] == OBJ)
			game->obj--;
		game->map[game->y + 1][game->x] = PLAYER;
		game->map[game->y][game->x] = FLOOR;
		game->y++;
		game->moves++;
	}
	else if (game->map[game->y + 1][game->x] == TRAP || game->map[game->y
		+ 1][game->x] == EXIT)
	{
		if (game->map[game->y + 1][game->x] == EXIT && game->obj)
			return ;
		mlx_destroy_window(game->display.mlx, game->display.win);
		ft_destroy_images(game->display.mlx, game->imgs);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] == WALL)
		return ;
	if (game->map[game->y][game->x - 1] == FLOOR || game->map[game->y][game->x
		- 1] == OBJ)
	{
		if (game->map[game->y][game->x - 1] == OBJ)
			game->obj--;
		game->map[game->y][game->x - 1] = PLAYER;
		game->map[game->y][game->x] = FLOOR;
		game->x--;
		game->moves++;
	}
	else if (game->map[game->y][game->x - 1] == TRAP
		|| game->map[game->y][game->x - 1] == EXIT)
	{
		if (game->map[game->y][game->x - 1] == EXIT && game->obj)
			return ;
		mlx_destroy_window(game->display.mlx, game->display.win);
		ft_destroy_images(game->display.mlx, game->imgs);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_move_rigth(t_game *game)
{
	if (game->map[game->y][game->x + 1] == WALL)
		return ;
	if (game->map[game->y][game->x + 1] == FLOOR || game->map[game->y][game->x
		+ 1] == OBJ)
	{
		if (game->map[game->y][game->x + 1] == OBJ)
			game->obj--;
		game->map[game->y][game->x + 1] = FLOOR;
		game->map[game->y][game->x + 1] = PLAYER;
		game->map[game->y][game->x] = FLOOR;
		game->x++;
		game->moves++;
	}
	else if (game->map[game->y][game->x + 1] == TRAP
		|| game->map[game->y][game->x + 1] == EXIT)
	{
		if (game->map[game->y][game->x + 1] == EXIT && game->obj)
			return ;
		mlx_destroy_window(game->display.mlx, game->display.win);
		ft_destroy_images(game->display.mlx, game->imgs);
		exit(EXIT_SUCCESS);
	}
}

void	ft_move_player(int keycode, t_game *game)
{
	if (keycode == UP)
		ft_move_up(game);
	else if (keycode == DOWN)
		ft_move_down(game);
	else if (keycode == LEFT)
		ft_move_left(game);
	else if (keycode == RIGHT)
		ft_move_rigth(game);
	// ft_print_array(game->map);
	// ft_printf("y: %d x: %d obj:%d\n", game->y, game->x, game->obj);
}
