/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:17:41 by albartol          #+#    #+#             */
/*   Updated: 2024/01/23 18:08:58 by albartol         ###   ########.fr       */
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
		ft_perror("Error\nFallo en mlx_init");
	}
	display->win = mlx_new_window(display->mlx, x_len, y_len, "so_long");
	if (!display->win)
	{
		ft_free_array(map);
		mlx_destroy_window(display->mlx, display->win);
		ft_perror("Error\nFallo en mlx_init");
	}
}

void	ft_display(char **map, t_display *display)
{
	ft_display_init(map, display);
}
