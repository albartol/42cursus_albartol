/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:08 by albartol          #+#    #+#             */
/*   Updated: 2024/01/18 18:15:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    ft_print_map(char **map)
{
    int i;

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
    free(map);
	return (EXIT_SUCCESS);
}
