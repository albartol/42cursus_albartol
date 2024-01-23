/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:08 by albartol          #+#    #+#             */
/*   Updated: 2024/01/23 18:17:51 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	ft_leaks(void)
{
	system("leaks so_long");
}

int  ft_close(int keycode, t_display *display)
{
	(void)keycode;
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_display	display;

	atexit(ft_leaks);
	if (argc != 2)
		return (EXIT_FAILURE);
	map = ft_get_map(argv[1]);
	ft_check_map(map);
	ft_display(map, &display);
	ft_print_array(map);
	ft_free_array(map);
	mlx_hook(display.win, 2, 0, ft_close, &display);
	mlx_loop(display.mlx);
	return (EXIT_SUCCESS);
}
