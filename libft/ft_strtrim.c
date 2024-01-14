/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:47:07 by albartol          #+#    #+#             */
/*   Updated: 2023/10/03 16:20:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/* static int	ft_count_trim(char const *s1, char const *set)
{
	int	i;
	int	n;
	int	cmp;

	i = 0;
	n = 0;
	cmp = 1;
	while (s1[i] && cmp)
	{
		while (s1[i] != set[n] && set[n])
			n++;
		if (s1[i] == set[n])
			i++;
		else
			cmp = 0;
		n = 0;
	}
	return (i);
}

static int	ft_count_trim_rev(char const *s1, char const *set)
{
	int	i;
	int	n;
	int	len;
	int	cmp;

	len = ft_strlen(s1) - 1;
	i = 0;
	n = 0;
	cmp = 1;
	while (len && cmp && s1[i])
	{
		while (s1[len] != set[n] && set[n])
			n++;
		if (s1[len] == set[n])
		{
			len--;
			i++;
		}
		else
			cmp = 0;
		n = 0;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		n;
	int		c;
	int		len;
	char	*str;

	len = ft_strlen(s1);
	i = ft_count_trim(s1, set);
	n = ft_count_trim_rev(s1 + i, set);
	len = len - i - n;
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	c = 0;
	while (--len > 0)
		str[c++] = s1[i++];
	str[c] = s1[i];
	return (str);
} */

/* #include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "));
	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	return (0);
} */