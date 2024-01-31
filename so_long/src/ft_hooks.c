/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:11:09 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* int	ft_process_input(int keycode, t_game *game)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == END || keycode == WSL_END)
		mlx_loop_end(game->display.mlx);
	ft_move_player(keycode, game);
	return (0);
} */

int	ft_process_input(int keycode, t_game *game)
{
	if (keycode == END || keycode == WSL_END)
	{
		ft_end_game(game);
		exit(EXIT_SUCCESS);
	}
	ft_move_player(keycode, game);
	return (0);
}

/* int	ft_close(t_game *game)
{
	mlx_loop_end(game->display.mlx);
	return (0);
} */

int	ft_close(t_game *game)
{
	ft_end_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

/* int	ft_render_frame(t_game *game)
{
	ft_put_images(&game->display, &game->imgs, game);
	ft_put_moves(game);
	return (0);
} */

int	ft_render_frame(t_game *game)
{
	ft_put_images(&game->display, &game->imgs, game);
	return (0);
}
