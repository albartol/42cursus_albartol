/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:28:34 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 15:17:11 by albartol         ###   ########.fr       */
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
		// mlx_loop_end(game->display.mlx);
		ft_end_game(game);
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
		// mlx_loop_end(game->display.mlx);
		ft_end_game(game);
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
		game->pos = 0;
	}
	else if (game->map[game->y][game->x - 1] == TRAP
		|| game->map[game->y][game->x - 1] == EXIT)
	{
		if (game->map[game->y][game->x - 1] == EXIT && game->obj)
			return ;
		// mlx_loop_end(game->display.mlx);
		ft_end_game(game);
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
		game->map[game->y][game->x + 1] = PLAYER;
		game->map[game->y][game->x] = FLOOR;
		game->x++;
		game->moves++;
		game->pos = 1;
	}
	else if (game->map[game->y][game->x + 1] == TRAP
		|| game->map[game->y][game->x + 1] == EXIT)
	{
		if (game->map[game->y][game->x + 1] == EXIT && game->obj)
			return ;
		// mlx_loop_end(game->display.mlx);
		ft_end_game(game);
		exit(EXIT_SUCCESS);
	}
}

void	ft_move_player(int keycode, t_game *game)
{
	if (keycode == UP || keycode == WSL_UP)
		ft_move_up(game);
	else if (keycode == DOWN || keycode == WSL_DOWN)
		ft_move_down(game);
	else if (keycode == LEFT || keycode == WSL_LEFT)
		ft_move_left(game);
	else if (keycode == RIGHT || keycode == WSL_RIGTH)
		ft_move_rigth(game);
	// ft_print_array(game->map);
	// ft_printf("y: %d x: %d obj:%d\n", game->y, game->x, game->obj);
}
