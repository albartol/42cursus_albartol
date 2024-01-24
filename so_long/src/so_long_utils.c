/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:48:27 by albartol          #+#    #+#             */
/*   Updated: 2024/01/23 17:38:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_perror(const char *str)
{
	if (str && *str)
		ft_putstr_fd((char *)str, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_array_dup(char **array)
{
	int		i;
	int		j;
	char	**dup;

	i = 0;
	while (array[i])
		i++;
	dup = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = ft_strdup(array[j]);
		if (!dup[j])
		{
			ft_free_array(dup);
			return (NULL);
		}
		j++;
	}
	return (dup);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
