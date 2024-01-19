/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:09:40 by albartol          #+#    #+#             */
/*   Updated: 2024/01/19 17:47:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	ft_check_dup(char **map, char c, short dup)
{
	int		i;
	size_t	j;
	size_t	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (map[i + 1])
	{
		j = 1;
		while (j <= len / 2)
		{
			if (map[i][j] == c)
				dup++;
			if (map[i][len - j] == c)
				dup++;
			j++;
		}
		if (dup > 1)
			return (EXIT_FAILURE);
		i++;
	}
	if (dup != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	ft_check_collectible(char **map)
{
	int		i;
	size_t	j;
	size_t	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] && map[i + 1])
	{
		j = 1;
		while (j <= len / 2)
		{
			if (map[i][j] == 'C')
				return ;
			if (map[i + 1][j] == 'C')
				return ;
			if (map[i][len - j] == 'C')
				return ;
			if (map[i + 1][len - j] == 'C')
				return ;
			j++;
		}
		i += 2;
	}
	ft_free_array(map);
	ft_perror("Error\nNo hay objetos en el mapa\n");
}

static void	ft_check_walls(char **map)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_free_array(map);
			ft_perror("Error\nLas paredes no son validas\n");
		}
		i++;
	}
	i--;
	j = 0;
	while (map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
		{
			ft_free_array(map);
			ft_perror("Error\nLas paredes no son validas\n");
		}
		j++;
	}
}

static void	ft_check_len(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
		{
			ft_free_array(map);
			ft_perror("Error\nEl mapa no es cuadrilatero\n");
		}
		i++;
	}
	if ((i < 3 || len < 3) || (i == 3 && len < 5) || (len == 3 && i < 5))
	{
		ft_free_array(map);
		ft_perror("Error\nNo hay suficientes filas o columnas\n");
	}
}

void	ft_check_map(char **map)
{
	ft_check_len(map);
	ft_check_walls(map);
	ft_check_collectible(map);
	if (ft_check_dup(map, 'E', 0))
	{
		ft_free_array(map);
		ft_perror("Error\nHay duplicados de la salida o no existe\n");
	}
	if (ft_check_dup(map, 'P', 0))
	{
		ft_free_array(map);
		ft_perror("Error\nHay duplicados del personaje o no existe\n");
	}
}
