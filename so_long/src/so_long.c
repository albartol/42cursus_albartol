/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:08 by albartol          #+#    #+#             */
/*   Updated: 2024/01/22 15:05:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h" 

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (EXIT_FAILURE);
	map = ft_get_map(argv[1]);
	ft_print_map(map);
	ft_check_map(map);
	ft_free_array(map);
	return (EXIT_SUCCESS);
}
