/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:10:53 by albartol          #+#    #+#             */
/*   Updated: 2024/01/26 18:44:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count_collectibles(char **map)
{
	int		i;
	int		res;
	size_t	j;
	size_t	len;

	i = 1;
	res = 0;
	len = ft_strlen(map[i]);
	while (map[i] && map[i + 1])
	{
		j = 1;
		while (j < len - 1)
		{
			if (map[i][j] == OBJ)
				res++;
			if (map[i + 1][j] == OBJ)
				res++;
			j++;
		}
		i += 2;
	}
	return (res);
}

static int	ft_update_map(char **map, int i, int j, int *col)
{
	if (map[i][j] == FLOOR)
	{
		if (map[i][j + 1] == PLAYER || map[i][j - 1] == PLAYER)
			map[i][j] = PLAYER;
		else if (map[i + 1][j] == PLAYER || map[i - 1][j] == PLAYER)
			map[i][j] = PLAYER;
		if (map[i][j] == PLAYER)
			return (1);
	}
	else if (map[i][j] == OBJ)
	{
		if (map[i][j + 1] == PLAYER || map[i][j - 1] == PLAYER)
			map[i][j] = PLAYER;
		else if (map[i + 1][j] == PLAYER || map[i - 1][j] == PLAYER)
			map[i][j] = PLAYER;
		if (map[i][j] == PLAYER)
		{
			(*col)--;
			return (1);
		}
	}
	return (0);
}

static int	ft_check_exit(char **map, int i, int j)
{
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == EXIT)
			{
				if (map[i][j + 1] == PLAYER)
					return (EXIT_SUCCESS);
				else if (map[i][j - 1] == PLAYER)
					return (EXIT_SUCCESS);
				else if (map[i + 1][j] == PLAYER)
					return (EXIT_SUCCESS);
				else if (map[i - 1][j] == PLAYER)
					return (EXIT_SUCCESS);
				else
					return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}

static int	ft_fill_map(char **map, int col)
{
	int	i;
	int	j;
	int	moving;

	moving = 1;
	while (moving && (col || ft_check_exit(map, 1, 1)))
	{
		moving = 0;
		i = 1;
		while (map[i + 1])
		{
			j = 1;
			while (map[i][j + 1])
			{
				if (ft_update_map(map, i, j, &col))
					moving = 1;
				j++;
			}
			i++;
		}
	}
	if (col || ft_check_exit(map, 1, 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_check_path(char **map)
{
	char	**map_copy;
	int		col;

	map_copy = ft_array_dup(map);
	if (!map_copy)
	{
		ft_free_array(map);
		ft_perror("Error\nFallo en ft_array_dup\n");
	}
	col = ft_count_collectibles(map);
	if (ft_fill_map(map_copy, col))
	{
		ft_free_array(map);
		ft_free_array(map_copy);
		ft_perror("Error\nCamino no valido\n");
	}
	ft_free_array(map_copy);
}
