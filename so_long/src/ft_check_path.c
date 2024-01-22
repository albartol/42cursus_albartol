/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:10:53 by albartol          #+#    #+#             */
/*   Updated: 2024/01/22 18:28:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_count_collectibles(char **map)
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
			if (map[i][j] == 'C')
				res++;
			if (map[i + 1][j] == 'C')
				res++;
			j++;
		}
		i += 2;
	}
	return (res);
}

static int	ft_update_map(char **map, int i, int j, int *col)
{
	if (map[i][j] == '0')
	{
		if (map[i][j + 1] == 'P' || map[i][j - 1] == 'P')
			map[i][j] = 'P';
		else if (map[i + 1][j] == 'P' || map[i - 1][j] == 'P')
			map[i][j] = 'P';
		if (map[i][j] == 'P')
			return (1);
	}
	else if (map[i][j] == 'C')
	{
		if (map[i][j + 1] == 'P' || map[i][j - 1] == 'P')
			map[i][j] = 'P';
		else if (map[i + 1][j] == 'P' || map[i - 1][j] == 'P')
			map[i][j] = 'P';
		if (map[i][j] == 'P')
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
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] == 'P')
					return (EXIT_SUCCESS);
				else if (map[i][j - 1] == 'P')
					return (EXIT_SUCCESS);
				else if (map[i + 1][j] == 'P')
					return (EXIT_SUCCESS);
				else if (map[i - 1][j] == 'P')
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
		ft_perror("Error\nCamino no valido\n");
	}
	ft_free_array(map_copy);
}
