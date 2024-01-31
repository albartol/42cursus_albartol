/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:08 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 14:45:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* void	ft_print_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
} */

/* void	ft_leaks(void)
{
	int	i;

	i = system("leaks so_long");
	(void)i;
} */

static void	ft_get_player(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == PLAYER)
			{
				game->x_old = game->x;
				game->y_old = game->y;
				return ;
			}
			game->x++;
		}
		game->y++;
	}
}

void	ft_print_moves(int moves)
{
	char	*str;
	char	*str2;

	str = "-----------------------------\n";
	str2 = "Numero de movimientos: ";
	ft_printf("%s", str);
	ft_printf("%s%d\n", str2, moves);
	ft_printf("%s", str);
}

void	ft_last_message(char c, int moves)
{
	char	*str;
	char	*str2;

	ft_print_moves(moves + 1);
	str = "-----------------------------\n";
	if (c == EXIT)
		str2 = "|          YOU WIN          |\n";
	else
		str2 = "|          YOU LOSE         |\n";
	ft_printf("%s", str);
	ft_printf("%s", str2);
	ft_printf("%s", str);
}

/* void	ft_end_game(t_game	*game)
{
	mlx_destroy_window(game->display.mlx, game->display.win);
	ft_destroy_images(game->display.mlx, game->imgs);
	ft_destroy_font(game->display.mlx, game->font);
	mlx_destroy_display(game->display.mlx);
	free(game->display.mlx);
	ft_free_array(game->map);
} */

void	ft_end_game(t_game	*game)
{
	mlx_destroy_window(game->display.mlx, game->display.win);
	ft_destroy_images(game->display.mlx, game->imgs);
	ft_destroy_font(game->display.mlx, game->font);
	ft_free_array(game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game.map = ft_get_map(argv[1]);
	ft_check_map(game.map);
	ft_get_player(&game);
	game.map[game.y][game.x] = FLOOR;
	game.obj = ft_count_collectibles(game.map);
	game.moves = 0;
	ft_display(&game);
	mlx_hook(game.display.win, ON_KEYDOWN, (1L << 0), ft_process_input, &game);
	mlx_hook(game.display.win, ON_DESTROY, 0, ft_close, &game);
	mlx_loop_hook(game.display.mlx, ft_render_frame, &game);
	mlx_loop(game.display.mlx);
	ft_end_game(&game);
	return (EXIT_SUCCESS);
}

/* int	main(int argc, char **argv)
{
	t_game	game;

	// atexit(ft_leaks);
	if (argc != 2)
		return (EXIT_FAILURE);
	game.moves = 0;
	game.map = ft_get_map(argv[1]);
	// ft_print_array(game.map);
	ft_check_map(game.map);
	ft_get_player(&game);
	game.map[game.y][game.x] = FLOOR;
	game.obj = ft_count_collectibles(game.map);
	// ft_printf("y: %d x: %d obj:%d\n", game.y, game.x, game.obj);
	ft_display(&game);
	mlx_hook(game.display.win, ON_KEYDOWN, (1L << 0), ft_process_input, &game);
	mlx_hook(game.display.win, ON_DESTROY, 0, ft_close, &game);
	mlx_loop_hook(game.display.mlx, ft_render_frame, &game);
	mlx_loop(game.display.mlx);
	ft_end_game(&game);
	return (EXIT_SUCCESS);
} */
