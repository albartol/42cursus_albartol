/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:30:37 by albartol          #+#    #+#             */
/*   Updated: 2023/10/25 15:17:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_order_nl(char *str)
{
	char	*res;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), str = NULL, NULL);
	res = (char *)ft_calloc(ft_strlen(str) - i + 1, 1);
	if (!res)
		return (free(str), str = NULL, NULL);
	i++;
	while (str[i])
		res[n++] = str[i++];
	return (free(str), res);
}

static char	*ft_substr_nl(char *str)
{
	char	*res;
	int		i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		res = (char *)ft_calloc(i + 1, 1);
	else
		res = (char *)ft_calloc(i + 2, 1);
	if (!res)
		return (0);
	while (i >= 0)
	{
		res[i] = str[i];
		i--;
	}
	return (res);
}

static char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	len;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, 1);
		if (!s1)
			return (0);
	}
	if (!s2)
		return (free(s1), NULL);
	i = ft_strlen(s1);
	n = ft_strlen(s2);
	str = (char *)ft_calloc(i + n + 1, 1);
	if (!str)
		return (free(s1), NULL);
	len = -1;
	while (++len < i)
		str[len] = s1[len];
	len = -1;
	while (++len < n)
		str[i + len] = s2[len];
	return (free(s1), str);
}

static char	*ft_read_nl(char *str, int fd)
{
	char	*res;
	ssize_t	data;

	res = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res)
		return (free(str), NULL);
	data = 2;
	while (!(ft_strchr(str, '\n')) && data)
	{
		data = read(fd, res, BUFFER_SIZE);
		if (data == -1)
			return (free(res), free(str), NULL);
		if (data == 0)
			return (free(res), str);
		res[data] = 0;
		str = ft_strjoin_nl(str, res);
		if (!str)
			return (free(res), str);
	}
	return (free(res), str);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_read_nl(temp, fd);
	if (!temp)
		return (0);
	res = ft_substr_nl(temp);
	if (!res)
		return (free(temp), temp = NULL, NULL);
	temp = ft_order_nl(temp);
	return (res);
}

/* int	main(int argc, char **argv)
{
    int i = 50;
	int fd = open(argv[1], O_RDONLY);
	char *res;
    while (i--)
	{
		res = get_next_line(fd);
	    printf("%s", res);
		if (res)
			free (res);
	}
	return (0);
} */
/* static size_t	ft_strlen_nl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

static char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	len;

	i = ft_strlen(s1);
	n = ft_strlen(s2);
	len = i + n;
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	len = -1;
	while (++len < i)
		str[len] = s1[len];
	len = -1;
	while (++len < n)
		str[i + len] = s2[len];
	if (i > 0)
		free(s1);
	return (str);
}

static char	*ft_read_nl(char *str, int fd)
{
	char	*res;
	ssize_t	data;

	res = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!res)
		return (0);
	data = 2;
	while (!(ft_strchr(str, '\n')) && data)
	{
		data = read(fd, res, BUFFER_SIZE);
		if (data == -1)
		{
			free(res);
			return (0);
		}
		else if (data < BUFFER_SIZE)
			res[data] = 0;
		str = ft_strjoin_nl(str, res);
		if (!str)
			data = 0;
	}
	free(res);
	return (str);
}

static int	ft_position(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i + 1);
		i++;
	}
	if (str[i] != (unsigned char)c)
		return (0);
	return (i + 1);
}

static char	*ft_substr_nl(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

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
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_nl(str, fd);
	if (!str || !*str)
	{
		free(str);
		return (0);
	}
	if (ft_strchr(str, '\n'))
	{
		res = ft_substr(str, 0, ft_position(str, '\n'));
		str = ft_substr_nl(str, ft_position(str, '\n'), ft_strlen(str));
	}
	if (!res || !str)
		return (free_nl(str, res));
	if (!ft_strchr(str, '\n'))
	{
		res = ft_substr(str, 0, ft_strlen(str));
		free (str);
	}
	return (res);
} */
/* char	*get_next_line(int fd)
{
	char	*str;
	char	*res;
	ssize_t	data;
	int		position;

	str = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (0);
	data = read(fd, str, BUFFER_SIZE);
	if (data < 0)
		return (0);
	position = ft_strchr(str, '\n');
	res = ft_substr(str, 0, position + 1);
	return (res);
} */

/* char	*get_next_line(int fd)
{
	static char	str[OPEN_MAX][BUFFER_SIZE];
	char		*res;
	long		i;
	int			n;

	i = 0;
	n = read(fd, str[i], BUFFER_SIZE);
	if (n == -1)
		return (0);
	res = ft_substr(str[i], 0, strchr(str[i], '\n'));
} */

/* static char	*free_array(char **array, int nb)
{
	while (nb >= 0)
		free(array[nb--]);
	free(array);
	return (0);
} */