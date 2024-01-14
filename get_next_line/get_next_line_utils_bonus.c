/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:18 by albartol          #+#    #+#             */
/*   Updated: 2023/10/24 16:47:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t len, size_t size)
{
	unsigned char	*array;
	size_t			i;
	size_t			n;

	i = len * size;
	n = 0;
	array = (unsigned char *)malloc(i);
	if (!array)
		return (0);
	while (n < i)
	{
		array[n] = (unsigned char)0;
		n++;
	}
	return (array);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] != (unsigned char)c)
		return (0);
	return ((char *)str + i);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		str = (char *)ft_calloc(1, 1);
	else if (len > ft_strlen(s) - start)
		str = (char *)ft_calloc(ft_strlen(s) - start + 1, 1);
	else
		str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
		return (str);
	while (len-- && s[start])
		str[i++] = s[start++];
	return (str);
} */