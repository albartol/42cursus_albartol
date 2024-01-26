/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:17:41 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 16:09:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_images_init(char **map, t_display *display, t_imgs *imgs)
{
	ft_img_init(display, &imgs->wall, "./textures/wall.xpm", map);
	ft_img_init(display, &imgs->floor, "./textures/floor.xpm", map);
	ft_img_init(display, &imgs->obj, "./textures/egg.xpm", map);
	ft_img_init(display, &imgs->exit, "./textures/exit.xpm", map);
	ft_img_init(display, &imgs->player, "./textures/rabbit.xpm", map);
	ft_img_init(display, &imgs->trap, "./textures/trap.xpm", map);
}

static void	ft_put_images(char **map, t_display *display, t_imgs *imgs)
{
	ft_put_img(display, &imgs->wall, map, WALL);
	ft_put_img(display, &imgs->floor, map, FLOOR);
	ft_put_img(display, &imgs->obj, map, OBJ);
	ft_put_img(display, &imgs->trap, map, TRAP);
	ft_put_img(display, &imgs->exit, map, EXIT);
	ft_put_img(display, &imgs->player, map, PLAYER);
}

void	ft_display(char **map, t_display *display, t_imgs *imgs)
{
	ft_display_init(map, display);
	ft_images_init(map, display, imgs);
	ft_put_images(map, display, imgs);
	ft_str_init(display, 4, 4, "Number of movements: ");
}
