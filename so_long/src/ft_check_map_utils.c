/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:51:29 by albartol          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_map_content(char c)
{
	if (c == FLOOR)
		return (EXIT_SUCCESS);
	else if (c == WALL)
		return (EXIT_SUCCESS);
	else if (c == OBJ)
		return (EXIT_SUCCESS);
	else if (c == TRAP)
		return (EXIT_SUCCESS);
	else if (c == PLAYER)
		return (EXIT_SUCCESS);
	else if (c == EXIT)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_check_content(char **map)
{
	int		i;
	size_t	j;
	size_t	len;
	size_t	half;

	i = 1;
	len = ft_strlen(map[i]);
	half = ft_strlen(map[i]) / 2;
	while (map[i] && map[i + 1])
	{
		j = 0;
		while (++j <= half)
		{
			if (ft_map_content(map[i][j]))
				return (EXIT_FAILURE);
			if (ft_map_content(map[i + 1][j]))
				return (EXIT_FAILURE);
			if (ft_map_content(map[i][len - j]))
				return (EXIT_FAILURE);
			if (ft_map_content(map[i + 1][len - j]))
				return (EXIT_FAILURE);
		}
		i += 2;
	}
	return (EXIT_SUCCESS);
}
