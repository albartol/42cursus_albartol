/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:23:30 by albartol          #+#    #+#             */
/*   Updated: 2024/01/29 17:37:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* void	ft_put_images(t_display *display, t_imgs *imgs, t_game *game)
{
	ft_put_img(display, &imgs->wall, game->map, WALL);
	ft_put_img(display, &imgs->obj, game->map, OBJ);
	ft_put_img(display, &imgs->floor, game->map, FLOOR);
	if (game->obj)
		ft_put_img(display, &imgs->exit_closed, game->map, EXIT);
	else
		ft_put_img(display, &imgs->exit, game->map, EXIT);
	ft_put_player(display, imgs, game);
	ft_anim_trap(display, imgs, game->map);
	mlx_put_image_to_window(display->mlx, display->win, imgs->blank.img, 0, 0);
} */

void	ft_put_images(t_display *display, t_imgs *imgs, t_game *game)
{
	if (game->obj == 0)
	{
		ft_put_img(display, &imgs->exit, game->map, EXIT);
		game->obj = -1;
	}
	if (game->x != game->x_old || game->y != game->y_old)
	{
		ft_put_player(display, imgs, game);
		ft_put_floor(display, &imgs->floor, game);
		game->x_old = game->x;
		game->y_old = game->y;
		mlx_put_image_to_window(display->mlx, display->win, imgs->blank.img, \
		0, 0);
		ft_put_moves(game);
	}
	ft_anim_trap(display, imgs, game->map);
}

void	ft_put_moves(t_game *game)
{
	char	*nbr;
	int		len;
	int		i;

	nbr = ft_itoa(game->moves);
	len = (int)ft_strlen(nbr);
	i = 0;
	while (i < len)
	{
		ft_put_font_num(&game->display, &game->font, nbr[i], i + 1);
		i++;
	}
	free(nbr);
}
