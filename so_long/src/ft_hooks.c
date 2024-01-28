/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:11:09 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 20:05:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_images(void *mlx, t_imgs imgs)
{
	if (imgs.exit.img)
		mlx_destroy_image(mlx, imgs.exit.img);
	if (imgs.wall.img)
		mlx_destroy_image(mlx, imgs.wall.img);
	if (imgs.player.img)
		mlx_destroy_image(mlx, imgs.player.img);
	if (imgs.player_2.img)
		mlx_destroy_image(mlx, imgs.player_2.img);
	if (imgs.trap.img)
		mlx_destroy_image(mlx, imgs.trap.img);
	if (imgs.floor.img)
		mlx_destroy_image(mlx, imgs.floor.img);
	if (imgs.obj.img)
		mlx_destroy_image(mlx, imgs.obj.img);
	if (imgs.blank.img)
		mlx_destroy_image(mlx, imgs.blank.img);
}

int	ft_process_input(int keycode, t_game *game)
{
	// ft_printf("keycode: %d\n", keycode);
	if (keycode == END || keycode == WSL_END)
		mlx_loop_end(game->display.mlx);
	ft_move_player(keycode, game);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_loop_end(game->display.mlx);
	// mlx_destroy_window(game->display.mlx, game->display.win);
	// ft_destroy_images(game->display.mlx, game->imgs);
	// exit(EXIT_SUCCESS);
	return (0);
}

int	ft_render_frame(t_game *game)
{
	char	*nbr;
	char	*str;

	ft_put_images(game->map, &game->display, &game->imgs);
	nbr = ft_itoa(game->moves);
	str = ft_strjoin("Number of movements: ", nbr);
	ft_str_init(&game->display, 10, 20, str);
	free(nbr);
	free(str);
	return (0);
}
