/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:59 by albartol          #+#    #+#             */
/*   Updated: 2024/01/19 17:20:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	ft_check_file(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		ft_perror("Error en ft_check_file.\n");
	i -= 4;
	if (ft_strncmp(&file[i], ".ber", 4))
		ft_perror("Error en ft_check_file.\n");
}

static void	ft_rm_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i > 0)
		str[i] = 0;
}

static char	**ft_copy_map(t_list *lines)
{
	char	**map;
	size_t	len;
	int		i;
	char	*str;

	i = 0;
	if (!lines)
		ft_perror("Error en ft_read_map.\n");
	len = ft_lstsize(lines);
	map = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (lines)
	{
		str = (char *)lines->content;
		ft_rm_n(str);
		map[i] = ft_strdup(str);
		if (!map[i])
			return (NULL);
		lines = lines->next;
		i++;
	}
	return (map);
}

static char	**ft_read_map(int fd)
{
	char	*str;
	t_list	*lines;
	t_list	*temp;
	char	**map;

	lines = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		temp = ft_lstnew(str);
		if (!temp)
		{
			free(str);
			ft_lstclear(&lines, free);
			ft_perror("Error en ft_lstnew.\n");
		}
		ft_lstadd_back(&lines, temp);
	}
	map = ft_copy_map(lines);
	ft_lstclear(&lines, free);
	if (!map)
		ft_perror("Error en ft_copy_map.\n");
	return (map);
}

char	**ft_get_map(char *file)
{
	char	**map;
	int		fd;

	ft_check_file(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror("Error en ft_get_map.\n");
	map = ft_read_map(fd);
	close(fd);
	return (map);
}
