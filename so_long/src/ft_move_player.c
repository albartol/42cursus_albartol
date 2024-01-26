/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:28:34 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 18:49:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_move_up(t_game *game)
{
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
}
